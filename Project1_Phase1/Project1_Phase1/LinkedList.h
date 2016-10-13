// Project 1 Phase 1
// Name: Kyle Moffett
// ASU Email Address: krmoffet@asu.edu
// Description: Defines the Athlete struct and LinkedList class for storing, searching and
//				removeing athlete data.

#include <iostream>
#include <string>

using namespace std;

struct Athlete // Define the main struct for Athlete object
{
private:
	string discipline;
	string gender;
	string type;
	string event;
	string venue;
	string medal;
	string name;
	string country;
	Athlete *next;

public:
	void setDiscipline(string newDiscipline) { discipline = newDiscipline; }	
	string getDiscipline() { return discipline; }

	void setGender(string newGender) { gender = newGender; }
	string getGender() { return gender; }

	void setEventType(string newType) { type = newType; }
	string getEventType() { return type; }

	void setEvent(string newEvent) { event = newEvent; }
	string getEvent() { return event; }

	void setVenue(string newVenue) { venue = newVenue; }
	string getVenue() { return venue; }

	void setMedal(string newMedal) { medal = newMedal; }
	string getMedal() { return medal; }

	void setName(string newName) { name = newName; }
	string getName() { return name; }

	void setCountry(string newCountry) { country = newCountry; }
	string getCountry() { return country; }

	void setNext(Athlete * newNext) { next = newNext; }
	Athlete * getNext() { return next; }
};

class LinkedList // Define the LinkedList class for storing Athletes
{
private:
	Athlete * head;
	int size = 0;
public:
	LinkedList();
	~LinkedList();
	int addAthlete(string discipline, string gender, string type, string event, string venue, string medal, string name, string country);
	int searchAthlete(string discipline, string gender, string event, string name);
	int removeAthlete(string discipline, string gender, string event, string name);
	int getSize();
	void printList();
};

//Constructor
LinkedList::LinkedList()
{
	head = NULL;
}

//Destructor
LinkedList::~LinkedList()
{
	Athlete *q = head;
	Athlete *p = q;
	if (head == NULL) {
		delete head;
		head = NULL;
	}
	else {
		while (q != NULL) {
			p = q;
			q = q->getNext();
			delete p;
		}
	}
}

int LinkedList::getSize() // Return the size of the Linked List
{
	return size;
}

int LinkedList::addAthlete(string discipline, string gender, string type, string event, string venue,		// adds an Athlete to the Linked List
							string medal, string name, string country)
{
	Athlete * newAthlete = new Athlete;
	newAthlete->setDiscipline(discipline);
	newAthlete->setGender(gender);
	newAthlete->setEventType(type);
	newAthlete->setEvent(event);
	newAthlete->setVenue(venue);
	newAthlete->setMedal(medal);
	newAthlete->setName(name);
	newAthlete->setCountry(country);

	Athlete * p = newAthlete;
	if (p != NULL && newAthlete != NULL) {
		p = newAthlete;
		p->setNext(head);
		head = p;
		size++;
		return 0;
	}
	else
		return 1;
}

int LinkedList::searchAthlete(string discipline, string gender, string event, string name)		// searches an Athlete and returns with medal recieved if found
{
	Athlete * p = new Athlete;
	p = head;
	while (p != NULL)
	{
		if (p->getDiscipline() == discipline && p->getGender() == gender && p->getEvent() == event && p->getName() == name)
		{
			cout << "\nThe medal recipient " << name << " has the medal of " << p->getMedal() << "\n";
			return 0;
		}
		p = p->getNext();
	}
	cout << "\n" << name << " for " << discipline << " with event " << event << " not found\n";
	return 1;
}

int LinkedList::removeAthlete(string discipline, string gender, string event, string name)		// removes an Athlete object from LinkedList
{
	Athlete * p = head;
	Athlete * q = NULL;
	
	if (p == NULL)
		return 1;
	if (p->getDiscipline() == discipline && p->getGender() == gender && p->getEvent() == event && p->getName() == name)
	{
		head = p->getNext();
		size--;
		return 0;
	}
	q = p->getNext();
	while (q != NULL && q->getDiscipline() != discipline || q->getGender() != gender || q->getEvent() != event || q->getName() != name)
	{
		p = p->getNext();
		q = q->getNext();
	}
	if (q == NULL)
		size--;
		return 0;
	if (q->getDiscipline() == discipline && q->getGender() == gender && q->getEvent() == event && q->getName() == name)
	{
		p->setNext(q->getNext());
		size--;
		return 0;
	}
	else
		return 1;
}

void LinkedList::printList()	// displays all information from LinkedList
{
	Athlete * p = head;
	if (p == NULL)
		cout << "The list is empty\n";
	while (p != NULL)
	{
		cout << "\ndiscipline:\t" << p->getDiscipline() << "\ngender:\t\t" << p->getGender() << "\nteam_or_ind:\t" << p->getEventType() << "\nevent:\t\t" << p->getEvent()
			<< "\nvenue:\t\t" << p->getVenue() << "\nmedal:\t\t" << p->getMedal() << "\nathlete:\t" << p->getName() << "\ncountry:\t" << p->getCountry() << "\n";
		p = p->getNext();
	}
}