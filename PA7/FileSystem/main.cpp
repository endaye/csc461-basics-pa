// LoadInPlace.cpp : Defines the entry point for the console application.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "List.h"
#include "Node.h"
#include "output.h"

int main()
{
	// Create the IO for this program, that's WHERE YOU PUT YOUR NAME, please change it.
	io::create("<YOUR NAME>");

	// Do not modify this function, you need to leave this routine alone.
	// It initializes the data if a very disjointed way do not modify it!
	List::CreateLinkedList();

	// Output Original Nodes
  	fprintf(io::getHandle(),"Original nodes in Memory\n\n");
    List::dumpList();

   // SECTION 1:  Under grads only
   //        1) Create a new Binary file
   //             a) open new binary file
   //             b) write code to copy the node data to a binary file
   //             c) close file
   //        2) Read the Binary file
   //             a) open file
   //             b) write code to load(read) data from your binary file
   //        3) Recreate the linked list from your loaded data
   //             a) add functions to the linked list to help with this task
   //             b) after loaded and linked, close file
   //        4) Print the linked list data, (like sample) 
   //             a) obviously your pointers will be different, but not your data
   //             b) append to existing output file



	return 0;
}

