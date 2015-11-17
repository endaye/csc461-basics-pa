// List.cpp : Defines the entry point for the console application.
//


#include <stdlib.h>
#include <assert.h>

#include "List.h"
#include "Node.h"
#include "output.h"


// Initialize statics
Node *List::head = 0;


void List::CreateLinkedList()
{
	// -----------------THIS ROUTINE CANNOT BE CHANGED at ALL -----------------------------------

	// initialize it NULL
	head = 0;

	// Reset the seed
	// NO-ONE should ever call this function
	// it is here to insure that everyone's seed is the same.
	// Do not change or recall srand anywhere
	srand(1);

	// create the space
	// this function magically initialize all the date with a set pattern
	Node *pA = new  Node;
	Node  *noiseA = new Node[3];
	Node  *noiseB = new Node[76];
	Node  *noiseC = new Node[223];
	Node *pB = new  Node;
	Node *noiseD = new Node [9];   
	Node  *noiseE = new Node [304];
	Node *pC = new  Node;
	Node  *noiseF = new Node [89];
	Node *pD = new  Node;
	Node  *noiseG = new Node [98];   
	Node  *noiseH = new Node [374];   
	Node  *noiseI = new Node [7];
	Node *pE = new  Node;
	Node  *noiseJ = new Node [34];
	Node  *noiseK = new Node [56];

	// Link the nodes together
	// B->C->A->E->D in that order

	head = pB;
	pB->setPrev(0);
	pB->setNext(pC);
	pB->setKey( 0xBBBBBBBB);

	pC->setPrev(pB);
	pC->setNext(pA);
	pC->setKey( 0xCCCCCCCC);

	pA->setPrev(pC);
	pA->setNext(pE);
	pA->setKey( 0xAAAAAAAA);

	pE->setPrev(pA);
	pE->setNext(pD);
	pE->setKey( 0xEEEEEEEE);

	pD->setPrev(pE);
	pD->setNext(0);
	pD->setKey( 0xDDDDDDDD);

	// Use the noise memory segments to prevent compiler from optimizing them out.

	noiseA[0].setNext(0);
	noiseB[0].setNext(0);
	noiseC[0].setNext(0);
	noiseD[0].setNext(0);
	noiseE[0].setNext(0);
	noiseF[0].setNext(0);
	noiseG[0].setNext(0);
	noiseH[0].setNext(0);
	noiseI[0].setNext(0);
	noiseJ[0].setNext(0);
	noiseK[0].setNext(0);


	fprintf(io::getHandle(),"\n");
	fprintf(io::getHandle(),"Creation Noise Pointers\n\n");
	fprintf(io::getHandle(),"    NodeA: Addr: 0x%p\n", noiseA);
	fprintf(io::getHandle(),"    NodeB: Addr: 0x%p\n", noiseB);
	fprintf(io::getHandle(),"    NodeC: Addr: 0x%p\n", noiseC);
	fprintf(io::getHandle(),"    NodeD: Addr: 0x%p\n", noiseD);
	fprintf(io::getHandle(),"    NodeE: Addr: 0x%p\n", noiseE);
	fprintf(io::getHandle(),"    NodeF: Addr: 0x%p\n", noiseF);
	fprintf(io::getHandle(),"    NodeG: Addr: 0x%p\n", noiseG);
	fprintf(io::getHandle(),"    NodeH: Addr: 0x%p\n", noiseH);
	fprintf(io::getHandle(),"    NodeI: Addr: 0x%p\n", noiseI);
	fprintf(io::getHandle(),"    NodeJ: Addr: 0x%p\n", noiseJ);
	fprintf(io::getHandle(),"    NodeK: Addr: 0x%p\n\n", noiseK);


	delete[] noiseA;
	delete[] noiseB;
	delete[] noiseC;
	delete[] noiseD;
	delete[] noiseE;
	delete[] noiseF;
	delete[] noiseG;
	delete[] noiseH;
	delete[] noiseI;
	delete[] noiseJ;
	delete[] noiseK;

}

void List::dumpList()
{
   // walk the linked list and print the nodes
   Node *p = head;

   while( p != 0 )
   {
      p->dumpNode();
      p = p->getNext();
   }

}

Node *List::getListHead()
{
	return head;
}



List::List()
{

}

List::~List()
{
	delete head;
	head = 0;
}