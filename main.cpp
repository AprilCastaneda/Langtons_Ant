/********************************************************************
** Program name: main.cpp
** Author: April Castaneda
** Date: 04.13.2019
** Description: Main program that tests Langston's Ant.
**		Displays menu that asks user to "Start Langston's Ant
**		Simulation" or "Quit". If program doesn't quit,
**		program displays second menu that aks user if they
**		would like a random starting location for the ant or
**		not. Third menu prompts user to enter # of rows and
**		columns for a board, # of steps for simulation, and if
**		user did not choose a random starting location, user
**		is also prompted to enter ant starting coordinates.
**		Based on user input, a board is built with Langston's
**		ant. Board is displayed and ant moves per user
**		inputted # of steps. Ant movement determined by 
**		Langston's ant rules. When simulation ends, user is
**		prompted if the user would like to "Play again?" or
**		"Quit". Program iterates per user choice.
********************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Menu.hpp" // Menu class
#include "Ant.hpp" // Ant class
#include "Board.hpp" // Board class

void startSimulation(Board, Ant); // Function prototype

int main()
{
	// FIRST PART of program: User goes through three menus to
	// populate Board and create Ant object

	bool inputValid = 0;
	int counter = 0; // counter of how many times program has run

	// Program loops if user wants to play again
	while(!inputValid)
	{
		// FIRST MENU - first iteration
		if(counter == 0)
		{		
			Menu menu1(2, 1, 2); // initialize rows=2,
						//  min=1, max=2
			// Populate menu1
			menu1.populateArray(0, "1. Start Langson's Ant Simulation. (EXTRA CREDIT)");
			menu1.populateArray(1, "2. Quit.");

			// Loop until input is valid
			while(!inputValid)
			{
				menu1.displayMenu(); // display menu1
				inputValid = menu1.validateInput();
			}
		
			// If user chose to quit
			if(menu1.getIntInput() == 2)
			{
				return 0;
			}

		}
		// FIRST MENU - second iteration - change first option
		else if(counter > 0)
		{
			Menu menu1(2, 1, 2); // initialize rows=2, 
						// min=1, max=2
			// Populate menu1, first line differently		
			menu1.populateArray(0, "1. Play Again? (EXTRA CREDIT)");
			menu1.populateArray(1, "2. Quit.");
			
			// Loop until input is valid
			while(!inputValid)
			{
				menu1.displayMenu(); // display menu1
				inputValid = menu1.validateInput();
			}
		
			// If user chose to quit
			if(menu1.getIntInput() == 2)
			{
				return 0;
			}
		}
		
		// SECOND MENU
		Menu menu2(2, 1, 2);
		menu2.populateArray(0, "1. Use random starting location for ant.");
		menu2.populateArray(1, "2. Do not use random starting location.");
	
		// Loop until input is valid
		inputValid = 0; // reset value to help loop menu2	
		while(!inputValid)
		{
			menu2.displayMenu(); 	// display menu2
			inputValid = menu2.validateInput();
		}
		
		// THIRD MENU AND SUB-MENUS
		// Create next menus based on choice from second menu
		// Create variables to store user validated input
		int rows, columns, steps, startR, startC;

		// Generate menus
		Menu menu3a(1, 2, 100); // row: min=2, max=100
		menu3a.populateArray(0, "Number of rows for board.");
		Menu menu3b(1, 2, 100); // column: min=2, max=100
		menu3b.populateArray(0, "Number of columns for board.");
		Menu menu3c(1, 1, 15000); // steps: min=1, max=15000
		menu3c.populateArray(0, "Number of steps during simulation.");

		// THIRD MENU AND SUB-MENUS - Get inputs		
		// Get rows - loop until input is valid
		inputValid = 0; // reset value to help loop menu3
		while(!inputValid)
		{
			menu3a.displayMenu(); 	// display menu
			inputValid = menu3a.validateInput();
		}
		rows = menu3a.getIntInput();
		
		// Get columns - loop until input is valid
		inputValid = 0;
		while(!inputValid)
		{
			menu3b.displayMenu();
			inputValid = menu3b.validateInput();
		}
		columns = menu3b.getIntInput();

		// Get steps - loop until input is valid
		inputValid = 0;		
		while(!inputValid)
		{
			menu3c.displayMenu();
			inputValid = menu3c.validateInput();
		}
		steps = menu3c.getIntInput();
		
		// If user chose 2 for menu2 (Non-random Ant start
		// location)
		// Get ant's starting row and column
		if(menu2.getIntInput() == 2)
		{
			// Generating starting row & column sub-menus
			Menu menu3d(1, 1, rows); // starting row menu:
						// min=1, max=rows
			menu3d.populateArray(0, "Ant's starting row.");
			Menu menu3e(1, 1, columns); // starting column
					// menu: min=1, max=columns
			menu3e.populateArray(0, "Ant's starting column.");
			
			// Get starting row
			inputValid = 0;
			while(!inputValid)
			{
				menu3d.displayMenu();
				inputValid = menu3d.validateInput();
			}
			startR = menu3d.getIntInput();
				
			// Get starting column
			inputValid = 0;
			while(!inputValid)
			{
				menu3e.displayMenu();
				inputValid = menu3e.validateInput();
			}
			startC = menu3e.getIntInput();
		}
		
		// If user chose 1 for menu2 (Random Ant location)
		// Get random ant starting row and column
		else // (menu2.getIntInput() == 1)
		{
			Ant randomG;
			// Send rows and columns to randomizer
			startR = randomG.randomRows(rows);
			startC = randomG.randomCols(columns);
		}

		// Create Ant object with user inputted coordinates
		Ant *antPtr;
		Ant token(startR, startC);
		antPtr = &token;

		// Create Board object with validated input
		Board instance(rows, columns, steps, antPtr); 
		
		// Run simulation per user inputted steps
		for(int x = 0; x <= steps; x++)
		{
			instance.displayBoard();
			instance.moveToken();
		
			if(x == steps)
			{
				cout << x << " steps." << endl;
			}
		}
		
		inputValid = 0; // Iterate program to beginning
		counter++;		
	}

	return 0;
}
