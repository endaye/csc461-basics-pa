#include <new>
#include <assert.h>
#include "mem.h"
#include "heapHdr.h"
#include "freeHdr.h"
#include "usedHdr.h"
#include "output.h"

#define ALIGNMENT_PAD (16)

memSystem::~memSystem()
{
	delete[] rawMem;
}

heapHdr *memSystem::getHeap()
{
	return heap;
}

memSystem::memSystem()
{ 
	// now initialize it.
	heap = 0;
	rawMem = 0;

	// create the memory block for the heap
	char *p_raw = new char[HEAP_SIZE + ALIGNMENT_PAD];

	// update the pointer
	rawMem = p_raw;

	// Correct pointer to make sure it's 16 byte aligned
	char *p_corrected = (char *)(((memU32)p_raw + (16 - 1)) & ~(16 - 1));

	// instantiate the heap header on the raw memory
	heapHdr *p = new(p_corrected)heapHdr(p_corrected);

	// update it
	heap = p;


}

memVoid memSystem::InitializeSystem()
{
	heapHdr *pHeap = this->getHeap();

	freeHdr *startFreeHdr = (freeHdr *)pHeap->stats.heapTopAddr;

	memU32 totalSize = (memU32)pHeap->stats.heapBottomAddr - (memU32)pHeap->stats.heapTopAddr;

	memU32 freeBlockSize = totalSize - sizeof(freeHdr);

	freeHdr *pFree = new (startFreeHdr)freeHdr(freeBlockSize);

	pHeap->freeHead = pFree;

	pHeap->stats.currNumFreeBlocks = 1;
	pHeap->stats.currFreeMem = freeBlockSize;

	memU32 heapSize = totalSize + sizeof(heapHdr);
	pHeap->stats.sizeHeap = heapSize;
	pHeap->stats.sizeHeapHeader = sizeof(heapHdr);
	freeHdr **secretPtr = (freeHdr **)((memU32)pHeap->stats.heapBottomAddr - sizeof(freeHdr *));
	*secretPtr = pFree;
}

