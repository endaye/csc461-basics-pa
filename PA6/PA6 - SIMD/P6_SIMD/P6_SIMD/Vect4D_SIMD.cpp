#include "Vect4D_SIMD.h"
#include "Matrix_SIMD.h"

#include <xmmintrin.h>
#include <smmintrin.h> 
#include <intrin.h>



Vect4D_SIMD Vect4D_SIMD::operator * ( Matrix_SIMD &m)
{			
	Vect4D_SIMD C;

	__m128 tmp;
	tmp = _mm_set1_ps(this->x);
	C.m = _mm_mul_ps(tmp, m.v0.m);
	
	tmp = _mm_set1_ps(this->y);
	C.m = _mm_add_ps(C.m, _mm_mul_ps(tmp, m.v1.m));

	tmp = _mm_set1_ps(this->z);
	C.m = _mm_add_ps(C.m, _mm_mul_ps(tmp, m.v2.m));
	
	tmp = _mm_set1_ps(this->w);
	C.m = _mm_add_ps(C.m, _mm_mul_ps(tmp, m.v3.m));
	return C;
};