#include <iostream>
#include <math.h>
#include <limits>
#include <map>
#include <unordered_map>
#include <functional>
#include <tuple>
#include <vector>
#include "calc_stream.h"

#ifndef CALC_H_
#define CALC_H_

constexpr double PI = 3.1415926535;

double declaration();
double expression();
double term();
double primary();
double fac(int);

const std::string prompt{"|> "};
const std::string square_root{"sqrt"};
const std::string _pow{"pow"};
const std::string declkey{"let"};
constexpr int max_int{std::numeric_limits<int>::max()};
constexpr char equals{'='};
constexpr char quit{'q'};
constexpr char group_open{'('};
constexpr char group_close{')'};
constexpr char brac_group_open{'{'};
constexpr char brac_group_close{'}'};
constexpr char addition{'+'};
constexpr char minus{'-'};
constexpr char multi{'*'};
constexpr char division{'/'};
constexpr char num{'8'};
constexpr char print_line{'\n'};
constexpr char command_string{'s'};
constexpr char factorial{'!'};

extern Calc_stream Cs;

#endif

