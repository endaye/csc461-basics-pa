
#include "UnitTest.h"
#include "answerRegistry.h"


TEST( simple_1, PointerWalk_Group )
{
	CHECK_EQUAL( Answer::getAnswer(0, 0), 0xAB );	
	CHECK_EQUAL( Answer::getAnswer(0, 1), 0x3f );
	CHECK_EQUAL( Answer::getAnswer(0, 2), 0xb5 );
	CHECK_EQUAL( Answer::getAnswer(0, 3), 0xcd );
	CHECK_EQUAL( Answer::getAnswer(0, 4), 0x44 );
	CHECK_EQUAL( Answer::getAnswer(0, 5), 0xcd );
	CHECK_EQUAL( Answer::getAnswer(0, 6), 0x75 );
	CHECK_EQUAL( Answer::getAnswer(0, 7), 0x11 );
	CHECK_EQUAL( Answer::getAnswer(0, 8), 0x29 );
	CHECK_EQUAL( Answer::getAnswer(0, 9), 0x56 );
	CHECK_EQUAL( Answer::getAnswer(0, 10), 0xa9 );
	CHECK_EQUAL( Answer::getAnswer(0, 11), 0xa9 );
}

TEST( simple_2, PointerWalk_Group )
{
	CHECK_EQUAL( Answer::getAnswer(0, 12), 0x3f12cdab );	
	CHECK_EQUAL( Answer::getAnswer(0, 13), 0x11225529 );
	CHECK_EQUAL( Answer::getAnswer(0, 14), 0x35d3b533 );
	CHECK_EQUAL( Answer::getAnswer(0, 15), 0x13a98856 );
	CHECK_EQUAL( Answer::getAnswer(0, 16), 0x11225529 );
}

TEST( simple_3, PointerWalk_Group )
{
	CHECK_EQUAL( Answer::getAnswer(0, 17), 0x0366 );	
	CHECK_EQUAL( Answer::getAnswer(0, 18), 0x3375 );
	CHECK_EQUAL( Answer::getAnswer(0, 19), 0x2668 );
	CHECK_EQUAL( Answer::getAnswer(0, 20), 0x8856 );
	CHECK_EQUAL( Answer::getAnswer(0, 21), 0x13 );
	CHECK_EQUAL( Answer::getAnswer(0, 22), 0x29 );	
	CHECK_EQUAL( Answer::getAnswer(0, 23), 0x14 );
}




TEST( simple_4, PointerWalk_Group )
{
 CHECK_EQUAL( Answer::getAnswer(1, 0), 0x11);
 CHECK_EQUAL( Answer::getAnswer(1, 1), 0xbb000000);
 CHECK_EQUAL( Answer::getAnswer(1, 2), 0xbb000011);
 CHECK_EQUAL( Answer::getAnswer(1, 3), 0xbb000022);
 CHECK_EQUAL( Answer::getAnswer(1, 4), 0xdd00);
 CHECK_EQUAL( Answer::getAnswer(1, 5), 0xdd11);
 CHECK_EQUAL( Answer::getAnswer(1, 6), 0xdd22);
 CHECK_EQUAL( Answer::getAnswer(1, 7), 0x0);
 CHECK_EQUAL( Answer::getAnswer(1, 8), 0x11);
 CHECK_EQUAL( Answer::getAnswer(1, 9), 0x22);
}

TEST( simple_5, PointerWalk_Group )
{
  CHECK_EQUAL( Answer::getAnswer(1, 11),  0x1);
  CHECK_EQUAL( Answer::getAnswer(1, 12),  0x4);
  CHECK_EQUAL( Answer::getAnswer(1, 13),  0x14);
  CHECK_EQUAL( Answer::getAnswer(1, 14),  0x1);
  CHECK_EQUAL( Answer::getAnswer(1, 15),  0x4);
  CHECK_EQUAL( Answer::getAnswer(1, 16),  0x8);
  CHECK_EQUAL( Answer::getAnswer(1, 17),  0x0);
  CHECK_EQUAL( Answer::getAnswer(1, 18),  0x1);
  CHECK_EQUAL( Answer::getAnswer(1, 19),  0x3);
}
