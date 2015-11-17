#include <stdio.h>

// ----------------------------------------------------------------------
// Problem 4:
//
// Rules: fixed the class to output the desired effect
//
// Note: the class has to be initialied using the initializer list only
// ----------------------------------------------------------------------

class Dog
{
public:
	Dog( int val ) 
	: lowerNum( val ), upperNum( lowerNum+1 )
	{
	}
       
	int getUpperNum()
	{
		return upperNum;
	}

	int getLowerNum()
	{
		return lowerNum;
	}

private:
	int lowerNum;
	int upperNum;
};

// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
int main()
{
	// test 4 header
	printf("\nTest_4: \n\n");

	// Create a Dog object
	Dog fido( 55 );

	// Print it's contents
	printf("Expecting: upperNum:56  lowerNum:55 \n" );
	printf("Actual:    upperNum:%d  lowerNum:%d \n",fido.getUpperNum(), fido.getLowerNum() );

	return 0;
}
