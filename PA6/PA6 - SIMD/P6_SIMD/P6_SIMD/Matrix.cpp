#include "Matrix.h"

Matrix Matrix::operator * (Matrix &t)
{
	Matrix A;

	A.m0 = m0*t.m0 + m1*t.m4 + m2*t.m8  + m3*t.m12;
	A.m1 = m0*t.m1 + m1*t.m5 + m2*t.m9  + m3*t.m13;
	A.m2 = m0*t.m2 + m1*t.m6 + m2*t.m10 + m3*t.m14;
	A.m3 = m0*t.m3 + m1*t.m7 + m2*t.m11 + m3*t.m15;

	A.m4 = m4*t.m0 + m5*t.m4 + m6*t.m8  + m7*t.m12;
	A.m5 = m4*t.m1 + m5*t.m5 + m6*t.m9  + m7*t.m13;
	A.m6 = m4*t.m2 + m5*t.m6 + m6*t.m10 + m7*t.m14;
	A.m7 = m4*t.m3 + m5*t.m7 + m6*t.m11 + m7*t.m15;

	A.m8 = m8*t.m0 + m9*t.m4 + m10*t.m8  + m11*t.m12;
	A.m9 = m8*t.m1 + m9*t.m5 + m10*t.m9  + m11*t.m13;
	A.m10= m8*t.m2 + m9*t.m6 + m10*t.m10 + m11*t.m14;
	A.m11= m8*t.m3 + m9*t.m7 + m10*t.m11 + m11*t.m15;

	A.m12 = m12*t.m0 + m13*t.m4 + m14*t.m8  + m15*t.m12;
	A.m13 = m12*t.m1 + m13*t.m5 + m14*t.m9  + m15*t.m13;
	A.m14 = m12*t.m2 + m13*t.m6 + m14*t.m10 + m15*t.m14;
	A.m15 = m12*t.m3 + m13*t.m7 + m14*t.m11 + m15*t.m15;

	return A;

}