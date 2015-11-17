#include <string.h>
#include <assert.h>

// minimum of two values of any type (call-by-reference)
template <typename T>
const T &min(T const& a, T const& b)
{
	if( a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}


// minimum of two C-strings (call-by-value)
const char *min(const char * a, const char * b)
{
	if (strcmp(a, b) > 0)
	{
		return b;
	}
	else
	{
		return a;
	}
}


// minimum of three values of any type (call-by-reference)
template <typename T>
const T min(T const &a, T const &b, T const &c)
{
    return min( min(a, b), c);  
}

void D()  // Overloading with side effects
{
	// Understand why the following code is not working
	// Once you understand the underlying reason, fix the above template code

// Do not change any code below this line --------------------------------------------

			int val;
			val = min( 42, 7, 68);
			assert( val == 7 );

			const char *  const s0 = "CSC";
			const char *  const s1 = "461";
			const char *  const s2 = "Optimized C++";

			const char *s;
			
			s = min( s0, s1, s2 );
			assert( strcmp( s, "461" ) ==  0 );
	
// Do not change any code above this line ------------------
}

