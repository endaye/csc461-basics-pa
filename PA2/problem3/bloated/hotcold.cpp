#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "hotcold.h"
#include "bloated.h"
#include "Node.h"


HotNode *HotCold::head = 0;

void HotCold::convert(OriginalNode *pOrigHead)
{
	// initialize it NULL
	head = 0;

	// create the space
	HotNode *p = new HotNode[NUM_NODES];

	head = p;

	HotNode *pFirst = p;
	HotNode *pLast = p + NUM_NODES - 1;
	HotNode *pCurr = pFirst;

	// some markers...
	OriginalNode *pOrigCurr = pOrigHead;

	// initialize the all nodes
	for (int i = 0; i < NUM_NODES; i++)
	{
		pCurr->copyData(pOrigCurr);
		pCurr->setNext(pCurr + 1);
		pCurr->setPrev(pCurr - 1);
		pCurr++;
		pOrigCurr++;
	}

	// fix up the first and last node
	pLast->setNext(0);
	pFirst->setPrev(0);
}

HotNode *HotCold::getListHead()
{
	return head;
}

bool HotCold::findKey(int key, ColdNode &foundNode)
{
	bool foundFlag(false);
	HotNode *p = HotCold::getListHead();

	while (p != 0)
	{
		// is this the node?
		if (p->key == key)
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
	foundNode = *((*p).pCold);

	// flag
	return foundFlag;
}

void HotCold::verify()
{
	
	bool isSame(false);
	HotNode	*pHotHead = HotCold::getListHead();
	OriginalNode *pOrigHead = Bloated::getListHead();
	HotNode	*pHot = pHotHead;
	OriginalNode *pOrig = pOrigHead;

	while (pHot != 0 && pOrig != 0)
	{
		/*
	float			   x;
	float			   y;
	float			   z;
	Vect_t			A;
	Vect_t			B;
	Vect_t			C;
	Matrix_t		   MA;
	Matrix_t		   MB;
	Matrix_t		   MC;
	Matrix_t		   MD;
	char			   name[NAME_SIZE];
	int				key;
	*/
		if (pHot->key == pOrig->key &&
			pHot->pCold->key == pOrig->key &&
			pHot->pCold->x == pOrig->x &&
			pHot->pCold->y == pOrig->y &&
			pHot->pCold->z == pOrig->z &&
			pHot->pCold->A == pOrig->A &&
			pHot->pCold->B == pOrig->B &&
			pHot->pCold->C == pOrig->C &&
			pHot->pCold->MA == pOrig->MA &&
			pHot->pCold->MB == pOrig->MB &&
			pHot->pCold->MC == pOrig->MC &&
			pHot->pCold->MD == pOrig->MD &&
			strcmp(pHot->pCold->name, pOrig->name))
		{
			isSame = true;
		}
		pHot = pHot->getNext();
		pOrig = pOrig->getNext();
	}
	assert(isSame && "Verifing Failed.");
}



HotCold::HotCold()
{
}


HotCold::~HotCold()
{
	delete head;
	head = 0;
}


