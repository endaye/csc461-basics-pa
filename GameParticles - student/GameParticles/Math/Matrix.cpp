#include <Math.h>
#include <assert.h>
#include "Vect4d.h"
#include "Matrix.h"



Matrix::Matrix()
{	
	// constructor for the matrix
	v0.set(0.0f);
	v2.set(0.0f);
	v1.set(0.0f);
	v3.set(0.0f);
}

Matrix::Matrix(Matrix& t)
{ 
	// copy constructor
	this->v0.m = t.v0.m;
	this->v1.m = t.v1.m;
	this->v2.m = t.v2.m;
	this->v3.m = t.v3.m;
}

Matrix::Matrix(const Vect4D &t0, const Vect4D &t1, const Vect4D &t2, const Vect4D &t3)
{
	// copy constructor
	this->v0.m = t0.m;
	this->v1.m = t1.m;
	this->v2.m = t2.m;
	this->v3.m = t3.m;
}

Matrix::~Matrix()
{
	// nothign to delete
}

void Matrix::get(Vect4D &t0, Vect4D &t1, Vect4D &t2, Vect4D &t3) const
{ // get a row of the matrix
	t0.m = this->v0.m;
	t1.m = this->v1.m;
	t2.m = this->v2.m;
	t3.m = this->v3.m;
}

void Matrix::setIdentMatrix2()
{
	m0 = m5 = m10 = m15 = 1.0f;
}

//void Matrix::setIdentMatrix()
//{ 
//	// initialize to the identity matrix
//	v0.set(1.0f, 0.0f, 0.0f, 0.0f);
//	v1.set(0.0f, 1.0f, 0.0f, 0.0f);
//	v2.set(0.0f, 0.0f, 1.0f, 0.0f);
//	v3.set(0.0f, 0.0f, 0.0f, 1.0f);
//}
//
//void Matrix::setTransMatrix(const Vect4D &t)
//{ 
//	// set the translation matrix (note: we are row major)
//	v0.set(1.0f, 0.0f, 0.0f, 0.0f);
//	v1.set(0.0f, 1.0f, 0.0f, 0.0f);
//	v2.set(0.0f, 0.0f, 1.0f, 0.0f);
//	v3.set(t.x,  t.y,  t.z,  1.0f);
//}
//
//void Matrix::setScaleMatrix(const Vect4D &scale)
//{
//	//	{	sx		0		0		0	}
//	//	{	0		sy		0		0	}
//	//	{	0		0		sz		0	}
//	//	{	0		0		0		1	}
//	this->v0.set(scale.x, 0.0f, 0.0f, 0.0f);
//	this->v1.set(0.0f, scale.y, 0.0f, 0.0f);
//	this->v2.set(0.0f, 0.0f, scale.z, 0.0f);
//	this->v3.set(0.0f, 0.0f, 0.0f, 1.0f);
//}
//
//void Matrix::setRotZMatrix(const float &az)
//{
//	//	{	cos		-sin	0		0	}
//	//	{	sin		cos		0		0	}
//	//	{	0		0		1		0	}
//	//	{	0		0		0		1	}
//	const float tsin = sinf(az);
//	const float tcos = cosf(az);
//	this->v0.set(tcos, -tsin, 0.0f, 0.0f);
//	this->v1.set(tsin, tcos, 0.0f, 0.0f);
//	this->v2.set(0.0f, 0.0f, 1.0f, 0.0f);
//	this->v3.set(0.0f, 0.0f, 0.0f, 1.0f);
//}

//float &Matrix::operator[](INDEX_ENUM e)
//{
//	// get the individual elements
//	switch (e)
//	{
//	case 0:
//		return m0;
//		break;
//	case 1:
//		return m1;
//		break;
//	case 2:
//		return m2;
//		break;
//	case 3:
//		return m3;
//		break;
//	case 4:
//		return m4;
//		break;
//	case 5:
//		return m5;
//		break;
//	case 6:
//		return m6;
//		break;
//	case 7:
//		return m7;
//		break;
//	case 8:
//		return m8;
//		break;
//	case 9:
//		return m9;
//		break;
//	case 10:
//		return m10;
//		break;
//	case 11:
//		return m11;
//		break;
//	case 12:
//		return m12;
//		break;
//	case 13:
//		return m13;
//		break;
//	case 14:
//		return m14;
//		break;
//	case 15:
//		return m15;
//		break;
//	default:
//		assert(0);
//		return m0;
//		break;
//	}
//}

