#include <gtest/gtest.h>
#include "calc.h"

TEST(expression, expression) {
	std::cout << "make the expression equal 4\n";
	EXPECT_EQ(4, expression());
	Token T = Cs.get();
}

TEST(term, term)
{
	std::cout << "Make the term equals 10\n";
	EXPECT_EQ(10, term());
	Token T = Cs.get();
}

TEST(prim, prim)
{
	std::cout <<" Make the primary equals 25\n";
	EXPECT_EQ(25, primary());
	Token T = Cs.get();
}

TEST(FAC,FAC)
{
	EXPECT_EQ(120, fac(5));
}


int main(int agv, char* agc[])
{
	testing::InitGoogleTest(&agv, agc);
	return RUN_ALL_TESTS();
}
