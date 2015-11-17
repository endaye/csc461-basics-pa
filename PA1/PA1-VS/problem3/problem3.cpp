//
//  problem3.cpp
//  problem3
//
//  Created by Yuancheng Zhang on 10/1/15.
//

#include <stdio.h>
#include <iostream>
#define NODE_NUM 10
using namespace std;

typedef struct ImportantData
{
	int* value;
} InportantData_t;

typedef struct LinkList
{
	struct LinkList 		*next;
	struct LinkList			*prev;
	struct ImportantData 	*data;
} LinkList_t;

LinkList_t* headList;


void RemoveNode(LinkList_t* &node)
{
	// the list is empty
	if (node == 0)
	{
		return;
	}

	// only one node in the list
	if (headList == node && node->next == 0)
	{
		headList = 0;
		delete node;
		return;
	}

	// first node
	if (headList == node)
	{
		headList = node->next;
		node->next->prev = 0;
		delete node;
		return;
	}

	// last node
	if (node->next == 0)
	{
		node->prev->next = 0;
		delete node;
		return;
	}

	// middle node
	node->next->prev = node->prev;
	node->prev->next = node->next;

	delete node;
	return;
}


int main() {

	headList = new LinkList;
	LinkList_t* node = headList;

	LinkList_t* deleteThisNode = 0;



	for (int i = 0; i < NODE_NUM; i++)
	{
		node->data = new ImportantData;
		node->data->value = new int(i);

		if (i == 6)
		{
			deleteThisNode = node;
		}

		if (i == NODE_NUM - 1) {
			node->next = 0;
		}
		else
		{
			node->next = new LinkList_t;
			node->next->prev = node;
			node = node->next;
		}

	}

	RemoveNode(deleteThisNode);

	node = headList;

	while (node)
	{
		//cout << *(*(*node).data).value << endl;
		int* tmp = node->data->value;
		cout << *tmp << '\t';
		node = node->next;
	}

	return 0;
}