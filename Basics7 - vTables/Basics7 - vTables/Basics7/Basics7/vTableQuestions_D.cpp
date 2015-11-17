#include "answerRegistry.h"
#include "C.h"


void vTableQuestions_D()
{

	// Class D:  Question 30-39
	
	// Only consider this class for this answer

	// Is there a vTable for this class?
	// (1 - true, 0 - false)

	QuestionAnswer( 30 , 1 );

	// How many jump vectors(pointers to functions) are in the vTable?
	//  (0 - no table, 1-N - number of jump vectors)?

	QuestionAnswer( 31 , 1 );

	// Next 8 questions, fill in the jump vector
	// Add the function label number 
	// Order is important, do not reorder the classes

	// 1st jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(32, 0xc006);

	// 2nd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(33, 0);

	// 3rd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 34 , 0 );

	// 4th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 35 , 0 );

	// 5th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 36 , 0 );

	// 6th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 37 , 0 );

	// 7th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 38 , 0 );

	// 8th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 39 , 0 );


}