#ifndef WRAPPER_H
#define WRAPPER_H

#include "MiddlewareNative.h"

// For this problem, you are wrapping a poor interface provided by the middleware vendors
// Feel free to modify and add to this class

// The class needs to derive privately from Vect2D_Native

// Requirements:

// 1) variables:  x, y should be private
// 2) prevent methods setID() and getID() from being called
// 3) Rework getX() and getY() to take float references
// 4) prevent the original getX() and getY() from being called
// 5) allow setX() and setY() to be called as is.

// The unit test has a section that is #if 0 - toggle it to make sure your code is producing the correct errors

class GameVect: private Vect2D_Native
{
public:
	GameVect()
		: Vect2D_Native()
	{
		this->x = Vect2D_Native::getX();
		this->y = Vect2D_Native::getY();
	}

	void getX(float & val)
	{
		val = this->x;
	}

	void getY(float & val)
	{
		val = this->y;
	}

	void setX(float val)
	{
		this->x = val;
	}

	void setY(float val)
	{
		this->y = val;
	}

private:
	float x;
	float y;

	float getX()
	{
		return this->x;
	}

	float getY()
	{
		return this->y;
	}

	void setID(int val)
	{
		this->id = val;
	}

	int getID()
	{
		return this->id;
	}
};


#endif