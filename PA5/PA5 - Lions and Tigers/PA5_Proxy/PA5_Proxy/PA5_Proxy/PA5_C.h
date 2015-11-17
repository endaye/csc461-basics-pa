#ifndef PA3_C_H
#define PA3_C_H

#define PROXY_ENABLE 1  // use this toggle to flip back and forth with your proxies

class Vect2D
{
public:

	// default constructor
	Vect2D()
		: x(0.0f), y(0.0f)
	{
	};
	
	// customized constructor
	Vect2D(const float xVal, const float yVal)
		:x(xVal), y(yVal)
	{
	};

	// copy constructor
	Vect2D(const Vect2D &t)
		:x(t.x), y(t.y)
	{};

	// assignment vector
	const Vect2D & operator = (const Vect2D &t)
	{
		this->x = t.x;
		this->y = t.y;
		return *this;
	}

	// destructor
	~Vect2D()
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

	void set( const float inX, const float inY )
	{
		this->x = inX;
		this->y = inY;
	};

	float getX()
	{
		return this->x;
	};

    float getY()
	{
		return this->y;
	};

	float x;
	float y;
};

struct VaddV
{
	const Vect2D &v1;
	const Vect2D &v2;

	VaddV(const Vect2D &t1, const Vect2D &t2)
		: v1(t1), v2(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x,
			v1.y + v2.y);
	}
};

inline VaddV operator + (const Vect2D &t1, const Vect2D &t2)
{
	return VaddV(t1, t2);
}


struct VaddVaddV
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;

	VaddVaddV(const VaddV &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x,
			v1.y + v2.y + v3.y);
	}
};

inline VaddVaddV operator + (const VaddV &t1, const Vect2D &t2)
{
	return VaddVaddV(t1, t2);
};

struct VaddVaddVaddV
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;
	const Vect2D &v4;

	VaddVaddVaddV(const VaddVaddV &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x,
			v1.y + v2.y + v3.y + v4.y);
	}
};

inline VaddVaddVaddV operator + (const VaddVaddV &t1, const Vect2D &t2)
{
	return VaddVaddVaddV(t1, t2);
};

struct VaddVaddVaddVaddV
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;
	const Vect2D &v4;
	const Vect2D &v5;

	VaddVaddVaddVaddV(const VaddVaddVaddV &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4), v5(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x,
			v1.y + v2.y + v3.y + v4.y + v5.y);
	}
};

inline VaddVaddVaddVaddV operator + (const VaddVaddVaddV &t1, const Vect2D &t2)
{
	return VaddVaddVaddVaddV(t1, t2);
};


#endif