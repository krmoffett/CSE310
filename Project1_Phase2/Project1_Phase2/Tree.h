#include <iostream>
#include <string>
#include <sstream>
//#include <cstring>
#include "Node.h"

using namespace std;

class RBTree {
private:
	Node * root;

public:
	RBTree();
	~RBTree();
	int keyComp(string key1, string key2);
	int inorderTreeWalk(Node * x);
	int preorderTreeWalk(Node * x);
	int postorderTreeWalk(Node * x);
	Node* treeSearch(Node * x, string k);
	Node* treeMinimum(Node * x);
	Node* treeMaximum(Node * x);
	Node* treeSuccessor(Node * x);
	Node* treePredecessor(Node * x);
	void treeInsert(Node * x);
	void bsTreeInsert(Node * z);
	int rightRotate(Node * x);
	int leftRotate(Node * x);
};

RBTree::RBTree()	// Constructor
{
	root = NULL;
}

RBTree::~RBTree()	// Destructor
{

}

int RBTree::keyComp(string key1, string key2)	// Used to compare to node keys. If comp returns < 0, key1 < key2
												// If comp returns > 0, key1 > key2
												// If comp returns = 0, keys are the same
{
	stringstream ss1(key1), ss2(key2);
	string gender1, gender2, discipline1, discipline2, event1, event2, athlete1, athlete2;
	getline(ss1, discipline1, ',');
	getline(ss1, gender1, ',');
	getline(ss1, event1, ',');
	getline(ss1, athlete1);
	getline(ss2, discipline2, ',');
	getline(ss2, gender2, ',');
	getline(ss2, event2, ',');
	getline(ss2, athlete2);

	if (discipline1.compare(discipline2) < 0)
		return -1;
	else if (discipline1.compare(discipline2) > 0)
		return 1;
	else
	{
		if (event1.compare(event2) < 0)
			return -1;
		else if (event1.compare(event2) > 0)
			return 1;
		else
		{
			if (gender1.compare(gender2) < 0)
				return -1;
			else if (gender1.compare(gender2) > 0)
				return 1;
			else
			{
				if (athlete1.compare(athlete2) < 0)
					return -1;
				else if (athlete1.compare(athlete2) > 0)
					return 1;
				else
					return 0;
			}
		}
	}
}

int RBTree::inorderTreeWalk(Node * x)
{
	if (x != NULL)
	{
		inorderTreeWalk(x->left);
		x->display();
		inorderTreeWalk(x->right);
		return 0;
	}
	else
		return 1;
}

int RBTree::preorderTreeWalk(Node * x)
{
	if (x != NULL)
	{
		x->display();
		preorderTreeWalk(x->left);
		preorderTreeWalk(x->right);
		return 0;
	}
	else
		return 1;
}

int RBTree::postorderTreeWalk(Node * x)
{
	if (x != NULL)
	{
		postorderTreeWalk(x->left);
		postorderTreeWalk(x->right);
		x->display();
		return 0;
	}
	else
		return 1;
}

Node* RBTree::treeSearch(Node * x, string k)
{
	if (x == NULL || k == x->getKey())
	{
		return x;
	}
	else
		if (keyComp(k, x->getKey()) < 0)
			return treeSearch(x->left, k);
		else
			return treeSearch(x->right, k);
}

Node* RBTree::treeMinimum(Node * x)
{
	while (x != NULL)
		x = x->left;
	return x;
}

Node* RBTree::treeMaximum(Node * x)
{
	while (x != NULL)
		x = x->right;
	return x;
}

Node* RBTree::treeSuccessor(Node * x)
{
	Node * y = new Node;
	if (x->right != NULL)
		return treeMinimum(x->right);
	else
	{
		y = x->parent;
		while (y != NULL && x == y->right)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}
}

Node* RBTree::treePredecessor(Node * x)
{
	Node * y = new Node;
	if (x->left != NULL)
		return treeMaximum(x->left);
	else
	{
		y = x->parent;
		while (y != NULL && x == y->left)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}

}

void RBTree::treeInsert(Node * x)
{
	bsTreeInsert(x);
	x->color = "RED";
	while(x != root && x->parent->color == "RED")
}

void RBTree::bsTreeInsert(Node * z)
{
	Node * y = NULL;
	Node * x = root;

	while (x != NULL)
	{
		y = x;
		if (z->getKey().compare(y->getKey()) < 0)
		{
			x = x->left;
		else
			x = x->right;
		}
	}
	z->parent = y;
	if (y == NULL)
		root = z;
	else
	{
		if (z->getKey().compare(y->getKey()) < 0)
			y->left = z;
		else
			y->right = z;
	}
}