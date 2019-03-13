#include "stdafx.h"
#include "DynamicArray.h"


/*DynamicArray::DynamicArray()
{
	this->capacity = 1;
	this->size = 0;
	this->elems = new TElem[capacity];
}*/


//Constructor Default
DynamicArray::DynamicArray(int capacity)
{

	this->capacity = capacity;
	this->size = 0;
	this->elems = new TElem[capacity];
}

//Constructor cu parametrii
DynamicArray::DynamicArray(const DynamicArray& array)
{
	this->size = array.size;
	this->capacity = array.capacity;
	this->elems = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->elems[i] = array.elems[i];
	}
}


//Destructorul clasei
DynamicArray::~DynamicArray()
{
	/*for (int i = 0; i < this->size; i++)
	{
		this->elems[i].~Bus();
	}
	delete[] this->elems;*/
}

DynamicArray& DynamicArray::operator=(const DynamicArray& array)
{
	if (this == &array)
		return *this;

	this->size = array.size;
	this->capacity = array.capacity;

	delete[] this->elems;
	this->elems = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = array.elems[i];

	return *this;
}

//mareste capacitatea vectorului
void DynamicArray::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TElem* els = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

bool DynamicArray::searchElem(TElem elem)
{
	for (int i = 0; i < this->getSize(); i++)
	{
		if (elems[i] == elem)
		{
			return true;
		}
	}

	return false;
}

//returneaza elementele vectorului
TElem* DynamicArray::getAllElems() const
{
	return this->elems;
}

//returneaza lungimea vectorului
int DynamicArray::getSize() const
{
	return this->size;
}

//Adauga un element
void DynamicArray::add(TElem& elem)
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


//Sterge un element din array
void DynamicArray::deleteElem(TElem elem)
{
	//bool check = searchElem(ID); // Verificam daca elementul pe care vrem sa il stergem chiar este in array
	//if (check == true) // Daca da, il stergem
	{
		int position = -1; // Initializam o pozitie
		for (int i = 0; i < this->size; i++) // Cautam pozitia
		{
			if (this->elems[i] == elem)
			{
				position = i;
				break;
			}
		}

		if (position != -1)
		{
			for (int i = position; i < this->size - 1; i++) // Facem overwrite la pozitie
			{
				this->elems[i] = this->elems[i + 1];
			}

			std::cout << std::endl;
			std::cout << "The bus with the ID: " << elem.getID() << " has been successfully deleted." << std::endl;
			std::cout << std::endl;

			this->size = size - 1; // Decrementam size-ul array-ului
			if (this->size > 0 && this->size == this->capacity / 4)
			{
				resize(); // Eventual facem un resize daca array-ul a devenit prea mic
			}
		}
		else
		{
			std::cout << "The Bus with the ID: " << elem.getID() << " does not exist on a current line!" << std::endl;
		}
	}
	/*else
	{
		std::cout << "The Bus with the ID: " << ID << " does not exist on a current line!" << std::endl;
	}*/
}

bool DynamicArray::isEmpty()
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