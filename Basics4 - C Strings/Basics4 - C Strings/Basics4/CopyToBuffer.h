#ifndef COPY_TO_BUFFER_H
#define COPY_TO_BUFFER_H

#define BUFF_SIZE 10

class dog
{
public:
	dog();
	~dog();

	// retrieve the message
	char *getMessage();
	
	// user sets the message
	void setMessage( const char * const inMessage );
	
	// prints the mesage
	void print();

private:

	// holds the message
	char buff[BUFF_SIZE];

};


#endif


