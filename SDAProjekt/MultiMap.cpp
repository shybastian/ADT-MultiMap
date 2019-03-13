#include "stdafx.h"
#include "MultiMap.h"


// Constructorul HashMap
HashMap::HashMap()
{
	table = new	LinkedList*[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		table[i] = NULL;
	}
	table[TABLE_SIZE] = NULL;
}


// Destructorul HashMap
HashMap::~HashMap()
{
	/*
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i] != NULL)
		{
			LinkedList *prevEntry = NULL;
			LinkedList *entry = table[i];
			while (entry != NULL)
			{
				prevEntry = entry; // Mutam locul din hashtable pe care vrem sa il stergem
				entry = entry->getNext(); // Mergem la next pentru nu a pierde referinta
				prevEntry->~LinkedList(); // Apelam destructorul pentru nod
				delete prevEntry; // Stergem nodul
			}
		}
	}

	delete[] table; // Stergem toata tabela din memorie
	*/
}

//Functia de hash
int HashMap::HashFunction(TKey key) const // FUNCTIA DE HASH NU MERGE?!
{
	int number = (key%this->size);

	return number; // Folosim Divisionsmethode ca si functie de hashing
}

bool HashMap::search(TKey key, TElem elem)
{
	int hash = this->HashFunction(key);
	if (table[hash] == NULL)
	{
		return false; // Daca cheia este goala, returnam false
	}
	else // Altfel, iteram lista
	{
		//std::string ID = elem.getID();
		LinkedList *entry = table[hash];
		while ((entry->getKey() != key) && (entry->getNext() != NULL)) // Iteram pana nu ajungem la sfarsit
		{															   // Sau cand cheia nodului este egala cu cea cautata
			entry = entry->getNext();
		}
		
		if (entry->getKey() == key)
		{
			return entry->getValues().searchElem(elem); // Returnam valoare true/false
		}

		return false; // Daca nu s-a gasit cheia, returnam false.
	}
}


DynamicArray HashMap::getValues(TKey key) const
{
	int hash = this->HashFunction(key); // Apelam functia de hash
	if (table[hash] == NULL) // Daca indexul din array nu pointeaza catre o lista
	{
		DynamicArray empty = DynamicArray();
		return empty;
		//return -1; // Vom returna -1; cheia respectiva nu are nici un element
	}
	else // Altfel exista o lista, noi trebuie sa o iteram pentru a ajunge la cheia dorita
	{
		LinkedList *entry = table[hash];
		while ((entry != NULL) && (entry->getKey() != key)) // Iteram lista
		{
			entry = entry->getNext();
		}
		if (entry == NULL)
		{
			DynamicArray empty = DynamicArray();
			return empty; // Daca am ajuns la finalul listei, inseamna ca aceasta cheie nu exista
			//return -1;
		}
		else
		{
			DynamicArray found(entry->getValues());
			return found;
			//return entry->getValues(); // altfel, returnam array-ul de valori al nodului
		}
	}
}


// Functie care gaseste toate cheile din HashMap
DynamicArrayKeys HashMap::getKeys() const
{
	DynamicArrayKeys keys = DynamicArrayKeys();
	int i = 0;
	while (i < this->size)
	{
		LinkedList *currNode = this->table[i];
		if (currNode == NULL)
		{
			i++;
		}
		else
		{
			while (currNode->getNext() != NULL)
			{
				TKey add = currNode->getKey();
				keys.addKey(add);
				currNode = currNode->getNext();
			}
			if (currNode->getNext() == NULL)
			{
				TKey add = currNode->getKey();
				keys.addKey(add);
			}
			i++;
		}
	}

	return keys;
}

//Add pe Hashtabelle
void HashMap::add(TKey key, TElem elem)
{
	bool check = this->search(key, elem.getID()); // verificam prima data daca elementul exista deja in cheie
	if (check == false) // Daca elementul nu exista in cheie, tratam cazurile de adaugare.
	{
		int hash = this->HashFunction(key); // Calculam hash-ul
		if (table[hash] == NULL) // Locul din tabela inca nu are o lista creata
		{
			TValue newArray = TValue(); // Cream Array-ul
			newArray.add(elem); // Punem elementul
			table[hash] = new LinkedList(key, newArray); // Cream lista
		}
		else // Locul din tabela are deja o lista creata; ori avem deja cheia in lista, ori trebuie sa o adaugam noi la final
		{
			bool added = false; // variabila de verificare
			LinkedList *entry = table[hash]; // head-ul listei
			while ((entry->getNext() != NULL) || (added == false))
			{
				if (entry->getKey() == key)
				{
					added = true;
					entry->addValue(elem); // S-a gasit cheia in inlantuirea listei, adaugam doar elementul in array
					break;
				}
				else
				{
					if (entry->getNext() == NULL)
					{
						break;
					}
					else
					{
						entry = entry->getNext();
					}
				}

			}

			// Aici tratam cazul daca s-a ajuns la final si daca nu s-a adaugat elementul intr-un nod din lista
			// Adica cheia nu exista in lista, si va trebui sa cream un nod nou care contine cheia si array-ul cu elem.
			if ((entry->getNext() == NULL) && (added == false)) //Swap aici daca nu merge (?!)
			{
				TValue newArray = TValue(); // Cream array-ul
				newArray.add(elem); // Punem elementul in array
				LinkedList *newNode = new LinkedList(key, newArray);
				newNode->setNext(NULL);
				//entry->setNext(new LinkedList(key, newArray)); // Next-ul elementului curent este nodul nou creat
				entry->setNext(newNode);
			}
		}
	}
	else
	{
		std::cout << "The Bus with the ID: " << elem.getID() << " already exists on the line: " << key << "." << std::endl;
	}
}

//Remove pe Hashtabelle
void HashMap::remove(TKey key, TElem elem)
{
	int hash = this->HashFunction(key); // Calculam hash-ul cheii
	if (table[hash] != NULL) // Daca hash-ul nu pointeaza catre o lista goala, continuam
	{
		LinkedList *prevEntry = NULL;
		LinkedList *entry = table[hash];
		while ((entry->getNext() != NULL) && (entry->getKey() != key))
		{
			prevEntry = entry;
			entry = entry->getNext();
		}

		if (entry->getKey() == key)
		{
			entry->deleteValue(elem); // Stergem valoarea din array
			if (entry->getValues().getSize() == 0) // Daca array-ul este gol, stergem tot nodul
			{
				if (prevEntry == NULL) // Daca trebuie sa stergem head-ul listei
				{
					table[hash] = entry->getNext();
					entry->~LinkedList();
					free(entry);

					//table[hash] = NULL;
					//entry->~LinkedList();


				}
				else if (entry->getNext() == NULL) // Daca s-a ajuns la sfarsitul listei
				{
					prevEntry->setNext(NULL); // Nextul nodului anterior posteaza acm catre NULL
					entry->~LinkedList(); // Distrugem nodul
					free(entry); // Eliberam spatiul

				}
				else // Aici stergem un nod din lista (nu e nici head, nici ultimul nod)
				{
					LinkedList *nextEntry = entry->getNext();
					prevEntry->setNext(nextEntry);
					entry->~LinkedList();
					free(entry);
				}
			}
		}
	}
	else
	{
		std::cout << "The Bus with the ID: " << elem.getID() << " does not exist on the line: " << key << "." << std::endl;
		std::cout << std::endl;
	}
}