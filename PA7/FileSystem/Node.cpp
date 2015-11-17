#include <stdlib.h>

#include "List.h"
#include "Node.h"
#include "output.h"

Node::Node()
  
{
	this->getRandInt(x);
	this->getRandInt(y);
	this->getRandInt(z);
	this->getRandInt(key);
}


void Node::setNext(Node * p)
{
	this->next = p;
}

void Node::setPrev(Node * p)
{
	this->prev = p;
}

Node * Node::getNext()
{
	return this->next;
}

Node * Node::getPrev()
{
	return this->prev;
}



void Node::getRandInt(int & var)
{
	int high = rand();
	int low = rand();
	var = high << 16 | low;
}

void Node::setKey( unsigned int in)
{
   this->key = in;
}

void Node::dumpNode()
{
   fprintf(io::getHandle(),"   Node Addr: 0x%p\n", this);
   fprintf(io::getHandle(),"        next: 0x%p\n", this->next);
   fprintf(io::getHandle(),"        prev: 0x%p\n", this->prev);
   fprintf(io::getHandle(),"           x: 0x%x\n", this->x);
	fprintf(io::getHandle(),"           y: 0x%x\n", this->y);
	fprintf(io::getHandle(),"           z: 0x%x\n", this->z);
	fprintf(io::getHandle(),"         key: 0x%x\n\n", this->key);
}