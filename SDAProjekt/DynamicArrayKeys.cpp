#include "stdafx.h"
#include "DynamicArrayKeys.h"


/*DynamicArray::DynamicArray()
{
this->capacity = 1;
this->size = 0;
this->elems = new TElem[capacity];
}*/


//Constructor Default
DynamicArrayKeys::DynamicArrayKeys(int capacity)
{

	this->capacity = capacity;
	this->size = 0;
	this->elems = new TKey[capacity];
}

//Constructor cu parametrii
DynamicArrayKeys::DynamicArrayKeys(const DynamicArrayKeys& array)
{
	this->size = array.size;
	this->capacity = array.capacity;
	this->elems = new TKey[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->elems[i] = array.elems[i];
	}
}


//Destructorul clasei
DynamicArrayKeys::~DynamicArrayKeys()
{
	/*for (int i = 0; i < this->size; i++)
	{
	this->elems[i].~Bus();
	}
	delete[] this->elems;*/
}

DynamicArrayKeys& DynamicArrayKeys::operator=(const DynamicArrayKeys& array)
{
	if (this == &array)
		return *this;

	this->size = array.size;
	this->capacity = array.capacity;

	delete[] this->elems;
	this->elems = new TKey[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = array.elems[i];

	return *this;
}

//mareste capacitatea vectorului
void DynamicArrayKeys::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TKey* els = new TKey[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}


//returneaza elementele vectorului
TKey* DynamicArrayKeys::getAllElems() const
{
	return this->elems;
}

//returneaza lungimea vectorului
int DynamicArrayKeys::getSize() const
{
	return this->size;
}

//Adauga un element
void DynamicArrayKeys::addKey(TKey& elem)
{
	//bool check = searchElem(elem.getID());
	//if (check == false)
	{
		if (this->size == this->capacity)
		{
			this->resize();
		}
		this->elems[this->size] = elem;
		this->size++;
	}
	/*else
	{
	std::cout << "The Bus with the ID: " << elem.getID() << " already exists on this line!" << std::endl;
	}*/
}

bool DynamicArrayKeys::isEmpty()
{
	if (this->size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}