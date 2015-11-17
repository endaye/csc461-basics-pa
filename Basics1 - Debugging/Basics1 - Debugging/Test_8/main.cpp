#include <stdio.h>

// ----------------------------------------------------------------------
// Problem 8:
//
// Rules: Fix the code to have the correct day printing for St Pat's day.
//        Please keep the virtual function init() as a restriction
//        You can make this work with a small addition
// ----------------------------------------------------------------------

class Holiday
{
public:
	virtual void init()
	{
	}
	
	Holiday() 
	{
		init(); 
	}
};

class StPats : public Holiday
{
public:
	const char *day;
	
	virtual void init() override
	{ 
		day = "March 17"; 
	}

	StPats()
	{
		init();
	}
};

// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
int main()
{	
	// test 8 header
	printf("\nTest_8: \n\n");

	StPats x; 

	printf( "St Patrick's Day is %s\n" , x.day );
	
	return 0;
}