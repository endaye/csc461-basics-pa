#include "answerRegistry.h"
#include "A.h"


void vTableQuestions_A()
{

	// Class A:  Question 0-9
	
	// Only consider this class for this answer

	// Is there a vTable for this class?
	// (1 - true, 0 - false)

	QuestionAnswer( 0,  1 );

	// How many jump vectors(pointers to functions) are in the vTable?
	//  (0 - no table, 1-N - number of jump vectors)?

	QuestionAnswer( 1, 0 );

	// Next 8 questions, fill in the jump vector
	// Add the function label number 
	// Order is important, do not reorder the classes

	// 1st jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(2, 0);

	// 2nd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(3, 0);

	// 3rd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(4, 0);

	// 4th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 5 , 0 );

	// 5th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 6 , 0 );

	// 6th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 7 , 0 );

	// 7th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 8 , 0 );

	// 8th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 9 , 0 );


}