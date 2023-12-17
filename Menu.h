/*
	Codey Webb
*/

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <map>
#include "ItemTracker.h"

using namespace std;

class Menu
{
public:
	Menu(); // constructor

private:
	const string INPUTFILE = "CS210_Project_Three_Input_File.txt"; // file to be read by ItemTracker
	const int RESETUSEROPTION = 0; // default userOption value
	const int EXITPROGRAM = 4; // value to exit the program
	const int BORDERLENGTH = 60;
	const char BORDERCHAR = '*';
	const char ALTBORDERCHAR = '='; // alternate border character
	const string RESETITEMTOCHECK = ""; // reset the itemToCheck string
	string itemToCheck = ""; // used to search for a specific item
	int userOption = 0; // used for choosing a menu item

	void DisplayMenu(); // display menu options
	void InputHandler(int input, ItemTracker &itemTracker); // handle user input
	void DisplayBorder(char borderChar, int borderLength); // display a border
};

#endif // !MENU_H
