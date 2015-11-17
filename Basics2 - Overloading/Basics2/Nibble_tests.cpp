#include <stdio.h>
#include "UnitTest.h"
#include "Nibble.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
// ---------------------------------------------------------------------------------
TEST( Basics, NibbleGroup )
{
	// default
	Nibble A;

	CHECK( A.getData() == 0 );

	// copy
	Nibble B(5);
	Nibble C(B);

	CHECK( B.getData() == 5 );
	CHECK( C.getData() == 5 );

	// Assign
	Nibble D;
	Nibble E(13);

	D = E;

	CHECK( D.getData() == 13 );
	CHECK( E.getData() == 13 );

	// quick walk
	for( int i = 0; i < 20; i++)
	{
		Nibble B(i);
		CHECK ( B.getData() < 16 );
	}

	// Random check
	Nibble F(4);
	Nibble G(15);
	Nibble H(16);
	Nibble I(17);
	Nibble J(33);

	CHECK( F.getData() == 4 );
	CHECK( G.getData() == 0xF );
	CHECK( H.getData() == 0 );
	CHECK( I.getData() == 1 );
	CHECK( J.getData() == 1 );
}


TEST( AddOp, NibbleGroup )
{
	
	Nibble A(3);
	Nibble B(4);
	Nibble C;

	CHECK( A.getData() == 3 );
	CHECK( B.getData() == 4 );
	CHECK( C.getData() == 0 );

	C = A + B;

	CHECK( A.getData() == 3 );
	CHECK( B.getData() == 4 );
	CHECK( C.getData() == 7 );

	Nibble D(5);
	Nibble E(13);

	D += E;

	CHECK( D.getData() == 2 );
	CHECK( E.getData() == 13);

	Nibble F(8);
	Nibble G;

	G = F + 3;

	CHECK( F.getData() == 8 );
	CHECK( G.getData() == 11 );

	Nibble H(14);
	Nibble I;

	I = 7 + H;

	CHECK( H.getData() == 14 );
	CHECK( I.getData() == 5 );

}

TEST( SpecialOps, NibbleGroup )
{
	
	Nibble A(5);
	Nibble B;

	B = ~A;

	CHECK( A.getData() == 5 );
	CHECK( B.getData() == 0xA );

	Nibble C(7);
	Nibble D;

	D = +C;

	CHECK( C.getData() == 7 );
	CHECK( D.getData() == 7 );

	// You have to use the casting operator for the next code segment below
	// Do not use another technique, please single step through your code
	
	// For academic purposes, 
	//     please have your casting operator add 5 to the converted value
	Nibble E(13);
	unsigned int MonkeyVal(0);

	MonkeyVal = E;

	CHECK( MonkeyVal == 18 );
	CHECK( E.getData() == 13 );

}

TEST( IncrementOps, NibbleGroup )
{

	Nibble A(10);
	Nibble B;

	// increment operators should wrap, just like eveything else
	B = ++A;

	CHECK( B.getData() == 11 );
	CHECK( A.getData() == 11 );

	B = ++A;

	CHECK( B.getData() == 12 );
	CHECK( A.getData() == 12 );

	++A;
	++A;
	B = ++A;

	CHECK( B.getData() == 15 );
	CHECK( A.getData() == 15 );
	
	B = ++A;

	CHECK( B.getData() == 0 );
	CHECK( A.getData() == 0 )
		
	B = ++A;

	CHECK( B.getData() == 1 );
	CHECK( A.getData() == 1 );

	Nibble C(3);
	Nibble D;

	D = C++;

	CHECK( C.getData() == 4 );
	CHECK( D.getData() == 3 );
	
	Nibble E(0xE);
	Nibble F;

	F = E++;
	
	CHECK( E.getData() == 0xF );
	CHECK( F.getData() == 0xE );

	F = E++;
	
	CHECK( E.getData() == 0 );
	CHECK( F.getData() == 0xF );

	F = E++;
	
	CHECK( E.getData() == 1 );
	CHECK( F.getData() == 0 );

}


TEST( BitShift, NibbleGroup )
{
	// Remember everything wraps around the 4 bits of the nibble
	Nibble A(10);
	Nibble B;

	B = A << 1;

	CHECK( A.getData() == 10 );
	CHECK( B.getData() == 5 );

	B = B << 1;

	CHECK( B.getData() == 10 );

	Nibble C(1);
	Nibble D;

	D = C << 1;
	
	CHECK( C.getData() == 1 );
	CHECK( D.getData() == 2 );

	D = D << 1;

	CHECK( D.getData() == 4 );

	D = D << 1;

	CHECK( D.getData() == 8 );

	D = D << 1;

	CHECK( D.getData() == 1 );

	Nibble E(3);
	Nibble F;
	
	F = E << 1;
	
	CHECK( E.getData() == 3 );
	CHECK( F.getData() == 6 );

	F = F << 1;

	CHECK( F.getData() == 12 );

	F = F << 1;

	CHECK( F.getData() == 9 );

	F = F << 1;

	CHECK( F.getData() == 3 );

	Nibble G(7);
	Nibble H;

	H = G << 0;

	CHECK( H.getData() == 7);

	H = G << 1; 

	CHECK( H.getData() == 0xE );

	H = G << 2;

	CHECK( H.getData() == 0xD );

	H = G << 3;

	CHECK( H.getData() == 0xB );

	H = G << 4;

	CHECK( H.getData() == 0x7 );

}