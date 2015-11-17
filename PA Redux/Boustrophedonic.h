#ifndef BOUSTROPHEDIC_H
#define BOUSTROPHEDIC_H

struct Node
{
	Node *pNorth;
	Node *pSouth;
	Node *pEast;
	Node *pWest;
};

void remove(Node *head, int row, int col);

#endif
