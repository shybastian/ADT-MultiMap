#pragma once

typedef int TKey;

class DynamicArrayKeys
{
private:
	TKey * elems;
	int size;
	int capacity;

	void resize(double factor = 2);

public:

	//Constructor default
	//Array-ul va avea o capacitate de 5 elemente
	DynamicArrayKeys(int capacity = 5);

	//Constructor de copiere
	DynamicArrayKeys(const DynamicArrayKeys& array);

	//Destructor
	~DynamicArrayKeys();

	//Operator de asignare
	DynamicArrayKeys& operator=(const DynamicArrayKeys& array);

	//Adaugarea elementului in array
	void addKey(TKey& elem);

	//Returneaza dimensiunea array
	int getSize() const;
	TKey* getAllElems() const;

	bool isEmpty();

};