memVoid memSystem::Free(memVoid * const data)
{
	// general check ================================================
	heapHdr *pHeap = this->getHeap();

	// Used Block (remove) ================================================
	usedHdr *pUsed = (usedHdr *)((memU32)data - sizeof(usedHdr));

	memBool aboveBlockFree = (memBool)pUsed->aboveBlockFree;
	if (pUsed->usedPrev == 0 && pUsed->usedNext == 0)
	{
		// only one
		pHeap->usedHead = 0;
	}
	else if (pUsed->usedPrev == 0)
	{
		// first
		pHeap->usedHead = pUsed->usedNext;
		pUsed->usedNext->usedPrev = 0;
	}
	else if (pUsed->usedNext == 0)
	{
		// last
		pUsed->usedPrev->usedNext = 0;
	}
	else
	{
		// middle
		pUsed->usedNext->usedPrev = pUsed->usedPrev;
		pUsed->usedPrev->usedNext = pUsed->usedNext;
	}
	pHeap->stats.currNumUsedBlocks--;
	pHeap->stats.currUsedMem -= pUsed->blockSize;

	if (pHeap->stats.currNumUsedBlocks == 0)
	{
		pHeap->usedHead = 0;
	}

	// free block (create) ================================================
	freeHdr *startFreeHdr = (freeHdr*)pUsed;
	freeHdr *pFree = new (startFreeHdr)freeHdr(pUsed->blockSize);

	pHeap->stats.currFreeMem += pFree->blockSize;
	pHeap->stats.currNumFreeBlocks++;

	pFree->freeNext = 0;
	pFree->freePrev = 0;

	if (pHeap->freeHead == 0)
	{
		pHeap->freeHead = pFree;
	}
	
	// secrete ptr
	freeHdr **secretPtr = (freeHdr **)((memU32)pFree + pFree->blockSize + sizeof(freeHdr) - sizeof(freeHdr *));
	*secretPtr = pFree;

	// below block =================================

	if (((memU32)pFree + sizeof(freeHdr) + pFree->blockSize) == (memU32)pHeap->stats.heapBottomAddr)
	{
		// 1. below bottom
		if (aboveBlockFree)
		{
			// above free
			freeHdr ** above = (freeHdr **)((memU32)pFree - sizeof(freeHdr *));
			freeHdr *aboveFree = *above;

			if (pHeap->freeHead == pFree)
			{
				pHeap->freeHead = aboveFree;
			}

			aboveFree->freeNext = 0;
			aboveFree->blockSize = aboveFree->blockSize + sizeof(freeHdr) + pFree->blockSize;

			*secretPtr = aboveFree;

			pHeap->stats.currFreeMem += sizeof(freeHdr);
			pHeap->stats.currNumFreeBlocks--;
		}
		else
		{
			// above used
			
			if (pHeap->freeHead != pFree)
			{
				freeHdr *aboveFree = pHeap->freeHead;
				while (true)
				{
					if (aboveFree->freeNext == 0)
					{
						break;
					}
					aboveFree = aboveFree->freeNext;
				}
				pFree->freePrev = aboveFree;
				aboveFree->freeNext = pFree;
			}
		}
	}
	else
	{
		// not bottom
		memU8 belowBlockType = (memU8)(*((int*)((memU32)pFree + sizeof(freeHdr) + pFree->blockSize + sizeof(usedHdr*) * 2 + sizeof(memU32))) & 0xFF);
		if (belowBlockType == 0xCC)
		{
			// 2. below free
			freeHdr *belowFree = (freeHdr *)((memU32)pFree + sizeof(freeHdr) + pFree->blockSize);

			if (belowFree->freePrev != 0)
			{
				belowFree->freePrev->freeNext = pFree;
			}
			if (belowFree->freeNext != 0)
			{
				belowFree->freeNext->freePrev = pFree;
			}
			if (pHeap->freeHead == belowFree)
			{
				pHeap->freeHead = pFree;
			}
			pFree->freeNext = belowFree->freeNext;
			pFree->freePrev = belowFree->freePrev;

			pFree->blockSize = pFree->blockSize + sizeof(freeHdr) + belowFree->blockSize;

			secretPtr = (freeHdr **)((memU32)pFree + pFree->blockSize + sizeof(freeHdr) - sizeof(freeHdr *));
			*secretPtr = pFree;

			pHeap->stats.currFreeMem += sizeof(freeHdr);
			pHeap->stats.currNumFreeBlocks--;

			if (aboveBlockFree)
			{
				// above free
				freeHdr ** above = (freeHdr **)((memU32)pFree - sizeof(freeHdr *));
				freeHdr *aboveFree = *above;

				if (pFree->freeNext != 0)
				{
					pFree->freeNext->freePrev = aboveFree;
				}
				if (pHeap->freeHead == pFree)
				{
					pHeap->freeHead = aboveFree;
				}
				aboveFree->freeNext = pFree->freeNext;
				aboveFree->blockSize = aboveFree->blockSize + sizeof(freeHdr) + pFree->blockSize;

				*secretPtr = aboveFree;

				pHeap->stats.currFreeMem += sizeof(freeHdr);
				pHeap->stats.currNumFreeBlocks--;
			}
		}
		else 
		{
			// 3. below used
			// if (belowBlockType == 0xAA)
			usedHdr *belowUsed = (usedHdr *)((memU32)pFree + sizeof(freeHdr) + pFree->blockSize);
			belowUsed->aboveBlockFree = true;

			if (aboveBlockFree)
			{
				// above free
				freeHdr ** above = (freeHdr **)((memU32)pFree - sizeof(freeHdr *));
				freeHdr *aboveFree = *above;

				aboveFree->blockSize = aboveFree->blockSize + sizeof(freeHdr) + pFree->blockSize;

				*secretPtr = aboveFree;

				pHeap->stats.currFreeMem += sizeof(freeHdr);
				pHeap->stats.currNumFreeBlocks--;
			}
			else
			{
				// above used
				if (pHeap->freeHead != pFree)
				{
					freeHdr *aboveFree = pHeap->freeHead;
					if (aboveFree > pFree)
					{
						pFree->freeNext = pHeap->freeHead;
						pHeap->freeHead->freePrev = pFree;
						pHeap->freeHead = pFree;
					}
					else
					{
						while (true)
						{
							if (aboveFree->freeNext == 0 || aboveFree->freeNext > pFree)
							{
								break;
							}
							aboveFree = aboveFree->freeNext;
						}
						if (aboveFree->freeNext == 0)
						{
							aboveFree->freeNext = pFree;
							pFree->freePrev = aboveFree;
							pFree->freeNext = 0;
						}
						else
						{
							pFree->freePrev = aboveFree;
							pFree->freeNext = aboveFree->freeNext;
							aboveFree->freeNext->freePrev = pFree;
							aboveFree->freeNext = pFree;
						}
					}
				}
			}
		}
	}
}


