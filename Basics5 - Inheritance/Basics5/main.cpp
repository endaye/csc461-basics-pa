#include "UnitTest.h"


int main()
{
	// Fill in these functions (follow the instructions provided):
	//  a)  Wrapper.h
	//  b)  A.h
	//  c)  C.h
	//  d)  E.h
	//  e)  M.h

	// perfect score  5/5 unit tests



	// Leave the following functions allow
	// DO NOT reorder them
	UnitTest_platform_init();

	const int numFailures = UnitTest_platform_runTests();
	
	UnitTest_platform_exit();
	return( numFailures );


}