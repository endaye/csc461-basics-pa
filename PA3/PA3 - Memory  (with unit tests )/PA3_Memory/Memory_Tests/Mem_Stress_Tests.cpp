#include "output.h"
#include "mem.h"
#include "Timer.h"

void inside_loop();
void inside_loop_original();


void MemStressTest()
{
	io::create("<your name>", "Mem_StressTest_PA3.txt");

	// Initialize timer
	timer::initTimer();

	// Create a timer objects
	timer t1,t2;

	//******* Original Library ************************************************************

	// start timer
	t2.tic();

	for (int i = 0; i<10000; i++)
	{
		inside_loop_original();
	}

	// start timer
	t2.toc();

	fprintf(io::getHandle(),"      Mem Lib: stress test: %f ms \n",t2.timeInSeconds()*1000.0f);

	//******** Custom Library *********************************************************

	// start timer
	t1.tic();

	memSystem mem;
	mem.InitializeSystem();

	for (int i = 0; i<10000; i++)
	{
		inside_loop();
	}

	// stop timer
	t1.toc();


	fprintf(io::getHandle(),"Custom Memory: stress test: %f ms \n",t1.timeInSeconds()*1000.0f);

	fprintf(io::getHandle(),"              times faster: %f \n",t2.timeInSeconds()/t1.timeInSeconds());


	io::destroy();
}


void inside_loop()
{

 	memSystem mem;
	mem.InitializeSystem();
	
	void *a0 = mem.Malloc( 0x100 );
	void *b0 = mem.Malloc( 0x200 );
	void *c0 = mem.Malloc( 0x300 );
	void *d0 = mem.Malloc( 0x1300 );
	void *e0 = mem.Malloc( 0x300 );
	void *f0 = mem.Malloc( 0x900 );
	void *g0 = mem.Malloc( 0x600 );

	void *a1 = mem.Malloc( 0x800 );
	void *b1 = mem.Malloc( 0x200 );
	void *c1 = mem.Malloc( 0x1300 );
	void *d1 = mem.Malloc( 0x500 );
	void *e1 = mem.Malloc( 0x200 );
	void *f1 = mem.Malloc( 0x700 );
	void *g1 = mem.Malloc( 0x300 );

	void *a2 = mem.Malloc( 0x100 );
	void *b2 = mem.Malloc( 0x200 );
	void *c2 = mem.Malloc( 0x1300 );
	void *d2 = mem.Malloc( 0x300 );
	void *e2 = mem.Malloc( 0x800 );
	void *f2 = mem.Malloc( 0x100 );
	void *g2 = mem.Malloc( 0x300 );

	void *a3 = mem.Malloc( 0x2200 );
	void *b3 = mem.Malloc( 0x200 );
	void *c3 = mem.Malloc( 0x1300 );
	void *d3 = mem.Malloc( 0x800 );
	void *e3 = mem.Malloc( 0x300 );
	void *f3 = mem.Malloc( 0x100 );
	void *g3 = mem.Malloc( 0x300 );

	// Every allocation should be real value pointers
	// Do not try to fake this stress test (academic integrity issues)
	// I'm going to spot check this, but this is here as a reminder
	if( a0 == b0 && b0 == c0 || c0 == 0 )
	{
		// BAIL - System isnt working
		fprintf(io::getHandle(),"\n\n      Crash! - Bail stress test\n\n\n");
		io::destroy();

		exit(-1);
	}



	mem.Free(a2);
	a2 = 0;
	mem.Free(b3);
	b3 = 0;
	mem.Free(c0);
	c0 = 0;
	mem.Free(d1);
	d1 = 0;

	a2 = mem.Malloc(0x200);
	b3 = mem.Malloc(0x500);
	c0 = mem.Malloc(0x200);
	d1 = mem.Malloc(0x180);

	mem.Free(a3);
	a3 = 0;

	void *p1 = mem.Malloc(0x180);
	void *p2 = mem.Malloc(0x80);
	void *p3 = mem.Malloc(0x180);
	void *p4 = mem.Malloc(0x80);
	void *p5 = mem.Malloc(0x180);

	mem.Free(a0);
	a0 = 0;
	mem.Free(a1);
	a1 = 0;
	mem.Free(f3);
	f3 = 0;
	mem.Free(g2);
	g2 = 0;
	mem.Free(g1);
	g1 = 0;

	void *s1 = mem.Malloc(0x180);
	void *s2 = mem.Malloc(0x80);
	void *s3 = mem.Malloc(0x180);
	void *s4 = mem.Malloc(0x80);
	void *s5 = mem.Malloc(0x180);
	void *s6 = mem.Malloc(0x80);
	void *s7 = mem.Malloc(0x180);	
	void *s8 = mem.Malloc(0x80);
	void *s9 = mem.Malloc(0x180);
	void *s10 = mem.Malloc(0x80);
	void *s11 = mem.Malloc(0x180);
	void *s12 = mem.Malloc(0x80);
	void *s13 = mem.Malloc(0x180);

	void *s14 = mem.Malloc(0x500);
	void *s15 = mem.Malloc(0x1180);
	void *s16 = mem.Malloc(0x200);
	void *s17 = mem.Malloc(0x280);
	void *s18 = mem.Malloc(0x80);

	mem.Free(s1);
	mem.Free(c2);
	mem.Free(d3);
	mem.Free(b3);
	mem.Free(d2);
	mem.Free(g0);
	mem.Free(a2);
	mem.Free(c1);

	mem.Free(d1);
	mem.Free(d0);
	mem.Free(s2);
	mem.Free(f2);
	mem.Free(b1);
	mem.Free(e1);

	mem.Free(e3);
	mem.Free(f0);
	mem.Free(g3);
	mem.Free(e2);

	mem.Free(s18);
	mem.Free(s17);
	mem.Free(s16);
	mem.Free(c3);
	mem.Free(s12);
	mem.Free(s10);
	mem.Free(b2);
	mem.Free(s8);
	mem.Free(s6);
	mem.Free(e0);
	mem.Free(s5);
	mem.Free(s3);

	mem.Free(c0);
	mem.Free(s4);
	mem.Free(s7);
	
	mem.Free(s9);
	mem.Free(s11);
	mem.Free(s13);
	mem.Free(s14);
	mem.Free(s15);

	mem.Free(p1);
	mem.Free(p3);
	mem.Free(b0);
	mem.Free(p5);
	mem.Free(p4);
	mem.Free(f1);
	mem.Free(p2);
	
	void *pp = mem.Malloc(0x200);
	mem.Free(pp);

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

	// every allocation should be a real value
	// I'm going to spot check this, but here is a reminder assert()
	assert( a0 != 0);
	assert( b0 != 0);
	assert( c0 != 0);
	assert( d0 != 0);
	assert( e0 != 0);
	assert( f0 != 0);
	assert( g0 != 0);

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