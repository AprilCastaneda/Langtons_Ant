/********************************************************************
** Program name: Board.cpp
** Author: April Castaneda
** Date: 04.13.2019
** Description: Board class implementation file.
**		Builds a board based on user entered dimensions.
**		Moves ant token on board per Langston's ant rules.
**		Displays board and deletes board after simulation.
********************************************************************/
#include<iostream>
using std::cout;
using std::endl;

#include "Board.hpp"

/********************************************************************
** Description: Constructors
********************************************************************/
Board::Board()
{
	setNumRows(0);
	setNumColumns(0);
	setNumSteps(1);
	setBoardColor('w');
	setAnt(nullptr);
	allocBoard();
	generateBoard();
}

Board::Board(int bRows, int bCols, int s, Ant* aPtr)
{
	setNumRows(bRows);
	setNumColumns(bCols);
	setNumSteps(s);
	setBoardColor('w');
	setAnt(aPtr);
	allocBoard();
	generateBoard();
}

/********************************************************************
** Description: Destuctor
********************************************************************/
Board::~Board()
{
	// Delete dynamically allocated array
	for(int j = 0; j < numRows; j++)
	{
		delete[] boardArray[j];
	}
	delete[] boardArray;
//	boardArray = nullptr;
}
/********************************************************************
** Description: Setter Functions
********************************************************************/
void Board::setNumRows(int bRows)
{
	numRows = bRows + 2;
}

void Board::setNumColumns(int bCols)
{
	numColumns = bCols + 2;
}

void Board::setNumSteps(int s)
{
	numSteps = s;
}

void Board::setBoardColor(char c)
{
	boardColor = c;
}

void Board::setAnt(Ant* aPtr)
{
	antPointer = aPtr;
}

/********************************************************************
** Description: Getter Functions
********************************************************************/
int Board::getNumRows()
{
	return numRows;
}

int Board::getNumColumns()
{
	return numColumns;
}

int Board::getNumSteps()
{
	return numSteps;
}

char Board::getBoardColor()
{
	return boardColor;
}

char** Board::getBoard()
{
	return boardArray;
}

Ant* Board::getAnt()
{
	return antPointer;
}

/********************************************************************
** Description: Function that dynamically allocates board
********************************************************************/
void Board::allocBoard()
{
	// First, make array of pointers with numRows
	boardArray = new char*[numRows];

	// Next, dynamically allocate arrays with numColumns
	for(int i = 0; i < numRows; i++)
	{
		boardArray[i] = new char[numColumns];
	}
}	

/********************************************************************
** Description: Function that generates board
********************************************************************/
void Board::generateBoard()
{
	// Populate board array
	for(int r = 0; r < numRows; r++)
	{
		for(int c = 0; c < numColumns; c++)
		{
			// Generate borders
			if((r == 0) || (r == (numRows-1)))
			{
				boardArray[r][c] = '-';
			}
			else if((c == 0) || (c == (numColumns-1)))
			{
				boardArray[r][c] = '|';
			}
			// Default to white 'w' spaces for 1st board
			else
			{
				boardArray[r][c] = 'w';
			}
		}
	}
}

/********************************************************************
** Description: Board Display Function
********************************************************************/
void Board::displayBoard()
{
	for(int r = 0; r < numRows; r++)
	{
		for(int c = 0; c < numColumns; c++)
		{
			// display white spaces
			if(boardArray[r][c] == 'w')
			{
				cout << ' ';
			}
			// display black spaces
			else if(boardArray[r][c] == 'b')
			{
				cout << '#';
			}
			else
			{
				cout << boardArray[r][c];
			}
		}
		cout << endl;
	}
}

/********************************************************************
** Description: Function that moves Ant based on Langston's ant rules
********************************************************************/
void Board::moveToken()
{
	// Get ant coordinates
	int r = antPointer->getRowPos();
	int c = antPointer->getColPos();
	
	// Determine how ant moves based on Langston's ant rules
	// If ant is on a white space
	if(boardColor == 'w') 
	{
		// Ant turns right 90 degrees and changes the space
		// to black
		moveRight90();
		boardArray[r][c] = 'b';
	}
	// If ant is on a black space
	else if(boardColor == 'b')
	{
		// Ant turns left 90 degrees and changes the space
		// to white
		moveLeft90();
		boardArray[r][c] = 'w';
	}
	
	// Get new ant coordinates
	int newR = antPointer->getRowPos();
	int newC = antPointer->getColPos();

	// Store board color from new at coordinates
	if(boardArray[newR][newC] == 'w')
	{
		boardColor = 'w';
	}
	else if(boardArray[newR][newC] == 'b')
	{
		boardColor = 'b';
	}

	// Now, place the ant
	boardArray[newR][newC] = '*';	
}

/********************************************************************
** Description: Function that turns Ant token right 90 degrees and
**		moves the token forward.
********************************************************************/
void Board::moveRight90()
{
	// Get ant direction
	char dir = antPointer->getDirection();

	// Turn ant right 90 degrees
	if(dir == 'l')
	{
		antPointer->setDirection('u');
	}
	else if(dir == 'u')
	{
		antPointer->setDirection('r');
	}
	else if(dir == 'r')
	{
		antPointer->setDirection('d');
	}
	else if(dir == 'd')
	{
		antPointer->setDirection('l');
	}

	// Check for edge cases and move ant token
	checkEdge();
}

/********************************************************************
** Description: Function that turns Ant token left 90 degrees and
**		moves the token forward.
********************************************************************/
void Board::moveLeft90()
{
	// Get ant direction
	char dir = antPointer->getDirection();

	// Turn ant right 90 degrees
	if(dir == 'l')
	{
		antPointer->setDirection('d');
	}
	else if(dir == 'd')
	{
		antPointer->setDirection('r');
	}
	else if(dir == 'r')
	{
		antPointer->setDirection('u');
	}
	else if(dir == 'u')
	{
		antPointer->setDirection('l');
	}

	// Check for edge cases and move ant token
	checkEdge();
}

/********************************************************************
** Description: Function that checks edges where Ant token is going.
**		If it hits edge, board wraps around and takes ant to
**		the other side. If not, ant moves forward.
********************************************************************/
void Board::checkEdge()
{
	// Get ant position
	int r = antPointer->getRowPos();
	int c = antPointer->getColPos();

	// Get ant direction
	char dir = antPointer->getDirection();

	// If ant is going to hit left side of board
	if(dir == 'l')
	{
		// edge case
		if(c == 1)
		{
			antPointer->setColPos(numColumns-2);
		}
		// non-edge
		else
		{
			antPointer->setColPos(c-1);
		}
	}
	// If ant is going to hit top side of the board
	else if(dir == 'u')
	{
		// edge case
		if(r == 1)	
		{
			antPointer->setRowPos(numRows-2);
		}
		// non-edge
		else
		{
			antPointer->setRowPos(r-1);
		}
	}
	// If ant is going to hit right side of the board
	else if(dir == 'r')
	{
		// edge case
		if(c == (numColumns-2))
		{
			antPointer->setColPos(1);
		}
		// non-edge
		else
		{
			antPointer->setColPos(c+1);
		}
	}
	// If ant is going to hit bottom of the board
	else if(dir == 'd')
	{
		// edge case
		if(r == (numRows-2))
		{
			antPointer->setRowPos(1);
		}
		// non-edge
		else
		{
			antPointer->setRowPos(r+1);
		}
	}
}
