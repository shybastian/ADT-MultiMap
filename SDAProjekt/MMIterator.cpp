#include "stdafx.h"
#include "MultiMapIterator.h"

Iterator::Iterator(HashMap map)
{
	this->hm = map;
	this->currNode = NULL;
	this->currPos = 0;
	this->currElem = 0;
}

Iterator::~Iterator()
{
}

void Iterator::init(HashMap map)
{
	this->hm = map;
	this->currPos = 0;
	this->currElem = 0;
	while ((this->currPos < map.size) && (map.table[this->currPos] == NULL))
	{
		this->currPos = this->currPos + 1;
	}
	if (this->currPos < map.size)
	{
		this->currNode = map.table[this->currPos];
	}
	else
	{
		this->currNode = NULL;
	}
}

TElem Iterator::getCurrent()
{
	return this->currNode->getValues().getAllElems()[this->currElem];
}

void Iterator::next()
{
	if (this->currElem < this->currNode->getValues().getSize()-1)
	{
		this->currElem = this->currElem + 1;
	}
	else
	{
		this->currElem = 0;
		if (this->currNode->getNext() != NULL)
		{
			this->currNode = this->currNode->getNext();
		}
		else if (this->currNode->getNext() == NULL)
		{
			this->currPos = this->currPos + 1;
			while ((this->currPos < this->hm.size) && (this->hm.table[this->currPos] == NULL))
			{
				this->currPos = this->currPos + 1;
			}
			if (this->currPos != NULL)
			{
				this->currNode = this->hm.table[this->currPos];
			}
			else
			{
				this->currNode = NULL;
			}
		}
	}
}

bool Iterator::valid()
{
	if (this->currNode == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}