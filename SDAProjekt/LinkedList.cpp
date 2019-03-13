#include "stdafx.h"
#include "LinkedList.h"

LinkedList::LinkedList(TKey key, TValue values)
{
	this->key = key;
	this->values = values;
	this->next = NULL;
}

LinkedList::~LinkedList()
{
	this->values.~DynamicArray();
	this->next = NULL;
//	free(this);
}

int LinkedList::getKey() const
{
	return key;
}

/*Bus LinkedList::getValue(int index) const
{
return this->values[index];
}*/

LinkedList * LinkedList::getNext()
{
	return next;
}

void LinkedList::setNext(LinkedList *next)
{
	this->next = next;
}

DynamicArray LinkedList::getValues()
{
	return this->values;
}

void LinkedList::addValue(TElem elem)
{
	values.add(elem);
}

void LinkedList::deleteValue(TElem elem)
{
	values.deleteElem(elem);
}