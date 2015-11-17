#ifndef VECT2D_H
#define VECT2D_H

class Vect2D
{
public:

	// default constructor
	Vect2D()
		: x(0.0f), y(0.0f)
	{
	};

	Vect2D( float a, float b)
	: x(a),y(b)
	{
	};

	Vect2D( const Vect2D &tmp)
		: x(tmp.x),y(tmp.y)
	{
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


	Vect2D operator + ( const Vect2D &tmp ) const;
	Vect2D operator - ( const Vect2D &tmp ) const;
	Vect2D operator * ( const float scale ) const;
	Vect2D operator / ( const float scale ) const;


private:
	float x;
	float y;

};

#endif