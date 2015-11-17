#include <stdio.h>
#include <string.h>

#include "Monkey.h"

int Monkey::numStringsCreated = 0;
int Monkey::numStringsDestroyed = 0;

Monkey::Monkey()
{
	x = 111;
	y = 222;
	status = new char [strlen("Initialized with default")+1];
	strcpy(status, "Initialized with default");
	numStringsCreated++;
}

Monkey::Monkey(int x1, int y1, char *status1)
{
	x = x1;
	y = y1;
	status = new char[strlen(status1)];
	strcpy(status, status1);
	numStringsCreated++;
}

Monkey::Monkey(const Monkey & monkey)
{
	x = monkey.x;
	y = monkey.y;
	status = new char[strlen(monkey.status)];
	strcpy(status, monkey.status);
	numStringsCreated++;
}

Monkey::~Monkey()
{
	delete status;
	numStringsDestroyed++;
}


Monkey::Monkey(int x1, int y1)
{
	x = x1;
	y = y1;
	status = new char[strlen("Initialized by user") + 1];
	strcpy(status, "Initialized by user");
	numStringsCreated++;
}

// ================

int Monkey::getX()
{
	return this->x;
}

int Monkey::getY()
{
	return this->y;
}

char *Monkey::getStatus()
{
	return this->status;
};

void Monkey::printStatus()
{
	printf("Monkey (Status): %s\n", this->status);
}


// END of File