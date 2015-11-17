// Vect4D.h
//
// This is a 4 dimensional Vect4D class
#ifndef Vect4D_H
#define Vect4D_H

// includes
#include "Enum.h"

// Foward Declarations
class Matrix;

// class
class Vect4D
{
public:
	friend class Matrix;

	Vect4D();	
	Vect4D( double tx, double ty, double tz, double tw = 1.0f );
	~Vect4D();

	void norm( Vect4D &out );
	void set( double tx, double ty, double tz, double tw = 1.0f);
	
	Vect4D operator + ( Vect4D t );
	Vect4D operator - ( Vect4D t );
	Vect4D operator * ( double scale );

	void Cross(Vect4D &vin, Vect4D &vout);

	double &operator[]( VECT_ENUM e);


private:
	double x;
	double y;
	double z;
	double w;
};

#endif  //Vect4D.h
