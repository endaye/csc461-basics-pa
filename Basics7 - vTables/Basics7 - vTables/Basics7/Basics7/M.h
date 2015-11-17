#ifndef M_H
#define M_H


// Do not change these classes,
// Feel free to add debug information, 
// but do not rearrange!

class M
{
public:
	M()
	: a(11)
	{
		// Label:  0xF000
	}

	int weight()
	{
		// Label:  0xF001
		return this->a;
	}

	virtual int max()
	{
		// Label:  0xF002
		return this->a;
	}

	void foo()
	{
		// Label:  0xF003
		this->a += 10;
	}

	~M()
	{
		// Label:  0xF004
	}

protected:
	int a;
};


class N : public M
{
public:
	N()
	: b(22)
	{
		// Label:  0xF005
	}

	void foo()
	{
		// Label:  0xF006
		a += 3;
	}

	virtual int weight()
	{
		// Label:  0xF007
		return this->a + this->b;
	}

	virtual int max()
	{
		// Label:  0xF008
		int max = this->a;

		if ( this->a > this->b)
		{
			max = this->a;
		}
		else
		{
			max = this->b;
		}
		return max;
	}


	~N()
	{
		// Label:  0xF009
	}

protected:
	int b;


};

class O : public N
{
public:
	O()
	: c(33)
	{
		// Label:  0xF00A
	}

	void foo()
	{
		// Label:  0xF00B
		a += 3;
	}

	int weight()
	{
		// Label:  0xF00C
		return this->a + this->b + this->c;
	}


	~O()
	{
		// Label:  0xF00D
	}

private:
	int c;

};









#endif