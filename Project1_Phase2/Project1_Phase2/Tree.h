#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class RBTree {
private:
	Node * root = NULL;

public:
	RBTree();
	~RBTree();
	int inorderTreeWalk(RBTree T);
	int perorderTreeWalk(RBTree T);
	int postorderTreeWalk(RBTree T);
	int treeSearch(RBTree T, Node x);
	int treeMinimum(RBTree T);
	int treeMaximum(RBTree T);
	int treeSuccessor(RBTree T, Node x);
	int treePredecessor(RBTree T, Node x);
	int treeInsert(Node x);
	int bsTreeInsert(Node x);
	int rightRotate(Node x);
	int leftRotate(Node x);
};