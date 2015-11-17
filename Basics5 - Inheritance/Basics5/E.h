#ifndef E_H
#define E_H

// RULES:

// Modify the classes to pass tests
// The class should be in a diamond inheritance pattern
// Only one variable in (H: a,b,c,d ) no duplicates or replicas

class E
{
public:
	E()
	: a(11)
	{
	}

	void foo()
	{
	}

	int a;
};

class F : virtual public  E
{
public:
	F()
	: b(22)
	{
	}

	void foo()
	{
	}

	int b;
};


class G : virtual public  E
{
public:
	G()
	: c(33)
	{
	}

	void foo()
	{
	}

	int c;
};


class H: public F, public G
{
public:
	H()
	: d(44)
	{
	}

	void  foo()
	{
	}

	int d;
};











#endif