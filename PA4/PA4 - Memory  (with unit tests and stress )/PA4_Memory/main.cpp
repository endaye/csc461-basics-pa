
#include <Windows.h>
#include "UnitTest.h"
#include "output.h"
#include "mem.h"

// Prototypes
void MemStressTest();

int main()
{
	memSystem mem;
	mem.InitializeSystem();

	// ---- Grading: ------------------------------------------------------

	// TOTAL of 15 unit tests in total, plus 1 stress test
	//        the stress tests counts for 10 more points
	// So you can get a total of 25/25 points

	//----------------------------------------------------------------
	// Leave the following functions allow
	// DO NOT reorder them
	//----------------------------------------------------------------
		UnitTest_platform_init();

		const int numFailures = UnitTest_platform_runTests();
	
		UnitTest_platform_exit();

	//----------------------------------------------------------------
	// Leave the following functions allow
	// DO NOT reorder them
	//----------------------------------------------------------------

		// Stress test
	MemStressTest();
	OutputDebugString("Stress Done");
	// ---------------------------------------------------------------
	// remember to do many prints and stat updates.
	// enjoy and have fun
	// ---------------------------------------------------------------

	return( numFailures );
}

