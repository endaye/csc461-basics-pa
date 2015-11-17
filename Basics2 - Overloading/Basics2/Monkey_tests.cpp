#include <string.h>

#include "UnitTest.h"
#include "Monkey.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
// ---------------------------------------------------------------------------------
int Monkey::numStringsCreated = 0;
int Monkey::numStringsDestroyed = 0;

TEST( SimpleCreate, MonkeyGroup )
{
	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK( Monkey::numStringsCreated == 0 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	Monkey	red_mono;

	CHECK( red_mono.getX() == 111 );
	CHECK( red_mono.getY() == 222 );
	CHECK( strcmp(red_mono.getStatus(),"Initialized with default") == 0) ; 
	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 0 );
}


TEST( Scope, MonkeyGroup )
{
	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK( Monkey::numStringsCreated == 0 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	if (1) 
	{
		Monkey	red_mono;

		CHECK( red_mono.getX() == 111 );
		CHECK( red_mono.getY() == 222 );
		CHECK( strcmp(red_mono.getStatus(),"Initialized with default") == 0) ; 
		CHECK( Monkey::numStringsCreated == 1 );
		CHECK( Monkey::numStringsDestroyed == 0 );
	}

	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 1 );
}


TEST( new_function, MonkeyGroup )
{
	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK( Monkey::numStringsCreated == 0 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	Monkey	*red_mono = new Monkey();

	CHECK( red_mono->getX() == 111 );
	CHECK( red_mono->getY() == 222 );
	CHECK( strcmp(red_mono->getStatus(),"Initialized with default") == 0) ; 
	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	delete red_mono;

	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 1 );
}


TEST( SpecializedConstructor, MonkeyGroup )
{
	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK( Monkey::numStringsCreated == 0 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	Monkey blue_mono(777,888);

	CHECK( blue_mono.getX() == 777 );
	CHECK( blue_mono.getY() == 888 );
	CHECK( strcmp(blue_mono.getStatus(),"Initialized by user") == 0) ; 
	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 0 );

}

TEST( CopyConstructor, MonkeyGroup )
{
	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK( Monkey::numStringsCreated == 0 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	Monkey blue_mono(777,888);

	CHECK( blue_mono.getX() == 777 );
	CHECK( blue_mono.getY() == 888 );
	CHECK( strcmp(blue_mono.getStatus(),"Initialized by user") == 0) ; 
	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	Monkey green_mono( blue_mono );

	CHECK( green_mono.getX() == 777 );
	CHECK( green_mono.getY() == 888 );
	CHECK( strcmp(green_mono.getStatus(),"Initialized by user") == 0) ; 
	CHECK( Monkey::numStringsCreated == 2 );
	CHECK( Monkey::numStringsDestroyed == 0 );
}


TEST( AssignmentOp, MonkeyGroup )
{
	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK( Monkey::numStringsCreated == 0 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	Monkey *yellow_mono = new Monkey( 444, 555 );

	CHECK( yellow_mono->getX() == 444 );
	CHECK( yellow_mono->getY() == 555 );
	CHECK( strcmp(yellow_mono->getStatus(),"Initialized by user") == 0) ; 
	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	*yellow_mono = *yellow_mono;

	CHECK( yellow_mono->getX() == 444 );
	CHECK( yellow_mono->getY() == 555 );
	CHECK( strcmp(yellow_mono->getStatus(),"Initialized by user") == 0) ; 
	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	delete yellow_mono;

	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 1 );
}


TEST( AssignmentOp2, MonkeyGroup )
{
	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK( Monkey::numStringsCreated == 0 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	Monkey	*red_mono = new Monkey();

	CHECK( red_mono->getX() == 111 );
	CHECK( red_mono->getY() == 222 );
	CHECK( strcmp(red_mono->getStatus(),"Initialized with default") == 0) ; 
	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 0 );
	
	Monkey *yellow_mono = new Monkey( 444, 555 );

	CHECK( yellow_mono->getX() == 444 );
	CHECK( yellow_mono->getY() == 555 );
	CHECK( strcmp(yellow_mono->getStatus(),"Initialized by user") == 0) ; 
	CHECK( Monkey::numStringsCreated == 2 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	*yellow_mono = *red_mono;

	CHECK( yellow_mono->getX() == 111 );
	CHECK( yellow_mono->getY() == 222 );
	CHECK( strcmp(yellow_mono->getStatus(),"Initialized with default") == 0) ; 
	CHECK( Monkey::numStringsCreated == 3 );
	CHECK( Monkey::numStringsDestroyed == 1 );

	delete yellow_mono;

	CHECK( Monkey::numStringsCreated == 3 );
	CHECK( Monkey::numStringsDestroyed == 2 );

	delete red_mono;

	CHECK( Monkey::numStringsCreated == 3 );
	CHECK( Monkey::numStringsDestroyed == 3 );
}