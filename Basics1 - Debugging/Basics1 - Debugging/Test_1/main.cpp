#include <stdio.h>

// ----------------------------------------------------------------------
// Problem 1:
//
// Rules: fix the small bug in the function, called findBitsInNibble
//        to output the correct number of '1' bits of any given number
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function: returns the number of 1 bits in a the data
// ----------------------------------------------------------------------
int findBitsInNibble(unsigned int data)  
{
	int n(0);
	//int bitPattern[16] = { 0,1,2,2,1,2,2,3,1,2,2,3,2,3,4 };
	int bitPattern[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };

	while( data > 0 )
	{
		n += bitPattern[ data & 0xF ];
		data >>= 4;
	}
	return n;
}


// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
int main()
{
	// test 1 header
	printf("\nTest_1: \n\n");

	// This function should return 7, but it returns 4
	printf( "-->expected:7  actual:%d\n", findBitsInNibble( 0x2F81 ) );

	return 0;
}

