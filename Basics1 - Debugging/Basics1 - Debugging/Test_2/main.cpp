#include <stdio.h>

// ----------------------------------------------------------------------
// Problem 2:
//
// Rules: fix the classes to make the function work as intended
//        construction of the object should print "Hello"
//        destruction of the object should print "Goodbye"
//        in the appropriate language
// ----------------------------------------------------------------------

class Person 
{ 
public: 
	Person()
	{
	}

	virtual ~Person()
	{
	} 
};

class Italian : public Person
{ 
public: 
	Italian()
	{
		printf( "Ciao\n" );
	}
	virtual ~Italian()
	{ 
		printf( "Arrivederci\n\n" ); 
	} 
};

class French : public Person
{ 
public: 
	French()
	{
		printf( "Bonjour\n" );
	}
	virtual ~French()
	{ 
		printf( "Au revoir\n\n" ); 
	} 
};

class Spanish : public Person
{ 
public: 
	Spanish()
	{
		printf( "Hola!\n" );
	}
	virtual ~Spanish()
	{ 
		printf( "Adios\n\n" ); 
	} 
};

// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
int main()
{
	// test 2 header
	printf("\nTest_2: \n\n");

	// Person pointer
	Person *p;

	// hello goodbye in Spanish	
	p = new Spanish;
    delete p;
       
	// hello goodbye in French
	p = new French;
    delete p;

	// hello goodbye in Italian
	p = new Italian;
    delete p;

    return 0;
}

