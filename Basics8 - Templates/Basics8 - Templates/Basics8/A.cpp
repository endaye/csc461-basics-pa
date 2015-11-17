// CANNOT change anything below this line

#include <assert.h>

template <typename T>
inline T const min(T const& a, T const& b)
{

	T val;

	if (a > b)
	{
		val = b;
	}
	else
	{
		val = a;
	}

	return  val;
}

// CANNOT change anything above this line -------------------

void A()  // Argument Deduction
{
	double val;

	// Fix this template call without a cast
	// Specify the or qualify explicity the type of T
	// Only change this call line below:

	val = min(5.0, 4.2);

	assert(val == 4.2);

}