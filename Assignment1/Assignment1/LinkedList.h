// Assignment #1
// Name: Kyle Moffett
// ASU Email Address: krmoffet@asu.edu
// Description: Defines the linked list and associated functions for Countries with medal counts.

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings

using namespace std;

//struct Country represents some country information
struct Country
{
    string name;
    int gold;
    int silver;
    int bronze;
    struct Country * next;
};

//class LinkedList will contains a linked list of countries
class LinkedList
{
    private:
        struct Country * head;
    public:
        LinkedList();
        ~LinkedList();
        bool addCountry(string countryName, int gold, int silver, int bronze);
        bool removeCountry(string countryName);
        bool changeMedalCount(string countryName, string medal, int count);
        void printList();
};

//Constructor to initialize the linked list
LinkedList::LinkedList()
{
    head = NULL;
}

//Destructor
//Description: Performs garbage collection on linked list nodes
LinkedList::~LinkedList()
{
	Country *q = head;
	Country *p = q;
	int delcount = 0;
	if (head == NULL) {
		delete head;
		head = NULL;
		cout << "\nThe number of deleted countries is: 0\n";
	}
	else {
		while (q != NULL) {
			p = q;
			q = q->next;
			delete p;
			delcount++;
		}
		head = NULL;
		cout << "\nThe number of deleted countries is: " << delcount << "\n";
	}
	/*
	delete head;
	head = NULL;*/
}

//Description: Adds country with medal count to linked list
bool LinkedList::addCountry(string newName, int gold, int silver, int bronze)
 {
	 Country *newCountry = new Country;
	 newCountry->name = newName;
	 newCountry->gold = gold;
	 newCountry->silver = silver;
	 newCountry->bronze = bronze; 
	 /*Country *p = new Country;
	 if (p != NULL && newCountry != NULL) {
		 p = newCountry;
		 p->next = head;
		 head = p;
		 return true;
	 }*/

	 Country *current = head;
	 Country *previous = NULL;
	 
	 while (current != NULL && current->name < newCountry->name) {
		 previous = current;
		 current = current->next;
	 }
	if (previous == NULL) {
		newCountry->next = head;
		head = newCountry;
		return true;
	}
	else {
		 previous->next = newCountry;
		 newCountry->next = current;
		 return true;
	 }
 }

//Description: removes specified country fromm linked list
bool LinkedList::removeCountry(string someName)
 {
	Country *p = head;
	Country *q = NULL;
	if (p == NULL)
		return false;
	if (p->name == someName) {
		head = p->next;
		return true;
	}
	q = p->next;
	while (q != NULL && q->name != someName) {
		p = p->next;
		q = q->next;
	}
	if (q == NULL)
		return false;
	if (q->name == someName) {
		p->next = q->next;
		return true;
	}
	else
		return false;
 }

//Description: Changes the medal count of specified country
bool LinkedList::changeMedalCount(string countryName, string medalType, int count)
{
	Country *p = head;
	if (p == NULL)
		return false;
	while (p->name != countryName && p->next != NULL) {
		p = p->next;
	}
	if (p == NULL || p->name != countryName) {
		return false;
	}
	if (p->name == countryName) {
		if (medalType == "gold") {
			p->gold = count;
			return true;
		}
		else if (medalType == "silver") {
			p->silver = count;
			return true;
		}
		else if (medalType == "bronze") {
			p->bronze = count;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

//Description: Prints a list of all countries and medals
void LinkedList::printList()
{
	Country *q = head;
	cout << "\n";
	while (q != NULL) {
		cout << "Country name: " << q->name << ", Gold: " << q->gold << ", Silver: " << q->silver << ", Bronze: " << q->bronze << "\n";
		q = q->next;
	}

}