Matrix Matrix::operator*(Matrix& rhs)
{
	//// matrix multiplications
	//Matrix tmp;
	//tmp.m0  = ( m0*rhs.m0) + ( m1*rhs.m4) + ( m2*rhs.m8)  + ( m3*rhs.m12);
	//tmp.m1  = ( m0*rhs.m1) + ( m1*rhs.m5) + ( m2*rhs.m9)  + ( m3*rhs.m13);
	//tmp.m2  = ( m0*rhs.m2) + ( m1*rhs.m6) + ( m2*rhs.m10) + ( m3*rhs.m14);
	//tmp.m3  = ( m0*rhs.m3) + ( m1*rhs.m7) + ( m2*rhs.m11) + ( m3*rhs.m15);
	//tmp.m4  = ( m4*rhs.m0) + ( m5*rhs.m4) + ( m6*rhs.m8)  + ( m7*rhs.m12);
	//tmp.m5  = ( m4*rhs.m1) + ( m5*rhs.m5) + ( m6*rhs.m9)  + ( m7*rhs.m13);
	//tmp.m6  = ( m4*rhs.m2) + ( m5*rhs.m6) + ( m6*rhs.m10) + ( m7*rhs.m14);
	//tmp.m7  = ( m4*rhs.m3) + ( m5*rhs.m7) + ( m6*rhs.m11) + ( m7*rhs.m15);
	//tmp.m8  = ( m8*rhs.m0) + ( m9*rhs.m4) + (m10*rhs.m8)  + (m11*rhs.m12);
	//tmp.m9  = ( m8*rhs.m1) + ( m9*rhs.m5) + (m10*rhs.m9)  + (m11*rhs.m13);
	//tmp.m10 = ( m8*rhs.m2) + ( m9*rhs.m6) + (m10*rhs.m10) + (m11*rhs.m14);
	//tmp.m11 = ( m8*rhs.m3) + ( m9*rhs.m7) + (m10*rhs.m11) + (m11*rhs.m15);
	//tmp.m12 = (m12*rhs.m0) + (m13*rhs.m4) + (m14*rhs.m8)  + (m15*rhs.m12);
	//tmp.m13 = (m12*rhs.m1) + (m13*rhs.m5) + (m14*rhs.m9)  + (m15*rhs.m13);
	//tmp.m14 = (m12*rhs.m2) + (m13*rhs.m6) + (m14*rhs.m10) + (m15*rhs.m14);
	//tmp.m15 = (m12*rhs.m3) + (m13*rhs.m7) + (m14*rhs.m11) + (m15*rhs.m15);
	//return tmp;

	Matrix A;
	__m128 tmp;

	tmp = _mm_set1_ps(this->v0.x);
	A.v0.m = _mm_mul_ps(tmp, rhs.v0.m);

	tmp = _mm_set1_ps(this->v0.y);
	A.v0.m = _mm_add_ps(A.v0.m, _mm_mul_ps(tmp, rhs.v1.m));

	tmp = _mm_set1_ps(this->v0.z);
	A.v0.m = _mm_add_ps(A.v0.m, _mm_mul_ps(tmp, rhs.v2.m));

	tmp = _mm_set1_ps(this->v0.w);
	A.v0.m = _mm_add_ps(A.v0.m, _mm_mul_ps(tmp, rhs.v3.m));


	tmp = _mm_set1_ps(this->v1.x);
	A.v1.m = _mm_mul_ps(tmp, rhs.v0.m);

	tmp = _mm_set1_ps(this->v1.y);
	A.v1.m = _mm_add_ps(A.v1.m, _mm_mul_ps(tmp, rhs.v1.m));

	tmp = _mm_set1_ps(this->v1.z);
	A.v1.m = _mm_add_ps(A.v1.m, _mm_mul_ps(tmp, rhs.v2.m));

	tmp = _mm_set1_ps(this->v1.w);
	A.v1.m = _mm_add_ps(A.v1.m, _mm_mul_ps(tmp, rhs.v3.m));


	tmp = _mm_set1_ps(this->v2.x);
	A.v2.m = _mm_mul_ps(tmp, rhs.v0.m);

	tmp = _mm_set1_ps(this->v2.y);
	A.v2.m = _mm_add_ps(A.v2.m, _mm_mul_ps(tmp, rhs.v1.m));

	tmp = _mm_set1_ps(this->v2.z);
	A.v2.m = _mm_add_ps(A.v2.m, _mm_mul_ps(tmp, rhs.v2.m));

	tmp = _mm_set1_ps(this->v2.w);
	A.v2.m = _mm_add_ps(A.v2.m, _mm_mul_ps(tmp, rhs.v3.m));


	tmp = _mm_set1_ps(this->v3.x);
	A.v3.m = _mm_mul_ps(tmp, rhs.v0.m);

	tmp = _mm_set1_ps(this->v3.y);
	A.v3.m = _mm_add_ps(A.v3.m, _mm_mul_ps(tmp, rhs.v1.m));

	tmp = _mm_set1_ps(this->v3.z);
	A.v3.m = _mm_add_ps(A.v3.m, _mm_mul_ps(tmp, rhs.v2.m));

	tmp = _mm_set1_ps(this->v3.w);
	A.v3.m = _mm_add_ps(A.v3.m, _mm_mul_ps(tmp, rhs.v3.m));

	return A;
}

