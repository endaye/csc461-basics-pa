#include "bloated.h"
#include "Node.h"
#include <stdlib.h>
#include <assert.h>

OriginalNode *Bloated::head = 0;


void Bloated::CreateLinkedList()
{
	// initialize it NULL
	head = 0;

	// Reset the seed
	// NO-ONE should ever call this function
	// it is here to insure that everyone's seed is the same.
	// Do not change or recall srand anywhere
	srand(1);

	// create the space
	// this function magically initialize all the date with a set pattern
	OriginalNode *p = new  OriginalNode[NUM_NODES];

	// int totalSize = sizeof(OriginalNode) * NUM_NODES ;

	// head
	head = p;

	// some markers...
	OriginalNode *pFirst = p;
	OriginalNode *pLast  = p + NUM_NODES - 1;
	OriginalNode *pCurr = pFirst;

	// initialize the all nodes
	for( int i = 0; i < NUM_NODES; ++i )
	{
		pCurr->setNext(pCurr + 1);
		pCurr->setPrev(pCurr - 1);
		pCurr++;
	}

	// fix up the first and last node
	pLast->setNext(0);
	pFirst->setPrev(0);
}

OriginalNode *Bloated::getListHead()
{
	return head;
}

bool Bloated::findKey(int key, OriginalNode &foundNode)
{
	bool foundFlag(false);
	OriginalNode *p = Bloated::getListHead();
	
	while( p != 0 )
	{
		// is this the node?
		if( p->key == key)
		{
			// yes, then break
			foundFlag = true;
			break;
		}

		// go to next
		p = p->next;
	}

	// return the node reference that contains the key
	assert(p);
	foundNode = *p;

	// flag
	return foundFlag;
}

Bloated::Bloated()
{

}

Bloated::~Bloated()
{
	delete head;
	head = 0;
}