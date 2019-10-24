/********************************************************************
** Program name: Board.hpp
** Author: April Castnaeda
** Date: 04.13.2019
** Description: Board class specification file.
**		Builds a board based on user entered dimensions.
**		Moves ant token on board per Langston's ant rules.
**		Displays board and delets board after simulation.
********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

#include "Ant.hpp"

// Board class declaration
class Board
{
private:
	int numRows, numColumns;
	int numSteps;
	char boardColor; // 'w' or 'b'
	char** boardArray; // 2D boardArray pointer
	Ant* antPointer; // get Ant position
public:
	// Constructor
	Board();
	Board(int bRows, int bCols, int s, Ant* aPtr);
	// Destructor
	~Board();
	// Setter Functions
	void setNumRows(int bRows);
	void setNumColumns(int bCols);
	void setNumSteps(int s);
	void setBoardColor(char c);
	void setAnt(Ant* aPtr);
	// Getter Functions
	int getNumRows();
	int getNumColumns();
	int getNumSteps();
	char getBoardColor();
	char** getBoard();
	Ant* getAnt();
	// Board Generator Functions
	void allocBoard();
	void generateBoard();
	// Board Display Function
	void displayBoard();
	// Ant Token Mover Functions
	void moveToken();
	void moveRight90();
	void moveLeft90();
	void checkEdge();
};
#endif
