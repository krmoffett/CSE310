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
	string color;
	List * parent;
	int d, f;
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
		array = new List[v];
		for (int i = 0; i < v; i++)
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

	void DFS()
	{
		List * u = array;
		for (int i = 0; i < v; i++)		// Initialize all nodes to white and NULL parent
		{
			u[i].color = "white";
			u[i].parent = NULL;
		}

		time = 0;
		for (int i = 0; i < v; i++)		// Perform visit on undiscovered edges
		{
			if (u[i].color == "white")
				DFSVISIT(&u[i]);
		}

	}

	void DFSVISIT(List * u)
	{
		u->color = "gray";
		time++;
		u->d = time;
		Node * vee = u->head;
		int count = 0;
		do
		{
			List node = u[count];
			while (node.name != vee->loser && count < v)
			{
				count++;
				node = u[count];
			}
			if (node.color == "white")
			{
				node.parent = u;
				DFSVISIT(&node);
			}
		} while (vee->next != NULL);
		u->color = "black";
		time++;
		u->f = time;
	}

	void deleteList()
	{
	}

};