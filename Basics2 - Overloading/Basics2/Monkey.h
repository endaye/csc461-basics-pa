#ifndef MONKEY_H
#define MONKEY_H

class Monkey
{
public:

	// insert your code here
	// big four constructors
	Monkey();
	Monkey(int x, int y, char *status);
	Monkey(const Monkey & monkey);
	~Monkey();
	
	// special constructor
	Monkey(int x, int y);

	// accessors
	int getX();
	int getY();
	char *getStatus();
	void printStatus();

	// global variables (incremented each creation or destruction)
	static int numStringsCreated;
	static int numStringsDestroyed;

private:
	int x;
	int y;
	char *status;
};


#endif