/********************************************************************
** Program name: Menu.cpp
** Author: April Castaneda
** Date: 04.13.2019
** Description: Menu class implementation file.
**		Dynamically creates a menu based on # of rows.
**		Takes Input. Validates Input. Returns valid input as
**		integer.
********************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Menu.hpp"

/********************************************************************
** Description: Default Constructor
********************************************************************/
Menu::Menu()
{
	setRows(1);
	setMin(1);
	setMax(1);
	setStringInput("1");
	setIntInput(1);
	menuArray = nullptr;
}

/********************************************************************
** Description: Constructor
********************************************************************/
Menu::Menu(int rows, int min, int max)
{
	setRows(rows);
	setMin(min);
	setMax(max);
	setMenuArray(rows);
}

/********************************************************************
** Description: Destructor
********************************************************************/
Menu::~Menu()
{
	if(menuArray != nullptr)
	{
		delete[] menuArray;
		menuArray = nullptr;
	}
}

/********************************************************************
** Description: Setter Functions
********************************************************************/
void Menu::setRows(int rows)
{
	menuRows = rows;
}
void Menu::setMin(int min)
{
	minVal = min;
}
void Menu::setMax(int max)
{
	maxVal = max;
}
void Menu::setStringInput(string strInput)
{
	stringInput = strInput;
}
void Menu::setIntInput(int input)
{
	intInput = input;
}
void Menu::setMenuArray(int rows)
{
	string *tempPtr = allocMenu(rows);
	menuArray = tempPtr;
}

/********************************************************************
** Description: Getter Functions
********************************************************************/
int Menu::getRows()
{
	return menuRows;
}
int Menu::getMin()
{
	return minVal;
}
int Menu::getMax()
{
	return maxVal;
}
string Menu::getStringInput()
{
	return stringInput;
}
int Menu::getIntInput()
{
	return intInput;
}
string* Menu::getMenuArray()
{
	return menuArray;
}

/********************************************************************
** Description: Dynamically allocate menu based on number of rows
********************************************************************/
string* Menu::allocMenu(int rows)
{
	string* tempPtr = new string[rows];
	
	return tempPtr;
}

/********************************************************************
** Description: Populate array
********************************************************************/
void Menu::populateArray(int rowNum, string optionScript)
{
	menuArray[rowNum] = optionScript;
}

/********************************************************************
** Description: Display Menu
********************************************************************/
void Menu::displayMenu()
{
	for(int x = 0; x < menuRows; x++)
	{
		cout << menuArray[x] << endl;
	}
	cout << "Please enter an integer between " << minVal;
	cout << " to " << maxVal << ": ";

	getline(cin, stringInput);	
}

/********************************************************************
** Description: Validates if input is an integer and between min/max
********************************************************************/
bool Menu::validateInput()
{
	// Check to see input is not empty
	while(stringInput.empty())
	{
		cout << "Input Error. Try again." << endl;
		getline(cin, stringInput);
	}

	// Go through characters of string to determine if integer
	for(int x = 0; x < stringInput.size(); x++)
	{
		char temp; // holder for characters in stringInput

		temp = stringInput.at(x);

		if(!isdigit(temp))
		{
			cout << "Input Error. Try again." << endl;
			return 0; // invalid data
		}		
	}

	// data is an integer, so turn string into integer
	int tempInt = stoi(stringInput);
		
	// Now, see if data is between minValue and maxValue
	if(!((tempInt >= minVal) && (tempInt <= maxVal)))  
	{
		cout << "Input Error. Try again." << endl;
		return 0; // invalid data
	}

	// data is valid, so assign tempInt to intInput
	intInput = tempInt;

	return 1;
}
