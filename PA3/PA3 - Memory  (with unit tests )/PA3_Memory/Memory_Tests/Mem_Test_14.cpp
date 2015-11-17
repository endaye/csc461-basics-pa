#include "UnitTest.h"
#include "output.h"
#include "mem.h"
#include "usedHdr.h"
#include "freeHdr.h"

#define PTR_FIX(x)  (x == 0) ? 0: ((unsigned int)x - (unsigned int)h) 



TEST( combo_1 , MemoryShakeOut )
{
	io::create("Student Values", "Test14.txt");

	fprintf(io::getHandle(),"Test14: \n\n");

	fprintf(io::getHandle(),"     memSystem mem;                     \n");
	fprintf(io::getHandle(),"     mem.InitializeSystem();            \n");

   	fprintf(io::getHandle(),"     void *a = mem.Malloc( 0x200 );     \n");
   	fprintf(io::getHandle(),"     void *b = mem.Malloc( 0x200 );     \n");
	fprintf(io::getHandle(),"     void *c = mem.Malloc( 0x300 );     \n");
	fprintf(io::getHandle(),"     void *d = mem.Malloc( 0x300 );     \n");
   	fprintf(io::getHandle(),"     void *e = mem.Malloc( 0x300 );     \n");
	fprintf(io::getHandle(),"     void *f = mem.Malloc( 0x400 );     \n");	
	fprintf(io::getHandle(),"     void *g = mem.Malloc( 0x300 );     \n");
       
	fprintf(io::getHandle(),"     mem.dump();                        \n");
	fprintf(io::getHandle(),"     mem.Free( a );                     \n");
	fprintf(io::getHandle(),"     mem.Free( c );                     \n");
	fprintf(io::getHandle(),"     mem.Free( f );                     \n");
	fprintf(io::getHandle(),"     mem.dump();                        \n");

	fprintf(io::getHandle(),"     void *r = mem.Malloc( 0x380 );     \n");
	fprintf(io::getHandle(),"     mem.dump();                        \n");

	// Part A:
	memSystem mem1;
	mem1.InitializeSystem();

   	void *a1 = mem1.Malloc( 0x200 );
   	void *b1 = mem1.Malloc( 0x200 );
	void *c1 = mem1.Malloc( 0x300 );
	void *d1 = mem1.Malloc( 0x300 );
	void *e1 = mem1.Malloc( 0x300 );
	void *f1 = mem1.Malloc( 0x400 );
	void *g1 = mem1.Malloc( 0x300 );

	mem1.dump();

	// Part B:
	mem1.Free( a1 );
	mem1.Free( c1 );
	mem1.Free( f1 );
	mem1.dump();

	// Part C:
	void *r1 = mem1.Malloc( 0x380 );
	mem1.dump();

	// to shut up warnings
	r1 = 0;
	g1 = 0;
	e1 = 0;
	d1 = 0;
	b1 = 0;

	io::destroy();

	

	// ----  GENERAL CHECK ------------------------------------------------------

	// ---- Part A: -------------------------------------------------------------
	
	memSystem mem;
	mem.InitializeSystem();

   	void *a = mem.Malloc( 0x200 );
   	void *b = mem.Malloc( 0x200 );
	void *c = mem.Malloc( 0x300 );
	void *d = mem.Malloc( 0x300 );
	void *e = mem.Malloc( 0x300 );
	void *f = mem.Malloc( 0x400 );
	void *g = mem.Malloc( 0x300 );


	// ---- Verify A: -----------------------------------------------------------

		heapHdr *h = mem.getHeap();

		CHECK_EQUAL( PTR_FIX(a), 0x50 );
		CHECK_EQUAL( PTR_FIX(b), 0x260 ); 
		CHECK_EQUAL( PTR_FIX(c), 0x470 );
		CHECK_EQUAL( PTR_FIX(d), 0x780 );
		CHECK_EQUAL( PTR_FIX(e), 0xa90 );
		CHECK_EQUAL( PTR_FIX(f), 0xda0 );
		CHECK_EQUAL( PTR_FIX(g), 0x11b0 );

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL( PTR_FIX(h), 0 );

		// Heap Start / Heap Bottom
		CHECK_EQUAL( PTR_FIX(h->stats.heapTopAddr), 0x40 );
		CHECK_EQUAL( PTR_FIX(h->stats.heapBottomAddr), HEAP_SIZE );

		// Used / Free
		CHECK_EQUAL( PTR_FIX(h->freeHead), 0x14b0 );
		CHECK_EQUAL( PTR_FIX(h->usedHead), 0x11a0 );

	// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL( h->stats.peakNumUsed, 7 );
		CHECK_EQUAL( h->stats.peakUsedMemory, 0x1400 );

		CHECK_EQUAL( h->stats.currNumUsedBlocks, 7 );
		CHECK_EQUAL( h->stats.currUsedMem, 0x1400 );
		
		CHECK_EQUAL( h->stats.currNumFreeBlocks, 1 );
		CHECK_EQUAL( h->stats.currFreeMem, 0xb340 );

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

	// ---- USED HDR 1 -------------------------------------------

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
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x250);
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0 );

	
	// ---- BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x250);
		CHECK_EQUAL( used->blockSize, 0x200 );
	
	// ---- HDR 2 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xAA );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x250 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x260);
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x460 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x40 );
		// Hdr Size
		CHECK_EQUAL( hdrEnd - hdrStart, sizeof(usedHdr) );
	
	// ---- used BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x460);
		CHECK_EQUAL( used->blockSize, 0x200 );

	// ---- HDR 3 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xAA );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x460 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x470 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x770 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x250 );
	
	
	// ---- used BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x770);
		CHECK_EQUAL( used->blockSize, 0x300 );

		// ---- HDR 4 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xAA );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x770);
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x780 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0xa80 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x460);
	
	
	// ---- used BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0xa80);
		CHECK_EQUAL( used->blockSize, 0x300 );



		// ---- HDR 5 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xAA );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0xa80);
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0xa90 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0xd90 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x770);
	
	
	// ---- used BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0xd90);
		CHECK_EQUAL( used->blockSize, 0x300 );


		// ---- HDR 6 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xAA );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0xd90);
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0xda0 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x11a0 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0xa80);
	
	
	// ---- used BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x11a0);
		CHECK_EQUAL( used->blockSize, 0x400 );


		// ---- HDR 7 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xAA );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x11a0);
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x11b0 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x0 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0xd90);
	
	
	// ---- used BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x14b0);
		CHECK_EQUAL( used->blockSize, 0x300 );

		// ---- HDR 8 -------------------------------------------

		// Check type
		freeHdr *free= (freeHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)free->blockType, 0xcc );
		
		hdrStart = (memU32)free;
		hdrEnd   = (memU32)free + sizeof(freeHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x14b0);
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x14c0 );
		// Prev
		CHECK_EQUAL( PTR_FIX(free->freePrev), 0x0 );
		// Next
		CHECK_EQUAL( PTR_FIX(free->freeNext), 0x0);
	
	
	// ---- BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + free->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL( free->blockSize, 0xb340 );


	// ---- Part B: -------------------------------------------------------------
	
	mem.Free( a );
	mem.Free( c );
	mem.Free( f );
	
	// ---- Verify B: -----------------------------------------------------------


		h = mem.getHeap();

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL( PTR_FIX(h), 0 );

		// Heap Start / Heap Bottom
		CHECK_EQUAL( PTR_FIX(h->stats.heapTopAddr), 0x40 );
		CHECK_EQUAL( PTR_FIX(h->stats.heapBottomAddr), HEAP_SIZE );

		// Used / Free
		CHECK_EQUAL( PTR_FIX(h->freeHead), 0x40 );
		CHECK_EQUAL( PTR_FIX(h->usedHead), 0x11a0 );

	// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL( h->stats.peakNumUsed, 7 );
		CHECK_EQUAL( h->stats.peakUsedMemory, 0x1400);

		CHECK_EQUAL( h->stats.currNumUsedBlocks, 4);
		CHECK_EQUAL( h->stats.currUsedMem, 0xb00 );
		
		CHECK_EQUAL( h->stats.currNumFreeBlocks, 4 );
		CHECK_EQUAL( h->stats.currFreeMem, 0xbc40 );

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
		free = (freeHdr *) h->stats.heapTopAddr;
		CHECK_EQUAL( (int)free->blockType, 0xcc );
		
		hdrStart = (memU32)free;
		hdrEnd   = (memU32)free + sizeof(freeHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x40  );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x50 );
		// Prev
		CHECK_EQUAL( PTR_FIX(free->freePrev), 0x0 );
		// Next
		CHECK_EQUAL( PTR_FIX(free->freeNext), 0x460 );
		// Hdr Size
		CHECK_EQUAL( hdrEnd - hdrStart, sizeof(freeHdr) );
	
	    // ---- BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + free->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x250 );
		CHECK_EQUAL( free->blockSize, 0x200 );
	
	// ---- HDR 2 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x250 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x260 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x770 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x0 );
		// Hdr Size
		CHECK_EQUAL( hdrEnd - hdrStart, sizeof(usedHdr) );
	
	// ---- BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x460 );
		CHECK_EQUAL( used->blockSize, 0x200 );

	// ---- Hdr 3 -------------------------------------------

		// Check type
		free = (freeHdr *) blkEnd;
		// Should be free
		CHECK_EQUAL( (int)free->blockType, 0xcc );
		
		hdrStart = (memU32)free;
		hdrEnd   = (memU32)free + sizeof(freeHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x460 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x470 );
		// Prev
		CHECK_EQUAL( PTR_FIX(free->freePrev), 0x40 );
		// Next
		CHECK_EQUAL( PTR_FIX(free->freeNext), 0xd90 );
	
		// ---- Block ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + free->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x770);
		CHECK_EQUAL( free->blockSize, 0x300 );
	


	// ---- HDR 4 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x770 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x780 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0xa80 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x250);

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0xa80 );
		CHECK_EQUAL( used->blockSize, 0x300 );
		
	// ---- HDR 5 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0xa80 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0xa90 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x11a0 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x770 );

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0xd90 );
		CHECK_EQUAL( used->blockSize, 0x300 );

	// ---- Hdr 6 -------------------------------------------

		// Check type
		free = (freeHdr *) blkEnd;
		// Should be free
		CHECK_EQUAL( (int)free->blockType, 0xcc );
		
		hdrStart = (memU32)free;
		hdrEnd   = (memU32)free + sizeof(freeHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0xd90 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0xda0 );
		// Prev
		CHECK_EQUAL( PTR_FIX(free->freePrev), 0x460);
		// Next
		CHECK_EQUAL( PTR_FIX(free->freeNext), 0x14b0 );

		blkStart = hdrEnd;
		blkEnd   = blkStart + free->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x11a0);
		CHECK_EQUAL( free->blockSize, 0x400 );
	

	// ---- HDR 7 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x11a0 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x11b0 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0xa80 );

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x14b0 );
		CHECK_EQUAL( used->blockSize, 0x300 );

	// ---- Hdr 8 -------------------------------------------

		// Check type
		free = (freeHdr *) blkEnd;
		// Should be free
		CHECK_EQUAL( (int)free->blockType, 0xcc );
		
		hdrStart = (memU32)free;
		hdrEnd   = (memU32)free + sizeof(freeHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x14b0 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x14c0 );
		// Prev
		CHECK_EQUAL( PTR_FIX(free->freePrev), 0xd90);
		// Next
		CHECK_EQUAL( PTR_FIX(free->freeNext), 0x0 );

		blkStart = hdrEnd;
		blkEnd   = blkStart + free->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL( free->blockSize, 0xb340 );

	
	// ---- Part C: -------------------------------------------------------------
	
	void *r = mem.Malloc( 0x380 );
	
	// ---- Verify C: -----------------------------------------------------------


		h = mem.getHeap();

		CHECK_EQUAL( PTR_FIX(r), 0xda0 );

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL( PTR_FIX(h), 0 );

		// Heap Start / Heap Bottom
		CHECK_EQUAL( PTR_FIX(h->stats.heapTopAddr), 0x40 );
		CHECK_EQUAL( PTR_FIX(h->stats.heapBottomAddr), HEAP_SIZE );

		// Used / Free
		CHECK_EQUAL( PTR_FIX(h->freeHead), 0x40 );
		CHECK_EQUAL( PTR_FIX(h->usedHead), 0xd90 );

	// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL( h->stats.peakNumUsed, 7 );
		CHECK_EQUAL( h->stats.peakUsedMemory, 0x1400);

		CHECK_EQUAL( h->stats.currNumUsedBlocks, 5);
		CHECK_EQUAL( h->stats.currUsedMem, 0xe80 );
		
		CHECK_EQUAL( h->stats.currNumFreeBlocks, 4 );
		CHECK_EQUAL( h->stats.currFreeMem, 0xb8b0 );

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
		free = (freeHdr *) h->stats.heapTopAddr;
		CHECK_EQUAL( (int)free->blockType, 0xcc );
		
		hdrStart = (memU32)free;
		hdrEnd   = (memU32)free + sizeof(freeHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x40  );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x50 );
		// Prev
		CHECK_EQUAL( PTR_FIX(free->freePrev), 0x0 );
		// Next
		CHECK_EQUAL( PTR_FIX(free->freeNext), 0x460 );
		// Hdr Size
		CHECK_EQUAL( hdrEnd - hdrStart, sizeof(freeHdr) );
	
	    // ---- BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + free->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x250 );
		CHECK_EQUAL( free->blockSize, 0x200 );
	
	// ---- HDR 2 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x250 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x260 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x770 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x0 );
		// Hdr Size
		CHECK_EQUAL( hdrEnd - hdrStart, sizeof(usedHdr) );
	
	// ---- BLOCK ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x460 );
		CHECK_EQUAL( used->blockSize, 0x200 );

	// ---- Hdr 3 -------------------------------------------

		// Check type
		free = (freeHdr *) blkEnd;
		// Should be free
		CHECK_EQUAL( (int)free->blockType, 0xcc );
		
		hdrStart = (memU32)free;
		hdrEnd   = (memU32)free + sizeof(freeHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x460 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x470 );
		// Prev
		CHECK_EQUAL( PTR_FIX(free->freePrev), 0x40 );
		// Next
		CHECK_EQUAL( PTR_FIX(free->freeNext), 0x1120);
	
		// ---- Block ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd   = blkStart + free->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x770);
		CHECK_EQUAL( free->blockSize, 0x300 );
	


	// ---- HDR 4 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x770 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x780 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0xa80 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x250);

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0xa80 );
		CHECK_EQUAL( used->blockSize, 0x300 );
		
	// ---- HDR 5 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0xa80 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0xa90 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x11a0 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x770 );

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0xd90 );
		CHECK_EQUAL( used->blockSize, 0x300 );

	// ---- Hdr 6 -------------------------------------------

		
		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0xd90 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0xda0 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0x0 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0x11a0 );

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x1120 );
		CHECK_EQUAL( used->blockSize, 0x380 );

		// ---- Hdr 6.1 -------------------------------------------
		
		// Check type
		free = (freeHdr *) blkEnd;
		// Should be free
		CHECK_EQUAL( (int)free->blockType, 0xcc );
		
		hdrStart = (memU32)free;
		hdrEnd   = (memU32)free + sizeof(freeHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x1120 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x1130 );
		// Prev
		CHECK_EQUAL( PTR_FIX(free->freePrev), 0x460);
		// Next
		CHECK_EQUAL( PTR_FIX(free->freeNext), 0x14b0 );

		blkStart = hdrEnd;
		blkEnd   = blkStart + free->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x11a0);
		CHECK_EQUAL( free->blockSize, 0x70);
	

	// ---- HDR 7 -------------------------------------------

		// Check type
		used = (usedHdr *) blkEnd;
		// Should be USED
		CHECK_EQUAL( (int)used->blockType, 0xaa );
		
		hdrStart = (memU32)used;
		hdrEnd   = (memU32)used + sizeof(usedHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x11a0 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x11b0 );
		// Prev
		CHECK_EQUAL( PTR_FIX(used->usedPrev), 0xd90 );
		// Next
		CHECK_EQUAL( PTR_FIX(used->usedNext), 0xa80 );

		blkStart = hdrEnd;
		blkEnd   = blkStart + used->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0x14b0 );
		CHECK_EQUAL( used->blockSize, 0x300 );

	// ---- Hdr 8 -------------------------------------------

		// Check type
		free = (freeHdr *) blkEnd;
		// Should be free
		CHECK_EQUAL( (int)free->blockType, 0xcc );
		
		hdrStart = (memU32)free;
		hdrEnd   = (memU32)free + sizeof(freeHdr);
	
		// Hdr Start
		CHECK_EQUAL( PTR_FIX(hdrStart), 0x14b0 );
		// Hdr End
		CHECK_EQUAL( PTR_FIX(hdrEnd), 0x14c0 );
		// Prev
		CHECK_EQUAL( PTR_FIX(free->freePrev), 0x1120);
		// Next
		CHECK_EQUAL( PTR_FIX(free->freeNext), 0x0 );

		blkStart = hdrEnd;
		blkEnd   = blkStart + free->blockSize; 
		
		CHECK_EQUAL( PTR_FIX(blkStart), PTR_FIX(hdrEnd) );
		CHECK_EQUAL( PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL( free->blockSize, 0xb340 );

}