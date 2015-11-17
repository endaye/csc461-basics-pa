#include "PA5_A.h"

#define IMPLICIT_CONVERSIONS 1   // toggle me to see performance differences

void StressTest( void )
{
#if IMPLICIT_CONVERSIONS
	volatile int I_ValueX(2);
	volatile int I_ValueY(3);
	volatile int I_ValueZ(4);
	
	volatile char C_ValueX(7);
	volatile char C_ValueY(8);
	volatile char C_ValueZ(9);

    volatile double D_ValueX( 11 );
    volatile double D_ValueY( 12 );
	volatile double D_ValueZ( 13 );

#else
	volatile float I_ValueX(2);
	volatile float I_ValueY(3);
	volatile float I_ValueZ(4);

	volatile float C_ValueX(7);
	volatile float C_ValueY(8);
	volatile float C_ValueZ(9);

	volatile float D_ValueX( 11 );
	volatile float D_ValueY( 12 );
	volatile float D_ValueZ( 13 );
#endif

	// Disable warning message (simulating bad users)
#pragma warning( disable : 4244 )

	Vect A;

	A.setX( I_ValueX );
	A.setY( I_ValueY );
	A.setZ( I_ValueZ );

	Vect B( D_ValueX, I_ValueY, D_ValueZ );

	Vect C;

	C = A + B;
	
	Vect D( C );

	D.setX( D_ValueZ );

	C.setZ( I_ValueX );

	Vect E = A + B;

	A.set( I_ValueX, D_ValueY, C_ValueX );

	B = A+ B;
	C = B + E;

	E.setZ(I_ValueX );

	Vect F;

	F.setX(C_ValueX);

	Vect G( F.getX(), A.getY(), B.getZ() );
	Vect H( C.getZ(), C_ValueZ, F.getX() );

}