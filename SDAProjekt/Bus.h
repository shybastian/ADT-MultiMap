#pragma once
#include <string>
#include <iostream>

class Bus
{
private:
	std::string ID;

public:

	// Contructor + Destructor + Overload
	Bus();
	~Bus();
	Bus(std::string ID);

	// Set + Get
	bool operator==(Bus &bus);
	std::string const getID();
	void setID(std::string newID);
	bool valid();
};