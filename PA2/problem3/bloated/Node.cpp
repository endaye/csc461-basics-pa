
#include "bloated.h"
#include "Node.h"
#include <stdlib.h>
#include <new>


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

//====================================

HotNode::HotNode()
{
	pCold = new ColdNode();
}

void HotNode::copyData(OriginalNode *pOrig)
{
	this->copyInt(key, pOrig->key);
	this->copyInt(pCold->key, pOrig->key);
	this->copyFloat(pCold->x, pOrig->x);
	this->copyFloat(pCold->y, pOrig->y);
	this->copyFloat(pCold->z, pOrig->z);
	this->copyVect(pCold->A, pOrig->A);
	this->copyVect(pCold->B, pOrig->B);
	this->copyVect(pCold->C, pOrig->C);
	this->copyMatrix(pCold->MA, pOrig->MA);
	this->copyMatrix(pCold->MB, pOrig->MB);
	this->copyMatrix(pCold->MC, pOrig->MC);
	this->copyMatrix(pCold->MD, pOrig->MD);
	this->copyName(pCold->name, NAME_SIZE, pOrig->name);
}

void HotNode::setNext(HotNode * p)
{
	this->next = p;
}

void HotNode::setPrev(HotNode * p)
{
	this->prev = p;
}

HotNode * HotNode::getNext()
{
	return this->next;
}

HotNode * HotNode::getPrev()
{
	return this->prev;
}

void HotNode::copyFloat(float & var, float & in)
{
	var = in;
}

void HotNode::copyInt(int & var, int & in)
{
	var = in;
}

void HotNode::copyVect(Vect_t & var, Vect_t & in)
{
	var = in;
}

void HotNode::copyMatrix(Matrix_t & var, Matrix_t & in)
{
	var = in;
}

void HotNode::copyName(char * p, const int size, char * in)
{
	for (int i = 0; i < size; i++)
	{
		p[i] = in[i];
	}	
}
