#include "UnitTest.h"
#include "output.h"
#include "mem.h"
#include "usedHdr.h"
#include "freeHdr.h"

#define PTR_FIX(x)  (x == 0) ? 0: ((unsigned int)x - (unsigned int)h) 



TEST( Allocate_Everything , MemoryShakeOut )
{
	io::create("Student Values", "Test2.txt");
	
	fprintf(io::getHandle(),"Test2: \n\n");

	fprintf(io::getHandle(),"1) allocate the biggest block               \n");

	fprintf(io::getHandle(),"     memSystem mem;                         \n");
	fprintf(io::getHandle(),"     mem.InitializeSystem();                \n");
   	fprintf(io::getHandle(),"     void *p = mem.Malloc( 0xc7b0 );        \n");
	fprintf(io::getHandle(),"     mem.dump();                            \n");

	memSystem mem;                         
	mem.InitializeSystem();                
   	void *p = mem.Malloc( 0xc7b0 );        
	mem.dump();   

	p;  // to shut up warnings

	io::destroy();


	// ----  GENERAL CHECK ------------------------------------------------------
		
		heapHdr *h = mem.getHeap();

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL( PTR_FIX(h), 0 );

		// Heap Start / Heap Bottom
		CHECK_EQUAL( PTR_FIX(h->stats.heapTopAddr), 0x40 );
		CHECK_EQUAL( PTR_FIX(h->stats.heapBottomAddr), HEAP_SIZE );

		// Used / Free
		CHECK_EQUAL( PTR_FIX(h->freeHead), 0 );
		CHECK_EQUAL( PTR_FIX(h->usedHead), 0x40);

	// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL( h->stats.peakNumUsed, 1 );
		CHECK_EQUAL( h->stats.peakUsedMemory, 0xc7b0 );

		CHECK_EQUAL( h->stats.currNumUsedBlocks, 1 );
		CHECK_EQUAL( h->stats.currUsedMem, 0xc7b0 );
		
		CHECK_EQUAL( h->stats.currNumFreeBlocks, 0 );
		CHECK_EQUAL( h->stats.currFreeMem, 0x0 );

		CHECK_EQUAL( h->stats.sizeHeap, 0xc800 );
		CHECK_EQUAL( h->stats.sizeHeapHeader, 0x40 );

		CHECK_EQUAL( PTR_FIX( h->stats.heapTopAddr), 0x40 );
		CHECK_EQUAL( PTR_FIX(h->stats.heapBottomAddr), 0xc800 );


	// ---- Heap Walk ------------------------------------------------------

	// ---- Heap Hdr -------------------------------------------------------

		// HeapHdr Start
		CHECK_EQUAL( PTR_FIX( (memU32)h->stats.heapTopAddr-sizeof(heapHdr) ), 0 );
		// HeapHdr End
		CHECK_EQUAL( PTR_FIX(h->stats.heapTopAddr), h->stats.sizeHeapHeader );
		// HeapHdr Size
		CHECK_EQUAL( h->stats.sizeHeapHeader, sizeof(heapHdr) );

	// ----  Block walk ------------------------------------------------------
		
		memU32 hdrStart;
		memU32 hdrEnd;
		memU32 blkStart;
		memU32 blkEnd; 

	// ---- HDR -------------------------------------------

		// Check type
		usedHdr *used = (usedHdr *) h->stats.heapTopAddr;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xAA );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x40  );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x50 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0 );
		// Hdr Size
		CHECK_EQUAL( hdrEnd - hdrStart, sizeof(usedHdr) );
	
	// ---- BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL( used->blockSize, 0xc7b0 );

}




