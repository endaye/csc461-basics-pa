#include "UnitTest.h"



TEST( testName, TestGroup )
{
	int x = 5;

	CHECK( x == 5 );
}

TEST( testWillFail, TestGroup )
{
	int x = 6;

	CHECK( x == 5 );
}

TEST( Addition, IntTests )
{
    CHECK( 1 + 1 == 2 );
}

TEST( Addition, FloatTests )
{
    CHECK( 1.0f + 1.0f == 2.0f );
}

TEST( Addition, MathTests )
{
    CHECK( 1 + 1 == 2 );
    CHECK( 2 + 2 == 4 );
}

TEST( AdditionInplace, MathTests )
{
    CHECK_EQUAL( 2, 1 + 1 );
    CHECK_EQUAL( 4, 2 + 2 );
}

TEST( SquareRoot, MathTests )
{
    DOUBLES_EQUAL( 1.414, sqrt( 2.0 ), 0.001 );
}
