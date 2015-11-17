#ifndef E_H
#define E_H


// Do not change these classes,
// Feel free to add debug information, 
// but do not rearrange!

class E
{
public:
	E()
	: a(11)
	{
		// Label:  0xe000
	}

	virtual int weight()
	{
		// Label:  0xe001
		return this->a;
	}

	virtual int max()
	{
		// Label:  0xe002
		return this->a;
	}

	void foo()
	{
		// Label:  0xe003
		this->a += 10;
	}

	~E()
	{
		// Label:  0xe004
	}

protected:
	int a;
};


class F : public E
{
public:
	F()
	: b(22)
	{
		// Label:  0xe005
	}

	void foo()
	{
		// Label:  0xe006
		a += 3;
	}

	int weight()
	{
		// Label:  0xe007
		return this->a + this->b;
	}

	int max()
	{
		// Label:  0xe008
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


	~F()
	{
		// Label:  0xe009
	}

private:
	int b;


};




class G : public E
{
public:
	G()
	: c(22)
	{
		// Label:  0xe00a
	}

	void foo()
	{
		// Label:  0xe00b
		a += 33;
	}

	int max()
	{
		// Label:  0xe00c
		int max = this->a;

		if ( this->a > this->c)
		{
			max = this->a;
		}
		else
		{
			max = this->c;
		}
		return max;
	}

	int weight()
	{
		// Label:  0xe00d
		return this->a + this->c;
	}

	~G()
	{
		// Label:  0xe00e
	}

private:
	int c;


};







#endif