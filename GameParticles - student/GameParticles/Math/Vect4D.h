// Vect4D.h
//
// This is a 4 dimensional Vect4D class
#ifndef Vect4D_H
#define Vect4D_H

// includes
#include <xmmintrin.h>
#include <smmintrin.h>  
#include "Enum.h"

// Foward Declarations
class Matrix;

// class
class Vect4D
{
public:
	friend class Matrix;

	Vect4D();
	Vect4D(float tx, float ty, float tz, float tw = 1.0f);
	Vect4D(const __m128 &M)
		:m(M)
	{};
	Vect4D(const Vect4D &tmp)
		:x(tmp.x), y(tmp.y), z(tmp.z), w(tmp.w)
	{
	};
	~Vect4D();


	void operator = (const Vect4D &tmp);

	void norm(Vect4D &out);
	void set(float tx, float ty, float tz, float tw = 1.0f);

	Vect4D operator + (Vect4D &t) const;
	Vect4D operator - (Vect4D &t) const;
	Vect4D operator * (float scale) const;

	void Cross(Vect4D &vin, Vect4D &vout);

	float &operator[](VECT_ENUM e);

	// Level 4 complains nameless struct/union ...
	#pragma warning( disable : 4201)

	// anonymous union
	union
	{
		__m128	m;

		// anonymous struct
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};

private:
	float SqrtOpt(float x);
};

#endif  //Vect4D.h
