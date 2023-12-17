/*
	Codey Webb
*/

#include "ItemTracker.h"

using namespace std;

// constructor
ItemTracker::ItemTracker(string fileToParse)
{
	// parse the input file
	this->ParseFile(fileToParse);
	// create a backup
	this->GenerateBackupFile();
}

// search for an item, get occurances if it exists
void ItemTracker::GetItem(string itemToCheck)
{
	// if item exists
	if (itemFrequencies.count(itemToCheck))
	{
		// get occurances
		itemOccurrence = itemFrequencies.at(itemToCheck);
		occurrenceSingleOrPlural = itemOccurrence > 1 ? "occurrences" : "occurrence";
		// print info to user
		cout << '\t' << itemToCheck << " found. " << itemOccurrence << " " << occurrenceSingleOrPlural << "." << endl;
	}
	else // otherwise
	{
		// inform user item was not found
		cout << '\t' << itemToCheck << " not found." << endl;;
	}
}

// display a list of items/frequencies
void ItemTracker::DisplayItemFrequenciesList()
{
	for (const auto& pair : itemFrequencies)
	{
		cout << '\t' << pair.first << ' ' << pair.second << endl;
	}
}


// display a histogram of items/frequencies using HISTOGRAMCHAR
void ItemTracker::DisplayItemFrequenciesHistogram()
{
	for (const auto& pair : itemFrequencies)
	{
		cout << '\t' << pair.first << ' ';
		for (int i = 0; i < pair.second; i++)
		{
			cout << HISTOGRAMCHAR;
		}
		cout << endl;
	}
}

// get information from the file and add it to the itemFrequencies map
void ItemTracker::ParseFile(string fileToParse)
{
	// open the file
	inFS.open(fileToParse);
	// if the file opened
	if (inFS.is_open())
	{
		// until the end of the file is reached, continue looping
		while (!inFS.eof())
		{
			// get an item from the .txt document
			getline(inFS, item);

			// if item is a space, newline, or nothing
			if (item == " " || item == "\n" || item == "")
			{
				// don't add to itemFrequencies
				continue;
			}
			// if item doesn't exist in itemFrequencies
			if (itemFrequencies.count(item) == 0)
			{
				// add item, set occurances to 1
				itemFrequencies[item] = 1;
			}
			else
			{
				// otherwise update items occurances
				itemCount = itemFrequencies[item] + 1;
				itemFrequencies[item] = itemCount;
			}
		}
		// close file
		inFS.close();
	}
	else
	{
		// otherwise inform the user the file was not opened
		cout << "File not opened. Check file name or location." << endl;
	}
}

// generate a backup of all items/occurances
void ItemTracker::GenerateBackupFile()
{
	// open an output file
	outFS.open("frequency.dat");
	// if output file opened
	if (outFS.is_open())
	{
		// add items/frequencies
		for (const auto& pair : itemFrequencies)
		{
			outFS << pair.first << ' ' << pair.second << endl;
		}
	}
	// close output file
	outFS.close();
}
