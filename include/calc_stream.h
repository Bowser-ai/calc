#ifndef CALC_STREAM_H_
#define CALC_STREAM_H_

#include "token.h"
#include "calc.h"

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

    private:
    bool allowed_char(char) const;
};

#endif
