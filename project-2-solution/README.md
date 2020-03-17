# COP 3530 - Data Structures and Algorithms I

# Due: 

# Project 2 - The Maze

## Objective:

This project is meant to help you familiarize yourself with multi-dimensional arrays, while also further strengthening
your knowledge of OO principles and problem solving. You will be creating an interactive maze that involves the creation
of multiple user-defined classes. As programs grow in size and complexity, you will need to be able to work with and manage
multiple modules and data structures.

## Learning Outcomes

Developer a program that uses:

- Multiple modules
- Multi-dimensional arrays

## Preparation:

To complete this project, you need to make sure that you have read the following:

- Chapter 3 - Strings
- Chapter 4 - Array and Vector Basics
- Chapter 7 - Objects and Classes Basics
- Chapter 9 - Modular Design and Makefiles
- Chapter 10 - Memory Management
- The Arrays Handout on Canvas

## Problem Description:

The idea for this project is similar to old text-based adventure games in which a player is presented with various options through various screens of text.
In the case of your project, you have been trapped in a maze and must figure out how to navigate a maze in order to escape.
The maze is composed of rooms. In order to escape, the player needs to travel through each room of the maze, gathering keys and objects along the way
that will aid in their escape.

Take the following maze as an example (note that you do not need to implement this visualization):

```
+--------------+-------------+----------------+
|              |             |                |
| The Start    = The Landing = Master Bedroom |
| axe,blue_key |             |    red_key     |
|              |             |                |
+---red_key----+-------------+----------------+
|              |             |                |
| The Kitchen  =  The Hall   =   The Exit!    =
|              |             |                |
+--------------+-------------+----------------+
```

This maze is composed of two rows and three columns. Every maze can be represented as a grid. In order to get the specifications for a maze, you will
read in a maze's layout through a data file (discussed later). For each maze, the player starts in the top left corner of the maze and must make their
way out of the maze. Escaping the maze means finding an exit that has an accessible passagway out of the maze.
The data read in from the input file will define characteristics about each room of the maze and the passageways connecting them. Some rooms will have passageways
blocked by doors that require special items to open. In the given example, the door to the south of the player's starting location is blocked by a door that requires
a red_key to open. The player must make their way to the "Master Bedroom" first before they backtrack and can finally open the door that will allow them to progress
to The Exit.
The maze will be interactive as described in the next section.

## Overview of the Interface:

The player starts in the top left corner of the maze. Each room has a name as specified in the data file. At the start of the game, you will be required to enter the
name of a data file that will contain the maze's details.

```
Welcome to The Maze.
Please enter the filename of your maze:
```

Once the file name is entered, the program should show options for the first room. Assume we were using the example maze that we previously mentioned. Then the interface
should look as follows:

```
Welcome to The Maze.
Please enter the filename of your maze: maze.txt

You are in The Start!
There is a(n) axe and a(n) blue_key in this room. You picked up the item(s)!
There is a(n) solid wall to the North.
There is a(n) open doorway to the East.
There is a(n) doorway that requires a(n) red_key to the South.
There is a(n) solid wall to the West.
Which way would you like to move?
```

Given the choices, there is only one option for the player, so the player moves to the East:

```
You are in The Start!
There is a(n) axe and a(n) blue_key in this room. You picked up the item(s)!
There is a(n) solid wall to the North.
There is a(n) open doorway to the East.
There is a(n) doorway that requires a(n) red_key to the South.
There is a(n) solid wall to the West.
Which way would you like to move? E

You are in The Landing!
There are no objects in this room.
There is a(n) solid wall to the North.
There is a(n) open doorway to the East.
There is a(n) solid wall to the South.
There is a(n) open doorway to the West.
Which way would you like to move?
```
When a player enters a room, they loot the room of all items. Entering that room again should show that there are no objects in the room. 

If the player chooses a path that is currently blocked, either by a solid wall or because they don't have a needed key,
then the game should output the message "You can't go that way!" and then prompt for another direction. The player may at any time, also choose to
enter "Q" in which case the output should be "Better luck next time!" and the program should end.

If the player makes it through an exit, then the program should output "It took you x moves, but you're free!" where x is the number of moves that the player
took to get out of the maze. Then the program should end. There can be multiple exits in a maze. An exit is a passageway that leads out of the maze.
The player wins when they travel through that passageway. In our example, if the player has reached The Exit, they still need to move East again to win.

## Data format

A maze is specified by an input file with the following format:

```
Row_count,Column_count
Room_name,North_passageway,East_passageway,South_passageway,West_passageway,list_of_items_in_room
```

The first line of the input file is the number of rows (Row_count) and the number of columns (Column_count)
in the maze. The first line is followed by Row_count x Column_count lines with each line representing a different Room in the maze.

Each room has a name, four connected passageways, and a list of items in that room. Each passageway in a room is one of three types:

1. "-": No passage is allowed
1. "+": Passage is open
1. "item_needed_to_open_passageway": Requires the item(s) specified to open the door

