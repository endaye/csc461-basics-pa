
#include <stdio.h>
#include <string.h>
#include "ComparingStrings.h"

int StringCompare_1(const char  * const s1, const char * const s2)
{
	// using strcmp()
	return strcmp(s1, s2);
}

int StringCompare_2(const char  * const s1, const char * const s2)
{
	// using memcmp() & strlen()
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int len;
	int n;
	if (len1 > len2)
	{
		len = len2;
	}
	else if (len1 < len2)
	{
		len = len1;
	}
	else
	{
		len = len1;
	}
	n = memcmp(s1, s2, len);
	if (n > 0)
	{
		return 1;
	}
	else if (n < 0)
	{
		return -1;
	}
	else
	{
		if (len1 > len2)
		{
			return 1;
		}
		else if (len1 < len2)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}

int StringCompare_3(const char  * const s1, const char * const s2)
{
	// using char by char comparisions
	int i;
	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
		{
			return 0;
		}
	}
	int diff = s1[i] - s2[i];
	if (diff > 0)
	{
		return 1;
	}
	else if (diff < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

