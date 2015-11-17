#ifndef HEAPHDR_H
#define HEAPHDR_H

#include"memTypes.h"

// forward declares
struct usedHdr;
struct freeHdr;

struct memStats
{
	memUInt peakNumUsed;		// number of peak used allocations
	memUInt peakUsedMemory;		// peak size of used memory

	memUInt currNumUsedBlocks;	// number of current used allocations
	memUInt currUsedMem;		// current size of the total used memory

	memUInt	currNumFreeBlocks;	// number of current free blocks
	memUInt currFreeMem;		// current size of the total free memory

	memUInt sizeHeap;			// size of Heap total space, including header
	memUInt sizeHeapHeader;		// size of heap header

	memVoid *heapTopAddr;		// start address available heap
	memVoid *heapBottomAddr;    // bottom of address of heap
};


struct heapHdr
{
	// Make sure that the heapHdr is 16 byte aligned.

	// allocation links
	usedHdr		*usedHead;
	freeHdr		*freeHead;

	memBool		heapInitialize;
	memU8		bytePad1;
	memU8		bytePad2;
	memU8		bytePad3;

	memU32		pad1;
	memU32		pad2;
	memU32		pad3;

	// recording stats
	memStats	stats;		

	// specialize constructor
	heapHdr(void * ptr);
};

#endif //heapHdr.h