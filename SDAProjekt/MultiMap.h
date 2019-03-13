#pragma once

#include "LinkedList.h"
#include "DynamicArrayKeys.h"

const int TABLE_SIZE = 20;

class HashMap
{
private:
	//LinkedList * *table;
	//int capacity = TABLE_SIZE;
	
public:
	LinkedList * *table;
	int size = TABLE_SIZE;

	//Constructori & Destructori
	HashMap();
	~HashMap();

	//Functia de HASH
	int HashFunction(TKey key) const;

	//CRUD
	void add(TKey key, TElem elem);
	void remove(TKey key, TElem elem);

	// functia de cautare
	bool search(TKey key, TElem elem);
	//bool searchValue(std::string ID);

	// functii de get pe chei/valori
	DynamicArray getValues(TKey key) const;
	DynamicArrayKeys getKeys() const;
};