#include <assert.h>
#include <stdio.h>
#include <vector>
 

#include "Boustrophedonic.h"

#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;
//struct Node
//{
//	Node *pNorth;
//	Node *pSouth;
//	Node *pEast;
//	Node *pWest;
//};

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void create(int row, int col)
{
	vector<Node> nodes(row * col);
	bool isDown = 0;
	// initialize nodes
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i].pNorth = 0;
		nodes[i].pSouth = 0;
		nodes[i].pEast = 0;
		nodes[i].pWest = 0;
		nodes[i].rank = i;
		nodes[i].pos.row = 0;
		nodes[i].pos.col = 0;
	}

	// link nodes
	int x = 0;
	int y = 0;
	for (int i = 0; i < nodes.size(); i++)
	{
		x = i / col; // row
		y = i % col; // col
		nodes[i].pos.row = x;
 
		if (x % 2 == 0)
		{
			// -> ->
			nodes[i].pos.col = y;
			if (nodes[i].pos.col < col - 1 && i < nodes.size() - 1)
			{
				nodes[i].pEast = &(nodes[i + 1]);
			}
			// down arrow
			if (nodes[i].pos.col == col - 1 && i < nodes.size() - 1)
			{
				nodes[i].pSouth = &(nodes[i + 1]);
			}
		}
		else
		{
			// <- <-
			nodes[i].pos.col = col - y - 1;
			if (nodes[i].pos.col > 0 && i < nodes.size() - 1)
			{
				nodes[i].pWest = &(nodes[i + 1]);
			}
			if (nodes[i].pos.col == 0 && i < nodes.size() - 1)
			{
				nodes[i].pSouth = &(nodes[i + 1]);
			}
		}
		// up & down
		if (nodes[i].pos.row == 0)
		{
			continue;
		}
		else
		{
			int up = nodes[i].pos.row * col * 2 - 1 - i;
			if (isDown)
			{
				nodes[i].pNorth = &nodes[up];
				isDown = 0;
			}
			else
			{
				nodes[up].pSouth = &nodes[i];
				isDown = 1;
			}
		}
	}

	// output
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].pNorth == 0 && nodes[i].pSouth == 0 && nodes[i].pEast == 0 && nodes[i].pWest == 0 && i != nodes.size() - 1)
		{
			continue;
		}
		gotoXY(nodes[i].pos.col * 15, nodes[i].pos.row * 7);
		printf("[%02d] %d %d\n", nodes[i].rank, nodes[i].pos.row, nodes[i].pos.col);
		gotoXY(nodes[i].pos.col * 15, nodes[i].pos.row * 7 + 1);
		printf(" <%p>\n", &(nodes[i]));
		gotoXY(nodes[i].pos.col * 15, nodes[i].pos.row * 7 + 2);
		if (nodes[i].pNorth == 0)
		{
			printf("N:");
		}
		else
		{
			printf("N:%p", nodes[i].pNorth);
		}
		gotoXY(nodes[i].pos.col * 15, nodes[i].pos.row * 7 + 3);
		if (nodes[i].pWest == 0)
		{
			printf("W:");
		}
		else
		{
			printf("W:%p", nodes[i].pWest);
		}
		gotoXY(nodes[i].pos.col * 15, nodes[i].pos.row * 7 + 4);
		if (nodes[i].pEast == 0)
		{
			printf("E:");
		}
		else
		{
			printf("E:%p", nodes[i].pEast);
		}
		
		gotoXY(nodes[i].pos.col * 15, nodes[i].pos.row * 7 + 5);
		if (nodes[i].pSouth == 0)
		{
			printf("S:");
		}
		else
		{
			printf("S:%p", nodes[i].pSouth);
		}
		
	}
	gotoXY(0, row * 7);
	
	//////////////// test remove() /////////////
	remove(&nodes[0], 4, 3);

	// output again

	// output
	for (int i = 0; i < nodes.size(); i++)
	{
		gotoXY(nodes[i].pos.col * 15, nodes[i].pos.row * 7 + row * 8);
		printf("[%02d] %d %d\n", nodes[i].rank, nodes[i].pos.row, nodes[i].pos.col);
		gotoXY(nodes[i].pos.col * 15, nodes[i].pos.row * 7 + 1 + row * 8);
		printf(" <%p>\n", &(nodes[i]));
		gotoXY(nodes[i].pos.col * 15, nodes[i].pos.row * 7 + 2 + row * 8);
		if (nodes[i].pNorth == 0)
		{
			printf("N:");
		}
		else
		{
			printf("N:%p", nodes[i].pNorth);
		}
		gotoXY(nodes[i].pos.col * 15, nodes[i].pos.row * 7 + 3 + row * 8);
		if (nodes[i].pWest == 0)
		{
			printf("W:");
		}
		else
		{
			printf("W:%p", nodes[i].pWest);
		}
		gotoXY(nodes[i].pos.col * 15, nodes[i].pos.row * 7 + 4 + row * 8);
		if (nodes[i].pEast == 0)
		{
			printf("E:");
		}
		else
		{
			printf("E:%p", nodes[i].pEast);
		}
		gotoXY(nodes[i].pos.col * 15, nodes[i].pos.row * 7 + 5 + row * 8);
		if (nodes[i].pSouth == 0)
		{
			printf("S:");
		}
		else
		{
			printf("S:%p", nodes[i].pSouth);
		}

	}
	gotoXY(0, row * 7);

	return;
}


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

	// output the result
	printf("node: %d\n", nodeNum);
	printf("row: %d\n", rowNum);
	printf("col: %d\n", colNum);

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
