// Project 1 Phase 2
// Name: Kyle Moffett
// ASU Email Address: krmoffet@asu.edu
// Description: Executes commands from a user to insert, search, and print from a red black tree

#include <iostream>
#include <string>
#include <sstream>
#include "Tree.h"

using namespace std;

int main()
{
	RBTree tree1;
	string input, command, key, discipline, gender, team_or_ind, event, venue, medal, athlete, country;
	
	while (input != "quit")
	{
		// ****************
		// BEGIN INPUT READ
		// ****************
		cout << "Please enter a command:\n";
		getline(cin, input);

		if (input == "tree_inorder")	// INORDER COMMAND
			if (tree1.getRoot() == NULL)
				cout << "\ntree is empty\n";
			else
				tree1.inorderTreeWalk(tree1.getRoot());

		else if (input == "tree_preorder")	// PREORDER COMMAND
			if (tree1.getRoot() == NULL)
				cout << "\ntree is empty\n";
			else
				tree1.preorderTreeWalk(tree1.getRoot());

		else if (input == "tree_postorder")	// POSTORDER COMMAND
			if (tree1.getRoot() == NULL)
				cout << "\ntree is empty\n";
			else
				tree1.postorderTreeWalk(tree1.getRoot());

		else if (input == "tree_maximum")	// FIND TREE MAXIMUM
		{
			Node * y = new Node;
			if (tree1.getRoot() == NULL)
				cout << "\ntree is empty\n";
			else
			{
				y = tree1.treeMaximum(tree1.getRoot());
				cout << "\nThe last athlete is:\n";
				y->display();
			}
		}
		else if (input == "tree_minimum")	// FIND TREE MINIMUM
		{
			Node * y = new Node;
			if (tree1.getRoot() == NULL)
				cout << "\ntree is empty\n";
			else
			{
				y = tree1.treeMinimum(tree1.getRoot());
				cout << "\nThe first athlete is:\n";
				y->display();
			}
		}

		else
		{
			stringstream ss(input);
			getline(ss, command, ',');
			if (command == "tree_insert")	// INSERT COMMAND
			{
				getline(ss, discipline, ',');
				getline(ss, gender, ',');
				getline(ss, team_or_ind, ',');
				getline(ss, event, ',');
				getline(ss, venue, ',');
				getline(ss, medal, ',');
				getline(ss, athlete, ',');
				getline(ss, country);

				Node * y = new Node;
				Node * x = new Node;

				y->discipline = discipline;
				y->gender = gender;
				y->team_or_ind = team_or_ind;
				y->event = event;
				y->venue = venue;
				y->medal = medal;
				y->athlete = athlete;
				y->country = country;
				y->left = NULL;
				y->right = NULL;
				y->parent = NULL;
				
				x = tree1.treeSearch(tree1.getRoot(), y->getKey());
				if (x == NULL) // medal data is not already in the tree
				{
					tree1.treeInsert(y);
					cout << "\nThe medal recipient " << y->athlete << " for " << y->discipline << " with event " << y->event << " inserted\n";
				}
				else	// medal data already in tree
					cout << "\nThe medal recipient " << y->athlete << " for " << y->discipline << " with event " << y->event << " NOT inserted\n";
			}
			else if (command == "tree_search")	// SEARCH FOR MEDAL INFO
			{
				getline(ss, key);
				stringstream ks(key);
				Node * x = new Node;
				x = tree1.treeSearch(tree1.getRoot(), key);
				if (tree1.getRoot() == NULL)
					cout << "\ntree is empty\n";
				else if (x != NULL)
					cout << "\nThe medal recipient " << x->athlete << " has the medal of " << x->medal << endl;
				else
				{
					getline(ks, discipline, ',');
					getline(ks, gender, ',');
					getline(ks, event, ',');
					getline(ks, athlete);
					cout << endl << athlete << " for " << discipline << " with event " << event << " not found\n";
				}
			}
			else if (command == "tree_predecessor")		// FIND PREDECESSOR
			{
				getline(ss, key);
				stringstream ks(key);
				if (tree1.getRoot() == NULL)		// tree is empty
					cout << "tree is empty";
				else		// tree is not empty
				{
					Node * y = tree1.treeSearch(tree1.getRoot(), key);
					if (y != NULL)
					{
						Node * x = tree1.treePredecessor(y);
						cout << "\nThe predecessor of the medal recipient " << x->athlete << " for " << x->discipline << " with event " << x->event << " is ";
						x->display();
					}
					else
					{
						getline(ks, discipline, ',');
						getline(ks, gender, ',');
						getline(ks, event, ',');
						getline(ks, athlete);
						cout << endl << athlete << " for " << discipline << " with event " << event << " not found\n";
					}
				}
			}
			else if (command == "tree_successor")	// FIND SUCCESSOR
			{
				getline(ss, key);
				stringstream ks(key);
				if (tree1.getRoot() == NULL)		// tree is empty
					cout << "tree is empty";
				else		// tree is not empty
				{
					Node * y = tree1.treeSearch(tree1.getRoot(), key);
					if (y != NULL)
					{
						Node * x = tree1.treeSuccessor(y);
						cout << "\nThe successor of the medal recipient " << x->athlete << " for " << x->discipline << " with event " << x->event << " is ";
						x->display();
					}
					else
					{
						getline(ks, discipline, ',');
						getline(ks, gender, ',');
						getline(ks, event, ',');
						getline(ks, athlete);
						cout << endl << athlete << " for " << discipline << " with event " << event << " not found\n";
					}
				}
			}
		}

	}
	return 0;
}