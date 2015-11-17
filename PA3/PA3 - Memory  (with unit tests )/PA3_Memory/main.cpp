#include "UnitTest.h"
#include "output.h"
#include "mem.h"

// Prototypes
void MemStressTest();

int main()
{

	// I created the memory system data structure and initial memory for the heap.
	// From this point forward, you implement:
	// 
	//     memSystem::InitializeSystem()
	//     memSystem::Malloc()
	//     memSystem::Free()
	//
	//     Use memSystem::getHeap() to get the heap pointer
	//     I created sample usedHdr and freeHdr use the headers I provided
	//
	//  I created a memSystem::dump() which prints the heap internals, 
	//   --> please use this frequently to check your system
	//
	// Create the space and memSystem structure
	//				since most people complained about singletons, 
	//				I didn't use them (I think it's screams for that pattern, btw)

	// initialize the memory system
	memSystem mem;
	mem.InitializeSystem();

	// do your first malloc()
	//void *p = mem.Malloc( 200 );

	// do your first free()
	// mem.Free( p );


	// remember to do many prints and stat updates.
	// enjoy and have fun, sample test patterns that will stress your memory system
	// Start try them one by one
	//
	// This is hard, no joke!
	//
	// - Ed Keenan


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
	// MemStressTest();

	// ---------------------------------------------------------------
	// remember to do many prints and stat updates.
	// enjoy and have fun
	// ---------------------------------------------------------------

	return( numFailures );
}

