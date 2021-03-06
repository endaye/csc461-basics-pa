// Test structures and classes for Problem 1 and 2
// Enjoy
// - Ed Keenan

struct Test_A
{
	char r;
	char g;
	char b;
};


struct Test_B
{
	int   x;
	int   y;
};


class Test_C
{
public:
	Test_C()
		:x(0x78787878), b('b')
	{

	}
	const unsigned int getSize4Each()
	{
		return sizeof(x) + sizeof(b);
	}
private:
	int   x;
	char  b;
};

class Test_D
{
public:
	Test_D()
		:c('c'), x(0x78787878), b('b')
	{

	}
	const unsigned int getSize4Each()
	{
		return sizeof(c) + sizeof(x) + sizeof(b);
	}
private:
	char  c;
	int   x;
	char  b;
};

struct Test_E
{
	void  *p;
	float x;
	int   y;
	char  a;
	char  b;
	char  c;
};

struct Test_F
{
	
	char   a;
	double t;
	float  s;
};

struct Test_G
{
	double t;
	float  s;
	char   a;
};

struct vect
{
	float vx;
	float vy;
	char  d;
	float vz;
	float vw;
};

struct Test_H
{
	int		a;
	vect	v1;
	char	c;
	int		b;
};

class Test_I
{
public:
	Test_I()
	{
		for (int i = 0; i < 63; i++)
		{
			name[i] = 0;
		}
		x = 0;
		z = 0;
		p = 0;
	}
	const unsigned int getSize4Each()
	{
		return sizeof(name) + sizeof(x) + sizeof(z) + sizeof(p);
	}
	char	name[63];
	int		x;
	char	z;
	int		*p;
};

struct Test_J
{
	char	name[122];
	int		x;
	char	z;
	double	d;
	int		*p;
	char	c;
	float	y;
};
