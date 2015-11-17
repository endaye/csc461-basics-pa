#include <stdio.h>
#include "UnitTest.h"

int main()
{
	// Everything needs to be warning free - not one

	// Suggest order of operation:
	// 1) Write the SecondMax function
	// 2) Fill out parse project's main function.

	UnitTest_platform_init();

	const int numFailures = UnitTest_platform_runTests();

	UnitTest_platform_exit();
	return(numFailures);
}