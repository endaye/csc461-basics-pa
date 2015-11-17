#ifndef ANSWER_REGISTRY_H
#define ANSWER_REGISTRY_H

#define NUM_ANSWERS (sizeof(answerData)/sizeof(answerData[0]))
#define QuestionAnswer(x,y)  Answer::registerAnswer(x,y)
#define WRONG_ANSWER  0x3333


class Answer
{
	// question storage
	struct questionData
	{
		int index;
		unsigned int value;
	};

public:
	static void registerAnswer( int questionNumber, unsigned int val );
	static unsigned int getAnswer( int questionNumber );

private:
	Answer();
	~Answer() {};
	Answer( const Answer &copy);
	Answer & operator = ( const Answer &copy );

	static Answer *privGetInstance();

	void privRegisterAnswer( int questionNumber, unsigned int val );
	unsigned int privGetAnswer( int questionNumber );

	// Data
	questionData answerData[100];


};


#endif