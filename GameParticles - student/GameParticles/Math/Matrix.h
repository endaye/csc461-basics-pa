#ifndef MATRIX_H
#define MATRIX_H

// includes
#include "Enum.h"
#include "Vect4D.h"

// forward declare
class Vect4D;

// class
class __declspec(align(16)) Matrix
{
public:
	Matrix();
	Matrix(Matrix& t);
	Matrix(const Vect4D &t0, const Vect4D &t1, const Vect4D &t2, const Vect4D &t3);
	~Matrix();

	void get(Vect4D &t0, Vect4D &t1, Vect4D &t2, Vect4D &t3) const;

	//void setIdentMatrix();
	void setIdentMatrix2();
	//void setTransMatrix(const Vect4D &t);
	//void setScaleMatrix(const Vect4D &s);
	//void setRotZMatrix(const float &az);
	Matrix operator*(Matrix &t);

	float Determinant();
	void Inverse(Matrix &out);
	void GetInverseRes(Matrix &out, const float det);
	// Matrix GetAdjugate() const

public:
	// Level 4 complains nameless struct/union ...
	#pragma warning( disable : 4201)

	union
	{
		struct
		{
			Vect4D v0;
			Vect4D v1;
			Vect4D v2;
			Vect4D v3;
		};

		struct
		{
			// ROW 0
			float m0;
			float m1;
			float m2;
			float m3;

			// ROW 1
			float m4;
			float m5;
			float m6;
			float m7;

			// ROW 2
			float m8;
			float m9;
			float m10;
			float m11;

			// ROW 3
			float m12;
			float m13;
			float m14;
			float m15;
		};
	};
};

#endif  // Matrix.h
