#include <string>
#ifndef TOKEN_H_
#define TOKEN_H_

struct Token
{
	char kind;
	double value{};
	std::string command;

	Token(char kind, double value = 0.0): kind{kind}, value{value} {}
	Token(char kind, std::string command) : kind{kind}, command{command} {}
	Token() {}
};

#endif
