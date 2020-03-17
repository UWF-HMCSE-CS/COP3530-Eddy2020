#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

#include "maze.hpp"
#include "game.hpp"


std::string AskDirection()
{
	std::string direction;
	std::cout << "Which way would you like to move? ";
	std::cin >> direction;
	return direction;
}

void DisplayRoom(Game& currentGame)
{
	std::cout << "You are in " << currentGame.GetCurrentRoomName() << "!" << std::endl;
	currentGame.DisplayItems();
	currentGame.DisplayPassages();	
}

int main (int argc, char* argv[])
{
	std::string mazeFile;

	std::cout << "Welcome to The Maze." << std::endl;
	std::cout << "Please enter the filename of your maze: ";
	std::cin >> mazeFile;
	
	Maze *newMaze = new Maze(mazeFile);
	Player *newPlayer = new Player();
	Game newGame(newMaze, newPlayer);
	while(!newGame.ExitFound())
	{
		std::cout << std::endl;
		newGame.LootRoom();
		DisplayRoom(newGame);
		std::string direction = AskDirection();
		while(!newGame.ValidDirection(direction))
		{
			if(direction == "Q")
			{
				std::cout << "Better luck next time!" << std::endl;
				exit(1);
			}
			std::cout << "You can't go that way!" << std::endl;	
			direction = AskDirection();
		}
		newGame.MoveDirection(direction);
	}
	std::cout << std::endl;
	DisplayRoom(newGame);
	std::cout << "It took you " << newPlayer->GetMoveCount()  << " moves, but you're free!" << std::endl;
	delete newMaze;
	delete newPlayer;
	return 0;
}
