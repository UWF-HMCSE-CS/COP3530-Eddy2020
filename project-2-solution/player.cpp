#include "player.hpp"
#include <algorithm>

Player::Player()
{
	this->row = 0;
	this->col = 0;
	this->moves = 0;
}

int Player::GetRow()
{
	return this->row;
}

int Player::GetCol()
{
	return this->col;
}

void Player::SetPosition(int row, int col)
{
	this->row = row;
	this->col = col;
}

void Player::AddItem(std::string item)
{
	this->items.push_back(item);
}

bool Player::HasItem(std::string item)
{
	return std::find(this->items.begin(), this->items.end(), item) != this->items.end();	
}

void Player::UseItem(std::string item)
{
	this->items.erase(std::remove(this->items.begin(), this->items.end(), item), this->items.end());
}

int Player::GetMoveCount()
{
	return this->moves;
}

void Player::IncrementMoves()
{
	this->moves++;
}

