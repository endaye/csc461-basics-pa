#include <stdio.h>
#include "answerRegistry.h"

#define QuestionAnswer(x,y)  Answer::registerAnswer(1,x,y)

struct Cat
{
	Cat()
	:c0( 0x00 ), c1(0x11), c2(0x22)
	{}

	unsigned char c0;
	unsigned char c1;
	unsigned char c2;
};

struct Dog
{
	Dog()
	: d0(0xDD00), d1(0xDD11), d2(0xDD22)
	{}

	unsigned short d0;
	unsigned short d1;
	unsigned short d2;
};

struct Bird
{
	Bird()
	: b0(0xBB000000), b1(0xBB000011), b2(0xBB000022)
	{}

	unsigned int b0;
	unsigned int b1;
	unsigned int b2;
};

struct petStore
{
	Cat		morris;
	Dog		fido;
	Bird	poly;
};


void Students_Casting()
{
	petStore		ps;
	unsigned int	*r;
	unsigned short	*s;
	unsigned char	*p;
	unsigned int   val;

	// Example:
	// Using only:  
	//             unsigned char *p
	//             initialize p with ps
	// Using only p, find the values: 
	//      question 0) morris.c1

	p = &ps.morris.c1;
	QuestionAnswer( 0, p[0] );

	// Now repeat the pattern above { use the QuestionAnswer( index, val ) macro } 

	// Using only:  
	//             unsigned int *r
	//             initialize r with ps
	// Using only r, find the values: 
	//      question 1)  b0 
	//      question 2)  b1
	//      question 3)  b2 

	r = &ps.poly.b0;
	QuestionAnswer(1, r[0]);
	QuestionAnswer(2, r[1]);
	QuestionAnswer(3, r[2]);


	// Using only:  
	//             unsigned short *s
	//             initialize s with ps
	// Using only s, find the values: 
	//      question 4)  d0 
	//      question 5)  d1
	//      question 6)  d2 

	s = &ps.fido.d0;
	QuestionAnswer(4, s[0]);
	QuestionAnswer(5, s[1]);
	QuestionAnswer(6, s[2]);

	
	// Using only:  
	//             unsigned char *p
	//             initialize p with ps
	// Using only p, find the values: 
	//      question 7)  c0 
	//      question 8)  c1
	//      question 9)  c2 

	p = &ps.morris.c0;
	QuestionAnswer(7, p[0]);
	QuestionAnswer(8, p[1]);
	QuestionAnswer(9, p[2]);
		

	// For the next set of questions
	//
	// You can cast and create temp variables to help you answer questions correctly.
	//          p <- the starting address of ps
	//          s <- the starting address of ps
	//          r <- the starting address of ps


	//      question 10)  addr of ps
	int addr = (int)&ps;
	QuestionAnswer(10, addr);

	/*
	0x0031FC60  00 11 22 cc  .."Ì
	0x0031FC64  00 dd 11 dd  .Ý.Ý
	0x0031FC68  22 dd cc cc  "ÝÌÌ
	0x0031FC6C  00 00 00 bb  ...»
	0x0031FC70  11 00 00 bb  ...»
	0x0031FC74  22 00 00 bb  "..»
	*/

	//      question 11)  number of unsigned chars to c1
	//      question 12)  number of unsigned chars to d0
	//      question 13)  number of unsigned chars to b2;
	
	QuestionAnswer(11, 1);
	QuestionAnswer(12, 4);
	QuestionAnswer(13, 20);

	//      question 14)  number of unsigned shorts to the first c2
	//      question 15)  number of unsigned shorts to the first d2
	//      question 16)  number of unsigned shorts to b1;

	QuestionAnswer(14, 1);
	QuestionAnswer(15, 4);
	QuestionAnswer(16, 8);

	//      question 17)  number of unsigned ints to the first c0
	//      question 18)  number of unsigned ints to the first d0
	//      question 19)  number of unsigned ints to the first b0;

	QuestionAnswer(17, 0);
	QuestionAnswer(18, 1);
	QuestionAnswer(19, 3);

	



}