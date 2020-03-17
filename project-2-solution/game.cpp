#include <iostream>

#include "game.hpp"

Game::Game(Maze* maze, Player* player)
{
	this->maze = maze;
	this->player = player;
	this->currentRoom = this->maze->GetRoom(0,0);
}

std::string Game::GetCurrentRoomName()
{
	return this->currentRoom->GetName();
}

void Game::LootRoom()
{

	std::string item = currentRoom->AcquireNextItem();
	while(item != "")
	{
		this->currentItems.push_back(item);
		this->player->AddItem(item);
		item = currentRoom->AcquireNextItem();
	}
}

void Game::DisplayItems()
{
	if(!this->currentItems.empty())
	{
		std::cout << "There is a(n) " << this->currentItems.back();

		this->currentItems.pop_back();
		while(!this->currentItems.empty())
		{
			std::cout << " and a(n) " << this->currentItems.back();
			this->currentItems.pop_back();
		}
		std::cout << " in this room. You picked up the item(s)!" << std::endl;
	}
	else
	{
		std::cout << "There are no objects in this room." << std::endl; 
	}
}


void Game::MoveDirection(std::string direction)
{
	int previousRow = this->player->GetRow();
	int previousCol = this->player->GetCol();

	this->player->IncrementMoves();	
	if(direction == "N")
	{
		if(currentRoom->GetNorthPassage()->RequiresKey())
		{
			currentRoom->GetNorthPassage()->Open();
			this->maze->GetRoom(previousRow - 1, previousCol)->GetSouthPassage()->Open();
			this->player->UseItem(currentRoom->GetNorthPassage()->GetRequiredKey());
		}
		this->player->SetPosition(previousRow - 1, previousCol);	
	}
	else if (direction == "E")
	{
		if(currentRoom->GetEastPassage()->RequiresKey())
		{
			currentRoom->GetEastPassage()->Open();
			this->maze->GetRoom(previousRow, previousCol + 1)->GetWestPassage()->Open();
			this->player->UseItem(currentRoom->GetEastPassage()->GetRequiredKey());
		}
		this->player->SetPosition(previousRow, previousCol + 1);	
	}
	else if (direction == "S")
	{
		if(currentRoom->GetSouthPassage()->RequiresKey())
		{
			currentRoom->GetSouthPassage()->Open();
			this->maze->GetRoom(previousRow + 1, previousCol)->GetNorthPassage()->Open();
			this->player->UseItem(currentRoom->GetSouthPassage()->GetRequiredKey());
		}
		this->player->SetPosition(previousRow + 1, previousCol);	
	}
	else
	{
		if(currentRoom->GetWestPassage()->RequiresKey())
		{
			currentRoom->GetWestPassage()->Open();
			this->maze->GetRoom(previousRow, previousCol - 1)->GetEastPassage()->Open();
			this->player->UseItem(currentRoom->GetWestPassage()->GetRequiredKey());
		}
		this->player->SetPosition(previousRow, previousCol - 1);	
	}
	this->currentRoom = this->maze->GetRoom(this->player->GetRow(), this->player->GetCol());
}

std::string Game::GetPassageDescription(Passage* passage)
{
	if(passage->RequiresKey() && !passage->IsOpen())
	{
		return "doorway that requires a(n) " + passage->GetRequiredKey();
	}
	if(!passage->IsOpen())
	{
		return "solid wall";
	}
	return "open doorway";
}

void Game::DisplayPassages()
{
	Passage* north = currentRoom->GetNorthPassage();
	Passage* east = currentRoom->GetEastPassage();
	Passage* south = currentRoom->GetSouthPassage();
	Passage* west = currentRoom->GetWestPassage();

	std::cout << "There is a(n) " << GetPassageDescription(north) << " to the North." << std::endl;
	std::cout << "There is a(n) " << GetPassageDescription(east) << " to the East." << std::endl;
	std::cout << "There is a(n) " << GetPassageDescription(south) << " to the South." << std::endl;
	std::cout << "There is a(n) " << GetPassageDescription(west) << " to the West." << std::endl;
}

bool Game::ValidDirection(std::string direction)
{	
	Passage* testPassage;
	if(direction == "N")
	{
		testPassage = currentRoom->GetNorthPassage();
	}
	else if (direction == "E")
	{
		testPassage = currentRoom->GetEastPassage();
	}
	else if (direction == "S")
	{
		testPassage = currentRoom->GetSouthPassage();
	}
	else
	{
		testPassage = currentRoom->GetWestPassage();
	}

	return (testPassage->IsOpen()) || 
		(testPassage->RequiresKey() && this->player->HasItem(testPassage->GetRequiredKey()));
	
}

bool Game::ExitFound()
{
	int playerRow = this->player->GetRow();
	int playerCol = this->player->GetCol();
	
	return ((playerRow == 0) && currentRoom->GetNorthPassage()->IsOpen()) ||
		((playerRow == this->maze->GetNumberRows() - 1) && currentRoom->GetSouthPassage()->IsOpen()) ||
		((playerCol == 0) && currentRoom->GetWestPassage()->IsOpen()) ||
		((playerCol == this->maze->GetNumberCols() - 1) && currentRoom->GetEastPassage()->IsOpen()) ;
}
