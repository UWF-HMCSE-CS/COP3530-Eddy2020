#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../room.hpp"
#include "../passage.hpp"
#include "../player.hpp"
#include "../maze.hpp"
#include "../game.hpp"

TEST_CASE("Test Passage object with solid wall.")
{
	Passage newPassage(false);
	REQUIRE((!newPassage.IsOpen() && !newPassage.RequiresKey()));
}

TEST_CASE("Test Passage object with open wall.")
{
	Passage newPassage(true);
	REQUIRE((newPassage.IsOpen() && !newPassage.RequiresKey()));
}

TEST_CASE("Test Passage object with closed door.")
{
	Passage newPassage(false, "red_key");
	REQUIRE((!newPassage.IsOpen() && newPassage.RequiresKey()));
	REQUIRE(newPassage.GetRequiredKey() == "red_key");

	newPassage.Open();
	REQUIRE(newPassage.IsOpen() == true);
}

TEST_CASE("Test Passage object with open door.")
{
	Passage newPassage(true, "red_key");
	REQUIRE((newPassage.IsOpen() && newPassage.RequiresKey()));
	REQUIRE(newPassage.GetRequiredKey() == "red_key");
}

TEST_CASE("Test Room object.")
{
	Passage* northPassage = new Passage(false);
	Passage* eastPassage = new Passage(true);
	Passage* southPassage = new Passage(false, "red_key");
	Passage* westPassage = new Passage(false);
	
	Room newRoom("The Start", northPassage, eastPassage, southPassage, westPassage);
	REQUIRE(newRoom.GetName() == "The Start");
	REQUIRE((!newRoom.GetNorthPassage()->IsOpen() && !newRoom.GetNorthPassage()->RequiresKey()));	
	REQUIRE((newRoom.GetEastPassage()->IsOpen() && !newRoom.GetEastPassage()->RequiresKey()));	
	REQUIRE((!newRoom.GetSouthPassage()->IsOpen() && newRoom.GetSouthPassage()->RequiresKey() 
		&& newRoom.GetSouthPassage()->GetRequiredKey() == "red_key"));	
	REQUIRE((!newRoom.GetWestPassage()->IsOpen() && !newRoom.GetWestPassage()->RequiresKey()));

	newRoom.AddItem("axe");
	newRoom.AddItem("blue_key");
	
	//notice that I remove in the opposite order that I insert, this is more efficient.
	//we will discuss stacks later in this class, but not you can just use push_back to insert, 
	//back to get element, and pop_back to remove
	REQUIRE(newRoom.AcquireNextItem() == "blue_key");
	REQUIRE(newRoom.AcquireNextItem() == "axe");
	REQUIRE(newRoom.AcquireNextItem() == "");	
}

TEST_CASE("Test Player object.")
{
	Player newPlayer;
	REQUIRE((newPlayer.GetRow() == 0 && newPlayer.GetCol() == 0));
	
	newPlayer.SetPosition(1,1);
	REQUIRE((newPlayer.GetRow() == 1 && newPlayer.GetCol() == 1));

	newPlayer.AddItem("red_key");
	REQUIRE(newPlayer.HasItem("red_key"));

	newPlayer.UseItem("red_key");
	REQUIRE(!newPlayer.HasItem("red_key"));
}


TEST_CASE("Test Maze object.")
{
	Maze* newMaze = new Maze("testMaze.txt");
	REQUIRE((newMaze->GetNumberRows() == 2 || newMaze->GetNumberCols() == 3));
	REQUIRE(newMaze->GetRoom(0,0)->GetName() == "The Start"); 
	REQUIRE(newMaze->GetRoom(0,0)->GetNorthPassage()->IsOpen() == false);
	REQUIRE(newMaze->GetRoom(0,0)->GetEastPassage()->IsOpen() == true);
	REQUIRE(newMaze->GetRoom(0,0)->GetSouthPassage()->IsOpen() == false);
	REQUIRE(newMaze->GetRoom(0,0)->GetWestPassage()->IsOpen() == false);

	REQUIRE(newMaze->GetRoom(0,1)->GetName() == "The Landing"); 
	REQUIRE(newMaze->GetRoom(0,1)->GetNorthPassage()->IsOpen() == false);
	REQUIRE(newMaze->GetRoom(0,1)->GetEastPassage()->IsOpen() == true);
	REQUIRE(newMaze->GetRoom(0,1)->GetSouthPassage()->IsOpen() == false);
	REQUIRE(newMaze->GetRoom(0,1)->GetWestPassage()->IsOpen() == true);
	delete newMaze;
}

TEST_CASE("Test Game object.")
{
	Maze* newMaze = new Maze("testMaze.txt");
	Player* newPlayer = new Player();
	Game newGame(newMaze, newPlayer);
	REQUIRE(newGame.GetCurrentRoomName() == "The Start");
	REQUIRE(newGame.ExitFound() == false);
	
	newGame.MoveDirection("E");
	newGame.MoveDirection("E");
	newGame.LootRoom();
	REQUIRE(newGame.GetCurrentRoomName() == "Master Bedroom");
	REQUIRE(newPlayer->HasItem("red_key"));
	REQUIRE(newGame.ExitFound() == false);

	newGame.MoveDirection("W");
	newGame.MoveDirection("W");
	newGame.MoveDirection("S");
	REQUIRE(newGame.GetCurrentRoomName() == "The Kitchen");
	REQUIRE(newGame.ExitFound() == false);
	REQUIRE(!newPlayer->HasItem("red_key"));

	newGame.MoveDirection("E");
	newGame.MoveDirection("E");
	REQUIRE(newGame.GetCurrentRoomName() == "The Exit!");
	REQUIRE(newGame.ExitFound() == true);
}

// Add more test cases as needed

// Compile & run:
// make test
