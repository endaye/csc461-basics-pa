#include "freeHdr.h"

freeHdr::freeHdr(memU32 sizeBlock)
{
	freeNext = 0;		// next free block
	freePrev = 0;		// prev free block
	blockSize = sizeBlock;		// size of block
	blockType =  0xCC;		// block type is used -> 0xAA  if block type is free -> 0xCC
	pad0 = 0;			// future use
	pad1 = 0;			// future use
	pad2 = 0;			// future use
}

freeHdr::freeHdr(freeHdr * pFree)
{
	freeNext = pFree->freeNext;		// next free block
	freePrev = pFree->freePrev;			// prev free block
	blockSize = pFree->blockSize;		// size of block
	blockType = 0xCC;		// block type is used -> 0xAA  if block type is free -> 0xCC
	pad0 = 0;			// future use
	pad1 = 0;			// future use
	pad2 = 0;			// future use
}