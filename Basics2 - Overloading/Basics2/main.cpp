#include "UnitTest.h"

int main()
{
	UnitTest_platform_init();

	const int numFailures = UnitTest_platform_runTests();
	
	UnitTest_platform_exit();
	return( numFailures );
}