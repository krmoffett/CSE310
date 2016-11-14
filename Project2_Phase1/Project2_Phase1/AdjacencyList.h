// Project 2 Phase 1
// Name: Kyle Moffett
// ASU Email Address: krmoffet@asu.edu
// Description:

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
	Graph()
	{
		v = 0;
		array = NULL;
	}
	Graph(int v, string names[])
	{
		this->v = v;
		array = new Node[v];
		for (int i = 0; i < v; i++)
		{
			array[i].head = NULL;
			array[i].name = names[i];
		}
	}

	void addEdge(string winner, string loser, string score)
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

	void buildGraph(int v, string names[])
	{
		this->v = v;
		array = new Node[v];
		for (int i = 0; i < v; ++i)
		{
			array[i].head = NULL;
			array[i].name = names[i];
		}
	}

	void DFS()
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

	}

	void DFSVISIT(Node * u)
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

		cout << "check";

		u->color = "black";
		time++;
		u->f = time;
	}

	void deleteNode()
	{
	}


};