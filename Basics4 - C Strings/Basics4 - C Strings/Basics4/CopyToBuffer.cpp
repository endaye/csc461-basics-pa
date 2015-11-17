#include <stdio.h>
#include <string.h>

#include "CopyToBuffer.h"


// retrieve the message
char * dog::getMessage()
{
	return this->buff;
}
	
// user sets the message
void dog::setMessage( const char * const inMessage )
{
	// Do the copy to internal variable buff
	// make sure it's safe
	// ----> do work here
	int len = 0;
	if (inMessage != 0)
	{
		len = BUFF_SIZE < strlen(inMessage) + 1 ? BUFF_SIZE - 1 : strlen(inMessage);
		memcpy(this->buff, inMessage, len);
	}
	this->buff[len] = '\0';
	//strcpy(this->buff, inMessage);

}

// prints the mesage
void dog::print()
{
	printf("message: %s\n",this->buff);
}


dog::dog()
{
	memset( this->buff, 0xaa, BUFF_SIZE );
}

dog::~dog()
{
	memset( this->buff, 0xaa, BUFF_SIZE );
}


