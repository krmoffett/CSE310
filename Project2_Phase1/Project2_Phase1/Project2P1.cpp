// Project 2 Phase 1
// Name: Kyle Moffett
// ASU Email Address: krmoffet@asu.edu
// Description:

#include <iostream>	
#include <string>
#include "AdjacencyList.h"

using namespace std;

/*NOTES
make sure to construct name array in alph order
*/

int main()
{
	string name[5];
	name[0] = "ASU"; name[1] = "UofA"; name[2] = "FSU"; name[3] = "USC";
	Graph g1(4,name);
	g1.addEdge("ASU", "UofA(41-0)");
	g1.addEdge("ASU", "FSU(522-8)");
	g1.addEdge("FSU", "UofA(53-3)");
	g1.printGraph();

	system("pause");
	return 0;
}