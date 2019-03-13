#pragma once
#include "Bus.h"

typedef Bus TElem;

class DynamicArray
{
private:
	/*
	TElem * elems;
	int size;
	int capacity;*/

	void resize(double factor = 2);

public:
	TElem * elems;
	int size;
	int capacity;

	//Constructor default
	//Array-ul va avea o capacitate de 5 elemente
	DynamicArray(int capacity = 5);

	//Constructor de copiere
	DynamicArray(const DynamicArray& array);

	//Destructor
	~DynamicArray();

	//Operator de asignare
	DynamicArray& operator=(const DynamicArray& array);

	//Adaugarea elementului in array
	void add(TElem& elem);

	//Returneaza dimensiunea array
	int getSize() const;
	TElem* getAllElems() const;
	bool searchElem(TElem elem);

	//Sterge un element din array
	void deleteElem(TElem elem);

	bool isEmpty();

};