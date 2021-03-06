// SDAProjekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MultiMapIterator.h"
#include <assert.h>

void testFunctionality()
{

	// 89%

	HashMap testMap = HashMap(); // Cream HashMap-ul
	assert(testMap.size == TABLE_SIZE); // Verificam daca capacitatea este egala cu 20

	Bus testBus = Bus(); // Cream obiectul Bus

	testBus.setID("EXAMPLE"); // Verificam functiile obiectului
	bool checkID = testBus.valid();
	assert(checkID == false);

	testBus.setID("MS-27-SEB");
	checkID = testBus.valid();
	assert(checkID == true);

	DynamicArray testValues = DynamicArray();
	assert(testValues.getSize() == 0);
	assert(testValues.isEmpty() == true);

	DynamicArrayKeys testKeys = DynamicArrayKeys();
	assert(testKeys.getSize() == 0);
	assert(testKeys.isEmpty() == true);

	testMap.add(5, testBus); // Il adaugam pe hash-ul 5
	testValues.add(testBus);

	assert(testValues.isEmpty() == false);
	assert(testValues.getSize() == 1);

	TKey key = 5;
	testKeys.addKey(key);
	assert(testKeys.isEmpty() == false);
	assert(testKeys.getSize() == 1);

	testBus.setID("MS-20-OOP");
	key = 20;
	testMap.add(key, testBus);
	testKeys.addKey(key);
	testBus.setID("MS-30-OOP");
	key = 30;
	testMap.add(key, testBus);
	testKeys.addKey(key);
	testBus.setID("MS-0-OOP");
	key = 40;
	testMap.add(key, testBus);
	testKeys.addKey(key);
	testBus.setID("MS-50-OOP");
	key = 50;
	testMap.add(key, testBus);
	testKeys.addKey(key);
	testBus.setID("MS-60-OOP");
	key = 60;
	testMap.add(key, testBus);
	testKeys.addKey(key);
	testBus.setID("MS-70-OOP");
	key = 70;
	testMap.add(key, testBus);
	testKeys.addKey(key);
	testBus.setID("MS-80-OOP");
	key = 80;
	testMap.add(key, testBus);
	testKeys.addKey(key);
	TKey *keyElem = testKeys.getAllElems();
	assert(keyElem[0] == 5);
	testKeys.~DynamicArrayKeys();


	LinkedList *check = testMap.table[5]->getNext();
	assert(check == NULL); // Verificam daca nu exista nod dupa head

	TElem *elem = testMap.table[5]->getValues().getAllElems();
	int size = testMap.table[5]->getValues().getSize();
	assert(size == 1); // Verificam cate elemente are nodul
	assert(elem[0].getID() == "MS-27-SEB"); // Verificam daca nodul are obiectul Bus introdus

	testBus.setID("XX-00-XXX");
	testMap.add(25, testBus);
	testBus.setID("AA-00-AAA");
	testMap.add(25, testBus); // Adaugamalte 2 obiecte, pe hash-ul 5

	check = testMap.table[5]->getNext(); // Verificam daca chiar s-a creat nodul dupa head
	assert(check != NULL);

	testBus.setID("XX-00-XXX");
	bool search = testMap.search(25,testBus);
	assert(search == true); // Verificam daca exista un element in HashMap

	testMap.remove(25, testBus);
	search = testMap.search(25,testBus);
	assert(search == false); // Verificam daca elementul sters exista in HashMap
	testBus.setID("AA-00-AAA");
	testMap.remove(25, testBus); // S-a sters tot nodul
	
	check = testMap.table[5]->getNext();
	assert(check == NULL); // Verificam daca head-ul are un next

	testValues = testMap.getValues(5);
	elem = testValues.getAllElems();
	assert(elem[0].getID() == "MS-27-SEB");

	std::cout << "Functionality tests completed." << std::endl;

}

/*HashMap init()
{
	HashMap map = HashMap();

	Bus bus("MS-27-SEB");
	map.add(5, bus);

	bus.setID("MS-01-IAN");
	map.add(15, bus);

	bus.setID("MS-98-UGH");
	map.add(15, bus);

	bus.setID("CJ-99-FFS");
	map.add(15, bus);

	bus.setID("MS-28-MVI");
	map.add(5, bus);

	bus.setID("CJ-10-FAC");
	map.add(1, bus);

	bus.setID("CJ-55-STO");
	map.add(1, bus);

	bus.setID("CJ-00-NFO");
	map.add(8, bus);

	bus.setID("MS-13-EGG");
	map.add(8, bus);

	bus.setID("MS-89-LOL");
	map.add(13, bus);

	return map;
}*/

