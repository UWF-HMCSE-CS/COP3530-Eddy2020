#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>
#include "player.hpp"
#include "maze.hpp"

class Game
{
	private:
		Maze* maze;
		Player* player;
		Room* currentRoom;
		bool exitFound;
		std::vector<std::string> currentItems;
	
		std::string GetPassageDescription(Passage* passage);
	public:
		Game(Maze* maze, Player* player);

		void DisplayItems();
		void DisplayPassages();
		std::string GetCurrentRoomName();
		void LootRoom();
		bool ValidDirection(std::string direction);
		void MoveDirection(std::string direction);
		bool ExitFound();

};

#endif
