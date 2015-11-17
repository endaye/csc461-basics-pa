#include "PA5_B.h"


void StressTest( void )
{
	volatile float v1 = 2.0f;
	volatile float v2 = 3.0f;
	volatile float v3 = 7.0f;
	volatile float v4 = -5.0f;
	volatile float v5 = 9.0f;	
	volatile float v6 = 4.0f;
	volatile float v7 = 22.23f;
	volatile float v8 = 0.234f;


	Vect2D A;

	Vect2D B;
	B.setX(v1);
	B.setY(v2);

	Vect2D C;
	C.set(v3,v4);

	Vect2D D;
	D.set(v5, v6);

	Vect2D sum;

	sum = A + B + C + D;

	Vect2D ScaledA = B * v7;
    Vect2D ScaledB = C / v8;
	Vect2D DiffVect = ScaledB - ScaledA;

	sum.setX( v1 );
	ScaledA.setX( v3 );
	DiffVect.setX( v7 );

	A = sum + ScaledA;
	B = DiffVect - C;
	D = DiffVect / ScaledA.getY();

	A = B + C;
	A = A - B - C;
	A = A * v4;
	A = A / v5;

		A = B + C;
	A = A - B - C;
	A = A * v4;
	A = A / v5;

		A = B + C;
	A = A - B - C;
	A = A * v4;
	A = A / v5;
	
	volatile Vect2D F = A;




}