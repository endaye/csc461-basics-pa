#include "answerRegistry.h"
#include "E.h"


void vTableQuestions_G()
{

	// Class G:  Question 60-69
	
	// Only consider this class for this answer

	// Is there a vTable for this class?
	// (1 - true, 0 - false)

	QuestionAnswer( 60 , 1 );

	// How many jump vectors(pointers to functions) are in the vTable?
	//  (0 - no table, 1-N - number of jump vectors)?

	QuestionAnswer( 61 , 2 );

	// Next 8 questions, fill in the jump vector
	// Add the function label number 
	// Order is important, do not reorder the classes

	// 1st jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(62, 0xe00d);

	// 2nd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(63, 0xe00c);

	// 3rd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(64, 0);

	// 4th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(65, 0);

	// 5th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 66 , 0 );

	// 6th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 67 , 0 );

	// 7th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 68 , 0 );

	// 8th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 69 , 0 );


}