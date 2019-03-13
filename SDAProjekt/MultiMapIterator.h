#pragma once

#include "MultiMap.h"

class Iterator
{
private:

public:
	HashMap hm;
	int currPos, currElem;
	LinkedList* currNode;

	// Constructor + Destructor
	Iterator(HashMap hm);
	~Iterator();

	void init(HashMap map);
	//void initArray();

	// Valid + Next
	bool valid();
	void next();

	// get
	TElem getCurrent();
		
};