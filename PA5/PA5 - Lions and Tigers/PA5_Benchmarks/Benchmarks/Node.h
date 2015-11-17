#ifndef NODE_H
#define NODE_H

struct Vect_t
{
public:
	float x;
	float y;
	float z;

	bool operator == (const Vect_t & t) const
	{
		return ( (this->x == t.x)&&(this->y == t.y)&&(this->z == t.z) );
	}
};

struct Matrix_t
{
	float m00;
	float m01;
	float m02;
	float m03;
	float m10;
	float m11;
	float m12;
	float m13;
	float m20;
	float m21;
	float m22;
	float m23;
	float m30;
	float m31;
	float m32;
	float m33;

	bool operator == (const Matrix_t & t) const
	{
		return ( (this->m00 == t.m00)&&(this->m01 == t.m01)&&(this->m02 == t.m02)&&(this->m03 == t.m03)  
			  && (this->m10 == t.m10)&&(this->m11 == t.m11)&&(this->m12 == t.m12)&&(this->m13 == t.m13)  
		  	  && (this->m20 == t.m20)&&(this->m21 == t.m21)&&(this->m22 == t.m22)&&(this->m23 == t.m23)  
			  && (this->m30 == t.m30)&&(this->m31 == t.m31)&&(this->m32 == t.m32)&&(this->m33 == t.m33)  	);
	}
};

#define NAME_SIZE 128

class OriginalNode
{
public:
	OriginalNode();

	void setNext(OriginalNode *p);
	void setPrev(OriginalNode *p);
	OriginalNode * getNext();
	OriginalNode * getPrev();

private:
	void getRandFloat(float & var);
	void getRandInt(int & var);
	void getRandVect(Vect_t & var);
	void getRandMatrix(Matrix_t & var);
	void getRandName(char * p, const int size);
	char getRandChar();

public:
	OriginalNode	*next;
	OriginalNode	*prev;
	float			   x;
	float			   y;
	float			   z;
	Vect_t			A;
	Vect_t			B;
	Vect_t			C;
	Matrix_t		   MA;
	Matrix_t		   MB;
	Matrix_t		   MC;
	Matrix_t		   MD;
	char			   name[NAME_SIZE];
	int				key;
};

#endif //NODE_H