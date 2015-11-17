#include <stdio.h>
#include "output.h"

void MemStressTest();
void BloatedStressTest();
void MathStressTest();


int main()
{
	// RULES

	// ONLY modifiy MR_FAST build settings / configuration
	// DO not modify any code
	// Run all three builds (debug,release,MR_FAST) and compare

	// MR_FAST was created as a copy of Release, it's there to modify

	// Create a text file with the modifications of settings you used.
	//  MR_FAST_SETTINGS.txt  (only the ones you changed - different than release)

	io::create("Yuancheng Zhang");

	//  the tests
	MemStressTest();
	BloatedStressTest();
	MathStressTest();

	io::destroy();

	return 0;
}