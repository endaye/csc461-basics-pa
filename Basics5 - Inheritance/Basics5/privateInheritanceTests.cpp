#include "UnitTest.h"
#include "MiddlewareNative.h"
#include "Wrapper.h"

int Vect2D_Native::id = 1234;

TEST( Private1, PrivateInheritanceTests)
{

	// Make sure the Native is working as advertised
	Vect2D_Native vNative;

	CHECK( vNative.getID() == 1235 );
	CHECK( vNative.getX() == 22.0f );
	CHECK( vNative.getY() == 33.0f );

	vNative.setX( 77 );
	vNative.setY( 88 );
	vNative.setID( 55 );

	CHECK( vNative.getID() == 55 );
	CHECK( vNative.getX() == 77.0f );
	CHECK( vNative.getY() == 88.0f );

	// Now check the wrapper class
	GameVect gVect;

	// Magic to test the base class (not good practice)
	Vect2D_Native *p = (Vect2D_Native *)&gVect;

	CHECK( p->getID() == 56 );
	CHECK( p->getX() == 22.0f );
	CHECK( p->getY() == 33.0f );

	// Get it by the new methods
	float xVal;
	gVect.getX( xVal );

	CHECK( xVal == 22.0f );

	float yVal;
	gVect.getY( yVal );

	CHECK( yVal == 33.0f );

	// Set it by the new methods
	gVect.setX( 66.0f );
	gVect.setY( 77.0f );

	gVect.getX( xVal );
	gVect.getY( yVal );

	CHECK( xVal == 66.0f );
	CHECK( yVal == 77.0f );

#if 0  // change this to make sure you get an error for each of the following statements

	int iVal;

	// 1)  Error
	gVect.getX( iVal );

	// 2) Error
	xVal = gVect.getX();

	// 3)  Error
	gVect.getY( iVal );

	// 4) Error
	yVal = gVect.getY();

	// 5) Error
	gVect.setID( 0x33 );

	// 6) Error
	iVal = gVect.getID();

	// 7)  Error
	gVect.x;

	// 8) Error
	gVect.y;

#endif

}