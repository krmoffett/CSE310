#include <iostream>
#include <string>

using namespace std;

struct Node {
	string discipline;
	string gender;
	string team;
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

	string getKey(Node x);
};

string Node::getKey(Node x)
{
	string key = x.discipline + x.gender + x.event + x.athlete;
	return key;
}