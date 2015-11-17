#include "output.h"
#include "bloated.h"
#include "Node.h"
#include "Timer.h"


void BloatedStressTest()
{
// Create a timer objects
	timer t1,t2;

		// log the time for the bloat creation
	fprintf(io::getHandle(),"\n --------- Bloated Nodes ---------------\n\n" );


		// start timer
	t1.tic();

	// Do not modify this function, you need to leave this routine alone.
	// It initializes the data if a very bloated way do not modify it!
	Bloated::CreateLinkedList();

	// stop timer
	t1.toc();

	// log the time for the bloat creation
	fprintf(io::getHandle(),"Creation of List: %f s\n", t1.timeInSeconds() );
	
	// start timer
	t2.tic();

	//
	bool foundFlag;
	OriginalNode foundNode;
	foundFlag = Bloated::findKey(0x30431daa, foundNode);

	// stop timer
	t2.toc();

	// log the time for the bloat creation
	fprintf(io::getHandle(),"        Find Key: %f ms\n\n", t2.timeInSeconds() * 1000 );
	
}


