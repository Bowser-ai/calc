#include <iostream>
#include <math.h>
#include <limits>
#include <map>
#include <functional>
#include <tuple>
#include <vector>

#ifndef CALC_H_
#define CALC_H_

constexpr double PI = 3.1415926535;

double expression();
double term();
double primary();
double fac(int);

const std::string prompt{"|> "};
const std::string square_root{"sqrt"};
const std::string _pow{"pow"};
constexpr int max_int{std::numeric_limits<int>::max()};
constexpr char quit{'q'};
constexpr char group_open{'('};
constexpr char group_close{')'};
constexpr char addition{'+'};
constexpr char minus{'-'};
constexpr char multi{'*'};
constexpr char division{'/'};
constexpr char num{'8'};
constexpr char print_line{'\n'};
constexpr char command_string{'s'};
constexpr char factorial{'!'};


struct Token
{
	char kind;
	double value{};
	std::string command;

	Token(char kind, double value = 0.0): kind{kind}, value{value} {}
	Token(char kind, std::string command) : kind{kind}, command{command} {}
	Token() {}
};

class Calc_stream
{
	std::istream& is;
	mutable bool empty{true};
	Token token_buffer;

	public:
	Calc_stream(std::istream& is) : is{is} {}
	Token get()const;
	Token buffer() const ;
	void put_back(Token T); 
    void clean() const;

};

extern Calc_stream Cs;

	

#endif

