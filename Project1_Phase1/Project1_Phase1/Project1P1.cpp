// Project 1 Phase 1
// Name: Kyle Moffett
// ASU Email Address: krmoffet@asu.edu
// Description: Reads a list of Athlete data from the user into a hash table and executes commands as defined.

#include <iostream>
#include <string>
#include <sstream>	
#include "HashTable.h"

using namespace std;

int main() {
	string discipline, gender, type, event, venue, medal, name, country;
	string input;
	string command = "";
	int tableSize, numCmds;

	Athlete * newAthlete = new Athlete;

	cout << "Please enter table size: ";
	cin >> tableSize;
	cin.ignore();
	HashTable table(tableSize);
	cout << "Please enter medal information: \n";
	getline(cin, input);
	if (input != "InsertionEnd")
	{
		do
		{
			stringstream ss(input);
			getline(ss, discipline, ',');
			getline(ss, gender, ',');
			getline(ss, type, ',');
			getline(ss, event, ',');
			getline(ss, venue, ',');
			getline(ss, medal, ',');
			getline(ss, name, ',');
			getline(ss, country);

			newAthlete->setDiscipline(discipline);
			newAthlete->setGender(gender);
			newAthlete->setEventType(type);
			newAthlete->setEvent(event);
			newAthlete->setVenue(venue);
			newAthlete->setMedal(medal);
			newAthlete->setName(name);
			newAthlete->setCountry(country);

			table.addAthlete(newAthlete);

			cout << "\nPlease enter medal information: \n";
			getline(cin, input);
		} while (input != "InsertionEnd");
	}

	cout << "Please enter number of commands: ";
	cin >> numCmds;
	cin.ignore();
	
	for (int i = 1; i <= numCmds; i++)
	{
		cout << "Enter command:\n";
		getline(cin, input);
		if (input == "hash_display")
		{
			table.printTable();
		}
		else
		{
			stringstream ss(input);
			getline(ss, command, ',');
			getline(ss, discipline, ',');
			getline(ss, gender, ',');
			getline(ss, event, ',');
			getline(ss, name);
			if (command == "hash_delete")
			{
				table.removeAthlete(discipline, gender, event, name);
			}
			else if (command == "hash_search")
			{
				table.searchAthlete(discipline, gender, event, name);
			}
		}
	}
	return 0;
}