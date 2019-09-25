#include "calc.h"

Calc_stream Cs{std::cin};


Token Calc_stream::get() const
{
	if(!empty) return buffer();

	char ch;
	is.get(ch);
	while(std::isspace(ch) && ch != print_line)
		is.get(ch);
		
	if (ch == print_line) return Token{print_line};

	switch(ch) {
		case quit: case group_open: case group_close:
        case addition: case minus: case multi: case division: case factorial:
			return Token{ch};
	}

	if (std::isdigit(ch)) {
		is.putback(ch);
		auto value{0.0};
		is >> value;
		return Token{num, value};
	}
		
		std::vector<std::string> commands_db{
			square_root,
            _pow
		};

		std::string command{ch};

		while(ch != '\n' && is.get(ch) ) {
			command += ch;
			for (auto& elem : commands_db)
			{
				if (elem == command) return Token{command_string,elem};
			}
			
		}
		is.putback(ch);
		throw std::runtime_error("Bad input");
}

Token Calc_stream::buffer() const 
{
	if(empty) throw std::runtime_error("error buffer is empty\n");
	empty=true;
	return token_buffer;
}

void Calc_stream::put_back(Token T) 
{
	if(!empty) throw std::runtime_error("buffer is full\n");
	token_buffer = T;
	empty = false;
}

void Calc_stream::clean() const 
{
    is.ignore(100000, '\n');
    char c;
    if (empty) return;
    empty = true;
}

double expression() {

	auto output = 0.0;
	output = term();
	
	while(true) {
		Token T = Cs.get();
	
	switch (T.kind) {
	
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

double term() {

	auto value = 0.0;
	value = primary();
		
	while(true){

		Token T = Cs.get();
		switch (T.kind) {
	
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

double primary () {
	Token T = Cs.get();

	switch(T.kind) { 
		
		case num:
			return T.value;
			
		case group_open: {
			auto value{0.0};
			value = expression();
            Token T = Cs.get();
			if (T.kind != group_close) {
				Cs.put_back(T);
				throw std::runtime_error("Did you forgot the \')\'?");
			}
			return value;
						 }

		case command_string:
			if(T.command == square_root) return std::sqrt(expression());
            if(T.command == _pow) {
                auto value_1 = expression();
                auto value_2 = expression();
                return std::pow(value_1, value_2);
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



