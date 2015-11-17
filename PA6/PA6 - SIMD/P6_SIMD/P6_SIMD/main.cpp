// main.cpp : Defines the entry point for the console application.
//

#include "Timer.h"
#include "output.h"
#include "UnitTest.h"

#include "Vect4D_SIMD.h"
#include "test.h"
#include "Vect4D.h"
#include "matrix.h"
#include "Matrix_SIMD.h"
#include "LERP.h"
#include "LERP_SIMD.h"

#ifdef _DEBUG
	#define FACTOR 1
#else
	#define FACTOR 10
#endif

int main()
{
	io::create("Yuancheng Zhang");

	// Leave the following functions allow
	// DO NOT reorder them
        // Any modification to unit test is an academic violation
        // all unit tests need to pass, for the test to run
	UnitTest_platform_init();

	const int numFailures = UnitTest_platform_runTests();
	
	UnitTest_platform_exit();

	
	// Performance tests
	printf("\nPerformance tests: Begin()\n");

	if( numFailures == 0 )
	{
		timer::initTimer();
		timer t8, t7,t6,t5,t4,t3,t2,t1;

		// --------------- VECT 4D ----------------------------------------------

		Vect4D x;
		fprintf(io::getHandle(),"---------- Vect4D ----------------\n");
		printf("                 : Vect4D\n");
		t2.tic();
		for( int j = 0; j < 6000000 * FACTOR; j++)
		{
			x = test();
		}
		t2.toc();

		// --------------- VECT 4D SIMD ----------------------------------------------

		x;
		fprintf(io::getHandle(),"  Vect4D Orig: %f  \n",t2.timeInSeconds());
		printf("                 : Vect4D_SIMD\n");
		Vect4D_SIMD x_SIMD;
		t1.tic();
		for( int i = 0; i < 6000000* FACTOR; i++)
		{
			x_SIMD = test_simd();
		}
		t1.toc();
		x_SIMD;

		fprintf(io::getHandle(),"  Vect4D_SIMD: %f\n",t1.timeInSeconds());
		fprintf(io::getHandle(),"       Faster: %f\n",t2.timeInSeconds()/t1.timeInSeconds() );

		// --------------- MATRIX ----------------------------------------------

		fprintf(io::getHandle(),"\n\n---------- Matrix ----------------\n");
			printf("                 : Matrix\n");
		Vect4D y;
		t3.tic();
		for( int k = 0; k < 1000* FACTOR; k++)
		{
			y = matrix_test();
		}
		t3.toc();
		y;

		// --------------- Matrix SIMD ----------------------------------------------

		fprintf(io::getHandle(),"  Matrix Orig: %f\n",t3.timeInSeconds());
		printf("                 : Matrix_SIMD\n");
		Vect4D_SIMD y_SIMD;
		t4.tic();
		for( int k = 0; k < 1000* FACTOR; k++)
		{
			y_SIMD = matrix_SIMD_test();
		}
		t4.toc();
		y_SIMD;

		fprintf(io::getHandle(),"  Matrix SIMD: %f\n",t4.timeInSeconds());
		fprintf(io::getHandle(),"       Faster: %f\n",t3.timeInSeconds()/t4.timeInSeconds());

		// --------------- Vect * Matrix ----------------------------------------------

		fprintf(io::getHandle(),"\n\n---------- Vect * Matrix ----------------\n");
		printf("                 : Vect * Matrix\n");
		t5.tic();
		for( int k=0; k<10000* FACTOR; k++)
		{
			Vect4D C = vectMultMatrix_test();
		}
		t5.toc();

		// --------------- Vect * Matrix (SIMD) ----------------------------------------------

		fprintf(io::getHandle(),"  Vect*Matrix Orig: %f\n",t5.timeInSeconds());
		printf("                 : Vect * Matrix (SIMD)\n");
		t6.tic();
		for( int k=0; k<10000* FACTOR; k++)
		{
			Vect4D_SIMD C = vectMultMatrix_SIMD_test();
		}
		t6.toc();
		fprintf(io::getHandle(),"  Vect*Matrix_SIMD: %f\n",t6.timeInSeconds());
		fprintf(io::getHandle(),"            Faster: %f\n",t5.timeInSeconds()/t6.timeInSeconds());

		// --------------- LERP ----------------------------------------------

		fprintf(io::getHandle(),"\n\n---------- LERP ----------------\n");
		printf("                 : LERP\n");
		Vect4D LERP_C;
		t7.tic();
		for( int k=0; k<1000000* FACTOR; k++)
		{
			LERP_C = LERP_Tests();
		}
		t7.toc();
		LERP_C;
		printf(" %f %f %f %f\n",LERP_C.x,LERP_C.y,LERP_C.z,LERP_C.w);
		fprintf(io::getHandle(),"  LERP Orig: %f\n",t7.timeInSeconds());

		// --------------- LERP SIMD ----------------------------------------------

		printf("                 : LERP SIMD\n");
		Vect4D_SIMD LERP_SIMD_C;
		t8.tic();
		for( int k=0; k<1000000* FACTOR; k++)
		{
			LERP_SIMD_C = LERP_SIMD_Tests();
		}
		t8.toc();
		LERP_SIMD_C;
		printf(" %f %f %f %f\n",LERP_SIMD_C.x,LERP_SIMD_C.y,LERP_SIMD_C.z,LERP_SIMD_C.w);
		fprintf(io::getHandle(),"  LERP SIMD: %f\n",t8.timeInSeconds());
		fprintf(io::getHandle(),"     Faster: %f\n",t7.timeInSeconds()/t8.timeInSeconds());

		printf("Performance tests: done() \n\n");

	}
	
	return( numFailures );



}

