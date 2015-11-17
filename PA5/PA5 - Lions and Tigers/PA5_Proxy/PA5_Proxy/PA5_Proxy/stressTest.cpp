#include "PA5_C.h"


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

	Vect2D E;
	E.set(v3, -v5);
	
	Vect2D sum;
	sum.set(0.0f, 0.0f);
	
	sum = A + B + C + D + E;
	
	volatile Vect2D F = sum;

	Vect2D A1;

	Vect2D B1;
	B1.setX(v4);
	B1.setY(v5);

	Vect2D C1;
	C1.set(v2,v7);

	Vect2D D1;
	D1.set(v3, v1);

	Vect2D E1;
	E1.set(v5, -v2);

	Vect2D sum2;
	sum2.set(0.0f, 0.0f);

	sum2 = A + B + C + D + E;
	volatile Vect2D G = sum2;

}