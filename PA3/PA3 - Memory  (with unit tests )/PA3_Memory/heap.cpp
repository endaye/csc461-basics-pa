#include "heapHdr.h"
#include "mem.h"


heapHdr::heapHdr(void * ptr)
:	usedHead(0),
	freeHead(0),
	heapInitialize(true),
	bytePad1(0),
	bytePad2(0),
	bytePad3(0),
	pad1(0),
	pad2(0),
	pad3(0)
{
	stats.peakNumUsed = 0;			// number of peak used allocations
	stats.peakUsedMemory  = 0;		// peak size of used memory

	stats.currNumUsedBlocks =0;		// number of current used allocations
	stats.currUsedMem =0;			// current size of the total used memory

	stats.currNumFreeBlocks =0;		// number of current free blocks
	stats.currFreeMem =0 ;			// current size of the total free memory

	stats.sizeHeap = 0;				// size of Heap total space, including header
	stats.sizeHeapHeader =0;		// size of heap header

	stats.heapTopAddr = reinterpret_cast<memVoid *> ( (memU8 *)ptr + sizeof(heapHdr) );		// start address available heap
	stats.heapBottomAddr = reinterpret_cast<memVoid *> ( (memU8 *)ptr + HEAP_SIZE );		// last address available heap
	
}