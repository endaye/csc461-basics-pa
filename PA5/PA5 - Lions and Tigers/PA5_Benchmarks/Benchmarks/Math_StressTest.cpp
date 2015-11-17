#include "Vect2D.h"
#include "output.h"
#include "Timer.h"

void StressTest();

void MathStressTest()
{
	// Create a timer objects
	timer t1;

	// start timer
	t1.tic();

	for (int i = 0; i < 5000000; i++)
	{
	   StressTest();
	}

	// stop timer
	t1.toc();

	fprintf(io::getHandle()," -----------Math Test------------\n\n");
	fprintf(io::getHandle(),"Math test: %f ms\n", t1.timeInSeconds()* 1000.0f );

}


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

	volatile Vect2D F = A;




}