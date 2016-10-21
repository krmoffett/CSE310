#include <iostream>
#include <string>
#include <sstream>
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
	void rightRotate(Node * x);
	void leftRotate(Node * x);

	Node * getRoot() { return root; }
};

RBTree::RBTree()	// Constructor
{
	root = NULL;
}

RBTree::~RBTree()	// Destructor
{

}

int RBTree::keyComp(string key1, string key2)	// Used to compare two node keys. If comp returns < 0, key1 < key2
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
	Node * y = NULL;
	bsTreeInsert(x);
	x->color = "RED";
	while (x != root && x->parent->color == "RED")
	{
		if (x->parent = x->parent->parent->left)
		{
			y = x->parent->parent->right;
			if (y->color == "RED")
			{
				x->parent->color = "BLACK";
				y->color = "BLACK";
				x->parent->parent->color = "RED";
				x = x->parent->parent;
			}
			else
			{
				if (x = x->parent->right)
				{
					x = x->parent;
					leftRotate(x);
				}
				x->parent->color = "BLACK";
				x->parent->parent->color = "RED";
				rightRotate(x->parent->parent);
			}
		}
	    else
		{
			y = x->parent->parent->left;
			if (y->color == "RED")
			{
				x->parent->color = "BLACK";
				y->color = "BLACK";
				x->parent->parent->color = "RED";
				x = x->parent->parent;
			}
			else
			{
				if (x = x->parent->left)
				{
					x = x->parent;
					rightRotate(x);
				}
				x->parent->color = "BLACK";
				x->parent->parent->color = "RED";
				leftRotate(x->parent->parent);
			}
		}
		
	}
	root->color = "BLACK";
}

void RBTree::bsTreeInsert(Node * z)
{
	Node * y = NULL;
	Node * x = root;

	while (x != NULL)
	{
		y = x;
		if (keyComp(z->getKey(), y->getKey()) < 0)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NULL)
		root = z;
	else
	{
		if (keyComp(z->getKey(), y->getKey()) < 0)
			y->left = z;
		else
			y->right = z;
	}
}

void RBTree::leftRotate(Node * x)
{
	Node * y = x->right;
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
	{
		root = y;
	}
	else
	{
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void RBTree::rightRotate(Node * x)
{
	Node * y = x->left;
	x->left = y->right;
	if (y->right != NULL)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
	{
		root = y;
	}
	else
	{
		if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
}