#ifndef NODE_H
#define NODE_H


class Node
{
public:
	Node();

	void setNext(Node *p);
	void setPrev(Node *p);
	Node * getNext();
	Node * getPrev();
   void dumpNode();
   void setKey( unsigned int in);

private:
	void getRandInt(int & var);

public:
	Node	*next;
	Node	*prev;
	int   x;
	int   y;
	int   z;
	int	key;
};

#endif //NODE_H