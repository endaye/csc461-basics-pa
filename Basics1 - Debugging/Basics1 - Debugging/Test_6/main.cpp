#include <stdio.h>

// ----------------------------------------------------------------------
// Problem 6:
//
// Rules: Dog's don't meow
//        Fix the code to have the dog bark
// ----------------------------------------------------------------------

class Animal
{ 
public:
	Animal( ) 
	: action("meow") 
	{ 
	}

	Animal(const Animal & a) 
	:action(a.action)  
	{ 
	}
    
	const char *action;

};

class Dog : public Animal
{ 
public:
	Dog() 
	{ 
		action = "bark"; 
	}

	Dog( const Dog & ) 
	{ 
		action = "bark";
	}

};

// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
void printME( const Dog d )
{
	printf( "Dogs %s\n", d.action );
}


// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
int main()
{
	// test 6 header
	printf("\nTest_6: \n\n");

	// create a Dog
	Dog fido;

	// print the Dog's Action
	printME( fido );
       
	return 0;
}