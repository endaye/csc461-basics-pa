#include "answerRegistry.h"
#include "A.h"

void vTableQuestions_B()
{

	// Class B:  Question 10-19
	
	// Only consider this class for this answer

	// Is there a vTable for this class?
	// (1 - true, 0 - false)

	QuestionAnswer( 10 , 1 );

	// How many jump vectors(pointers to functions) are in the vTable?
	//  (0 - no table, 1-N - number of jump vectors)?

	QuestionAnswer( 11 , 3 );

	// Next 8 questions, fill in the jump vector
	// Add the function label number 
	// Order is important, do not reorder the classes

	// 1st jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(12, 0xa005);

	// 2nd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(13, 0xa006);

	// 3rd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(14, 0xa007);

	// 4th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 15 , 0 );

	// 5th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 16 , 0 );

	// 6th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 17 , 0 );

	// 7th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 18 , 0 );

	// 8th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 19 , 0 );


}