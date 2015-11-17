#include <assert.h>
#include <stdio.h>

#include "Boustrophedonic.h"

void remove(Node *head, int row, int col)
{

	if (head == 0)
	{
		return;
	}
	Node *pNode = head;

	// number of nodes
	int nodeNum = 0;

	// total numbers of rows and columns
	int rowNum = 0;
	int colNum = 0;
	
	// find number of colums
	while (pNode != 0)
	{
		colNum++;
		pNode = pNode->pEast;
	}

	// find number of rows
	bool toEast = 1;
	pNode = head;
	while (pNode != 0)
	{
		nodeNum++;
		if (toEast)
		{
			if (pNode->pEast != 0)
			{
				pNode = pNode->pEast;
			}
			else
			{
				pNode = pNode->pSouth;
				toEast = 0;
				rowNum++;
			}
		}
		else
		{
			if (pNode->pWest != 0)
			{
				pNode = pNode->pWest;
			}
			else
			{
				pNode = pNode->pSouth;
				toEast = 1;
				rowNum++;
			}
		}
	}

	// chech the boundries
	if (row < 0 || row >= rowNum || col < 0 || col >= colNum || (row == 0 && col == 0))
	{
		assert(0);
	}

	// find the target node and its surround nodes;
	toEast = 1;
	pNode = head;
	Node * pNodeTarget = 0;
	Node * pNodeNorth = 0;
	Node * pNodeSouth = 0;
	Node * pNodeEast = 0;
	Node * pNodeWest = 0;
	int j = 0;
	{
		int r = 0; // current node row
		int c = 0; // current node column
		while (pNode != 0)
		{
			// chech the positions
			if (r == row && c == col)
			{
				pNodeTarget = pNode; // removed node;
			}
			if (r == row - 1 && c == col)
			{
				pNodeNorth = pNode; // north
			}
			if (r == row + 1 && c == col)
			{
				pNodeSouth = pNode; // south
			}
			if (r == row && c == col - 1)
			{
				pNodeWest = pNode;
			}
			if (r == row && c == col + 1)
			{
				pNodeEast = pNode;
			}

			if (toEast)
			{
				if (pNode->pEast != 0)
				{
					pNode = pNode->pEast;
					c++;
				}
				else
				{
					pNode = pNode->pSouth;
					toEast = 0;
					r++;
				}
			}
			else
			{
				if (pNode->pWest != 0)
				{
					pNode = pNode->pWest;
					c--;
				}
				else
				{
					pNode = pNode->pSouth;
					toEast = 1;
					r++;
				}
			}
		}
	}
	
	// fixed surround node links
	// north
	if (pNodeNorth != 0 && pNodeNorth->pSouth != 0)
	{
		pNodeNorth->pSouth = pNodeSouth;
	}
	// south
	if (pNodeSouth != 0 && pNodeSouth->pNorth != 0)
	{
		pNodeSouth->pNorth = pNodeNorth;
	}
	// east
	if (pNodeEast != 0 && pNodeEast->pWest != 0)
	{
		pNodeEast->pWest = pNodeWest;
	}

	// west
	if (pNodeWest != 0 && pNodeWest->pEast != 0)
	{
		pNodeWest->pEast = pNodeEast;
	}

	// remove the nodes;
	pNodeTarget->pNorth = 0;
	pNodeTarget->pSouth = 0;
	pNodeTarget->pEast = 0;
	pNodeTarget->pWest = 0;	
	// delete pNodeTarget;
}
