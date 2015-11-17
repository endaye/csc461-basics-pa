// LoadInPlace.cpp : Defines the entry point for the console application.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <vector>

#include "List.h"
#include "Node.h"
#include "output.h"

struct inPlaceHdr
{
	int sizeBlock;
	int numPtrs;
	int offsetToPtrs[];
};

int main()
{
	// Create the IO for this program, that's WHERE YOU PUT YOUR NAME, please change it.
	io::create("Yuancheng Zhang");

	// Do not modify this function, you need to leave this routine alone.
	// It initializes the data if a very disjointed way do not modify it!
	List::CreateLinkedList();

	// Output Original Nodes
  	fprintf(io::getHandle(),"Original nodes in Memory\n\n");
	List::dumpList();

   // SECTION 1:  Grads only section 
   //        Create your contiguous memory footprint here
   // Needs to be:
   //        1) in one contiguous memory footprint
   //        2) offsets instead of pointers
   //        3) See sample print out
   //            a) append to existing output file
	fprintf(io::getHandle(), "Memory in Contiguous form\n\n");
	
	int sizeInPlaceBlock = 5 * sizeof(Node);
	Node *ptrList = List::getListHead();
	
	// a-copy, b-copy, c-copy
	char *p = new char[sizeInPlaceBlock];
	char *s = new char[sizeInPlaceBlock];
	char *r = new char[sizeInPlaceBlock];
	char *pOrig = p;
	char *sOrig = s;
	char *rOrig = r;
	Node *node = 0;

	// a-copy
	while (ptrList != 0)
	{
		node = new(p)Node(ptrList);

		if (ptrList->getPrev() == 0)
		{
			node->setPrev(0);
		}
		else
		{
			node->setPrev((Node *)(p - sizeof(Node)));
			node->getPrev()->setNext(node);
		}
		if (ptrList->getNext() == 0)
		{
			node->setNext(0);
		}

		p += sizeof(Node);
		ptrList = ptrList->getNext();
	}

	// b-copy
	ptrList = List::getListHead();
	while (ptrList != 0)
	{
		node = new(s)Node(ptrList);

		if (ptrList->getPrev() == 0)
		{
			node->setPrev(0);
		}
		else
		{
			node->setPrev((Node *)(s - sizeof(Node)));
			node->getPrev()->setNext(node);
		}
		if (ptrList->getNext() == 0)
		{
			node->setNext(0);
		}

		s += sizeof(Node);
		ptrList = ptrList->getNext();
	}

	// c-copy = a - b;
	std::vector<int> fixup;

	// num int* in block
	int numIntPtrInBlock = (5 * sizeof(Node)) / sizeof(int *);

	// setup the pointers
	int *b = (int *)sOrig;
	int *a = (int *)pOrig;
	int *c = (int *)rOrig;
	for (int i = 0; i < numIntPtrInBlock; i++)
	{
		if ((*b - *a) != 0x0)
		{
			// copy offset data
			*c = (unsigned int)*a - (unsigned int)pOrig;
			
			// squirrel away which pointers were affected
			fixup.push_back((unsigned int)a - (unsigned int)pOrig);
		}
		else
		{
			// copy static data
			*c = *a;
		}

		a++;
		b++;
		c++;
	}
	
	r = rOrig;
	for (int i = 0; i < sizeInPlaceBlock; i += sizeof(Node))
	{
		node = (Node*)(r + i);
		fprintf(io::getHandle(), "   Node Addr: 0x%p\n", (unsigned int)node - (unsigned int)rOrig);
		fprintf(io::getHandle(), "        next: 0x%p\n", node->getNext());
		fprintf(io::getHandle(), "        prev: 0x%p\n", node->getPrev());
		fprintf(io::getHandle(), "           x: 0x%x\n", node->x);
		fprintf(io::getHandle(), "           y: 0x%x\n", node->y);
		fprintf(io::getHandle(), "           z: 0x%x\n", node->z);
		fprintf(io::getHandle(), "         key: 0x%x\n\n", node->key);
	}



   // SECTION 2:  Grad Section  (No credit if Section 1 isn't 100% complete)
   //        1) Write Contiguous memory footprint to a new binary file
   //            a) add any extra data necessary for pointer fix-up
   //            b) close the file
   //        2) Load this data from a binary file into ONE memory block
   //            a) open the file
   //            b) load the in-Place buffer
   //            c) preform pointer fix-up
   //            d) close the file
   //        3) print the linked list data
   //            a) your pointers will be pointing to address within block
   //            b) data will be the same as before, everything has to come from binary file
   //            c) append to existing output file

	fprintf(io::getHandle(), "New linked list after loading it back from a file\n\n");
	
	// get the size of the inPlaceHdr struture in total
	int sizeInPlaceHdr = sizeof(inPlaceHdr);
	int vectorCount = fixup.size();
	int totalSize = sizeInPlaceHdr + vectorCount * sizeof(int);

	// create a buffer
	char *p_inPlaceHdr = new char[totalSize];

	// cast this to inPlaceHdr * pointer
	inPlaceHdr *ip1 = (inPlaceHdr *)p_inPlaceHdr;
	
	// fill in the block size
	ip1->sizeBlock = 5 * sizeof(Node);
	ip1->numPtrs = vectorCount;

	// fill in the array of offsets
	for (int i = 0; i < vectorCount; i++)
	{
		ip1->offsetToPtrs[i] = fixup[i];
	}

	int *w = (int *)rOrig;
	FILE * pFile;

	// save list into file
	pFile = fopen("Saved_List.txt", "wb+");
	if (pFile != 0)
	{
		// inPlaceHdt
		fwrite(ip1, 4, (ip1->numPtrs + 2), pFile);
		
		// offset list
		fwrite(rOrig, 1, sizeInPlaceBlock, pFile);
		fclose(pFile);
	}

	if (fopen_s(&pFile, "Saved_List.txt", "rb") == 0)
	{
		fseek(pFile, 0, SEEK_END);
		long len = ftell(pFile);
		fseek(pFile, 0, SEEK_SET);

		unsigned char *buffer = (unsigned char*)malloc(len);
		if (!buffer)
		{
			fclose(pFile);
			exit(1);
		}
		long readlen = (long)fread(buffer, 1, len, pFile);
		fclose(pFile);

		inPlaceHdr *ip2 = new inPlaceHdr;
		ip2->sizeBlock = (int)*buffer;
		ip2->numPtrs = (int)*(buffer + 4);
		for (int i = 0; i < ip2->numPtrs; i++)
		{
			ip2->offsetToPtrs[i] = (int)*(buffer + 8 + 4 * i);
		}
		int *qOrig = (int *)(buffer + 8 + 4 * ip2->numPtrs);
		int startAddr = (int)qOrig;
		int *pCorr;

		for (int i = 0; i < ip2->numPtrs; i++)
		{
			pCorr = (int *)((unsigned int)startAddr + ip2->offsetToPtrs[i]);
			*pCorr += startAddr;
		}

		char *r = (char *)startAddr;
		for (int i = 0; i < sizeInPlaceBlock; i += sizeof(Node))
		{
			node = (Node*)(r + i);
			fprintf(io::getHandle(), "   Node Addr: 0x%p\n", node);
			fprintf(io::getHandle(), "        next: 0x%p\n", node->getNext());
			fprintf(io::getHandle(), "        prev: 0x%p\n", node->getPrev());
			fprintf(io::getHandle(), "           x: 0x%x\n", node->x);
			fprintf(io::getHandle(), "           y: 0x%x\n", node->y);
			fprintf(io::getHandle(), "           z: 0x%x\n", node->z);
			fprintf(io::getHandle(), "         key: 0x%x\n\n", node->key);
		}

	}

	return 0;
}

