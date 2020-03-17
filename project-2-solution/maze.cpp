#include <iostream>
#include <sstream>
#include <stdlib.h>

#include "maze.hpp" 
#include "room.hpp"
#include "passage.hpp"

Maze::Maze(std::string mazeFile)
{
	this->mazeFile.open(mazeFile.c_str());

	this->LoadMaze();
}

Passage* Maze::CreatePassage(std::string type)
{
	if(type == "-")
	{
		return new Passage(false);
	}
	if(type == "+")
	{
		return new Passage(true);
	}
	
	return	new Passage(false, type); 
}

void Maze::LoadMaze()
{
	if(this->mazeFile.is_open())
	{				
		std::string line;
		std::string part;
		std::string name;
		std::string item;
		std::istringstream inSS;

		this->mazeFile >> this->rows;
		this->mazeFile >> this->cols;
		std::getline(this->mazeFile, line); //throw out end of line

		this->rooms = new Room*[this->rows];
		for(int i = 0; i < this->rows; i++)
		{
			this->rooms[i] = new Room[this->cols];
		}

		Passage* north;
		
		for(int i = 0; i < this->rows; ++i)
		{
			for(int j = 0; j < this->cols; ++j)
			{
				std::getline(this->mazeFile, line);
			
				inSS.clear();
				inSS.str(line);
			
				std::getline(inSS, name, ',');
			
				std::getline(inSS,part,',');
				north = CreatePassage(part);
				Passage* passages[3];
				for(int k = 0; k < 3; ++k)
				{
					std::getline(inSS,part,',');
					passages[k] = CreatePassage(part); 
				}
			
				this->rooms[i][j] = Room(name, north, passages[0], passages[1], passages[2]);
				
				while(std::getline(inSS,item, ' '))
				{
					this->rooms[i][j].AddItem(item);
				}
			}	
		}
		
		
		this->mazeFile.close();
	}
	else
	{
		std::cout << "Error with opening file" << std::endl;
		exit(1);
	}

}

Room* Maze::GetRoom(int row, int col)
{
	return &this->rooms[row][col];
}

int Maze::GetNumberRows()
{
	return this->rows;
}

int Maze::GetNumberCols()
{
	return this->cols;
}

Maze::~Maze()
{
		
		for(int i = 0; i < this->rows; i++)
		{
			for(int j = 0; j < this->cols; j++)
			{
				delete this->rooms[i][j].GetNorthPassage();
				delete this->rooms[i][j].GetEastPassage();
				delete this->rooms[i][j].GetSouthPassage();
				delete this->rooms[i][j].GetWestPassage();
			}
			delete[] this->rooms[i];
		}
		delete[] this->rooms;
}
