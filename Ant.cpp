/********************************************************************
** Program name: Ant.cpp
** Author: April Castaneda
** Date: 04.13.2019
** Description: Ant class implementation file.
**		Contains ant's location and direction. Contains
**		function that generates random ant location.
********************************************************************/
#include <cstdlib> // library to generate random numbers

#include "Ant.hpp"

/********************************************************************
** Description: Constructor
********************************************************************/
Ant::Ant()
{
	setRowPos(1);
	setColPos(1);
	setDirection('l'); // default direction facing left
}
 
/********************************************************************
** Description: Constructor
********************************************************************/
Ant::Ant(int r, int c)
{
	setRowPos(r);
	setColPos(c);
	setDirection('l'); // default direction facing left
}

/********************************************************************
** Description: Setter Functions
********************************************************************/
void Ant::setRowPos(int r)
{
	rowPos = r;
}

void Ant::setColPos(int c)
{
	colPos = c;
}

void Ant::setDirection(char dir)
{
	direction = dir;
}

/********************************************************************
** Description: Getter Functions
********************************************************************/
int Ant::getRowPos()
{
	return rowPos;
}

int Ant::getColPos()
{
	return colPos;
}

char Ant::getDirection()
{
	return direction;
}

/********************************************************************
** Description: Function that sets random starting row for Ant
********************************************************************/
int Ant::randomRows(int bRows)
{
 	int tempRows = rand() % bRows + 1;

	return tempRows;
}

/********************************************************************
** Description: Function that sets random starting columns for Ant
********************************************************************/
int Ant::randomCols(int bCols)
{
	int tempCols = rand() % bCols + 1;

	return tempCols;
}

