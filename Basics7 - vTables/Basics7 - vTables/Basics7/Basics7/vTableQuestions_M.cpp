#include "answerRegistry.h"
#include "M.h"


void vTableQuestions_M()
{

	// Class M:  Question 70-79
	
	// Only consider this class for this answer

	// Is there a vTable for this class?
	// (1 - true, 0 - false)

	QuestionAnswer( 70 , 1 );

	// How many jump vectors(pointers to functions) are in the vTable?
	//  (0 - no table, 1-N - number of jump vectors)?

	QuestionAnswer( 71 , 1 );

	// Next 8 questions, fill in the jump vector
	// Add the function label number 
	// Order is important, do not reorder the classes

	// 1st jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(72, 0xF002);

	// 2nd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 73 , 0 );

	// 3rd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 74 , 0 );

	// 4th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 75 , 0 );

	// 5th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 76 , 0 );

	// 6th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 77 , 0 );

	// 7th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 78 , 0 );

	// 8th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 79 , 0 );


}