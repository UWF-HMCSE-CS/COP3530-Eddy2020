#include "passage.hpp"

Passage::Passage(bool isOpen)
{
	this->isOpen = isOpen;
	this->key = "";
}

Passage::Passage(bool isOpen, std::string key)
{
	this->isOpen = isOpen;
	this->key = key;
}

bool Passage::IsOpen()
{
	return this->isOpen;
}

bool Passage::RequiresKey()
{
	return this->key != "";
}


std::string Passage::GetRequiredKey()
{
	return this->key;
}

void Passage::Open()
{
	this->isOpen = true;
}