void Matrix::Inverse(Matrix &out)
{
	float det = Determinant();
	if (fabs(det) < 0.0001)
	{
		// do nothing, Matrix is not invertable
		return;
	}
	else
	{
		//out = GetAdjugate();
		//out /= det;
		GetInverseRes(out, det);		
	}
}

float Matrix::Determinant()
{
	// A = { a, b, c, d / e, f, g, h / j, k, l, m /  n, o, p, q }
	// A = { 0, 1, 2, 3 / 4, 5, 6, 7 / 8, 9,10,11 / 12,13,14,15 }

	// det(A) =   a * det( { f,g,h / k,l,m / o,p,q } )
	//			- b * det( { e,g,h / j,l,m / n,p,q } )
	//			+ c * det( { e,f,h / j,k,m / n,o,q } )
	//			- d * det( { e,f,g / j,k,l / n,o,p } )

	// det(A) =   (a (f (lq - mp) - g (kq - mo) + h (kp - lo) ) )
	//			- (b (e (lq - mp) - g (jq - mn) + h (jp - ln) ) )
	//			+ (c (e (kq - mo) - f (jq - mn) + h (jo - kn) ) )
	//			- (d (e (kp - lo) - f (jp - ln) + g (jo - kn) ) )

	// ta = (lq - mp)
	float ta = ((m10 * m15) - (m11 * m14));
	// tb = (kq - mo)
	float tb = ((m9 * m15) - (m11 * m13));
	// tc = (kp - lo)
	float tc = ((m9 * m14) - (m10 * m13));
	// td = (jq - mn)
	float td = ((m8 * m15) - (m11 * m12));
	// te = (jo - kn)
	float te = ((m8 * m13) - (m9 *  m12));
	// tf = (jp - ln)
	float tf = ((m8 * m14) - (m10 * m12));

	// det(A) =   (a (f * ta - g * tb + h * tc) )
	//			- (b (e * ta - g * td + h * tf) )
	//			+ (c (e * tb - f * td + h * te) )
	//			- (d (e * tc - f * tf + g * te) )
	return ((m0 * ((m5 * ta) - (m6 * tb) + (m7 * tc)))
		  - (m1 * ((m4 * ta) - (m6 * td) + (m7 * tf)))
		  + (m2 * ((m4 * tb) - (m5 * td) + (m7 * te)))
		  - (m3 * ((m4 * tc) - (m5 * tf) + (m6 * te))));
	//return ((m0 * ((m5 * ((m10 * m15) - (m11 * m14))) - (m6 * ((m9 * m15) - (m11 * m13))) + (m7 * ((m9 * m14) - (m10 * m13)))))
	//	  - (m1 * ((m4 * ((m10 * m15) - (m11 * m14))) - (m6 * ((m8 * m15) - (m11 * m12))) + (m7 * ((m8 * m14) - (m10 * m12)))))
	//	  + (m2 * ((m4 * (( m9 * m15) - (m11 * m13))) - (m5 * ((m8 * m15) - (m11 * m12))) + (m7 * ((m8 * m13) - ( m9 * m12)))))
	//	  - (m3 * ((m4 * (( m9 * m14) - (m10 * m13))) - (m5 * ((m8 * m14) - (m10 * m12))) + (m6 * ((m8 * m13) - ( m9 * m12))))));

}

