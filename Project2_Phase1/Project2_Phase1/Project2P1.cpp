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
	/*		TESTING
	string name[5];
	name[0] = "ASU"; name[1] = "UofA"; name[2] = "FSU"; name[3] = "USC";
	Graph g1(4,name);
	g1.addEdge("ASU", "UofA(41-0)");
	g1.addEdge("ASU", "FSU(522-8)");
	g1.addEdge("FSU", "UofA(53-3)");
	g1.printGraph();*/

	ifstream commands(argv[1]), edges(argv[2]);
	string command, fill, start, finish, edge;
	int begin, end;

	while (command != "quit")
	{
		getline(commands, command);
		cout << "next command: " << command << endl;

		if (command == "print_graph")
		{
		}
		else
		{
			stringstream ss(command);
			getline(ss, fill, ',');
			getline(ss, start, ',');
			getline(ss, finish);
			begin = stoi(start);
			end = stoi(finish);

			
		}
	}

	


	system("pause");
	return 0;
}