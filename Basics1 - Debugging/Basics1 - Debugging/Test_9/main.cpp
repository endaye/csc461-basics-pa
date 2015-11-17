#include <stdio.h>

// ----------------------------------------------------------------------
// Problem 9:
//
// Rules: Fix the code to correctly calculated the triangular sum
//        You can make this work with a small addition
// ----------------------------------------------------------------------

const int N = 10;
int a[N];

int getTriangularSum()
{
	// so we can compute the Nth Triangular Number
	// number: 1 + 2 + 3 + ... + N
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += a[i];
	}

	return sum;
}

// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
void prepareArray()
{
	int n = 0;
	// prepare an array of ascending
	// integers:  1, 2, 3, ... , N
	for (int i = 0; i < N; i++)
	{
		a[i] = ++n;
	}

}

// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
int main()
{
	// test 9 header
	printf("\nTest_9: \n\n");

	// initialize the array
	prepareArray();

	//compute the Nth Triangular Number
	int sum = getTriangularSum();

	/* for N == 10 this should be 55 */
	printf( "expected:55  actual:%d\n", sum );
}