The input file for our example maze would look like the following:

```
2 3
The Start,-,+,red_key,-,axe blue_key
The Landing,-,+,-,+,
Master Bedroom,-,-,-,+,red_key
The Kitchen,red_key,+,-,-,
The Hall,-,+,-,+,
The Exit!,-,+,-,+,
```

Note that the list of items in the room is not comma-separated.

### Sample run of program

## Code Organization:

You will need to make sure that your code meets the following specifications.
Note that there is some room for interpretation, but a general code outline is given below.
 
### The Main File
The main file shall create a Game instance and utilize its methods to implement the game.
Additionally, the main file will handle user selections and input. 

### The Passage Class
![UML of Passage class](http://www.plantuml.com/plantuml/png/SoWkIImgAStDuKhEIImkLWW04edfgGhLNBgPnVu5gNbM2adv-JbSkjcfbLOAnIKfLbR59KMPUUbSsb2b6fe89aYf0aGVTb4TP2CKW6PgSd5fUuAbD3GLe7Pf1wKMbcOMfHPxfrOYYRgdba0bKg0Io8O1pO6RKfQVcS9Lo-MGcfS2z1a0)

This class is responsible for storing information on a passage in the maze. A passage can either be a solid wall, an open passageway, or a door. The first parameterized constructor can be used to create a passage that is not a door. The second takes in an additional key parameter for a door.
In addition to the parameterized constructors, this class should have the following methods:
* `IsOpen ()`
	* Returns a boolean value to state whether the passage is currently open.
* `RequiresKey ()`
	* Returns a boolean (true or false) if the passage requires a key to open.
	* This function allows you to determine whether the passage is a door.
* `GetRequiredKey ()`
	* Returns an std::string of the key needed to open the door. For instance a "red_key" is needed to open the door that is South of The Start
* `Open ()`
	* Opens a closed door. You should check that the player has the required key before opening the door.
   

### The Room Class
![UML of Room class](http://www.plantuml.com/plantuml/png/VP71YeCm48RlynGvwhg-W2oBUrYMlKXf3pq7CzY0CJGpiONITs_IYYXLJmxpVn_EhoMnTEnD2tKhYSJUMYDka7VIO268LL4GEzqra6j6GyEknvgj-vhatn0aw_YqaqIo2V8mV42EadXXJTOluXTSmY6BjoNfy9oyMiHZFqToUmh-7t8LZ2GLyuRY5KrAH6Gqd-blgB8Q7gpVK8-ueaBsezG_uxnK_DmHwwrMWQZFNZkiyCgHVBlz3YLsAlp71m00)

This class holds information for a Room in the maze. Each Room object is composed of four passages pointers (one for each direction), a name, and the list of items in that Room. 
In addition to the parameterized constructor, this class should have the following methods:
* `GetName ()`
	* Returns the name of the Room.
* `GetNorthPassage ()`, `GetEastPassage ()`, `GetSouthPassage ()`, `GetWestPassage ()`
	* Each of these methods returns a pointer to the corresponding Passage.
   * This allows for calls such as "someRoom->GetNorthPassage()->Open()"
* `AddItem (std::string item)`
	* Adds an item to the items vector of the Room object.
* `AcquireNextItem ()`
	* When a player enters a room, they should receive all items in that room. AcquireNextItem returns one item at a time and removes it from the Room.
   
### The Maze Class
![UML of Maze class](http://www.plantuml.com/plantuml/png/LOx1QiCm38RlUWeTdMH-0Py2WUsoZP4ty68j6Enus4fBM_hkbKDAwCcI_i_IrnUscTSOO0gs5FooLy8Rw9nIB0P7UTgsjcVf_CAWfnJs4dGK-jq7CbZO6UF_2cUoKPBFP5tTfHg3f-GTw44IfXyvOcTI6o-qNsRaopy9jaSjG2S_Nv7deGQw3-9gfSG0HUiDQo5I3Uww6_Aznb_AesYh6bJTOpoaS8plqDFYrXWU)

This class holds the information for the Maze. The Maze is a two-dimensional array of Rooms represented by a Room**. You will need to read the information for the Maze from an input file, assemble the information into Room objects, and add them to the array.    
In addition to the constructor and destructor, this class should have the following methods:
* `LoadMaze ()`
	* This private helper function is used to read the file and create the two-dimensional array of Room objects.
* `CreatePassage()`
	* This private helper function takes in a string of '-', '+', or an item need to open a door, and returns a pointer to an appropriate Passage object.
* `GetRoom (int row, int col)`
	* Takes in a position in terms of a row and col and returns a pointer to the Room object at that location in the Maze.
* `GetNumberRows ()`, `GetNumberCols ()`
   * Simple getter methods that return the number of rows and columns in the maze.
   
### The Player Class
![UML of Player class](http://www.plantuml.com/plantuml/png/VP31IWGn44Jl_HKvPXdd1mQHbJte7eH5yGDYqaWWIKEwDuk8_svd8pDUzFOggLGLsREuAkUSm2V7R4x9VM0rdp1NkYmc5e7PK_gXJ0rvCCnHCAjW2SlIq0lLsokpr5ZUxm2c4MPtYWyeptInEpDUTtsWjEaNb1Dnb4Z5we7HzXlJGSkxgL4C6dCVmb5hxQyYqtUibkdHyP-EDw84qolZlnbZxHCrFD2voBRnM7p5ZELwntRrVy4UIz0__0O0)

This class holds the information for the Player. As the player moves through the maze, you must keep track of the player's location, any items that they pick up along the way, and the number of moves that they have made. This class should have the following methods:
* `GetRow ()`, `GetCol ()`
	* Simple getter methods that return the player's current row and column in the maze.
* `SetPosition(int row, int col)`
	* A setter method that updates the player's row and column.
* `AddItem (std::string item)`
	* Add an item to the current collection of items that the player has.
* `HasItem (std::string item)`
	* Returns a boolean value that says whether the player has obtained a given item. Should return true if the item is in the player's collection of obtained items and false otherwise. 
* `UseItem (std::string item)`
   * Items are consumables, which means that when they are used, they should be removed completely from the player. 
* `GetMoveCount ()`
   * Returns the number of moves the player has made in the maze.
* `IncrementMoves ()`
   * Every time the player makes a move, this function should be used to increase the number of moves the player has made by 1.
   
### The Game Class
![UML of Game class](http://www.plantuml.com/plantuml/png/XOxFQiCm38VlVWeTqsPv0JD6OTd2O1rbXzqzMnI3RHLB2Vl3tdsnITkmoowo-IJzzErOJ9On1cM3OOR1H8HlrKNpXHhsSzsgxXJC9sODX_hEm8uvOv9NegYXr2jx4eoiWSLfFQ4LohVrpv9zEjufrGqe1yDiZjWZs-nFuYar2zfkGCDgGQcsA3NLvEPii9bnxxburNjDsPh8kmjUujQT0UN-wlrIKlyUQv-9QdUrzcQ2TxtFQAldQXpScPRfTwAWsZrD-F_m4ltmuUMHnkIQIy2Fsc5oOmo_)

This class holds the primary logic for the game. It takes in a Maze and a Player objects and allows the player to manipulate the Maze according to the rules of the game. In addition to a parameterized constructor, the class should also have the following methods:
* `GetPassageDescription (Passage* passage)`
	* This helper function returns a string that describes the given Passage. Descriptions include whether it is a solid wall, open passage, or doorway requiring a key. Look at the example console output in this project description to see the types of information that should be returned.
* `DisplayItems ()`
	* Prints all the current items in the room according to this project description.
* `DisplayPassages ()`
	* Prints all details about the passages connected to this room according to the project description.
* `GetCurrentRoomName ()`
	* Returns the name of the room that the player is currently in.
* `LootRoom ()`
	* When the player enters a new room, they should loot it. This means removing all items from the Room object and adding them to the Player object. 
* `ValidDirection (std::string direction)`
   * Returns a boolean for whether the player can travel in a specific direction of 'N', 'E', 'S', or 'W'. 
* `MoveDirection (std::string direction)`
   * Moves a player in a legal direction. This should update the player's position and also the current Room.
* `ExitFound ()`
   * Returns a boolean for whether the player has reached a room with an exit.   

## Additional Requirements:

Your application must function as described below:

1. Your program must adhere to the class diagrams provided in this description, including the use of a two-dimensional array to store the rooms of the maze.
2. You program must adhere to using the given interface as specified and the given file format.
3. Any passageway that allows an exit beyond the bounds of the array is considered an exit. Note that you do not want to actually move the player outside the bounds of your array as that may cause your program to crash before it properly exits.
4. When using an item to pass though a door, the two rooms adjacent to the doorway should both be updated to know that the doorway is now open. Thus, a user can go back and forth through a red_key doorway as many times as they want once they have used the red_key on that door.

## Important Notes:

- Projects will be graded on whether they correctly solve the problem, and whether they adhere to good programming practices.
- Projects must be received by the time specified on the due date. Projects received after that time will get a grade of zero.
- Please review the academic honesty policy.
  - Note that viewing another student's solution, whether in whole or in part, is considered academic dishonesty.
  - Also note that submitting code obtained through the Internet or other sources, whether in whole or in part, is considered academic dishonesty. \* All programs submitted will be reviewed for evidence of academic dishonesty, and all violations will be handled accordingly.
  
## Breakdown of Grades

You will find a rubric for the project in Canvas. 

## Submission Instructions:

1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted" the assignment.
   1. After pushing, with `git push origin master`, visit the web URL of your repository to verify that your code is there.
      If you don't see the code there, then we can't see it either.
3. Your code must compile and run in Travis-CI or it might not be graded.
   1. The Travis-CI build should begin automatically when you push your code to GitHub.
   2. If your program will not compile, the graders will not be responsible for trying to test it.
   3. You should get an email regarding the status of your build, if it does not pass, keep trying.
