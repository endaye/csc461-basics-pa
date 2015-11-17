#include "answerRegistry.h"
#include "C.h"


void vTableQuestions_C()
{

	// Class C:  Question 20-29
	
	// Only consider this class for this answer

	// Is there a vTable for this class?
	// (1 - true, 0 - false)

	QuestionAnswer( 20 , 1 );

	// How many jump vectors(pointers to functions) are in the vTable?
	//  (0 - no table, 1-N - number of jump vectors)?

	QuestionAnswer( 21 , 1 );

	// Next 8 questions, fill in the jump vector
	// Add the function label number 
	// Order is important, do not reorder the classes

	// 1st jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(22, 0xc001);

	// 2nd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 23 , 0 );

	// 3rd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 24 , 0 );

	// 4th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 25 , 0 );

	// 5th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 26 , 0 );

	// 6th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 27 , 0 );

	// 7th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 28 , 0 );

	// 8th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 29 , 0 );


}