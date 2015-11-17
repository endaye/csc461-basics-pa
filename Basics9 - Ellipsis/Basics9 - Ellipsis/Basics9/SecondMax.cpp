#include <stdio.h>
#include <cstdarg>
#include <limits>
// Add functions and includes as needed

// The ellipses must be the last parameter
int SecondMax(int count, ...)
{
	int max = std::numeric_limits<int>::min();
	int max2nd = std::numeric_limits<int>::min();
	int tmp = std::numeric_limits<int>::min();
	// Do your magic here:
	va_list list;
	va_start(list, count);

	for (int nArg = 0; nArg < count; nArg++)
	{
		tmp = va_arg(list, int);
		if (tmp > max)
		{
			max2nd = max;
			max = tmp;
		}
		if (tmp > max2nd && tmp < max)
		{
			max2nd = tmp;
		}
		else;
	}

	va_end(list);
	
	return max2nd;
}