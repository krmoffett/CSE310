// Project 2 Phase 1
// Name: Kyle Moffett
// ASU Email Address: krmoffet@asu.edu
// Description: Driver file for Adjacency List. Takes arguments for 2 file names.

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
		cout << "\nnext command: " << command << endl;

		if (command == "print_graph")	// PRINT COMAND
		{
			g1.printGraph();
		}
		else if (command == "end_graph")	// FREE MEMORY
		{
			g1.~Graph();
		}
		else if (command == "depth_first_search")	// DFS COMMAND
		{
			g1.DFS();
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
				string * nodeNames = new string[10000];
				string nameStage1, nameStage2;

				//	EXTRACT NODE NAMES
				edgesFile.clear();
				edgesFile.seekg(0, ios::beg);
				for (int i = 0; i < begin; i++)
				{
					getline(edgesFile, fill);
				}

				int index = 0;
				for (int i = begin; i <= end; i++)
				{
					if (edgesFile.eof() == false)
					{
						getline(edgesFile, nameStage1, ',');
						getline(edgesFile, fill, ',');
						getline(edgesFile, nameStage2, ',');
						if (nameInArray(nameStage1, nodeNames, index) == false)
						{
							nodeNames[index] = nameStage1;
							index++;
						}
						if (nameInArray(nameStage2, nodeNames, index) == false)
						{
							nodeNames[index] = nameStage2;
							index++;
						}

						getline(edgesFile, fill);
					}
				}
				string * EdgesToInsert = new string[index];
				
				for (int i = 0; i < index; i++)
				{
					EdgesToInsert[i] = nodeNames[i];
				}
				
				sortArray(EdgesToInsert, index);
				g1.buildGraph(index, EdgesToInsert);

				// EXTRACT EDGES
				edgesFile.clear();
				edgesFile.seekg(0, ios::beg);
				for (int i = 0; i < begin; i++)
				{
					getline(edgesFile, fill);
				}
				for (int i = begin; i <= end; i++)
				{
					if (edgesFile.eof() == false)
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
	}
	system("pause");
	return 0;
}

bool nameInArray(string name, string array[], int size) // Check if a name is already within a given array
{
	for (int i = 0; i < size; i++)
	{
		if (name == array[i])
			return true;
	}
	return false;
}

void sortArray(string names[], int size) // Sort array alphabetically
{

	bool check;

	do
	{
		check = 0;
		for (int count = 0; count < (size - 1); count++)
		{
			if (names[count] > names[count + 1])
			{
				names[count].swap(names[count + 1]);
				check = 1;

			}

		}

	} while (check == 1);
}