void menu()
{
	std::cout << "======= T R A N S P O R T    I N C =======" << std::endl;
	std::cout << "1. Show lines and each bus it has" << std::endl;
	std::cout << "2. Add a bus to a new line, or add a bus to an existing line." << std::endl;
	std::cout << "3. Remove a bus from a line." << std::endl;
	std::cout << "4. Show every bus currently on a line." << std::endl;
	std::cout << "5. Show every line number." << std::endl;
	std::cout << "6. Test code functionality." << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cout << std::endl;
	std::cout << "Option: ";
}

int choice()
{
	char choice;
	do
	{
		std::cin >> choice;
		if ((choice < 48) || (choice > 57))
		{
			std::cout << "Option must be a number between 0 and 5!" << std::endl;
			std::cout << "Please try again: ";
		}
	} while ((choice < 48) || (choice > 57));

	std::cout << "==========================================" << std::endl;
	std::cout << std::endl;

	int opt = choice - '0';

	return opt;
}

bool checkStr(std::string given)
{
	int size = given.size();
	if (size <= 3)
	{
		for (int i = 0; i < size; i++)
		{
			if ((given[i] < 48) || (given[i] > 57))
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

int convertStrToInt(std::string given)
{
	int numar = 0;
	int schimb;
	for (int i = 0; i < given.size(); i++)
	{
		schimb = given[i] - '0';
		numar = numar * 10 + schimb;
	}

	return numar;
}


int main()
{
	HashMap map = HashMap();

	Bus add("MS-27-SEB");
	map.add(5, add);
	add.setID("MS-01-SIG");
	map.add(5, add);
	add.setID("MS-02-TGM");
	map.add(5, add);
	add.setID("MS-03-REG");
	map.add(5, add);
	add.setID("MS-04-SEB");
	map.add(5, add);

	add.setID("SB-11-SIB");
	map.add(25, add);
	add.setID("SB-12-SIB");
	map.add(25, add);

	add.setID("HG-21-MCI");
	map.add(45, add);

	add.setID("BV-31-BSV");
	map.add(65, add);
	add.setID("BV-32-POI");
	map.add(65, add);

	add.setID("CJ-41-UBB");
	map.add(13, add);
	add.setID("CJ-42-UTC");
	map.add(13, add);
	add.setID("CJ-43-AMV");
	map.add(13, add);
	add.setID("CJ-45-NFO");
	map.add(13, add);
	add.setID("CJ-46-SGA");
	map.add(13, add);

	menu();
	int opt = choice();
	while (opt != 0)
	{
		if (opt == 1) // Afisam MultiMap-ul pe ecran
		{
			/*Iterator it = Iterator(map);
			it.init(map);
			bool empty = true;
			while (it.valid() == true)
			{
				std::cout << "The line: " << it.currNode->getKey() << " has the following buses: " << std::endl;
				for (int i = 0; i < it.currNode->getValues().getSize(); i++)
				{
					std::cout << it.getCurrent().getID() << std::endl;
					it.next(map);
				}
			}
			if (empty == true)
			{
				std::cout << "The database is empty!" << std::endl;
			}
			std::cout << std::endl;*/

			Iterator it = Iterator(map);
			it.init(map);
			bool empty = true;
			while (it.valid() == true)
			{
				empty = false;
				std::cout << "The line: " << it.currNode->getKey() << " has the following buses: ";
				std::cout << it.getCurrent().getID() << std::endl;
				it.next();
			}

			if (empty == true)
			{
				std::cout << "The database is empty!" << std::endl;
			}

			std::cout << std::endl;

			/*Iterator it = Iterator(map);
			it.init(map);
			bool empty = true;
			while (it.valid() == true)
			{
				empty = false;
				std::cout << "The line: " << it.currNode->getKey() << " has the followng buses: " << std::endl;
				for (int i = 0; i<it.currNode->getValues().getSize()-1; i++)
				{
					std::cout << it.getCurrent().getID() << std::endl;
					it.next(map);
				}
				std::cout << std::endl;
			}
			if (empty == true)
			{
				std::cout << "The database is empty!" << std::endl;
			}*/

		}
		if (opt == 2)
		{
			std::string ID, keyStr;
			Bus newBus = Bus();

			std::cout << "Line/New line to add bus on: ";
			do
			{
				std::cin >> keyStr;
				if (checkStr(keyStr) == false)
				{
					std::cout << "Line must be a value between 0 and 100; with no special characters" << std::endl;
					std::cout << "Please try again: ";
				}
			} while (checkStr(keyStr) == false);

			int key = convertStrToInt(keyStr);


			std::cout << std::endl;
			std::cout << "The ID of the bus: ";
			do
			{
				std::cin >> ID;
				newBus.setID(ID);
				if (newBus.valid() == false)
				{
					std::cout << "The ID must be of the form: AA-00-BBB" << std::endl;
					std::cout << "Please try again: ";
				}
			} while (newBus.valid() == false);

			map.add(key, newBus);
		}
		if (opt == 3)
		{
			std::string ID, keyStr;
			Bus newBus = Bus();

			std::cout << "Line to delete bus from: ";
			do
			{
				std::cin >> keyStr;
				if (checkStr(keyStr) == false)
				{
					std::cout << "Line must be a value between 0 and 100; with no special characters" << std::endl;
					std::cout << "Please try again: ";
				}
			} while (checkStr(keyStr) == false);

			int key = convertStrToInt(keyStr);

			std::cout << std::endl;
			std::cout << "The ID of the bus: ";
			do
			{
				std::cin >> ID;
				newBus.setID(ID);
				if (newBus.valid() == false)
				{
					std::cout << "The ID must be of the form: AA-00-BBB" << std::endl;
					std::cout << "Please try again: ";
				}
			} while (newBus.valid() == false);

			map.remove(key, newBus);
		}
		if (opt == 4)
		{
			std::string keyStr;

			std::cout << "Line to see buses from: ";
			do
			{
				std::cin >> keyStr;
				if (checkStr(keyStr) == false)
				{
					std::cout << "Line must be a value between 0 and 100; with no special characters" << std::endl;
					std::cout << "Please try again: ";
				}
			} while (checkStr(keyStr) == false);

			int key = convertStrToInt(keyStr);

			std::cout << std::endl;
			std::cout << "The line: " << key << " has the following buses: ";
			std::cout << std::endl;

			DynamicArray found = map.getValues(key);
			if (found.isEmpty() == false)
			{
				TElem *elem = found.getAllElems();
				for (int i = 0; i < found.getSize(); i++)
				{
					std::cout << elem[i].getID() << std::endl;
				}
			}
			else
			{
				std::cout << "The line: " << key << " does not have any buses!";
			}

			/*bool found = false;
			std::cout << "The line: " << key << " contains following buses:" << std::endl;

			Iterator it = Iterator(map);
			it.init(map);
			while (it.valid() == true)
			{
				if (it.currNode->getKey() == key)
				{
					found = true;
					std::cout << it.getCurrent().getID() << std::endl;
				}
				it.next();
			}

			if (found == false)
			{
				std::cout << "The line: " << key << " does not contain buses!" << std::endl;
			}*/
		}
		if (opt == 5)
		{

			DynamicArrayKeys keys = DynamicArrayKeys();
			keys = map.getKeys();

			std::cout << "Following lines are in use: ";
			TKey *show = keys.getAllElems();
			for (int i = 0; i < keys.getSize(); i++)
			{
				std::cout << show[i] << " , ";
			}

			std::cout << std::endl;

			/*Iterator it = Iterator(map);
			bool found = false;
			std::cout << "Following lines are in use: " << std::endl;
			it.init(map);
			int currKey = it.currNode->getKey();
			while (it.valid() == true)
			{
				found = true;
				std::cout << currKey << " , ";
				do
				{
					it.next();
				} while (currKey == it.currNode->getKey());
				currKey = it.currNode->getKey();
			}

			if (found == false)
			{
				std::cout << "No lines are currently in use!" << std::endl;
			}*/

		}
		if (opt == 6)
		{
			testFunctionality();
		}
		if (opt == 0)
		{
			break;
		}

		std::cout << std::endl;
		menu();
		opt = choice();
	}
    return 0;
}

