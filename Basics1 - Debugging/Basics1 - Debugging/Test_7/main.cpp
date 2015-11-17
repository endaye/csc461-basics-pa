#include <stdio.h>

// ----------------------------------------------------------------------
// Problem 7:
//
// Rules: Fix the code below to have the correct number of components in Car
// ----------------------------------------------------------------------

class Car
{ 
public:
	enum class Color
	{ 
		Blue, 
		Red,
		Black,
		White
	} color;

	int	wheelDrive = 0;
	int	numDoors = 0;
	int	wings = 0;

};

class Volkswagon : public Car
{
 public: 
	Volkswagon()
	{ 
		wheelDrive = 2; 
		numDoors = 4;
	}
};

class Audi: public Volkswagon
{ 
public:
	Audi() 
	{ 
		color = Color::Black;
		wheelDrive += 2; 
	}

};

// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
int main()
{	
	// test 7 header
	printf("\nTest_7: \n\n");

	Audi m;

	printf("Expected: Color:2 numDoors:4 wheelDrive:4 wings:0\n" );
	printf("  Actual: Color:%d numDoors:%d wheelDrive:%d wings:%d\n", m.color, m.numDoors, m.wheelDrive, m.wings);

	return 0;
}