void Matrix::GetInverseRes(Matrix &out, const float det)
{
	Matrix tmp;

	float t1 = (m10*m15) - (m11*m14);
	float t2 = ( m9*m15) - (m11*m13);
	float t3 = ( m9*m14) - (m10*m13);

	tmp.m0 = (m5*t1) - (m6*t2) + (m7*t3);
	tmp.m1 = (m2*t2) - (m3*t3) - (m1*t1);

	float t4 = (m8*m15) - (m11*m12);
	float t5 = (m8*m14) - (m10*m12);

	tmp.m4 = (m6*t4) - (m7*t5) - (m4*t1);
	tmp.m5 = (m0*t1) - (m2*t4) + (m3*t5);

	t1 = (m8*m13) - (m9*m12);
	tmp.m12 = (m5*t5) - (m6*t1) - (m4*t3);
	tmp.m13 = (m0*t3) - (m1*t5) + (m2*t1);

	t3 = (m8*m15) - (m11*m12);

	tmp.m8 = (m4*t2) - (m5*t3) + (m7*t1);
	tmp.m9 = (m1*t3) - (m3*t1) - (m0*t2);

	t1 = (m6*m15) - (m7*m14);
	t2 = (m4*m15) - (m7*m12);
	t3 = (m4*m14) - (m6*m12);

	tmp.m6 = (m2*t2) - (m3*t3) - (m0*t1);

	t4 = (m5*m14) - (m6*m13);
	t5 = (m4*m13) - (m5*m12);

	tmp.m14 = (m1*t3) - (m3*t5) - (m0*t4);

	t3 = (m5*m15) - (m7*m13);

	tmp.m10 = (m0*t3) - (m1*t2) + (m3*t5);

	tmp.m2 = (m1*t1) - (m2*t3) + (m3*t4);

	t1 = (m6*m11) - (m7*m10);
	t2 = (m5*m11) - (m7*m9);
	t3 = (m5*m10) - (m6*m9);

	tmp.m3 = (m2*t2) - (m3*t3) - (m1*t1);

	t4 = (m4*m11) - (m7*m8);
	t5 = (m4*m10) - (m6*m8);

	tmp.m7 = (m0*t1) - (m2*t4) + (m3*t5);

	t1 = (m4*m9) - (m5*m8);

	tmp.m11 = (m1*t4) - (m3*t1) - (m0*t2);

	tmp.m15 = (m0*t3) - (m1*t5) + (m2*t1);
	__m128 invDet = _mm_set1_ps(1.0f / det);
	out.v0.m = _mm_mul_ps(tmp.v0.m, invDet);
	out.v1.m = _mm_mul_ps(tmp.v1.m, invDet);
	out.v2.m = _mm_mul_ps(tmp.v2.m, invDet);
	out.v3.m = _mm_mul_ps(tmp.v3.m, invDet);
}

