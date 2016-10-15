#include <iostream>
#include <string>

using namespace std;

struct Node {
	string discipline;
	string gender;
	string team_or_ind;
	string event;
	string venue;
	string medal;
	string athlete;
	string country;
	string color;
	Node * parent;
	Node * left;
	Node * right;

	string getKey();
	void display();
};

string Node::getKey()
{
	string key = discipline + "," + gender + "," + event + "," + athlete;
	return key;
}

void Node::display()
{
	cout << "\ndiscipline:\t" << discipline << "\ngender:\t\t" << gender << "\nteam_or_ind\t" << team_or_ind
		<< "\nevent:\t\t" << event << "\nvenue:\t\t" << venue << "\nmedal:\t\t" << medal << "\nathlete:\t"
		<< athlete << "\ncountry:\t" << country << "\ncolor:\t\t" << color;
}