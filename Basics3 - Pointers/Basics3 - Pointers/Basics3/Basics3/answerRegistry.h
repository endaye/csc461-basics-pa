#ifndef ANSWER_REGISTRY_H
#define ANSWER_REGISTRY_H

#define NUM_ANSWERS (sizeof(answerData)/sizeof(answerData[0]))

//------------------------------------------------------------------
// DO NOT MODIFY anything in this file
//------------------------------------------------------------------

class Answer
{
	// question storage
	struct questionData
	{
		int index;
		unsigned int value;
	};

public:
	static void registerAnswer( int group, int questionNumber, unsigned int val );
	static unsigned int getAnswer( int group, int questionNumber );

private:
	Answer();
	~Answer() {};
	Answer( const Answer &copy);
	Answer & operator = ( const Answer &copy );

	static Answer *privGetInstance();

	void privRegisterAnswer( int group, int questionNumber, unsigned int val );
	unsigned int privGetAnswer( int group, int questionNumber );

	// Data
	questionData answerData[24];
	questionData answerData2[24];

};


#endif