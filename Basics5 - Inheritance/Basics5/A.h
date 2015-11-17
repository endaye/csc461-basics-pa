#ifndef A_H
#define A_H

#include "bufferManager.h"

// Rules:

// FIX class A to prevent the memory leak in the unit tests
// You may not touch class B 
// Only modify class A

class A
{
public:
	A()
	: x(5)
	{
	}
	
	virtual ~A()
	{
	}

	int getX()
	{
		return this->x;
	}
private:
	int x;
	int *buffer;
};

class B : public A
{
public:
	B()
	: y(33)
	{
		this->buffer = new int[100];
		bufferManager::getInstance()->increment();
	}

	~B()
	{
		delete[] this->buffer;
		bufferManager::getInstance()->decrement();
	}


private:
	int y;
	int *buffer;
};





#endif