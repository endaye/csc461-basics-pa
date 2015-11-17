#include "answerRegistry.h"
#include "M.h"


void vTableQuestions_N()
{

	// Class N:  Question 80-89
	
	// Only consider this class for this answer

	// Is there a vTable for this class?
	// (1 - true, 0 - false)

	QuestionAnswer( 80 , 1 );

	// How many jump vectors(pointers to functions) are in the vTable?
	//  (0 - no table, 1-N - number of jump vectors)?

	QuestionAnswer( 81 , 2 );

	// Next 8 questions, fill in the jump vector
	// Add the function label number 
	// Order is important, do not reorder the classes

	// 1st jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(82, 0xF008);

	// 2nd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(83, 0xF007);

	// 3rd jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer(84, 0);

	// 4th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 85 , 0 );

	// 5th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 86 , 0 );

	// 6th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 87 , 0 );

	// 7th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 88 , 0 );

	// 8th jump vector ?
    // (label number, 0- otherwise)

	QuestionAnswer( 89 , 0 );


}