#ifndef FREEHDR_H
#define FREEHDR_H

#include "memTypes.h"

struct freeHdr
{
public:
	freeHdr(memU32 sizeBlock);
	freeHdr(freeHdr * pFree);

	freeHdr *freeNext;		// next free block
	freeHdr *freePrev;		// prev free block
	memU32  blockSize;		// size of block
	memU8	blockType;		// block type is used -> 0xAA  if block type is free -> 0xCC
	memU8	pad0;			// future use
	memU8	pad1;			// future use
	memU8	pad2;			// future use

};

#endif //FREEHDR_H