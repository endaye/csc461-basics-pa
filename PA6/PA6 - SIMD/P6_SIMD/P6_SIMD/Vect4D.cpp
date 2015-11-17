#include "Vect4D.h"
#include "Matrix.h"


Vect4D Vect4D::operator * (const Matrix &m)
{	
	Vect4D C;

	C.x = x * m.m0 + y*m.m4 + z*m.m8 + w * m.m12;
	C.y = x * m.m1 + y*m.m5 + z*m.m9 + w * m.m13;
	C.z = x * m.m2 + y*m.m6 + z*m.m10 + w * m.m14;
	C.w = x * m.m3 + y*m.m7 + z*m.m11 + w * m.m15;

	return C;
};