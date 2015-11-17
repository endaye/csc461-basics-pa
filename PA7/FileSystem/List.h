#ifndef LIST_H
#define LIST_H

// forward declaration - always try to do this before including a header, in a header (Keenan)
class Node;

// List class
class List
{
	public:
		List();	
		~List();

		static void CreateLinkedList();
		static Node *getListHead();
      static void dumpList();

	private:
		static Node *head;
};


#endif //List.h
