
#include <stdio.h>
#include <string.h>

#pragma warning( disable : 4996 )

#include "CopyingStrings.h"
 

char *StringCopy_1( char * const dest, const char * const input)
{
	// using strcpy()
	return strcpy(dest, input);
}

char *StringCopy_2( char  * const dest, const char * const input)
{
	// using memcpy() and strlen()
	memcpy(dest, input, strlen(input) + 1);
	return dest;
}

char *StringCopy_3( char  * const dest, const char * const input)
{
	// using char by char copies
	int i = 0;
	for (; input[i] != '\0'; i++)
	{
		dest[i] = input[i];
	}
	dest[i] = '\0';
	return dest;
}

