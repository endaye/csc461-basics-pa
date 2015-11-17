#include "UnitTest.h"

void Students_PointerWalk();
void Students_Casting();

int main()
{

	// fill in these functions:
	Students_PointerWalk();
	Students_Casting();

	// Leave the following functions allow
	// DO NOT reorder them
	UnitTest_platform_init();

	const int numFailures = UnitTest_platform_runTests();
	
	UnitTest_platform_exit();
	return( numFailures );
}