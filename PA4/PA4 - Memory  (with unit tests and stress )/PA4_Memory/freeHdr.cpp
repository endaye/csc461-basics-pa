#include "freeHdr.h"

freeHdr::freeHdr(memU32 sizeBlock)
{
	freeNext = 0;		// next free block
	freePrev = 0;		// prev free block
	blockSize = sizeBlock;		// size of block
	blockType = 0xCC;		// block type is used -> 0xAA  if block type is free -> 0xCC
	pad0 = 0;			// future use
	pad1 = 0;			// future use
	pad2 = 0;			// future use
}

freeHdr::freeHdr(freeHdr * pFree)
{
	freeNext = (freeHdr *)((memU32)pFree);		// next free block
	freePrev = (freeHdr *)((memU32)pFree + sizeof(freeHdr *));		// prev free block
	blockSize = (memU32)((memU32)pFree + sizeof(freeHdr *) * 2);		// size of block
	blockType = 0xCC;		// block type is used -> 0xAA  if block type is free -> 0xCC
	pad0 = 0;			// future use
	pad1 = 0;			// future use
	pad2 = 0;			// future use
}