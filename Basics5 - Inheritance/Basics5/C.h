#ifndef C_H
#define C_H

// Rules: 

// Cannot change anything in Class C
// Modify Class D's constructor to pass the class

class C
{
public:
	C()
	: x(33), y(44)
	{
	}

	C( int valX, int valY)
	: x(valX), y(valY)
	{
	}

	int getX()
	{
		return this->x;
	}

	int getY()
	{
		return this->y;
	}

private:
	int x;
	int y;
};


class D : public C
{
public:
	D()
	: z(55)
	{
	}

	D( int xVal, int yVal, int zVal )
	: C(xVal, yVal), z(zVal)
	{
	}

	int getZ()
	{
		return this->z;
	}
private:
	int z;

};

#endif