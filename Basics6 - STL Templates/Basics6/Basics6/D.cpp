#include "output.h"
#include <vector>
#include <algorithm>

struct Vect
{
	int a;
	int b;
	int c;
};

Vect V[] =
{
	{ 3, 5, 6 },
	{ 6, 5, 3 },
	{ 3, 4, 7 },
	{ 7, 2, 5 },
	{ 1, 3, 5 },
	{ 3, 2, 5 },
	{ 2, 3, 4 },
	{ 3, 5, 5 },
	{ 7, 3, 2 },
	{ 4, 3, 2 },
	{ 1, 7, 1 }
};

bool cmpVect(Vect t1, Vect t2)
{
	if (t1.a != t2.a)
	{
		return (t1.a < t2.a);
	}
	else if (t1.b != t2.b)
	{
		return (t1.b < t2.b);
	}
	else
	{
		return (t1.c < t2.c);
	}
}

void Problem_4()
{
	// create file
	io::create("Yuancheng Zhang", "problem4.txt");


	// Original data

	Vect *p = &V[0];
	fprintf(io::getHandle(), "original\n");
	for (int i = 0; i < 11; i++)
	{
		fprintf(io::getHandle(), "        V[%2d]: %d  %d  %d \n", i, p->a, p->b, p->c);
		p++;
	}

	// a) Load the V[] data into a vector
	//    print it to the file (begin to end) order
	std::vector<Vect> Vect_V(V, V + 11);
	std::vector<Vect>::iterator it = Vect_V.begin();
	int i = 0;
	fprintf(io::getHandle(), "\nstl: vector\n");
	for (; it < Vect_V.end(); ++it, i++)
	{
		fprintf(io::getHandle(), "        V[%2d]: %d  %d  %d \n", i, it->a, it->b, it->c);
	}

	// b) Sort the new STL vector with strict weak ordering
	//    print it to the file (begin to end) order
	i = 0;
	fprintf(io::getHandle(), "\nstl: strict weak ordering\n");
	std::sort(Vect_V.begin(), Vect_V.end(), cmpVect);
	for (it = Vect_V.begin(); it < Vect_V.end(); ++it, i++)
	{
		fprintf(io::getHandle(), "        V[%2d]: %d  %d  %d \n", i, it->a, it->b, it->c);
	}

	// bye bye
	fprintf(io::getHandle(), "\n");
	io::destroy();
}