//Matrix Matrix::GetAdjugate() const
//{
//	// matrix = { a,b,c,d / e,f,g,h / j,k,l,m / n,o,p,q }
//
//	// ta = lq - mp
//	// tb = kq - mo
//	// tc = kp - lo
//	// td = gq - hp
//	// te = fq - ho
//	// tf = fp - go
//	// tg = gm - hl
//	// th = fm - hk
//	// ti = fl - gk
//	// tj = jq - mn
//	// tk = jp - ln
//	// tl = eq - hn
//	// tm = ep - gn
//	// tn = em - hj
//	// to = el - gj
//	// tp = jo - kn
//	// tq = ek - fj
//	// tr = eo - fn
//
//	// a = det( { f,g,h / k,l,m / o,p,q } )
//	// a = f(lq - mp) - g(kq - mo) + h(kp - lo)
//	// a = f(ta) - g(tb) + h(tc)
//
//	// b = -det( { b,c,d / k,l,m / o,p,q } )
//	// b = -( b(lq - mp) - c(kq - mo) + d(kp - lo))
//	// b = -( b(ta) - c(tb) + d(tc))
//
//	// c = det( { b,c,d / f,g,h / o,p,q } )
//	// c = b(gq - hp) - c(fq - ho) + d(fp - go)
//	// c = b(td) - c(te) + d(tf)
//
//	// d = -det( { b,c,d / f,g,h / k,l,m } )
//	// d = -( b(gm - hl) - c(fm - hk) + d(fl - gk) )
//	// d = -( b(tg) - c(th) + d(ti) )
//
//	// e = -det( { e,g,h / j,l,m / n,p,q } )
//	// e = - ( e(lq - mp) - g(jq - mn) + h(jp - ln))
//	// e = - ( e(ta) - g(tj) + h(tk))
//
//	// f = det( { a,c,d / j,l,m / n,p,q } )
//	// f = a(lq - mp) - c(jq - mn) + d(jp - ln)
//	// f = a(ta) - c(tj) + d(tk)
//
//	// g = -det( { a,c,d / e,g,h / n,p,q } )
//	// g = - ( a(gq - hp) - c(eq - hn) + d(ep - gn))
//	// g = - ( a(td) - c(tl) + d(tm))
//
//	// h = det( { a,c,d / e,g,h / j,l,m } )
//	// h = a(gm - hl) - c(em - hj) + d(el - gj)
//	// h = a(tg) - c(tn) + d(to)
//
//	// j = det( { e,f,h / j,k,m / n,o,q } )
//	// j = e(kq - mo) - f(jq - mn) + h(jo - kn)
//	// j = e(tb) - f(tj) + h(tp)
//
//	// k = -det( { a,b,d / j,k,m / n,o,q } )
//	// k = - ( a(kq - mo) - b(jq - mn) + d(jo - kn))
//	// k = - ( a(tb) - b(tj) + d(tp))
//
//	// l = det( { a,b,d / e,f,h / n,o,q } )
//	// l = a(fq - ho) - b(eq - hn) + d(eo - fn)
//	// l = a(te) - b(tl) + d(tr)
//
//	// m = -det( { a,b,d / e,f,h / j,k,m } )
//	// m = -( a(fm - hk) - b(em - hj) + d(ek - fj))
//	// m = -( a(th) - b(tn) + d(tq))
//
//	// n = -det( { e,f,g / j,k,l / n,o,p } )
//	// n = -( e(kp - lo) - f(jp - ln) + g(jo - kn))
//	// n = -( e(tc) - f(tk) + g(tp))
//
//	// o = det( { a,b,c / j,k,l / n,o,p } )
//	// o = a(kp - lo) - b(jp - ln) + c(jo - kn)
//	// o = a(tc) - b(tk) + c(tp)
//
//	// p = -det( { a,b,c / e,f,g / n,o,p } )
//	// p = - ( a(fp - go) - b(ep - gn) + c(eo - fn))
//	// p = - ( a(tf) - b(tm) + c(tr))
//
//	// q = det( { a,b,c / e,f,g / j,k,l } )
//	// q = a(fl - gk) - b(el - gj) + c(ek - fj)
//	// q = a(ti) - b(to) + c(tq)
//
//	Matrix tmp;
//
//	// load		ABC		(3)		ABC--
//	float t1 = (m10*m15) - (m11*m14);
//	float t2 = (m9*m15) - (m11*m13);
//	float t3 = (m9*m14) - (m10*m13);
//
//	// a = f(ta) - g(tb) + h(tc)
//	tmp.m0 = (m5*t1) - (m6*t2) + (m7*t3);
//	// b = -( b(ta) - c(tb) + d(tc))
//	tmp.m1 = -((m1*t1) - (m2*t2) + (m3*t3));
//
//	// load		JK		(5)		ABCJK
//	float t4 = (m8*m15) - (m11*m12);
//	float t5 = (m8*m14) - (m10*m12);
//	// e = - ( e(ta) - g(tj) + h(tk))
//	tmp.m4 = -((m4*t1) - (m6*t4) + (m7*t5));
//	// f = a(ta) - c(tj) + d(tk)
//	tmp.m5 = (m0*t1) - (m2*t4) + (m3*t5);
//
//	// unload	AJ		(3)		-BC-K
//	// load		P		(4)		PBC-K
//	t1 = (m8*m13) - (m9*m12);
//	// n = -( e(tc) - f(tk) + g(tp))
//	tmp.m12 = -((m4*t3) - (m5*t5) + (m6*t1));
//	// o = a(tc) - b(tk) + c(tp)
//	tmp.m13 = (m0*t3) - (m1*t5) + (m2*t1);
//
//	// unload	KC		(2)		PB---
//	// load		J		(3)		PBJ--
//	t3 = (m8*m15) - (m11*m12);
//
//	// j = e(tb) - f(tj) + h(tp)
//	tmp.m8 = (m4*t2) - (m5*t3) + (m7*t1);
//	// k = - ( a(tb) - b(tj) + d(tp))
//	tmp.m9 = -((m0*t2) - (m1*t3) + (m3*t1));
//
//	// unload	BPJ		(0)		-----
//	// load		DLM		(3)		DLM--
//	t1 = (m6*m15) - (m7*m14);
//	t2 = (m4*m15) - (m7*m12);
//	t3 = (m4*m14) - (m6*m12);
//
//	// g = - ( a(td) - c(tl) + d(tm))
//	tmp.m6 = -((m0*t1) - (m2*t2) + (m3*t3));
//
//	// load		FR		(5)		DLMFR
//	t4 = (m5*m14) - (m6*m13);
//	t5 = (m4*m13) - (m5*m12);
//
//	// p = - ( a(tf) - b(tm) + c(tr))
//	tmp.m14 = -((m0*t4) - (m1*t3) + (m3*t5));
//
//	// unload	M		(4)		DL-FR
//	// load		E		(5)		DLEFR
//	t3 = (m5*m15) - (m7*m13);
//
//	// l = a(te) - b(tl) + d(tr)
//	tmp.m10 = (m0*t3) - (m1*t2) + (m3*t5);
//
//	// unload	LR		(3)		D-EF-
//	// c = b(td) - c(te) + d(tf)
//	tmp.m2 = (m1*t1) - (m2*t3) + (m3*t4);
//
//	// unload	DEF		(0)		-----
//	// load		GHI		(3)		GHI--
//	t1 = (m6*m11) - (m7*m10);
//	t2 = (m5*m11) - (m7*m9);
//	t3 = (m5*m10) - (m6*m9);
//
//	// d = -( b(tg) - c(th) + d(ti) )
//	tmp.m3 = -((m1*t1) - (m2*t2) + (m3*t3));
//
//	// load		NO		(5)		GHINO
//	t4 = (m4*m11) - (m7*m8);
//	t5 = (m4*m10) - (m6*m8);
//
//	// h = a(tg) - c(tn) + d(to)
//	tmp.m7 = (m0*t1) - (m2*t4) + (m3*t5);
//
//	// unload	G		(4)		-HINO
//	// load		Q		(5)		QHINO
//	t1 = (m4*m9) - (m5*m8);
//
//	// m = -( a(th) - b(tn) + d(tq))
//	tmp.m11 = -((m0*t2) - (m1*t4) + (m3*t1));
//
//	// unload	HN		(3)		Q-I-O
//	// q = a(ti) - b(to) + c(tq)
//	tmp.m15 = (m0*t3) - (m1*t5) + (m2*t1);
//
//	return tmp;
//}





// End of file