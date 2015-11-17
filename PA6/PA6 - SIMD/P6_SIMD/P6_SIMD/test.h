#ifndef TEST_H
#define TEST_H

#include "Vect4D.h"

Vect4D_SIMD test_simd();
Vect4D test();
Vect4D matrix_test();
Vect4D_SIMD matrix_SIMD_test();

Vect4D vectMultMatrix_test( void );
Vect4D_SIMD vectMultMatrix_SIMD_test( void );

Vect4D LERP_Tests();
Vect4D_SIMD LERP_SIMD_Tests();
#endif