#include <stdio.h>
#include <math.h>
#include "Timer.h"
#include "GlobalTimer.h"

#define LEN 8000

float InvSqrt(float x)
{
	float xhalf = 0.5f*x;
	int i = *(int*)&x; // get bits for floating value
	i = 0x5f375a86 - (i >> 1); // gives initial guess y0
	x = *(float*)&i; // convert bits back to float
	x = x*(1.5f - xhalf*x*x); // Newton step, repeating increases accuracy
	return x;
}

float SqrtOpt(float x)
{
	float xhalf = 0.5f * x;
	int i = *(int*)&x; // get bits for floating value
	i = 0x5f375a86 - (i >> 1); // gives initial guess y0
	x = *(float*)&i; // convert bits back to float
	x = x * (1.5f - xhalf * x * x); // Newton step, repeating increases accuracy
	return 1.0f / x; // return sqrt root
}

void SqrtOptR(float x, float &out)
{
	out = 0.5f * x;
	int i = *(int*)&x; // get bits for floating value
	i = 0x5f375a86 - (i >> 1); // gives initial guess y0
	x = *(float*)&i; // convert bits back to float
	out = 1.0f / (x * (1.5f - out * x * x)); // Newton step, repeating increases accuracy
}

int main()
{
	// intialization
	srand(1);
	float a[LEN];
	float b[LEN];
	float c[LEN];
	for (int i = 0; i < LEN; i++)
	{
		a[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 100));
		// printf("%f ", a[i]);
	}

	// test result
	for (int i = 0; i < 20; i++)
	{
		b[i] = sqrtf(a[i]);
		c[i] = SqrtOpt(a[i]);
		printf("%2d: %f \t %f \t %f\n", i, a[i], b[i], c[i]);
	}

	// Initialize timer
	timer::initTimer();

	// Create a global Timer
	globalTimer::create();

	// Create a timer objects
	timer sqrtTimer;
	timer invSqrtTimer;

	sqrtTimer.tic();
	for (int k = 0; k < LEN; k++)
	{
		for (int i = 0; i < LEN; i++)
		{
			b[i] = sqrtf(a[i]);
		}
	}
	sqrtTimer.toc();

	invSqrtTimer.tic();
	for (int k = 0; k < LEN; k++)
	{
		for (int i = 0; i < LEN; i++)
		{
			c[i] = SqrtOpt(a[i]);
		}
	}
	invSqrtTimer.toc();

	float sqrtTime = sqrtTimer.timeInSeconds();
	float invSqrtTime = invSqrtTimer.timeInSeconds();

	printf("  sqrtf(): %f ms\nInvSqrt(): %f ms\ndifferent: %.2fx\n", sqrtTime * 1000.0f, invSqrtTime * 1000.0f, invSqrtTime / sqrtTime);

	return 1;
}

