#ifndef BUFFER_MANAGER_H
#define BUFFER_MANAGER_H



// Singleton to track the number of allocations (needed to detect leaks)
class bufferManager
{
public:
	static bufferManager *getInstance()
	{
		return privGetInstance();
	}

	void increment()
	{
		this->numBuffers++;
	}

	void decrement()
	{
		this->numBuffers--;
	}

	int getCount()
	{
		return this->numBuffers;
	}

private:
	static bufferManager *privGetInstance()
	{
		static bufferManager instance;
		return &instance;
	}

	bufferManager()
	: numBuffers(0)
	{
	}

	int numBuffers;
};



#endif