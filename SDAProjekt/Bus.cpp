#include "stdafx.h"
#include "Bus.h"


Bus::Bus()
{

}

Bus::Bus(std::string ID)
{
	this->ID = ID;
}

Bus::~Bus()
{

}

bool Bus::operator==(Bus& bus)
{
	if (this->getID() == bus.getID())
	{
		return true;
	}
	else
	{
		return false;
	}
}


std::string const Bus::getID()
{
	return ID;
}

void Bus::setID(std::string newID)
{
	this->ID = newID;
}

bool Bus::valid()
{
	if ((this->getID()[2] != '-') && (this->getID()[5] != '-'))
	{
		return false;
	}
	int i = 0;
	while (i < this->getID().size())
	{
		if ((i == 2) || (i == 5))
		{
			i++;
		}
		else
		{
			if ((this->getID()[i] < 48) || (this->getID()[i] > 90))
			{
				return false;
			}
			else
			{
				i++;
			}
		}
	}
	return true;
}