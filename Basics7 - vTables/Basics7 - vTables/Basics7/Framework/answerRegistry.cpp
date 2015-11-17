#include <assert.h>
#include <stdio.h>

#include "answerRegistry.h"


Answer::Answer()
{
}

Answer *Answer::privGetInstance()
{
	static Answer instance;
	return &instance;
}

void Answer::registerAnswer( int questionNumber, unsigned int val )
{
	Answer::privGetInstance()->privRegisterAnswer( questionNumber, val );
}

unsigned int Answer::getAnswer( int questionNumber )
{
	return privGetInstance()->privGetAnswer( questionNumber );
}

void Answer::privRegisterAnswer(  int questionNumber, unsigned int val )
{
	assert( questionNumber >= 0 );
	assert( questionNumber < NUM_ANSWERS );


	this->answerData[ questionNumber ].index = questionNumber;
	this->answerData[ questionNumber ].value = val;

	printf("  %d  val:0x%x \n", questionNumber, val);
	
}

unsigned int Answer::privGetAnswer(  int questionNumber )
{	
	assert( questionNumber >= 0 );
	assert( questionNumber < NUM_ANSWERS );

	unsigned int val;

	val = this->answerData[ questionNumber ].value ;


	return val;

}