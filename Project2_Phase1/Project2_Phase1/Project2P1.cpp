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

int main(int argc, char *argv[])
{
	ifstream commandsFile(argv[1]), edgesFile(argv[2]);
	string command, fill, start, finish, edge, winner, wScore, loser, lScore;
	int begin, end;
	Graph g1;
	bool nameInArray(string name, string array[], int size);
	void sortArray(string names[], int size);

	while (command != "quit")
	{
		getline(commandsFile, command);
		cout << "next command: " << command << endl;

		if (command == "print_graph")	// PRINT COMAND
		{
			g1.printGraph();
		}
		else if (command == "end_graph")	// FREE MEMORY
		{

		}
		else if (command == "depth_first_search")	// DFS COMMAND
		{

		}
		else		// GRAPH COMMAND
		{
			int numEdges;
			stringstream ss(command);
			getline(ss, fill, ',');
			if (fill == "graph")
			{
				getline(ss, start, ',');
				getline(ss, finish);
				begin = stoi(start);
				end = stoi(finish);
				numEdges = end - begin + 1;
				string * nodes = new string[numEdges];
				string nameStage;
				string text[100];

				//	EXTRACT NODE NAMES
				for (int i = 0; i < begin; i++)
				{
					getline(edgesFile, fill);
				}

				int index = 0;
				for (int i = begin; i <= end; i++)
				{

					getline(edgesFile, nameStage, ',');
					if (nameInArray(nameStage, nodes, numEdges) == false)
					{
						nodes[index] = nameStage;
						index++;
					}
					/*else
						end--;*/

					getline(edgesFile, fill);
				}
				string * nodesToInsert = new string[index];
				
				for (int i = 0; i < index; i++)
				{
					nodesToInsert[i] = nodes[i];
				}
				
				sortArray(nodesToInsert, index);
				g1.buildGraph(index, nodesToInsert);
				// EXTRACT EDGES
				edgesFile.clear();
				edgesFile.seekg(0, ios::beg);
				for (int i = 0; i < numEdges; i++)
				{
					getline(edgesFile, winner, ',');
					getline(edgesFile, wScore, ',');
					getline(edgesFile, loser, ',');
					getline(edgesFile, lScore);

					string scoreStr = "(" + wScore + "-" + lScore + ")";
					g1.addEdge(winner, loser, scoreStr);
				}
			}
		}
	}
	
	

	


	system("pause");
	return 0;
}

bool nameInArray(string name, string array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (name == array[i])
			return true;
	}
	return false;
}

void sortArray(string names[], int size)
{

	bool flag;

	do
	{
		flag = 0;
		for (int count = 0; count < (size - 1); count++)
		{
			if (names[count] > names[count + 1])
			{
				names[count].swap(names[count + 1]);
				flag = 1;

			}

		}

	} while (flag == 1);
}