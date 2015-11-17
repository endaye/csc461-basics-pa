
//-----------------------------------------------
// programming assignment 1:
// problem 3
// Optimized C++
//-----------------------------------------------
// Edited by Yuancheng Zhang 10/4/2015
//-----------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bloated.h"
#include "Node.h"
#include "output.h"
#include "Timer.h"
#include "hotcold.h"


int main()
{
	// Create the IO for this program, that's WHERE YOU PUT YOUR NAME, please change it.
	io::create("Yuancheng Zhang");

	// Initialize timer
	timer::initTimer();

	// Create a timer objects
	timer t1,t2,t3,t4,t5;

	// start timer
	t1.tic();

	// Do not modify this function, you need to leave this routine alone.
	// It initializes the data if a very bloated way do not modify it!
	Bloated::CreateLinkedList();

	// stop timer
	t1.toc();

	// log the time for the bloat creation
	fprintf(io::getHandle(),"Creation of Bloated List: %f s\n", t1.timeInSeconds() );
	
	// start timer
	t2.tic();

	//
	bool foundFlag;
	OriginalNode foundNode;
	foundFlag = Bloated::findKey(0x30431daa, foundNode);

	// stop timer
	t2.toc();

	float findingKeyOld = t2.timeInSeconds()*1000.0f;

	// log the time conversion and proof
	fprintf(io::getHandle(),"\n");
	fprintf(io::getHandle(),"Original linked list---------------------------\n");
	fprintf(io::getHandle(),"   Finding Key: %f ms\n", t2.timeInSeconds()*1000.0f );
	fprintf(io::getHandle()," (Proof)   key: 0x%X\n", foundNode.key );
	fprintf(io::getHandle(),"       name[0]: %x\n", 0xff & foundNode.name[0]);
	fprintf(io::getHandle(),"      name[55]: %x\n", 0xff & foundNode.name[55]);
	fprintf(io::getHandle(),"     name[111]: %x\n", 0xff & foundNode.name[111]);
	fprintf(io::getHandle(),"     name[113]: %x\n", 0xff & foundNode.name[113]);
	fprintf(io::getHandle(),"             z: %f\n", foundNode.z);
	fprintf(io::getHandle(),"        MB[13]: %f\n", foundNode.MB.m13);
	fprintf(io::getHandle(),"           A.y: %f\n", foundNode.A.y);

	// start timer
	t3.tic();

	// -----------------------------------------------------------------------
	// --->>>>  Add your magic here
	//          Convert the bloated list to hot/cold
	// -----------------------------------------------------------------------
	// FOR EXAMPLE 	
	//              hotcold::convert();
	// -----------------------------------------------------------------------
	HotCold::convert(Bloated::getListHead());

	//printf("Convert finish!\n");
    fprintf(io::getHandle()," \n");

	// stop timer
	t3.toc();

	// log the time conversion
	fprintf(io::getHandle(),"\n");
	fprintf(io::getHandle(),"Conversion to Hot/Cold: %f ms\n", t3.timeInSeconds() * 1000.0f);

	// start timer
	t4.tic();

	// -----------------------------------------------------------------------
	// --->>>>  Add your magic here, 
	//          Find key: 0x30431daa, add code here:
	// -----------------------------------------------------------------------
    // FOR EXAMPLE: 
	//              ColdNode coldTmp;
    //           	hotcold::findKey(0x30431daa,coldTmp);
	// -----------------------------------------------------------------------
	ColdNode coldTmp;
	bool foundFlag2;
	foundFlag2 = HotCold::findKey(0x30431daa, coldTmp);

	//printf("Key found!\n");
	fprintf(io::getHandle()," \n");
	// stop timer
	t4.toc();

	// log the time conversion and proof
	float findingKeyNew = t4.timeInSeconds()*1000.0f;

	fprintf(io::getHandle(),"\n");
	fprintf(io::getHandle(),"Hot/Cold linked list---------------------------\n");
	fprintf(io::getHandle(),"   Finding Key: %f ms\n", t4.timeInSeconds()*1000.0f );
	// UNCOMMENT THIS CODE:  YES YOU!
	fprintf(io::getHandle()," (Proof)   key: 0x%X\n",coldTmp.key  );
	fprintf(io::getHandle(),"       name[0]: %x\n",0xff & coldTmp.name[0] );
	fprintf(io::getHandle(),"      name[55]: %x\n",0xff & coldTmp.name[55] );
	fprintf(io::getHandle(),"     name[111]: %x\n",0xff & coldTmp.name[111]);
	fprintf(io::getHandle(),"     name[113]: %x\n",0xff & coldTmp.name[113] );
 	fprintf(io::getHandle(),"             z: %f\n",coldTmp.z);
	fprintf(io::getHandle(),"        MB[13]: %f\n",coldTmp.MB.m13 );
	fprintf(io::getHandle(),"           A.y: %f\n",coldTmp.A.y );
	// start timer
	t5.tic();

	// --------------------------------------------------------------------------------------
	// --->>>>  Add your magic here, 
	//          Verify all data nodes between Original and New Hot/Cold
	// ---------------------------------------------------------------------------------------
    // FOR EXAMPLE	
	//              hotcold::verify();
	// ---------------------------------------------------------------------------------------
	HotCold::verify();

	// stop timer
	t5.toc();

	// log the time conversion
	fprintf(io::getHandle(),"\n");
	fprintf(io::getHandle(),"Verify Nodes: Original and New Hot/Cold : %f ms\n", t5.timeInSeconds()*1000.0f );

	fprintf(io::getHandle(),"\n");
	fprintf(io::getHandle(),"------ Summary ------------------------------------- \n\n");
    fprintf(io::getHandle(),"                 orig: %f ms \n", findingKeyOld );
	fprintf(io::getHandle(),"                  new: %f ms \n", findingKeyNew );
	fprintf(io::getHandle(),"                ratio: %f \n", findingKeyOld/findingKeyNew );


	return 0;
}

