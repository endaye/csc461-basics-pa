#include "PA5_B.h"

Vect2D Vect2D::operator + ( const Vect2D &tmp ) const
{
	return Vect2D(this->x + tmp.x, this->y + tmp.y);
};
 
Vect2D Vect2D::operator - ( const Vect2D &tmp ) const
{
	return Vect2D(this->x - tmp.x, this->y - tmp.y);
};

Vect2D Vect2D::operator * ( const float scale ) const
{
	return Vect2D(x * scale, y * scale);
};

Vect2D Vect2D::operator / ( const float scale ) const
{
	return Vect2D(x / scale, y / scale);
};