memVoid * memSystem::Malloc(const memU32 size)
{
	// general check ================================================
	heapHdr *pHeap = this->getHeap();

	// find a available free block ====================================
	freeHdr *availFree = (freeHdr *)pHeap->freeHead;
	while (true)
	{
		if (availFree->blockSize >= size)
		{
			break;
		}
		availFree = availFree->freeNext;
		if (availFree == 0)
		{
			// throw an exception here!
		}
	}

	freeHdr *availFreeNext = availFree->freeNext;
	freeHdr *availFreePrev = availFree->freePrev;
	memU32 availFreeSize = (memU32)availFree->blockSize;

	// Used Block (create) ================================================
	usedHdr *startUsedHdr = (usedHdr *)availFree;
	usedHdr *pUsed = new (startUsedHdr)usedHdr(size);

	// pUsed->usedPrev
	// pUsed->usedNext
	// pHeap->usedHead
	pUsed->usedPrev = 0;
	pUsed->usedNext = pHeap->usedHead;
	if (pHeap->usedHead != 0)
	{
		pHeap->usedHead->usedPrev = pUsed;
	}
	pHeap->usedHead = pUsed;

	pUsed->aboveBlockFree = false;

	memU32 restSize = availFreeSize - (memU32)pUsed->blockSize;

	if (restSize == 0)
	{
		pHeap->stats.currNumUsedBlocks++;
		pHeap->stats.currUsedMem += size;

		pHeap->stats.currNumFreeBlocks--;
		pHeap->stats.currFreeMem -= size;

		if (availFreePrev == 0 && availFreeNext == 0)
		{
			pHeap->freeHead = 0;
		}
		else if (availFreePrev == 0)
		{
			availFreeNext->freePrev = 0;
			pHeap->freeHead = availFreeNext;
		}
		else if (availFreeNext == 0)
		{
			availFreePrev->freeNext = 0;
		}
		else
		{
			availFreePrev->freeNext = availFreeNext;
			availFreeNext->freePrev = availFreePrev;
		}
	}
	else if (restSize < sizeof(freeHdr))
	{
		// need add this block to usedblock
	}
	else
	{
		pHeap->stats.currNumUsedBlocks++;
		pHeap->stats.currUsedMem += (memU32)size;

		pHeap->stats.currFreeMem -= size + sizeof(freeHdr);

		// free block (create) 
		freeHdr *startFreeHdr = (freeHdr *)((memU32)pUsed + size + sizeof(usedHdr));
		freeHdr *pFree = new (startFreeHdr)freeHdr(restSize);
		pFree->blockSize = restSize - sizeof(freeHdr);
		pFree->freePrev = availFreePrev;
		pFree->freeNext = availFreeNext;

		if (pFree->freePrev == 0 && pFree->freeNext == 0)
		{
			pHeap->freeHead = pFree;
		}
		else if (pFree->freePrev == 0)
		{
			pFree->freeNext->freePrev = pFree;
			pHeap->freeHead = pFree;
		}
		else if (pFree->freeNext == 0)
		{
			pFree->freePrev->freeNext = pFree;
		}
		else
		{
			pFree->freePrev->freeNext = pFree;
			pFree->freeNext->freePrev = pFree;
		}
		// secrete ptr
		freeHdr **secretPtr = (freeHdr **)((memU32)pFree + pFree->blockSize + sizeof(freeHdr) - sizeof(freeHdr *));
		*secretPtr = pFree;
	}

	// pHeap->stats.peakNumUsed
	// pHeap->stats.peakUsedMemory
	if (pHeap->stats.currNumUsedBlocks > pHeap->stats.peakNumUsed)
	{
		pHeap->stats.peakNumUsed = pHeap->stats.currNumUsedBlocks;
	}
	if (pHeap->stats.currUsedMem > pHeap->stats.peakUsedMemory)
	{
		pHeap->stats.peakUsedMemory = pHeap->stats.currUsedMem;
	}
	if (pHeap->stats.currNumFreeBlocks == 0)
	{
		pHeap->freeHead = 0;
	}

	return (memVoid*)((memU32)pUsed + sizeof(usedHdr));
}

memVoid memSystem::dump()
{

	fprintf(io::getHandle(), "\n------- DUMP -------------\n\n");

	fprintf(io::getHandle(), "heapStart: 0x%p     \nheapEnd:   0x%p \n\n", heap, heap->stats.heapBottomAddr);
	fprintf(io::getHandle(), "usedHead:  0x%p     \nfreeHead:  0x%p \n\n", heap->usedHead, heap->freeHead);

	fprintf(io::getHandle(), "Heap Hdr   s: %p  e: %p                            size: 0x%x \n", (memU32)heap->stats.heapTopAddr - sizeof(heapHdr), heap->stats.heapTopAddr, heap->stats.sizeHeapHeader);

	memU32 p = (memU32)heap->stats.heapTopAddr;

	char *type;
	char *typeHdr;

	while (p < (memU32)heap->stats.heapBottomAddr)
	{
		usedHdr *used = (usedHdr *)p;
		if (used->blockType == 0xAA)
		{
			typeHdr = "USED HDR ";
			type = "USED     ";
		}
		else
		{
			typeHdr = "FREE HDR ";
			type = "FREE     ";
		}

		memU32 hdrStart = (memU32)used;
		memU32 hdrEnd = (memU32)used + sizeof(usedHdr);
		fprintf(io::getHandle(), "%s  s: %p  e: %p  p: %p  n: %p  size: 0x%x    AF: %d \n", typeHdr, hdrStart, hdrEnd, used->usedPrev, used->usedNext, sizeof(usedHdr), used->aboveBlockFree);
		memU32 blkStart = hdrEnd;
		memU32 blkEnd = blkStart + used->blockSize;
		fprintf(io::getHandle(), "%s  s: %p  e: %p                            size: 0x%x \n", type, blkStart, blkEnd, used->blockSize);

		p = blkEnd;

	}
}