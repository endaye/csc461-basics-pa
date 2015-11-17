#ifndef MATRIX_H
#define MATRIX_H

// includes
#include "Enum.h"

// forward declare
class Vect4D;

// class
class Matrix
{
public:

	// local enumerations
	enum MatrixRowEnum
	{
		MATRIX_ROW_0,
		MATRIX_ROW_1,
		MATRIX_ROW_2,
		MATRIX_ROW_3
	};

	Matrix();	
	Matrix( Matrix& t );	
	~Matrix();

	void set( MatrixRowEnum row, Vect4D *t );
	void get( MatrixRowEnum row, Vect4D *vOut );

	void setIdentMatrix();
	void setTransMatrix(Vect4D *t );
	void setScaleMatrix(Vect4D *s );
	void setRotZMatrix( double Z_Radians );

	double &operator[]( INDEX_ENUM e);
	
	Matrix operator*( Matrix &t );
	Matrix operator*( double s );

	double Determinant();
	
	Matrix GetAdjugate();
	Matrix& Matrix::operator/=(double t);
	
	void Matrix::Inverse( Matrix &out );
	
private:

	// ROW 0
	double m0;
	double m1;
	double m2;
	double m3;

	// ROW 1
	double m4;
	double m5;
	double m6;
	double m7;

	// ROW 2
	double m8;
	double m9;
	double m10;
	double m11;

	// ROW 3
	double m12;
	double m13;
	double m14;
	double m15;
};

#endif  // Matrix.h
