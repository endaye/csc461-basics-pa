#ifndef MIDDLEWARE_NATIVE_H
#define MIDDLEWARE_NATIVE_H

// This is a mockup of a middleware class
// Too many functions and/or incorrect were provided to the End User

// See Wrapper.h to fix

// Do not modify any lines of Vect2D_Native

class Vect2D_Native
{
public:
	Vect2D_Native()
	: x(22.0f), y(33.0f)
	{
		id++ ;
	}

	void setX( float val )
	{
		this->x = val;
	}

	void setY( float val )
	{
		this->y = val;
	}

	float getX( )
	{
		return this->x;
	}

	float getY()
	{
		return this->y;
	}

	void setID( int val )
	{
		this->id = val;
	}

	int getID(  )
	{
		return this->id;
	}

	// Data:
	//       - Yes its public (that's the problem)
	float x;
	float y;
	static int id;
};

#endif