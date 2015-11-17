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
	int   x;
	char  b;
	char  c;
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
	double t; 
	float  s; 
	char   a;
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
	float vz;
	float vw;
	char  d;
};

struct Test_H
{
	vect  v1;
	int   a;
	int   b;
	char  c;
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
	int		x;
	int		*p;
	char	name[63];
	char	z;
};

struct Test_J
{
	double  d;
	float	y;
	int     x;
	int		*p;
	char	name[122];
	char	c;
	char	z;
};
