#include <stdio.h>
#include <assert.h>
#include "output.h"


void io::create(const char * const name)
{
	privGetInstance()->privCreate( name );
}

void io::create(const char * const name, const char * const filename )
{
	privGetInstance()->privCreate( name, filename );
}

void io::destroy()
{
	privGetInstance()->privDestroy();
}

FILE *io::getHandle()
{
	return privGetInstance()->privGetHandle();
}

io *io::privGetInstance()
{
	static io instance;
	return &instance;
}

void io::privDestroy()
{
	errno_t fileError;
	assert( fileHandle );

	fileError = fflush( fileHandle );
	assert( !fileError );

	fileError = fclose( fileHandle);
	fileHandle = 0;
	assert( !fileError );	
}

void io::privCreate(const char * const name)
{
	errno_t fileError;

#ifdef _DEBUG
	const char *outName = "Benchmark_PA5_debug.txt";
#endif

#ifdef MR_FAST 
	const char *outName = "Benchmark_PA5_fast.txt";
#else
#ifndef _DEBUG
	const char *outName = "Benchmark_PA5_release.txt";
#endif

#endif

	fileError = fopen_s(&fileHandle,outName,"wt");
	assert( fileHandle );

	fprintf(fileHandle,"Program Assignment: 5 \n");
	fprintf(fileHandle,"Name: %s\n\n",name);

}

void io::privCreate(const char * const name, const char * const filename )
{
	errno_t fileError;

	fileError = fopen_s(&fileHandle,filename,"wt");
	assert( fileHandle );

	fprintf(fileHandle,"Program Assignment: 4 \n");
	fprintf(fileHandle,"Name: %s\n\n",name);

}

FILE *io::privGetHandle()
{
	assert( fileHandle );
	return fileHandle;
}


