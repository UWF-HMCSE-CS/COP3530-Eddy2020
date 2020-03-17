#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>

class Player
{
	private:
		int row;
		int col;
		int moves;

		std::vector<std::string> items;
	public:
		Player();

		int GetRow();
		int GetCol();
		void SetPosition(int row, int col);

		void AddItem(std::string item);
		bool HasItem(std::string item);
		void UseItem(std::string item);
		int GetMoveCount();	
		void IncrementMoves();	
};

#endif
