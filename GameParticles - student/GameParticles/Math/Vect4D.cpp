#include <math.h>
#include <assert.h>

#include <xmmintrin.h>
#include <smmintrin.h> 
#include "Vect4D.h"


/*Vect4D::Vect4D()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->w = 1.0f;
}

Vect4D::Vect4D(float tx, float ty, float tz, float tw)
{
	this->x = tx;
	this->y = ty;
	this->z = tz;
	this->w = tw;
}

//Vect4D::Vect4D(const __m128 &M)
//{
//	this->m = M;
//}

Vect4D::~Vect4D()
{
	// nothing to delete
}

void Vect4D::operator = (const Vect4D &tmp)
{
	this->x = tmp.x;
	this->y = tmp.y;
	this->z = tmp.z;
	this->w = tmp.w;
};





Vect4D Vect4D::operator + (Vect4D &t) const
{
	//return Vect4D(_mm_add_ps(this->m, t.m));
	Vect4D out;
	out.x = this->x + t.x;
	out.y = this->y + t.y;
	out.z = this->z + t.z;
	return out;
}

Vect4D Vect4D::operator - (Vect4D &t) const
{
	Vect4D out;

	out.x = this->x - t.x;
	out.y = this->y - t.y;
	out.z = this->z - t.z;

	return out;
}

Vect4D Vect4D::operator *(float scale) const
{
	Vect4D tmp;

	tmp.x = this->x * scale;
	tmp.y = this->y * scale;
	tmp.z = this->z * scale;

	return tmp;
}

void Vect4D::set(float tx, float ty, float tz, float tw)
{
this->x = tx;
this->y = ty;
this->z = tz;
this->w = tw;
}


float& Vect4D::operator[](VECT_ENUM e)
{
	switch (e)
	{
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	case 2:
		return z;
		break;
	case 3:
		return w;
		break;
	default:
		assert(0);
		return x;
	}
}
*/
void Vect4D::updatePos(const float life)
{
	//Vect4D z_axis(0.0f, -0.25f, 1.0f);
	float tx, ty, tz;
	//tx = (this->y*z_axis.z - this->z*z_axis.y);
	//ty = (this->z*z_axis.x - this->x*z_axis.z);
	//tz = (this->x*z_axis.y - this->y*z_axis.x);
	tx = (this->y - this->z*(-0.25f));
	ty = (0.0f - this->x);
	tz = (this->x * (-0.25f));

	if (tx == 0.0f && ty == 0.0f && tz == 0.0f)
	{
		return;
	}

	// float mag = SqrtOpt(tx * tx + ty * ty + tz * tz) * 20.0f / life;
	float mag = tx * tx + ty * ty + tz * tz;
	float xhalf = 0.5f * mag;
	int i = *(int*)&mag; // get bits for floating value
	i = 0x5f375a86 - (i >> 1); // gives initial guess y0
	mag = *(float*)&i; // convert bits back to float
	mag = mag * (1.5f - xhalf * mag * mag) * 0.05f * life; // Newton step, repeating increases accuracy

	//position += v * (0.05f * life);
	this->x += tx * mag;
	this->y += ty * mag;
	this->z += tz * mag;
	//this->w += mag;
}

/*
void Vect4D::norm(Vect4D& out)
{
	if (this->x == 0.0f && this->y == 0.0f && this->z == 0.0f)
	{
		return;
	}

	float mag = sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
	//float mag = SqrtOpt(this->x * this->x + this->y * this->y + this->z * this->z);

	out.x /= mag;
	out.y /= mag;
	out.z /= mag;
	out.w = 1.0f;

}

void Vect4D::Cross(const Vect4D& vin, Vect4D& vout) const
{
	vout.x = (y*vin.z - z*vin.y);
	vout.y = (z*vin.x - x*vin.z);
	vout.z = (x*vin.y - y*vin.x);
	vout.w = 0.0f;
}

float Vect4D::SqrtOpt(float x)
{
	float xhalf = 0.5f * x;
	int i = *(int*)&x; // get bits for floating value
	i = 0x5f375a86 - (i >> 1); // gives initial guess y0
	x = *(float*)&i; // convert bits back to float
	x = x * (1.5f - xhalf * x * x); // Newton step, repeating increases accuracy
	return 1.0f / x; // return sqrt root
}

*/
// End of file