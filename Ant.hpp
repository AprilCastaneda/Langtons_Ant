/********************************************************************
** Program name: Ant.hpp
** Author: April Castaneda
** Date: 04.13.2019
** Description: Ant class specification file.
**		Contains ant's location and direction. Contains
**		function that generates random ant location.
********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

// Ant class declaration
class Ant
{
private:
	int rowPos, colPos; // row and column coordinates
	char direction; // could be l=left, r=right, u=up, d=down
public:
	// Constructor
	Ant();
	Ant(int r, int c);
	// Setter Functions
	void setRowPos(int r);
	void setColPos(int c);
	void setDirection(char dir);
	// Getter Functions
	int getRowPos();
	int getColPos();
	char getDirection();
	// Function that generates random Ant coordinates
	int randomRows(int bRows);
	int randomCols(int bCols);
};
#endif
