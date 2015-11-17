
#include "bloated.h"
#include "Node.h"
#include <stdlib.h>


OriginalNode::OriginalNode()
{
	this->getRandFloat(x);
	this->getRandFloat(y);
	this->getRandFloat(z);
	this->getRandVect(A);
	this->getRandVect(B);
	this->getRandVect(C);
	this->getRandMatrix(MA);
	this->getRandMatrix(MB);
	this->getRandMatrix(MC);
	this->getRandMatrix(MD);
	this->getRandName(name, NAME_SIZE);
	this->getRandInt(key);
	
}


void OriginalNode::setNext(OriginalNode * p)
{
	this->next = p;
}

void OriginalNode::setPrev(OriginalNode * p)
{
	this->prev = p;
}

OriginalNode * OriginalNode::getNext()
{
	return this->next;
}

OriginalNode * OriginalNode::getPrev()
{
	return this->prev;
}

void OriginalNode::getRandFloat(float & var)
{
	float real = static_cast<float> (rand());
	float decimal = static_cast< float > (rand());
	var = real + (decimal / RAND_MAX);
}

void OriginalNode::getRandInt(int & var)
{
	int high = rand();
	int low = rand();
	var = high << 16 | low;
}

void OriginalNode::getRandVect(Vect_t & var)
{
	this->getRandFloat(var.x);
	this->getRandFloat(var.y);
	this->getRandFloat(var.z);
}

char  OriginalNode::getRandChar()
{
	char var = static_cast<char> (rand() % 256);
	return var;
}

void OriginalNode::getRandMatrix(Matrix_t & var)
{
	this->getRandFloat(var.m00);
	this->getRandFloat(var.m01);
	this->getRandFloat(var.m02);
	this->getRandFloat(var.m03);

	this->getRandFloat(var.m10);	
	this->getRandFloat(var.m11);	
	this->getRandFloat(var.m12);	
	this->getRandFloat(var.m13);	
	
	this->getRandFloat(var.m20);	
	this->getRandFloat(var.m21);
	this->getRandFloat(var.m22);
	this->getRandFloat(var.m23);

	this->getRandFloat(var.m30);
	this->getRandFloat(var.m31);
	this->getRandFloat(var.m32);
	this->getRandFloat(var.m33);
}

void OriginalNode::getRandName(char * p, const int size)
{
	for( int i = 0; i<size; i++)
	{
		*p++ = this->getRandChar();
	}
}