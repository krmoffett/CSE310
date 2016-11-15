// Project 2 Phase 1
// Name: Kyle Moffett
// ASU Email Address: krmoffet@asu.edu
// Description: Defines the Graph class with structs for nodes and edges

#include <iostream>
#include <string>

using namespace std;

struct Edge {
	string loser;
	string score;
	Edge * next;
	void printEdge()
	{
		cout << loser << score;
		if (next != NULL)
			cout << ", ";
	}
	void printName()
	{
		cout << loser << endl;
	}

};

struct Node {
	string name;
	string color;
	Node * parent;
	int d, f;
	Edge * head;
	Node()
	{
		head = NULL;
	}

	void printNode()
	{
		Edge * p = head;
		cout << name << " beat: ";
		if (p == NULL)
			cout << "none";
		else
		{
			while (p != NULL)
			{
				p->printEdge();
				p = p->next;
			}
		}
	}
};

class Graph
{
private:
	int v;
	Node * array;
	int time;
public:
	Graph()		// Constructor
	{
		v = 0;
		array = NULL;
	}
	Graph(int v, string names[])	// Overloaded Constructor
	{
		this->v = v;
		array = new Node[v];
		for (int i = 0; i < v; i++)
		{
			array[i].head = NULL;
			array[i].name = names[i];
		}
	}
	~Graph()	// Destructor
	{
		v = 0;
		delete[] array;
		time = 0;
	}

	void addEdge(string winner, string loser, string score) // Add edge pointing away from winner towards loser
	{
		Edge * newEdge = new Edge;
		newEdge->loser = loser;
		newEdge->score = score;
		newEdge->next = NULL;
		int count = 0;
		while (array[count].name != winner && count < v)
			count++;
		if (count >= v)
			cout << "cannot find source";
		else
		{
			Edge * current = array[count].head;
			Edge * previous = NULL;

			while (current != NULL && current->loser < newEdge->loser)
			{
				previous = current;
				current = current->next;
			}
			if (previous == NULL)
			{
				newEdge->next = array[count].head;
				array[count].head = newEdge;
			}
			else
			{
				previous->next = newEdge;
				newEdge->next = current;
			}
		}
	}

	void printGraph()
	{
		cout << "\nGraph (Adjacency Node) contents\n" << endl;
		if (v == 0)
			cout << "graph is empty" << endl;
		else
		{
			for (int i = 0; i < v; i++)
			{
				array[i].printNode();
				cout << endl << endl;
			}
		}
	}

	void buildGraph(int v, string names[]) // Adds nodes to graph structure
	{
		this->v = v;
		array = new Node[v];
		for (int i = 0; i < v; ++i)
		{
			array[i].head = NULL;
			array[i].name = names[i];
		}
	}

	void DFS() // Depth First Search
	{
		Node * u = array;
		for (int i = 0; i < v; i++)		// Initialize all Edges to white and NULL parent
		{
			u[i].color = "white";
			u[i].parent = NULL;
		}

		time = 0;

		for (int i = 0; i < v; i++)		// Perform visit on undiscovered edges
		{
			if (u[i].color == "white")
			{
				DFSVISIT(&u[i]);
			}
		}
		printPi();
		printD();
		printF();
	}

	void DFSVISIT(Node * u)		// Helper function for DFS
	{
		u->color = "gray";
		time++;
		u->d = time;
		Edge * edge = u->head;

		if (edge != NULL)
		{
			do
			{
				int count = 0;
				Node * vee = &array[0];
				while (vee->name != edge->loser)
				{
					count++;
					vee = &array[count];
				}
				if (vee->color == "white")
				{
					vee->parent = u;
					DFSVISIT(vee);
				}
				edge = edge->next;
			} while (edge != NULL);
		}

		u->color = "black";
		time++;
		u->f = time;
	}

	void printPi()	// Prints the array of pi values for each node
	{
		cout << "\nThe array pi contents:\n" << endl;
		for (int i = 0; i < v; i++)
		{
			cout << "pi[" << array[i].name << "] = ";
			if (array[i].parent == NULL)
				cout << "none" << endl;
			else
				cout << array[i].parent->name << endl;
		}
	}

	void printD()	// Prints the discover time for each node
	{
		cout << "\nThe array discoverTime contents:\n" << endl;
		for (int i = 0; i < v; i++)
		{
			cout << "discoverTime[" << array[i].name << "] = number " << array[i].d << endl;
		}
	}

	void printF()	// Prints the finish time for each node
	{
		cout << "\nThe array finishTime contents:\n" << endl;
		for (int i = 0; i < v; i++)
		{
			cout << "finishTime[" << array[i].name << "] = number " << array[i].f << endl;
		}
	}
};