#include "Expr.h"
#include <gtest.h>



TEST(expression, test_on_smoke)
{
	expression input("|1.23+a| a=2.0");
	ASSERT_TRUE(3.23 == input.counting());
}

TEST(EXPression, test_on_ez_aritm)
{
	expression input("5+5*2^5-7");
	ASSERT_TRUE(158 == input.counting());
}

TEST(EXPression, test_on_braets_abs_aritm)
{
	expression input("-100+|2-(5+5)^2*2|");
	ASSERT_TRUE(98 == input.counting());
}

TEST(EXPression, test_on_pow_and_abs)
{
	expression input("2^|2^2|");
	ASSERT_TRUE(16 == input.counting());
}

TEST(EXPression, test_on_abs)
{
	expression input("-100+|2-(-5+5)^2*2|");
	ASSERT_TRUE(-98 == input.counting());
}

TEST(EXPression, test_on_un_munis_and_abs)
{
	expression input("-10+|-100-2|");
	ASSERT_TRUE(92 == input.counting());
}

TEST(EXPression, test_on_many_vars_and_aritm)
{
	expression input("2-(d+5)^a*l a=5 d=0 l=2");
	ASSERT_TRUE(-6248 == input.counting());
}

	
TEST(EXPression, test_on_correct_inp1)
{
	EXPECT_ANY_THROW(expression input("2...2"));
}
TEST(EXPression, test_on_correct_inp2)
{
	expression input("2+2");
	ASSERT_TRUE(input.counting() == 4);
}

TEST(EXPression, test_on_correct_inp3)
{
	expression input("--");
	EXPECT_ANY_THROW(input.counting());
}
TEST(EXPression, test_on_correct_inp4)
{
	EXPECT_ANY_THROW(expression input(")"));
}
TEST(EXPression, test_on_correct_inp5)
{
	EXPECT_ANY_THROW(expression input("#_1.20"));
}
TEST(EXPression, test_on_correct_inp6)
{
	EXPECT_ANY_THROW(expression input("="));
}
TEST(EXPression, test_on_correct_inp7)
{
	EXPECT_ANY_THROW(expression input("0.12.12.$"));
}
TEST(EXPression, test_on_correct_inp8)
{
	EXPECT_ANY_THROW(expression input("-(0,12)"));
}

TEST(EXPression, test_on_correct_inp9)
{
	EXPECT_ANY_THROW(expression input("-0.12+#"));
}


TEST(EXPression, test_on_correct_var)
{
	ASSERT_NO_THROW(expression input("|3+2+13+2+a| a=-2.12"));
}

TEST(EXPression, test_on_smoke_1)
{
	expression input("(-a) a=3");
	EXPECT_TRUE(input.counting() == -3);
}


TEST(EXPression, test_on_smoke_2)
{
	EXPECT_ANY_THROW(expression input("(-3)*a a==2"));
}


TEST(EXPression, test_on_brackets_1)
{
	EXPECT_ANY_THROW(expression input("()((()"));
}

TEST(EXPression, test_on_brackets_2)
{
	EXPECT_ANY_THROW(expression input("()((())))"));
}

TEST(EXPression, test_on_brackets_3)
{
	expression input("()((()))");
}

TEST(EXPression, test_on_brackets_4)
{
	expression input("(2-((d)+(5))^(a)*(l)) a=5 d=0 l=2");
	ASSERT_TRUE(-6248 == input.counting());
}

TEST(EXPression, test_on_brackets_5)
{
	EXPECT_ANY_THROW(expression input("(2-((d)+(5)))^(a)*(l)) a=5 d=0 l=2"));
}

TEST(EXPression, test_on_abs__)
{
	EXPECT_ANY_THROW(expression input("|||"));
}

TEST(EXPression, test_on_abs_2)
{
	expression input("|(-5^(-1)*5-2)|");
	ASSERT_TRUE(3 == input.counting());
}

TEST(EXPression, test_on_abs_3)
{
	expression input("(|-5^(-1)*5|-|-2|)");
	ASSERT_TRUE(-1 == input.counting());
}

TEST(EXPression, test_on_abs_brack)
{
	EXPECT_ANY_THROW(expression input("(|)|"));
}