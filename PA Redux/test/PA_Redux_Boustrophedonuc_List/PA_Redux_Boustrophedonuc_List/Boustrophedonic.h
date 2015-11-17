#ifndef BOUSTROPHEDIC_H
#define BOUSTROPHEDIC_H

#include <vector>

struct position
{
	int row;
	int col;
};

struct Node
{
	Node *pNorth;
	Node *pSouth;
	Node *pEast;
	Node *pWest;
	position pos;
	int rank;
};

void remove(Node *head, int row, int col);

void create(int row, int col);

void gotoXY(int, int);

#endif
