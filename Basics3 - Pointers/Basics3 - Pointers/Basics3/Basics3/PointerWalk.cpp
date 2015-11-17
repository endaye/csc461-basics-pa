#include <assert.h>
#include "answerRegistry.h"



#define QuestionAnswer(x,y)  Answer::registerAnswer(0,x,y)

unsigned char data[] =
{ 
  0xAB, 0xCD, 0x12, 0x3F,
  0x33, 0xB5, 0xD3, 0x35,
  0x23, 0x24, 0x01, 0xFE,
  0xCD, 0x33, 0x44, 0x55,
  0x66, 0x03, 0x75, 0x33,
  0x29, 0x55, 0x22, 0x11,
  0x56, 0x88, 0xA9, 0x13,
  0x14, 0x82, 0x68, 0x26 
};


void Students_PointerWalk()
{
	unsigned char  *p;  // char are 8-bits wide
	unsigned int   *r;  // ints are 32-bits wide
	unsigned short *s;  // shorts are 16-bits wide

	unsigned int val;   // answer value

	// Sample Question 1
	// follow the pattern for the whole walking pointer test

	p = &data[0];       
	
	val = p[0];
	QuestionAnswer(0, 0xAB);
	
	// first page

	val = *(p + 3);
	QuestionAnswer(1, 0x3F);
	
	val = *(p + 5);
	QuestionAnswer(2, 0xB5);
	
	p = p + 12;
	val = *(p);
	QuestionAnswer(3, 0xCD);

	val = p[2];
	QuestionAnswer(4, 0x44);

	val = *p++;
	QuestionAnswer(5, 0xCD);

	p += 6;
	val = *--p;
	QuestionAnswer(6, 0x75);

	val = p[5];
	QuestionAnswer(7, 0x11);
	
	p = p + 2;
	val = *p++;
	QuestionAnswer(8, 0x29);
	
	val = *(p + 3);
	QuestionAnswer(9, 0x56);
	
	p = 5 + p;
	val = *(p++);
	QuestionAnswer(10, 0xA9);
	
	val = *(--p);
	QuestionAnswer(11, 0xA9);

	// second page

	r = (unsigned int*)&data[0];
	
	val = *(r);
	QuestionAnswer(12, 0x3F12CDAB);
	
	val = *(r + 5);
	QuestionAnswer(13, 0x11225529);

	r++;
	val = *r++;
	QuestionAnswer(14, 0x35D3B533);

	r = r + 2;
	val = r[2];
	QuestionAnswer(15, 0x13A98856);
	
	r = r + 1;
	val = r[0];
	QuestionAnswer(16, 0x11225529);
	
	s = (unsigned short *)r;

	val = s[-2];
	QuestionAnswer(17, 0x0366);

	s = s - 3;
	val = s[2];
	QuestionAnswer(18, 0x3375);
	
	s += 5;
	val = *(s + 3);
	QuestionAnswer(19, 0x2668);
	
	val = *(s);
	QuestionAnswer(20, 0x8856);
	
	p = (unsigned char *)s;
	val = *(p + 3);
	QuestionAnswer(21, 0x13);
	
	p += 5;
	val = p[-9];
	QuestionAnswer(22, 0x29);
	
	--p;
	val = p[0];
	QuestionAnswer(23, 0x14);
	

	// Now repeat for the pointer test
	// 0-23 question in total for this part

	// Make sure you look at the memory window 
	// and understand the test thoroughly

   

}


