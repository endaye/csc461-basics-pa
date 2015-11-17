#include <assert.h>
#include <stdio.h>

#include "answerRegistry.h"

//------------------------------------------------------------------
// DO NOT MODIFY anything in this file
//------------------------------------------------------------------

Answer::Answer()
{
}

Answer *Answer::privGetInstance()
{
	static Answer instance;
	return &instance;
}

void Answer::registerAnswer( int group, int questionNumber, unsigned int val )
{
	Answer::privGetInstance()->privRegisterAnswer( group, questionNumber, val );
}

unsigned int Answer::getAnswer( int group, int questionNumber )
{
	return privGetInstance()->privGetAnswer(group, questionNumber );
}

void Answer::privRegisterAnswer( int group, int questionNumber, unsigned int val )
{
	assert( questionNumber >= 0 );
	assert( questionNumber < NUM_ANSWERS );

	if (group == 0 )
	{
		this->answerData[ questionNumber ].index = questionNumber;
		this->answerData[ questionNumber ].value = val;
	}
	else
	{
		this->answerData2[ questionNumber ].index = questionNumber;
		this->answerData2[ questionNumber ].value = val;
	}

	printf(" %d  %d  val:0x%x \n",group,questionNumber, val);
	
}

unsigned int Answer::privGetAnswer( int group, int questionNumber )
{	
	assert( questionNumber >= 0 );
	assert( questionNumber < NUM_ANSWERS );

	unsigned int val;

	if (group == 0)
	{
		val = this->answerData[ questionNumber ].value ;
	}
	else
	{
		val = this->answerData2[ questionNumber ].value ;
	}

	return val;

}