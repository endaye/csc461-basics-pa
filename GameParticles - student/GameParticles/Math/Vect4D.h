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
// class __declspec(align(16)) Matrix;

// class
class __declspec(align(16)) Vect4D
{
public:
	//friend class Matrix;

	Vect4D()
		:x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}; 

	Vect4D(float tx, float ty, float tz, float tw = 1.0f)
		:x(tx), y(ty), z(tz), w(tw) {};

	Vect4D(const __m128 &M)
		:m(M) {};

	Vect4D(const Vect4D &tmp)
		:x(tmp.x), y(tmp.y), z(tmp.z), w(tmp.w) {};

	~Vect4D()
	{};

	void set(float tx, float ty, float tz, float tw = 1.0f)
	{
		x = tx;
		y = ty;
		z = tz;
		w = tw;
	}

	void operator = (const Vect4D &t)
	{
		x = t.x;
		y = t.y;
		z = t.z;
		w = t.w;
	};

	Vect4D operator + (Vect4D &t) const
	{
		return Vect4D(_mm_add_ps(this->m, t.m));
	};

	void operator += (Vect4D &t)
	{
		this->m = _mm_add_ps(this->m, t.m);
	};

	Vect4D operator - (Vect4D &t) const
	{
		return Vect4D(_mm_sub_ps(this->m, t.m));
		//return Vect4D(this->x - t.x, this->y - t.y, this->z - t.z, 1.0f);
	};

	void operator -= (Vect4D &t)
	{
		this->m = _mm_sub_ps(this->m, t.m);
	};

	Vect4D operator * (Vect4D &tmp) const
	{
		return Vect4D(_mm_mul_ps(this->m, tmp.m));
	};
	
	Vect4D operator * (float scale) const
	{
		return Vect4D(_mm_mul_ps(this->m, _mm_set1_ps(scale)));
	};

	void operator *= (Vect4D &tmp)
	{
		this->m = _mm_mul_ps(this->m, tmp.m);
	};

	void operator *= (float scale)
	{
		this->m = _mm_mul_ps(this->m, _mm_set1_ps(scale));
	};

	
	void updatePos(const float life);
	//float &operator[](VECT_ENUM e);
	//void norm(Vect4D &out);
	//void Cross(const Vect4D &vin, Vect4D &vout) const;
	//float SqrtOpt(float x);
public:
	// Level 4 complains nameless struct/union ...
	#pragma warning( disable : 4201)

	// anonymous union
	union
	{
		__declspec(align(16)) __m128	m;

		// anonymous struct
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};


};

#endif  //Vect4D.h
