
#include <stdio.h>
#include <string.h>

#include"LengthOfStrings.h"



size_t LengthOfString_1( const char  * const input)
{
	// using strlen()
	return strlen(input);
}

size_t LengthOfString_2( const char  * const input)
{
	// using char by char
	int i = 0;
	while (input[i] != '\0')
	{
		i++;
	}
	return i;
}
