/*
	Codey Webb
*/

#include "Menu.h"

using namespace std;

// constructor
Menu::Menu()
{
	// create an ItemTracker
	ItemTracker itemTracker(INPUTFILE);

	// until user types 4, continue looping
	while (userOption != 4)
	{
		DisplayMenu(); // display menu
		InputHandler(userOption, itemTracker); // handle input
	}
}

// display menu options for user
void Menu::DisplayMenu()
{
	DisplayBorder(BORDERCHAR, BORDERLENGTH);
	cout << "-------------------------Main  Menu-------------------------" << endl;
	cout << '\t' << "What do you want to do? (Type a number)" << endl;
	cout << "1. Search frequency of 1 item (case sensitive)." << endl;
	cout << "2. View a list of all items and their frequency as an integer." << endl;
	cout << "3. View a histogram of all items and their frequency." << endl;
	cout << "4. Exit program." << endl;
	DisplayBorder(ALTBORDERCHAR, BORDERLENGTH);
	cout << "Your option: ";
	cin >> userOption;
	DisplayBorder(BORDERCHAR, BORDERLENGTH);
}

// handle users input
void Menu::InputHandler(int input, ItemTracker &itemTracker)
{
	userOption = RESETUSEROPTION; // reset userOption to default value
	switch (input) {
	case 1: // if input is 1
		itemToCheck = RESETITEMTOCHECK; // reset itemToCheck
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "--Search For One Item--" << endl;
		cout << "Item (case sensitive): ";
		getline(cin, itemToCheck); // prompt user for new itemToCheck
		itemTracker.GetItem(itemToCheck); // search for item, return occurances if exists
		break;
	case 2: // if input is 2
		cout << "--List of All Items--" << endl;
		itemTracker.DisplayItemFrequenciesList(); // display list of items/occurances
		break;
	case 3: // if input is 3
		cout << "--Histogram of All Items--" << endl;
		itemTracker.DisplayItemFrequenciesHistogram(); // display histogram of items/occurances
		break;
	case 4: // if input is 4
		userOption = EXITPROGRAM; // set userOption to 4 (exit program)
		break;
	default: // otherwise
		// inform user of invalid input, clear stream and ignore everything in buffer until a newline
		cout << endl << "! Unrecognized input !" << endl << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

// display border
void Menu::DisplayBorder(char borderChar, int borderLength)
{
	for (int i = 0; i < borderLength; i++)
	{
		cout << borderChar;
	}
	cout << endl;
}