#ifndef VECT4D_H
#define VECT4D_H

class Matrix;

class Vect4D
{
public:

	Vect4D()
		:x(0.0f), y(0.0f), z(0.0f), w(0.0f)
	{
	}

	Vect4D(const Vect4D &t)
		:x(t.x), y(t.y), z(t.z), w(t.w)
	{
	}

	Vect4D( float tx, float ty,  float tz,  float tw )
	{
		x = tx;
		y = ty;
		z = tz;
		w = tw;
	}


	~Vect4D()
	{
	}

	void operator = ( const Vect4D &tmp)
	{
		this->x = tmp.x;
		this->y = tmp.y;
		this->z = tmp.z;
		this->w = tmp.w;
	}

	void set( float xVal, float yVal, float zVal, float wVal )
	{
		this->x = xVal;
		this->y = yVal;
		this->z = zVal;
		this->w = wVal;
	}

	Vect4D operator + (const Vect4D &t) const
	{
		return Vect4D(this->x + t.x, this->y + t.y, this->z + t.z, this->w + t.w);
	}

	void operator += (const Vect4D &t)
	{
		this->x += t.x;
		this->y += t.y;
		this->z += t.z;
		this->w += t.w;
	}

	Vect4D operator - (const Vect4D &t) const
	{
		return Vect4D(this->x - t.x, this->y - t.y, this->z - t.z, this->w - t.w);
	}

	void operator -= (const Vect4D &t) 
	{
		this->x -= t.x;
		this->y -= t.y;
		this->z -= t.z;
		this->w -= t.w;
	}

	Vect4D operator * (const Vect4D &t) const
	{
		return Vect4D(this->x * t.x, this->y * t.y, this->z * t.z, this->w * t.w);
	};

	Vect4D operator * (const float s) const
	{
		return Vect4D(this->x * s, this->y * s, this->z * s, this->w * s);
	}

	void operator *= (const Vect4D &t)
	{
		this->x *= t.x;
		this->y *= t.y;
		this->z *= t.z;
		this->w *= t.w;
	}

	Vect4D operator / (const Vect4D &t) const
	{
		return Vect4D(this->x / t.x, this->y / t.y, this->z / t.z, this->w / t.w);
	}

	void operator /= (const Vect4D &t)
	{
		this->x /= t.x;
		this->y /= t.y;
		this->z /= t.z;
		this->w /= t.w;
	}
	
	Vect4D operator * ( const Matrix &m);

	float dot(const Vect4D &t )
	{
		return (this->x * t.x + this->y * t.y + this->z * t.z + this->w * t.w);
	}

public:
	float x;
	float y;
	float z;
	float w;

};

#endif



