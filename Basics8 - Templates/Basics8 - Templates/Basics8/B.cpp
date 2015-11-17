// CANNOT change anything below this line  ------------

#include <assert.h>

template <typename R, typename S, typename T>
T const min(R const& a, S const& b)
{
	T val;

	if (a > b)
	{
		// need a cast incase type T != type S
		val = static_cast<T>(b);
	}
	else
	{
		// need a cast incase type T != type R
		val = static_cast<T>(a);
	}
	return  val;
}

// CANNOT change anything above this line  --------------------


void B() //Template parameters
{
	int val = 0;

	// Fix this template call without a cast
	// Specify the or qualify explicity the type of T
	// Only change the next line

	val = min<int, double, int>(5, 4.2);

	assert(val == 4);


}