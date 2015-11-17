#ifndef PA3_A_H
#define PA3_A_H

class Vect
{
public:
	//*********************************************************************
	// The Givens:  Always define these four
	//*********************************************************************

		// default constructor
		Vect()
			: x(0.0f), y(0.0f), z(0.0)
		{
		};

		// copy constructor
		Vect( const Vect &tmp)
			: x(tmp.x), y(tmp.y), z(tmp.z)
		{
		};

		// assignment vector
		const Vect & operator = (const Vect &tmp )
		{
			this->x = tmp.x;
			this->y = tmp.y;
			this->z = tmp.z;

			return *this;
		};

		// destructor
		~Vect()
		{
		};

	//*********************************************************************
	// Methods and operators that have take implicit conversions
	// These are the functions you need to prevent implicit conversion:
	//*********************************************************************

	// overload constructor
	Vect( const float inX, const float inY, const float inZ )
		: x(inX), y(inY), z(inZ)
	{
	};

	// set functions
	void setX( const float inX )
	{
		this->x = inX;
	};
	

	void setY( const float inY )
	{
		this->y = inY;
	};
	
	void setZ( const float inZ )
	{
		this->z = inZ;
	};
	
	void set(const float inX, const float inY, const float inZ)
	{
		this->x = inX;
		this->y = inY;
		this->z = inZ;
	};

	float getX()
	{
		return this->x;
	};

	float getY()
	{
		return this->y;
	};

	float getZ()
	{
		return this->z;
	};

	Vect operator + (const Vect tmp ) const
	{
		return ( Vect(this->x + tmp.x, this->y + tmp.y, this->z + tmp.z ) );

	}


private:
	float x;
	float y;
	float z;

	template <typename T> void setX(T);
	template <typename T> void setY(T);
	template <typename T> void setZ(T);
	template <typename T, typename S, typename V> void set(T, S, V);
};

#endif