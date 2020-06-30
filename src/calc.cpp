#include "calc.h"
#include "var_table.h"

Calc_stream Cs{std::cin};
Var_table var_table;

double declaration()
{
	Token T = Cs.get();
    if (T.kind == command_string && T.command == declkey)
    {
        auto var_name = Cs.get().command;
        T = Cs.get();
        if (T.kind != equals) throw std::runtime_error{"expecting an = after var_name in a let expression"};
        double d = expression();
        var_table.set_value(var_name, d);
        return d;
    }
	Cs.put_back(T);
	return expression();
}

double expression() 
{
	auto output = 0.0;
	output = term();
	
	while(true) 
    {
		Token T = Cs.get();
	
	switch (T.kind) 
    {
		case addition:
            output += term();
            break;
				
		
		case minus:  
            output -= term();
            break;
				
	
		default:	
            Cs.put_back(T);
            return output;
	
		}
	}
}

double term() 
{
	auto value = 0.0;
	value = primary();
		
	while(true)
    {
		Token T = Cs.get();
		switch (T.kind) 
        {
			case multi : 
                value *= primary();
                break;
						
			case division : 
                value /= primary();
                break;

            case factorial:
                value = fac(value);
                break;
	
			default:
                Cs.put_back(T);
                return value;
					
		}
	}
}

double primary () 
{
	Token T = Cs.get();

	switch(T.kind) 
    { 
		case num:
			return T.value;
			
		case group_open: 
		case brac_group_open: 
			{
				const std::unordered_map<char, char> match_grouping{
					{brac_group_open, brac_group_close}, {group_open, group_close}};
				char matching_close_group{match_grouping.at(T.kind)};
				auto value{0.0};
				value = expression();
				Token T = Cs.get();
				if (T.kind != matching_close_group) 
                {
					Cs.put_back(T);
					throw std::runtime_error("Did you forgot the \')\'?");
				}
				return value;
			}

		case command_string:
			if (T.command == square_root) return std::sqrt(expression());
			return var_table.get_value(T.command);

		case quit:
			exit(0);
	}

	throw std::runtime_error("Bad input");
}

double fac(int n)
{
	return (n>1) ? n*fac(n-1) : 1;
}
