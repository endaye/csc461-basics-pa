#include "UnitTest.h"
#include "A.h"
#include "C.h"
#include "E.h"
#include "M.h"


TEST( Public1, PublicInheritanceTests)
{
	
	if (1)  // used to control scope in this test
	{
		B dataB;
		A *pA = &dataB;
		pA->getX();
	}

	if (1)   // used to control scope in this test
	{
		A *pA = new B;
		delete pA;
	}

	CHECK( bufferManager::getInstance()->getCount() == 0 );
}


TEST( Public2, PublicInheritanceTests)
{
	
	D d0;

	CHECK( d0.getX() == 33 );
	CHECK( d0.getY() == 44 );
	CHECK( d0.getZ() == 55 );

	D d1( 0xAA, 0xBB, 0xCC );

	CHECK( d1.getX() == 0xAA);
	CHECK( d1.getY() == 0xBB );
	CHECK( d1.getZ() == 0xCC );

	CHECK( bufferManager::getInstance()->getCount() == 0 );
}


TEST( Public3, PublicInheritanceTests)
{
	H data;

	CHECK( data.a == 11 );
	CHECK( data.b == 22 );
	CHECK( data.c == 33 );
	CHECK( data.d == 44 );

	CHECK( sizeof(H) == 24 );

	F *pF = &data;
	G *pG = &data;

	CHECK( pF->a == 11 );
	CHECK( pF->b == 22 );

	CHECK( pG->a == 11 );
	CHECK( pG->c == 33 );

	CHECK( bufferManager::getInstance()->getCount() == 0 );
}


TEST( Public4, PublicInheritanceTests)
{
	P data;

	CHECK( data.a == 11 );
	CHECK( data.b == 22 );
	CHECK( data.c == 33 );
	CHECK( data.d == 44 );

	CHECK( sizeof(P) == 24 );

	N *pN = &data;
	O *pO = &data;

	CHECK( pN->a == 11 );
	CHECK( pN->b == 22 );

	CHECK( pO->a == 11 );
	CHECK( pO->c == 33 );

	P data1( 5,6,7,8 );

	CHECK( data1.a == 5 );
	CHECK( data1.b == 6 );
	CHECK( data1.c == 7 );
	CHECK( data1.d == 8 );

	pN = &data1;
	pO = &data1;

	CHECK( pN->a == 5 );
	CHECK( pN->b == 6 );

	CHECK( pO->a == 5 );
	CHECK( pO->c == 7 );

	CHECK( bufferManager::getInstance()->getCount() == 0 );
}
