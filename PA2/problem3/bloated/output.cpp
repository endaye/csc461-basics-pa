#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "output.h"


void io::create(const char * const name)
{
	privGetInstance()->privCreate( name );
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
	char fileName[64];
	char *out_string = "output_";

	strcpy_s(fileName,64,out_string);
#if _DEBUG
	char *debug_string = "Debug.txt";
	strcat_s(fileName, 64, debug_string);
#else
	char *debug_string = "Release.txt";
	strcat_s(fileName, 64, debug_string);
#endif

	fileError = fopen_s(&fileHandle,fileName,"wt");
	assert( fileHandle );

	fprintf(fileHandle,"Program Assignment: 1 \n");
	fprintf(fileHandle,"Name: %s\n",name);
	fprintf(fileHandle,"\n",name);
	fprintf(fileHandle,"-------------------------------------------------\n",name);
	fprintf(fileHandle,"\n",name);
}


FILE *io::privGetHandle()
{
	assert( fileHandle );
	return fileHandle;
}


