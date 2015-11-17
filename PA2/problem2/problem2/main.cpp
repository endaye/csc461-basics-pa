#include <new>
#include <stdio.h>
#include <string.h>
#include <math.h> 
#include "TestDataStruct_2.h"

#define NUM 3

void output(unsigned int *p, const unsigned int size_e, const unsigned int size_t, const char x)
{
	// size_t	: total size
	// size		: each struct or class size
	// size_e	: the sum size of elements in the struct or class
	// pad		: padding size
	// lines	: the number of output memory for each (maybe need to one more line when output)
	// q		: memory value
	// z[4]		: each byte value in q
	FILE * pFile;
	pFile = fopen("Output.txt", "a+");
	fprintf(pFile, "Test_%c:\n", x);
	unsigned int size = size_t / NUM;
	const unsigned int pad = size - size_e;
	const unsigned int tmp = size >> 2;
	const unsigned int lines = (size % 4 == 0 ? tmp : tmp + 1) * NUM;
	unsigned int q;
	unsigned int z[4];
	fprintf(pFile, "%d \tbytes total size\n", size_t / NUM);
	fprintf(pFile, "%d \tbytes padding\n", pad);

	for (int i = 0; i < lines; i++)
	{
		q = (unsigned int)*p;
		z[0] = q & 0xFF;
		z[1] = (q >> 8) & 0xFF;
		z[2] = (q >> 16) & 0xFF;
		z[3] = (q >> 24) & 0xFF;
		fprintf(pFile, "0x%08x:  %02x %02x %02x %02x,  %c %c %c %c \n", p, z[0], z[1], z[2], z[3], z[0], z[1], z[2], z[3]);
		p++;
	}

	fprintf(pFile, "\n");
	fclose(pFile);
}

void test_a()
{
	// Test A
	Test_A A[NUM];
	for (int i = 0; i < NUM; i++)
	{
		A[i].r = 'r';
		A[i].g = 'g';
		A[i].b = 'b';
	}
	const unsigned int size_e = (const unsigned int)(sizeof(A[0].r) + sizeof(A[0].g) + sizeof(A[0].b));
	output((unsigned int *)A, size_e, sizeof(A), 'A');

}

void test_b()
{
	// Test B;
	Test_B B[NUM];

	for (int i = 0; i < NUM; i++)
	{
		B[i].x = 0x78787878;
		B[i].y = 0x79797979;
	}
	const unsigned int size_e = (const unsigned int)(sizeof(B[0].x) + sizeof(B[0].y));
	output((unsigned int *)B, size_e, sizeof(B), 'B');
}

void test_c()
{
	Test_C C[NUM];
	output((unsigned int *)C, C[0].getSize4Each(), sizeof(C), 'C');
}

void test_d()
{
	Test_D D[NUM];
	output((unsigned int *)D, D[0].getSize4Each(), sizeof(D), 'D');
}

void test_e()
{
	Test_E E[NUM];
	for (int i = 0; i < NUM; i++)
	{
		E[i].p = 0;
		E[i].x = 0.0f;
		E[i].y = 0;
		E[i].a = 0;
		E[i].b = 0;
		E[i].c = 0;
	}
	const unsigned int size_e = (const unsigned int)(sizeof(E[0].p) + sizeof(E[0].x) + sizeof(E[0].y) + sizeof(E[0].a) + sizeof(E[0].b) + sizeof(E[0].c));
	output((unsigned int *)E, size_e, sizeof(E), 'E');
}

void test_f()
{
	Test_F F[NUM];
	for (int i = 0; i < NUM; i++)
	{
		F[i].a = 0;
		F[i].t = 0.0;
		F[i].s = 0.0f;
	}
	const unsigned int size_e = (const unsigned int)(sizeof(F[0].a) + sizeof(F[0].t) + sizeof(F[0].s));
	output((unsigned int *)F, size_e, sizeof(F), 'F');
}

void test_g()
{
	Test_G G[NUM];
	for (int i = 0; i < NUM; i++)
	{
		G[i].a = 0;
		G[i].s = 0.0f;
		G[i].t = 0.0;
	}
	const unsigned int size_e = (const unsigned int)(sizeof(G[0].a) + sizeof(G[0].t) + sizeof(G[0].s));
	output((unsigned int *)G, size_e, sizeof(G), 'G');
}

void test_h()
{
	Test_H H[NUM];
	for (int i = 0; i < NUM; i++)
	{
		H[i].a = 0;
		H[i].v1 = vect();
		H[i].c = 0;
		H[i].b = 0;
	}
	const unsigned int size_e = (const unsigned int)(sizeof(H[0].a) + sizeof(H[0].v1) + sizeof(H[0].c) + sizeof(H[0].b));
	output((unsigned int *)H, size_e, sizeof(H), 'H');
}

void test_i()
{
	Test_I I[NUM];
	output((unsigned int *)I, I[0].getSize4Each(), sizeof(I), 'I');
}

void test_j()
{
	Test_J J[NUM];
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < sizeof(J[i].name); j++)
		{
			J[i].name[j] = 0;
		}
		J[i].x = 0;
		J[i].z = 0;
		J[i].d = 0.0;
		J[i].p = 0;
		J[i].c = 0;
		J[i].y = 0.0f;
	}
	const unsigned int size_e = (const unsigned int)(sizeof(J[0].name) + sizeof(J[0].x) + sizeof(J[0].z)
		+ sizeof(J[0].d) + sizeof(J[0].p) + sizeof(J[0].c) + sizeof(J[0].y));
	output((unsigned int *)J, size_e, sizeof(J), 'J');
}

int main()
{

	char name[100] = "Yuancheng Zhang";
	FILE * pFile;
	pFile = fopen("Output.txt", "w");
	fprintf(pFile, "Problem %d\nby %s\n%d structions shown for each\n\n", 2, name, NUM);
	fclose(pFile);

	test_a();
	test_b();
	test_c();
	test_d();
	test_e();
	test_f();
	test_g();
	test_h();
	test_i();
	test_j();


	return 0;
}