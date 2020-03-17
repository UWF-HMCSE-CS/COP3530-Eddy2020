#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>
#include "passage.hpp"

class Room
{
	private:
		std::string name;
		std::vector<std::string> items;

		Passage* northPassage;
		Passage* eastPassage;
		Passage* southPassage;
		Passage* westPassage;

	public:
		Room(){};
		Room(std::string name, Passage* north, Passage* east, Passage* south, Passage* west);
		std::string GetName();

		Passage* GetNorthPassage();
		Passage* GetEastPassage();
		Passage* GetSouthPassage();
		Passage* GetWestPassage();

		void AddItem(std::string item);
		std::string AcquireNextItem();
};

#endif
