#include "token.h"
#ifndef CALC_STREAM_H_
#define CALC_STREAM_H_

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

#endif
