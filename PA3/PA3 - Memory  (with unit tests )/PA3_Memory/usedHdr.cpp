#include "usedHdr.h"

usedHdr::usedHdr(memU32 sizeBlock)
{
	usedNext = 0;		// next used block
	usedPrev = 0;		// prev used block
	blockSize = sizeBlock;		// size of block
	blockType = 0xAA;		// block type is used -> 0xAA  if block type is free -> 0xCC
	aboveBlockFree = false;	        // if(block is free) -> true or if(block is used) -> false
	pad0 = 0;                   // future use
	pad1 = 0;			// future use
}

/*
usedHdr::usedHdr(memVoid * const data)
{
	this->usedNext = data->usedNext;		// next used block
	this->usedPrev = 0;		// prev used block
	this->blockSize = sizeBlock;		// size of block
	this->blockType = 0xAA;		// block type is used -> 0xAA  if block type is free -> 0xCC
	this->aboveBlockFree = true;	        // if(block is free) -> true or if(block is used) -> false
	this->pad0 = 0;                   // future use
	this->pad1 = 0;			// future use
}
*/