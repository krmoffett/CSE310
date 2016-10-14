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
	Node * parent;
	Node * left;
	Node * right;

	int getKey(Node x);
};

Node::getKey(Node x)
{
	string str = x.discipline + x.gender + x.event + x.athlete;
	int key = (int)str;
	return key;
}