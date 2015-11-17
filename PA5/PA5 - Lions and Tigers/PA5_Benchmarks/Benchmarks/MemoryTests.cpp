#include "output.h"
#include "Timer.h"


void inside_loop_original();


void MemStressTest()
{
	// Initialize timer
	timer::initTimer();

	// Create a timer objects
	timer t2;

	//******* Original Library ************************************************************

	// start timer
	t2.tic();

	for (int i = 0; i<10000; i++)
	{
		inside_loop_original();
	}

	// start timer
	t2.toc();

	
	fprintf(io::getHandle()," -----------Memory System------------\n\n");
	fprintf(io::getHandle(),"Memory Time: %f ms\n\n",t2.timeInSeconds()* 1000.0f );
}



void inside_loop_original()
{
	void *a0 = malloc( 0x100 );
	void *b0 = malloc( 0x200 );
	void *c0 = malloc( 0x300 );
	void *d0 = malloc( 0x1300 );
	void *e0 = malloc( 0x300 );
	void *f0 = malloc( 0x900 );
	void *g0 = malloc( 0x600 );

	void *a1 = malloc( 0x800 );
    void *b1 = malloc( 0x200 );
	void *c1 = malloc( 0x1300 );
	void *d1 = malloc( 0x500 );
	void *e1 = malloc( 0x200 );
	void *f1 = malloc( 0x700 );
	void *g1 = malloc( 0x300 );

	void *a2 = malloc( 0x100 );
    void *b2 = malloc( 0x200 );
	void *c2 = malloc( 0x1300 );
	void *d2 = malloc( 0x300 );
	void *e2 = malloc( 0x800 );
	void *f2 = malloc( 0x100 );
	void *g2 = malloc( 0x300 );

	void *a3 = malloc( 0x2200 );
    void *b3 = malloc( 0x200 );
	void *c3 = malloc( 0x1300 );
	void *d3 = malloc( 0x800 );
	void *e3 = malloc( 0x300 );
	void *f3 = malloc( 0x100 );
	void *g3 = malloc( 0x300 );

	free(a2);
	a2 = 0;
	free(b3);
	b3 = 0;
	free(c0);
	c0 = 0;
	free(d1);
	d1 = 0;

	a2 = malloc(0x200);
	b3 = malloc(0x500);
	c0 = malloc(0x200);
	d1 = malloc(0x180);

	free(a3);
	a3 = 0;

	void *p1 = malloc(0x180);
	void *p2 = malloc(0x80);
	void *p3 = malloc(0x180);
	void *p4 = malloc(0x80);
	void *p5 = malloc(0x180);

	free(a0);
	a0 = 0;
	free(a1);
	a1 = 0;
	free(f3);
	f3 = 0;
	free(g2);
	g2 = 0;
	free(g1);
	g1 = 0;

	void *s1 = malloc(0x180);
	void *s2 = malloc(0x80);
	void *s3 = malloc(0x180);
	void *s4 = malloc(0x80);
	void *s5 = malloc(0x180);
	void *s6 = malloc(0x80);
	void *s7 = malloc(0x180);	
	void *s8 = malloc(0x80);
	void *s9 = malloc(0x180);
	void *s10 = malloc(0x80);
	void *s11 = malloc(0x180);
	void *s12 = malloc(0x80);
	void *s13 = malloc(0x180);

	void *s14 = malloc(0x500);
	void *s15 = malloc(0x1180);
	void *s16 = malloc(0x200);
	void *s17 = malloc(0x280);
	void *s18 = malloc(0x80);

	free(s1);
	free(c2);
	free(d3);
	free(b3);
	free(d2);
	free(g0);
	free(a2);
	free(c1);

	free(d1);
	free(d0);
	free(s2);
	free(f2);
	free(b1);
	free(e1);

	free(e3);
	free(f0);
	free(g3);
	free(e2);

	free(s18);
	free(s17);
	free(s16);
	free(c3);
	free(s12);
	free(s10);
	free(b2);
	free(s8);
	free(s6);
	free(e0);
	free(s5);
	free(s3);
	free(c0);
	free(s4);
	free(s7);
	
	free(s9);
	free(s11);
	free(s13);
	free(s14);
	free(s15);

	free(p1);
	free(p3);
	free(b0);
	free(p5);
	free(p4);
	free(f1);
	free(p2);
	
	void *pp = malloc(0x200);
	free(pp);
}