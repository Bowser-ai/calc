#ifndef CALC_STREAM_H_
#define CALC_STREAM_H_

#include "token.h"
#include "calc.h"

class Calc_stream
{

	public:
	Calc_stream(std::istream& is) : is{is} {}
	Token get()const;
	Token buffer() const ;
	void put_back(Token T) const; 
    void clean() const;
	bool is_ok() const {return static_cast<bool>(is);}

    private:
    bool allowed_char(char) const;
	std::istream& is;
	mutable bool empty{true};
	mutable Token token_buffer;
};

#endif
