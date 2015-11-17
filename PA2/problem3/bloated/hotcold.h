#ifndef HOTCOLD_H
#define HOTCOLD_H

#include "Node.h"
class HotNode;

class HotCold
{
public:
	HotCold();
	~HotCold();

	static void HotCold::convert(OriginalNode *pOrigHead);
	static bool HotCold::findKey(int key, ColdNode &foundNode);
	static HotNode *getListHead();
	void static HotCold::verify();

private:
	static HotNode *head;
};

#endif //hotcold.h
