#ifndef BLOATED_H
#define BLOATED_H

// forward declaration - always try to do this before including a header, in a header (Keenan)
class OriginalNode;

// needs to be this value, do not change in final submission
#define NUM_NODES 1000000

class Bloated
	{
	public:
		Bloated();	
		~Bloated();

		static void CreateLinkedList();
		static bool Bloated::findKey(int key, OriginalNode &foundNode);
		static OriginalNode *getListHead();
	private:
		static OriginalNode *head;
	};


#endif //bloated.h
