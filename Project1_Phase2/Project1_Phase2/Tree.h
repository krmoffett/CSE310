#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class RBTree {
private:
	Node * root;

public:
	RBTree();
	~RBTree();
	int inorderTreeWalk(Node * x);
	int preorderTreeWalk(Node * x);
	int postorderTreeWalk(Node * x);
	Node* treeSearch(Node * x, string k);
	int treeMinimum();
	int treeMaximum();
	int treeSuccessor(Node * x);
	int treePredecessor(Node * x);
	int treeInsert(Node * x);
	int bsTreeInsert(Node * x);
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
		if (k < x->getKey())
			return treeSearch(x->left, k);
		else
			return treeSearch(x->right, k);
}