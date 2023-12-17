/*
	Codey Webb
*/

#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class ItemTracker
{
public:
	ItemTracker(string fileToParse); // constructor
	void GetItem(string itemToCheck); // search for a specific item and get occurances
	void DisplayItemFrequenciesList(); // print a list of items
	void DisplayItemFrequenciesHistogram(); // print a histogram of items

private:
	ifstream inFS; // input file stream
	ofstream outFS; // output file stream

	map<string, int> itemFrequencies; // holds item/frequencies

	const char HISTOGRAMCHAR = '*'; // used to count items in the histogram
	string item = ""; // used in ParseFile()
	string occurrenceSingleOrPlural; // check for use of "occurances" or "occurance" depending on amount of items
	int itemCount = 0; // used in ParseFile() to update counts in itemFrequencies
	int itemOccurrence = 0; // used in GetItem() to hold occurances of item

	void ParseFile(string fileToParse); // read file, count occurances, place in itemOccurances
	void GenerateBackupFile(); // create a backup file after ParseFile() is finished
};

#endif // !ITEMTRACKER_H
