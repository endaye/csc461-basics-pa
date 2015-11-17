#include <stdio.h>

// ----------------------------------------------------------------------
// Problem 5:
//
// Rules: Expected to sum the numbers from 1 to 9, 
//        fixed the getNum() function
//        As ugly as this function is..., keep the same logic
// ----------------------------------------------------------------------

// Function getNum(), returns true/false, increments n
bool getNum( int& n )
{
	n = n + 1;

	if( n < 10 ) 
	{
		return true;
	}
	else
	{
		return false;
	}   
}

// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
int main()
{
	// test 5 header
	printf("\nTest_5: \n\n");

	// init the variables
	int n = 0;
	int sum = 0;

	// sum up the numbers
	while( getNum(n) && n ) 
	{
		sum += n;
	}

	printf( "expected sum: 45 actual sum: %d\n", sum );

	return 0;

}

