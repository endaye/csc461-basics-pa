#ifndef LERP_SIMD_H
#define LERP_SIMD_H

#include "Vect4D_SIMD.h"

class VectApp_SIMD
{
		
public:

	// lerp
	static void Lerp(Vect4D_SIMD &out, const Vect4D_SIMD &a, const Vect4D_SIMD &b, const float t);

};


#endif