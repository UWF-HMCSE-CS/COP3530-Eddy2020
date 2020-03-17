#ifndef MAZE_HPP
#define MAZE_HPP

#include <string>
#include <fstream>

#include "room.hpp"

class Maze
{
	private:
		Room **rooms;
		int rows;
		int cols;

		std::ifstream mazeFile;

		void LoadMaze();
		Passage* CreatePassage(std::string type);
	public:
		Maze(std::string mazeFile);

        Room* GetRoom(int row, int col);
		int GetNumberRows();
		int GetNumberCols();
		~Maze();		
};

#endif
