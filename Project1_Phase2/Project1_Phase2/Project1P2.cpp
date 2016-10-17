#include <iostream>
#include <string>
#include <sstream>
#include "Tree.h"

using namespace std;

int main()
{
	RBTree tree1;
	string input, command, key, discipline, gender, team_or_ind, event, venue, medal, athlete, country;
	Node * x = new Node;

	while (input != "quit")
	{
		cout << "\nPlease enter a command:\n";
		getline(cin, input);

		if (input == "tree_inorder")
			tree1.inorderTreeWalk(tree1.getRoot());

		else if (input == "tree_preorder")
			tree1.preorderTreeWalk(tree1.getRoot());

		else if (input == "tree_postorder")
			tree1.postorderTreeWalk(tree1.getRoot());

		else if (input == "tree_maximum")
			tree1.treeMaximum(tree1.getRoot());

		else if (input == "tree_minimum")
			tree1.treeMinimum(tree1.getRoot());

		else
		{
			stringstream ss(input);
			getline(ss, command, ',');
			if (command == "tree_insert")
			{
				getline(ss, discipline, ',');
				getline(ss, gender, ',');
				getline(ss, team_or_ind, ',');
				getline(ss, event, ',');
				getline(ss, venue, ',');
				getline(ss, medal, ',');
				getline(ss, athlete, ',');
				getline(ss, country);

				x->discipline = discipline;
				x->gender = gender;
				x->team_or_ind = team_or_ind;
				x->event = event;
				x->venue = venue;
				x->medal = medal;
				x->athlete = athlete;
				x->country = country;
				x->left = NULL;
				x->right = NULL;
				x->parent = NULL;

				tree1.treeInsert(x);
			}
			else if (command == "tree_search")
			{
				getline(ss, key);
				stringstream ks(key);
				x = tree1.treeSearch(tree1.getRoot(), key);
				if (x != NULL)
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
		}

	}
	return 0;
}