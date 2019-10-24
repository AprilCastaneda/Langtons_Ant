/********************************************************************
** Program name: Menu.hpp
** Author: April Castaneda
** Date: 04.13.2019
** Description: Menu class specification file.
**		Dynamically creates a menu based on # of rows.
**		Takes Input. Validates Input. Returns valid input as
**		integer.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

// Menu class declaration
class Menu
{
private:
	int menuRows;		// how many rows in the menu
	int minVal, maxVal; 	// min and max values of user input
	int intInput;		// user input changed to integer
	string stringInput; 	// user input as a string
	string* menuArray;	// array to be dynamically allocated
public:
	// Constructors
	Menu(); 		// default constructor
	Menu(int rows, int min, int max);
	// Dstructor
	~Menu();
	// Setter Functions
	void setRows(int rows);
	void setMin(int min);
	void setMax(int max);	
	void setIntInput(int input);
	void setStringInput(string strInput);
	void setMenuArray(int rows);
	// Getter Functions
	int getRows();
	int getMin();
	int getMax();
	int getIntInput();
	string getStringInput();
	string* getMenuArray();
	// Dynamically allocate Menu Array
	string* allocMenu(int rows);
	// Populate Menu Array
	void populateArray(int rowNum, string optionScript);
	// Display Menu
	void displayMenu();
	// Validate Input
	bool validateInput();
};
#endif
		

