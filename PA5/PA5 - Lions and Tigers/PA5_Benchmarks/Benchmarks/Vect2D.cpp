#include "Vect2D.h"

Vect2D Vect2D::operator + ( const Vect2D &tmp ) const
	{
		Vect2D sum;

		sum.x = this->x + tmp.x;
		sum.y = this->y + tmp.y;

		return ( sum );
	};

	Vect2D Vect2D::operator - ( const Vect2D &tmp ) const
	{
		Vect2D sum;

		sum.x = this->x - tmp.x;
		sum.y = this->y - tmp.y;

		return ( sum );
	};

	Vect2D Vect2D::operator * ( const float scale ) const
	{
		Vect2D tmp;

		tmp.x = tmp.x * scale;
		tmp.y = tmp.y * scale;

		return ( tmp );
	};

	Vect2D Vect2D::operator / ( const float scale ) const
	{
		Vect2D tmp;

		tmp.x = x / scale;
		tmp.y = y / scale;

		return ( tmp );
	};

