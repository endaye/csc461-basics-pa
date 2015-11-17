#include <stdio.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

// ----------------------------------------------------------------------
// Problem 10:
//
// Rules: Fix the code to correctly print the predicted output
// ----------------------------------------------------------------------

class Dog
{
public:
	int *pVal;

	Dog( int val)
	{ 
		pVal = new int;
		*pVal = val;
	}

	~Dog() 
	{ 
		//delete pVal; 
	}
};


// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
void printME( Dog dog )
{  
	printf( " %lu\n", *dog.pVal );  
}


// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
int main() 
{
	// test 10 header
	printf("\nTest_10: \n\n");

	printf("Expect: \n 20 \n 20 \n 21\n");
	printf("Actual:\n");

    Dog fido(20); 
	printME( fido );
	
    Dog rex(21); 
	printME( fido );  
	printME( rex );
    
	return 0;
}