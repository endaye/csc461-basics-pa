#include "UnitTest.h"
#include "output.h"
#include "mem.h"
#include "usedHdr.h"
#include "freeHdr.h"

#define PTR_FIX(x)  (x == 0) ? 0: ((unsigned int)x - (unsigned int)h) 



TEST( combo_2 , MemoryShakeOut )
{
	io::create("Student Values", "Test15.txt");

	fprintf(io::getHandle(),"Test15: \n\n");

	fprintf(io::getHandle(),"     memSystem mem;                     \n");
	fprintf(io::getHandle(),"     mem.InitializeSystem();            \n");

   	fprintf(io::getHandle(),"     void *a = mem.Malloc( 0x100 );     \n");
   	fprintf(io::getHandle(),"     void *b = mem.Malloc( 0x200 );     \n");
	fprintf(io::getHandle(),"     void *c = mem.Malloc( 0x10 );     \n");
	fprintf(io::getHandle(),"     void *d = mem.Malloc( 0x200 );     \n");

       
	fprintf(io::getHandle(),"     mem.dump();                        \n");
	fprintf(io::getHandle(),"     mem.Free( d );                     \n");
	fprintf(io::getHandle(),"     mem.Free( b );                     \n");

	fprintf(io::getHandle(),"     mem.dump();                        \n");

	fprintf(io::getHandle(),"     void *r = mem.Malloc( 0x200 );     \n");
	fprintf(io::getHandle(),"     mem.dump();                        \n");

	// Part A:
	memSystem mem1;
	mem1.InitializeSystem();

   	void *a1 = mem1.Malloc( 0x100 );
   	void *b1 = mem1.Malloc( 0x200 );
	void *c1 = mem1.Malloc( 0x10 );
	void *d1 = mem1.Malloc( 0x200 );

	mem1.dump();

	// Part B:
	mem1.Free( d1 );
	mem1.Free( b1 );

	mem1.dump();

	// Part C:
	void *r1 = mem1.Malloc( 0x200 );
	mem1.dump();

	// to shut up warnings
	r1 = 0;
	a1 = 0;
	c1 = 0;


	io::destroy();

	

	// ----  GENERAL CHECK ------------------------------------------------------

	// ---- Part A: -------------------------------------------------------------
	
	memSystem mem;
	mem.InitializeSystem();


   	void *a = mem.Malloc( 0x100 );
   	void *b = mem.Malloc( 0x200 );
	void *c = mem.Malloc( 0x10 );
	void *d = mem.Malloc( 0x200 );

	
	// ---- Verify A: -----------------------------------------------------------


		heapHdr *h = mem.getHeap();

		CHECK_EQUAL( PTR_FIX(a), 0x50 );
		CHECK_EQUAL( PTR_FIX(b), 0x160 ); 
		CHECK_EQUAL( PTR_FIX(c), 0x370 );
		CHECK_EQUAL( PTR_FIX(d), 0x390 );

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL( PTR_FIX(h), 0 );

		// Heap Start / Heap Bottom
		CHECK_EQUAL( PTR_FIX(h->stats.heapTopAddr), 0x40 );
		CHECK_EQUAL( PTR_FIX(h->stats.heapBottomAddr), HEAP_SIZE );

		// Used / Free
		CHECK_EQUAL( PTR_FIX(h->freeHead), 0x590 );
		CHECK_EQUAL( PTR_FIX(h->usedHead), 0x380 );

	// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL( h->stats.peakNumUsed, 4 );
		CHECK_EQUAL( h->stats.peakUsedMemory, 0x510);

		CHECK_EQUAL( h->stats.currNumUsedBlocks, 4);
		CHECK_EQUAL( h->stats.currUsedMem, 0x510 );
		
		CHECK_EQUAL( h->stats.currNumFreeBlocks, 1 );
		CHECK_EQUAL( h->stats.currFreeMem, 0xc260 );

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
	
	// ---- HDR 1 -------------------------------------------

		// Check type
		usedHdr *used = (usedHdr *) h->stats.heapTopAddr;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xAA );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x40 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x50 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x150 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x0 );
		// Hdr Size
		CHECK_EQUAL( hdrEnd - hdrStart, sizeof(usedHdr) );
	
		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x150 );
		CHECK_EQUAL( used->blockSize, 0x100 );

	
	// ---- HDR 2 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x150 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x160 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x360 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x40);

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x360 );
		CHECK_EQUAL( used->blockSize, 0x200 );
		
	// ---- HDR 3 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x360 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x370 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x380 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x150);

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x380 );
		CHECK_EQUAL( used->blockSize, 0x10 );

	// ---- HDR 4 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x380 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x390 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x0 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x360);

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x590 );
		CHECK_EQUAL( used->blockSize, 0x200 );
		
	// ---- Hdr 5 -------------------------------------------

		// Check type
		freeHdr *free = (freeHdr *) blkEnd;
		// Should be free
		CHECK_EQUAL( (int)free->blockType, 0xcc );
		
		hdrStart = (memU32)free;
		hdrEnd   = (memU32)free + sizeof(freeHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x590 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x5a0 );
		// Prev
		CHECK_EQUAL( PTR_FIX(free->freePrev), 0x0 );
		// Next
		CHECK_EQUAL( PTR_FIX(free->freeNext), 0x0);
	
		// ---- Block ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + free->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL( free->blockSize, 0xc260 );
	
	// ---- Part B: -------------------------------------------------------------
	
	mem.Free( d );
	mem.Free( b );
	
	// ---- Verify B: -----------------------------------------------------------


		h = mem.getHeap();

		CHECK_EQUAL( PTR_FIX(a), 0x50 );
		CHECK_EQUAL( PTR_FIX(b), 0x160 ); 
		CHECK_EQUAL( PTR_FIX(c), 0x370 );
		CHECK_EQUAL( PTR_FIX(d), 0x390 );

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL( PTR_FIX(h), 0 );

		// Heap Start / Heap Bottom
		CHECK_EQUAL( PTR_FIX(h->stats.heapTopAddr), 0x40 );
		CHECK_EQUAL( PTR_FIX(h->stats.heapBottomAddr), HEAP_SIZE );

		// Used / Free
		CHECK_EQUAL( PTR_FIX(h->freeHead), 0x150 );
		CHECK_EQUAL( PTR_FIX(h->usedHead), 0x360 );

	// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL( h->stats.peakNumUsed, 4 );
		CHECK_EQUAL( h->stats.peakUsedMemory, 0x510);

		CHECK_EQUAL( h->stats.currNumUsedBlocks, 2);
		CHECK_EQUAL( h->stats.currUsedMem, 0x110 );
		
		CHECK_EQUAL( h->stats.currNumFreeBlocks, 2 );
		CHECK_EQUAL( h->stats.currFreeMem, 0xc670 );

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
	
	
	// ---- HDR 1 -------------------------------------------

		// Check type
		used = (usedHdr *) h->stats.heapTopAddr;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xAA );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x40 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x50 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x360 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x0 );
		// Hdr Size
		CHECK_EQUAL( hdrEnd - hdrStart, sizeof(usedHdr) );
	
		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x150 );
		CHECK_EQUAL( used->blockSize, 0x100 );

	
	// ---- HDR 2 -------------------------------------------

		// Check type
		free = (freeHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)free->blockType, 0xcc );
		
		hdrStart = (memU32)free;
		hdrEnd   = (memU32)free + sizeof(freeHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x150 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x160 );
		// Prev
		CHECK_EQUAL( PTR_FIX(free->freePrev), 0x0 );
		// Next
		CHECK_EQUAL( PTR_FIX(free->freeNext), 0x380);

		blkStart = hdrEnd;
		blkEnd   = blkStart + free->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x360 );
		CHECK_EQUAL( free->blockSize, 0x200 );
		
	// ---- HDR 3 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x360 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x370 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x0 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x40);

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x380 );
		CHECK_EQUAL( used->blockSize, 0x10 );

	// ---- HDR 4 -------------------------------------------

		// Check type
		free = (freeHdr *) blkEnd;
		// Should be free
		CHECK_EQUAL( (int)free->blockType, 0xcc );
		
		hdrStart = (memU32)free;
		hdrEnd   = (memU32)free + sizeof(freeHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x380 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x390 );
		// Prev
		CHECK_EQUAL( PTR_FIX(free->freePrev), 0x150 );
		// Next
		CHECK_EQUAL( PTR_FIX(free->freeNext), 0x0);

		blkStart = hdrEnd;
		blkEnd   = blkStart + free->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0xc800 );
		CHECK_EQUAL( free->blockSize, 0xc470 );
	
	

	// ---- Part C: -------------------------------------------------------------
	
	void *r = mem.Malloc( 0x200 );
	
	// ---- Verify C: -----------------------------------------------------------


		h = mem.getHeap();

		CHECK_EQUAL( PTR_FIX(r), 0x160 );


		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL( PTR_FIX(h), 0 );

		// Heap Start / Heap Bottom
		CHECK_EQUAL( PTR_FIX(h->stats.heapTopAddr), 0x40 );
		CHECK_EQUAL( PTR_FIX(h->stats.heapBottomAddr), HEAP_SIZE );

		// Used / Free
		CHECK_EQUAL( PTR_FIX(h->freeHead), 0x380 );
		CHECK_EQUAL( PTR_FIX(h->usedHead), 0x150 );

	// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL( h->stats.peakNumUsed, 4 );
		CHECK_EQUAL( h->stats.peakUsedMemory, 0x510);

		CHECK_EQUAL( h->stats.currNumUsedBlocks, 3);
		CHECK_EQUAL( h->stats.currUsedMem, 0x310 );
		
		CHECK_EQUAL( h->stats.currNumFreeBlocks, 1 );
		CHECK_EQUAL( h->stats.currFreeMem, 0xc470 );

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
	
	
	// ---- HDR 1 -------------------------------------------

		// Check type
		used = (usedHdr *) h->stats.heapTopAddr;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xAA );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x40 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x50 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x360 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x0 );
		// Hdr Size
		CHECK_EQUAL( hdrEnd - hdrStart, sizeof(usedHdr) );
	
		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x150 );
		CHECK_EQUAL( used->blockSize, 0x100 );

	
	// ---- HDR 2 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x150 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x160 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x0 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x360);

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x360 );
		CHECK_EQUAL( used->blockSize, 0x200 );
		
	// ---- HDR 3 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x360 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x370 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x150 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x40);

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x380 );
		CHECK_EQUAL( used->blockSize, 0x10 );

	// ---- HDR 4 -------------------------------------------

		// Check type
		free = (freeHdr *) blkEnd;
		// Should be free
		CHECK_EQUAL( (int)free->blockType, 0xcc );
		
		hdrStart = (memU32)free;
		hdrEnd   = (memU32)free + sizeof(freeHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x380 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x390 );
		// Prev
		CHECK_EQUAL( PTR_FIX(free->freePrev), 0x0 );
		// Next
		CHECK_EQUAL( PTR_FIX(free->freeNext), 0x0);

		blkStart = hdrEnd;
		blkEnd   = blkStart + free->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0xc800 );
		CHECK_EQUAL( free->blockSize, 0xc470 );
	

}