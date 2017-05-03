// BFS_DFS.cpp : Defines the entry point for the console application.
//

#include "Graph.h"
#include <iostream>


int main()
{
	auto MainGraph = new Graph;

	//auto p = &MainGraph->graph[0];
	
	//debug
	//while(p)
	//{
	//	std::cout << p->data << "\n";
	//	p = p->next;
	//}
	std::cout << "Graph::\n";
	std::cout << "   0\n 1  2  3\n4  5\n";

	std::cout << "Depth first search:: \n";
	MainGraph->DFS();
	MainGraph->PrintTree();

	std::cout << "Breadth first search::\n";
	MainGraph->BFS();
	MainGraph->PrintTree();

	system("PAUSE");
	std::cout << " ";
    return 0;
}

