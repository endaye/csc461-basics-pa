#include "UnitTest.h"


int main()
{
	// Fill in these functions (follow the instructions provided):
	//  a)  CopyingStrings.cpp
	//  b)  ComparingStrings.cpp
	//  c)  LengthOfStrings.cpp
	//  d)  CopyToBuffer.cpp
	//  e)  SortStrings.cpp

	// perfect score  6/6 unit tests



	// Leave the following functions allow
	// DO NOT reorder them
	UnitTest_platform_init();

	const int numFailures = UnitTest_platform_runTests();
	
	UnitTest_platform_exit();
	return( numFailures );
}