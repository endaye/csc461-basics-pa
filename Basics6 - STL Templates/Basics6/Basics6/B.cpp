#include "output.h"
#include <list>


int B[] =
{
	66,
	77,
	33,
	22,
	88,
	11,
	99,
	44
};


void Problem_2()
{
	// create file
	io::create("Yuancheng Zhang", "problem2.txt");

	// Original data

	int *p = &B[0];
	fprintf(io::getHandle(), "original\n");
	for (int i = 0; i < 8; i++)
	{
		fprintf(io::getHandle(), "        B[%2d]: %d   \n", i, *p++);
	}

	// a) Load the B[] data into a list
	//    print it to the file (begin to end) order
	std::list<int> List_B(B, B + 8);
	fprintf(io::getHandle(), "\nstl: init list \n");
	int i = 0;
	for (std::list<int>::iterator it = List_B.begin(); it != List_B.end(); ++it, i++)
	{
		fprintf(io::getHandle(), "        List_B[%d]: %d   \n", i, *it);
	}

	// b) Insert the number '55' between 22 and 88
	//    No brute force, assume there are 1000000 numbers before 22 and after 88.
	//    No iterative, simple approach, use the appropriate STL calls for efficency.
	//    print it to the file (begin to end) order
	int prevVal = 0;
	i = 0;
	for (std::list<int>::iterator it = List_B.begin(); it != List_B.end(); ++it, i++)
	{
		if (*it == 88 && prevVal == 22)
		{
			List_B.insert(it, 55);
		}
		prevVal = *it;

	}
	i = 0;
	fprintf(io::getHandle(), "\nstl: insert '55' into list (between 22 and 88)\n");
	for (std::list<int>::iterator it = List_B.begin(); it != List_B.end(); ++it, i++)
	{
		fprintf(io::getHandle(), "        List_B[%d]: %d   \n", i, *it);
	}
	// c) sort the list in reverse order using the built in functional functions
	//    print it to the file (begin to end) order

	List_B.sort();
	List_B.reverse();
	i = 0;
	fprintf(io::getHandle(), "\nstl: sort list in reverse order using built in function \n");
	for (std::list<int>::iterator it = List_B.begin(); it != List_B.end(); ++it, i++)
	{
		fprintf(io::getHandle(), "        List_B[%d]: %d   \n", i, *it);
	}

	// bye bye
	fprintf(io::getHandle(), "\n");
	io::destroy();
}