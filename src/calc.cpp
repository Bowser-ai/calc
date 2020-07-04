#include "calc.h"
#include "var_table.h"

Var_table var_table;

double set_var(const Calc_stream& cs, bool is_const=false)
{
	auto var_name = cs.get().command;
	auto T = cs.get();
	if (T.kind != equals) throw std::runtime_error{"expecting an = after var_name in a let expression"};
	double d = expression(cs);
	var_table.set_value(var_name, d, is_const);
	return d;
}

double declaration(const Calc_stream& cs)
{
	Token T = cs.get();
    if (T.kind == command_string)
		{
			if (T.command == declkey) return set_var(cs, false);
			if (T.command == constkey) return set_var(cs, true);
		}
	cs.put_back(T);
	return expression(cs);
}

double expression(const Calc_stream& cs) 
{
	auto output = 0.0;
	output = term(cs);
	
	while(true) 
    {
		Token T = cs.get();
	
	switch (T.kind) 
    {
		case addition:
            output += term(cs);
            break;
				
		
		case minus:  
            output -= term(cs);
            break;
				
	
		default:	
            cs.put_back(T);
            return output;
	
		}
	}
}

double term(const Calc_stream& cs) 
{
	auto value = 0.0;
	value = primary(cs);
		
	while(true)
    {
		Token T = cs.get();
		switch (T.kind) 
        {
			case multi : 
                value *= primary(cs);
                break;
						
			case division : 
                value /= primary(cs);
                break;

            case factorial:
                value = fac(value);
                break;
	
			default:
                cs.put_back(T);
                return value;
					
		}
	}
}

double primary(const Calc_stream& cs) 
{
	Token T = cs.get();

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
				value = expression(cs);
				Token T = cs.get();
				if (T.kind != matching_close_group) 
                {
					cs.put_back(T);
					throw std::runtime_error("Did you forgot the \')\'?");
				}
				return value;
			}

		case command_string:
            {
                if (T.command == square_root) return std::sqrt(expression(cs));
                auto T2 = cs.get();
                if ( T2.kind == equals)
                {
                    double d = expression(cs);
                    return var_table.reassign(T.command, d);
                }
                cs.put_back(T2);
                return var_table.get_value(T.command);
            }

		case quit:
			exit(0);
	}

	throw std::runtime_error("Bad input");
}

double fac(int n)
{
	return (n>1) ? n*fac(n-1) : 1;
}
