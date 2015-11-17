#ifndef A_H
#define A_H

// Do not change these classes,
// Feel free to add debug information, 
// but do not rearrange!

class A
{
public:
	A()
	: x(5), y(6)
	{
		// Label:  0xa000
	}
	

	virtual int weight() = 0;
	virtual int max() = 0;
	virtual int min() = 0;

	int getX()
	{	
		// Label:  0xa001
		return this->x;
	}

	int getY()
	{
		// Label:  0xa002
		return this->y;
	}

	~A()
	{
		// Label:  0xa003
	}

protected:
	int x;
	int y;
};

class B : public A
{
public:
	B()
	: z(7)
	{
		// Label:  0xa004
	}

	int weight( )
	{
		// Label:  0xa005
		int sum = this->x + this->y + this->z;
		return (sum);
	}

	int max()
	{
		// Label:  0xa006
		int maxVal = this->x;

		if( this->x > this->y )
		{
			if( this->z > this->x )
			{
				maxVal = this->z;
			}
			else
			{
				maxVal = this->x;
			}
		}
		else
		{  // y >= x
			if( this->y > this->z )
			{
				maxVal = y;
			}
			else
			{
				maxVal = this->z;
			}
		}
		return maxVal;
	}

	int min()
	{
		// Label:  0xa007
		int minVal = this->x;

		if( this->x < this->y )
		{
			if( this->z < this->x )
			{
				minVal = this->z;
			}
			else
			{
				minVal = this->x;
			}
		}
		else
		{  // y <= x
			if( this->y < this->z )
			{
				minVal = y;
			}
			else
			{
				minVal = this->z;
			}
		}
		return minVal;
	}

	int getZ()
	{
		// Label:  0xa008
		return this->z;
	}

	~B()
	{
		// Label:  0xa009
	}


private:
	int z;

};





#endif