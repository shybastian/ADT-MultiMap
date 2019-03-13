#pragma once
#include "DynamicArray.h"


typedef DynamicArray TValue;
typedef int TKey;

class LinkedList
{
private:
	/*
	TKey key;
	TValue values;
	LinkedList *next;
	*/

public:
	TKey key;
	TValue values;
	LinkedList *next;
	//Constructor
	LinkedList(TKey key, TValue values);

	//Destructor
	~LinkedList();

	//Accessori + Setteri
	int getKey() const;
	DynamicArray getValues();
	void addValue(TElem elem);
	void deleteValue(TElem elem);
	LinkedList *getNext();
	void setNext(LinkedList *next);
	
};