// Project 2 Phase 1
// Name: Kyle Moffett
// ASU Email Address: krmoffet@asu.edu
// Description:

#include <iostream>	
#include <string>
#include <fstream>
#include <sstream>
#include "AdjacencyList.h"

using namespace std;

/*NOTES
make sure to construct name array in alph order
*/

int main(int argc, char *argv[])
{
	ifstream commandsFile(argv[1]), edgesFile(argv[2]);
	string command, fill, start, finish, edge, winner, wScore, loser, lScore;
	int begin, end;
	Graph g1;
	bool nameInArray(string name, string array[]);

	while (command != "quit")
	{
		getline(commandsFile, command);
		cout << "next command: " << command << endl;

		if (command == "print_graph")
		{
			g1.printGraph();
		}
		else if (command == "end_graph")
		{

		}
		else if (command == "depth_first_search")
		{

		}
		else
		{
			int numEdges;
			stringstream ss(command);
			getline(ss, fill, ',');
			getline(ss, start, ',');
			getline(ss, finish);
			begin = stoi(start);
			end = stoi(finish);
			numEdges = end - begin + 1;
			string names[100];
			string text[100];

			for (int i = 0; i < begin; i++)
			{
				getline(edgesFile, fill);
			}
			for (int i = begin; i <= end; i++)
			{
				getline(edgesFile, winner, ',');
				getline(edgesFile, wScore, ',');
				getline(edgesFile, loser, ',');
				getline(edgesFile, lScore);
				if (nameInArray(winner, names) == false)
					names[i] = winner;
				
				text[i] = loser + "(" + wScore + "-" + lScore + ")";
			}			
			g1.buildGraph(numEdges, names);
			for (int i = 0; i < numEdges; i++)
			{
				g1.addEdge(names[i], text[i]);
			}
		}
	}
	
	

	


	system("pause");
	return 0;
}

bool nameInArray(string name, string array[])
{
	for (int i = 0; i < 100; i++)
	{
		if (name == array[i])
			return true;
		else
			return false;
	}
}