#ifndef MEM_H
#define MEM_H

// forward declare
struct headHdr;

#include "heapHdr.h"

#define HEAP_SIZE ( (50 * 1024) )  //50K


class memSystem
{
public:
	memSystem();	
	~memSystem();
	heapHdr *getHeap();
	memVoid dump();

	// implement these functions
	memVoid Free( memVoid * const data );
	memVoid *Malloc(const memU32 size );
	memVoid InitializeSystem( );
	freeHdr * glue(freeHdr *& pFree1, freeHdr *& pFree2);


private:
	heapHdr	*heap;
	char	*rawMem;

};

#endif // mem.h