#include "calc.h"
#include "calc_stream.h"

Token Calc_stream::get() const
{
	if(!empty) return buffer();

	char ch;
	is.get(ch);
	while(std::isspace(ch) && ch != print_line)
		is.get(ch);
		
	if (ch == print_line) return Token{print_line};

	switch(ch) {
		case quit: case group_open: case group_close: case brac_group_open: case brac_group_close:
		case addition: case minus: case multi: case division: case factorial: case equals:
			return Token{ch};
	}

	if (std::isdigit(ch)) {
		is.putback(ch);
		auto value{0.0};
		is >> value;
		return Token{num, value};
	}
		
	if (std::isalpha(ch) || allowed_char(ch)) {
		std::cin.putback(ch);
		std::string command;
		while(std::cin.get(ch) && (std::isalpha(ch) || allowed_char(ch))) command += ch;
		if (!std::isalpha(ch) && !allowed_char(ch)) std::cin.putback(ch);
		return Token(command_string, command);
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

bool Calc_stream::allowed_char(char ch) const
{
    return allowed_var_chars.find(ch) != std::string::npos;
}
