#include "answerRegistry.h"
#include "E.h"


void vTableQuestions_F()
{

	// Class F:  Question 50-59
	
	// Only consider this class for this answer

	// Is there a vTable for this class?
	// (1 - true, 0 - false)

	QuestionAnswer( 50 , 1 );

	// How many jump vectors(pointers to functions) are in the vTable?
	//  (0 - no table, 1-N - number of jump vectors)?

	QuestionAnswer( 51 , 2 );

	// Next 8 questions, fill in the jump vector
	// Add the function label number 
	// Order is important, do not reorder the classes

	// 1st jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(52, 0xe007);

	// 2nd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(53, 0xe008);

	// 3rd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(54, 0);

	// 4th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(55, 0);

	// 5th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 56 , 0 );

	// 6th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 57 , 0 );

	// 7th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 58 , 0 );

	// 8th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 59 , 0 );


}