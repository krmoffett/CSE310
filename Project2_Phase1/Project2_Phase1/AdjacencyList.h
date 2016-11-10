// Project 2 Phase 1
// Name: Kyle Moffett
// ASU Email Address: krmoffet@asu.edu
// Description:

#include <iostream>
#include <string>

using namespace std;

struct Node {
	string loser;
	string score;
	Node * next;
	void printNode()
	{
		cout << loser << score;
		if (next != NULL)
			cout << ", ";
	}

};

struct List {
	string name;
	Node * head;
	List()
	{
		head = NULL;
	}

	void printList()
	{
		Node * p = head;
		cout << name << " beat: ";
		if (p == NULL)
			cout << "none";
		else
		{
			while (p != NULL)
			{
				p->printNode();
				p = p->next;
			}
		}
	}
};

class Graph
{
private:
	int v;
	List * array;
public:
	Graph()
	{
		v = 0;
		array = NULL;
	}
	Graph(int v, string names[])
	{
		this->v = v;
		array = new List[v];
		for (int i = 0; i < v; ++i)
		{
			array[i].head = NULL;
			array[i].name = names[i];
		}
	}

	void addEdge(string winner, string loser, string score)
	{
		Node * newNode = new Node;
		newNode->loser = loser;
		newNode->score = score;
		newNode->next = NULL;
		int count = 0;
		while (array[count].name != winner && count < v)
			count++;
		if (count >= v)
			cout << "cannot find source";
		else
		{
			Node * current = array[count].head;
			Node * previous = NULL;

			while (current != NULL && current->loser < newNode->loser)
			{
				previous = current;
				current = current->next;
			}
			if (previous == NULL)
			{
				newNode->next = array[count].head;
				array[count].head = newNode;
			}
			else
			{
				previous->next = newNode;
				newNode->next = current;
			}
		}
	}

	void printGraph()
	{
		if (v == 0)
			cout << "graph is empty" << endl;
		else
		{
			for (int i = 0; i < v; i++)
			{
				array[i].printList();
				cout << endl << endl;
			}
		}
	}

	void buildGraph(int v, string names[])
	{
		this->v = v;
		array = new List[v];
		for (int i = 0; i < v; ++i)
		{
			array[i].head = NULL;
			array[i].name = names[i];
		}
	}

	void deleteList()
	{
	}

};