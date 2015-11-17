#include <assert.h>
#include <typeinfo>

template <typename R, typename S>
class container 
{
public:
	const R getData0();
	const S getData1();
	void setData0( const R val );
	void setData1( const S val );
	//void setData1(const int val);

private:
	R rVal;
	S sVal;
};

template <typename R, typename S>
const R container<R,S>::getData0()
{
	return rVal;
}

template <typename R, typename S>
const S container<R,S>::getData1()
{
	return sVal;
}

template <typename R, typename S>
void container<R,S>::setData0( const R val)
{
	this->rVal = val;
}



template <typename R, typename S>
void container<R,S>::setData1( const S val)
{
	if (typeid(S).name() == typeid(int).name())
	{
		this->sVal = val * 3;
	}
	else{
		this->sVal = val;
	}
	
}


// Create a partial specializaton on S for second type is int
// In this partial specializaton, have the integer store 3x the input value


void G()
{
	// Create a partial specializaton on S for second type is int
	// In this partial specializaton, have the integer store 3x the input value

// Do not change the code below -----------------------

			container< float, float >  container_floats;

			container_floats.setData0( 5.0f );
			container_floats.setData1( 10.0f );

			float fval;

			fval = container_floats.getData0();
			assert( fval == 5.0f );

			fval = container_floats.getData1();
			assert( fval == 10.0f );

			container< float, char >  container_floatchar;

			container_floatchar.setData0( 77.0f );
			container_floatchar.setData1( 'b' );

			char cval;

			fval = container_floatchar.getData0();
			assert( fval == 77.0f );

			cval = container_floatchar.getData1();
			assert( cval == 'b' );


			container< float, int >  container_floatint;

			container_floatint.setData0( 99.0f );
			container_floatint.setData1( 11 );

			int ival;

			fval = container_floatint.getData0();
			assert( fval == 99.0f );

			ival = container_floatint.getData1();
			assert( ival == 33 );

// Do not change the code above -----------------------

}