// Project 1 Phase 1
// Name: Kyle Moffett
// ASU Email Address: krmoffet@asu.edu
// Description: Defines the hash table class and functions to add, remove and search for objects
//				at indices requested.

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

class HashTable		// Define HashTable class and associated functions
{
private:
	LinkedList * array;
	int size;
	int hash(string discipline, string gender, string event, string name);
public:
	HashTable(int tableLength = 14);
	~HashTable();
	void addAthlete(Athlete * newAthlete);
	int searchAthlete(string discipline, string gender, string event, string name);
	int removeAthlete(string discipline, string gender, string event, string name);
	void printTable();
};

HashTable::HashTable(int tableSize)		// constructor with default table length 14
{
	array = new LinkedList[tableSize];
	size = tableSize;
}

HashTable::~HashTable()		// Destructor
{
	delete[] array;
}

int HashTable::hash(string discipline, string gender, string event, string name)	// Hash function. Concatenates discipline, gender, event, and name for key value.
{
	string str = (discipline + gender + event + name);
	int key = 0;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		key = key + (int)str[i];
	}
	int hash = key % size;
	return hash;
}

void HashTable::addAthlete(Athlete * newAthlete)		// insert Athlete into linked list at hashed index
{
	int index = hash(newAthlete->getDiscipline(), newAthlete->getGender(), newAthlete->getEvent(), newAthlete->getName());
	array[index].addAthlete(newAthlete->getDiscipline(), newAthlete->getGender(), newAthlete->getEventType(), newAthlete->getEvent(), newAthlete->getVenue(),
							newAthlete->getMedal(), newAthlete->getName(), newAthlete->getCountry());
}

int HashTable::searchAthlete(string discipline, string gender, string event, string name)		// search for athlete in linked list at hashed index
{
	int index = hash(discipline, gender, event, name);
	if (array[index].searchAthlete(discipline, gender, event, name) == 0)
		return 0;
	else
	{
		return 1;
	}
}

int HashTable::removeAthlete(string discipline, string gender, string event, string name)		// removes athlete from linked list
{
	int index = hash(discipline, gender, event, name);
	if (array[index].removeAthlete(discipline, gender, event, name) == 0)
	{
		cout << "\nThe medal recipient " << name << " for " << discipline << " with event " << event << " deleted\n";
		return 0;

	}
	else
	cout << name << " for " << discipline << " with event " << event << " not found\n";
	return 1;
}

void HashTable::printTable()		// Displays all information in hash table
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nindex: " << i << ", linked list size: " << array[i].getSize() << "\n";
		array[i].printList();
	}
}