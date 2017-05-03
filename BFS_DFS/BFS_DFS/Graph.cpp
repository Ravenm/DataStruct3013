#include "Graph.h"
#include <limits>
#include <iostream>
#include <queue>


Graph::Graph()
{
	counter = 0;
	time = 0;
	for (int i = 0; i < 6; i++)
	{
		tree[i] = 0;
		graph[i] = new Node;
		graph[i]->data = i;
	}
	//node A = 0
	graph[0]->adj[0] = 1;
	graph[0]->adj[1] = 2;
	graph[0]->adj[2] = 3;
	//node b =1
	graph[1]->adj[0] = 4;
	graph[1]->adj[1] = 5;
	graph[1]->adj[2] = 0;
	//node c = 2
	graph[2]->adj[0] = 0;
	graph[2]->adj[1] = 5;
	graph[2]->adj[2] = -1;
	//node d = 3
	graph[3]->adj[0] = 0;
	graph[3]->adj[1] = -1;
	graph[3]->adj[2] = -1;
	//node e = 4
	graph[4]->adj[0] = 1;
	graph[4]->adj[1] = -1;
	graph[4]->adj[2] = -1;
	//node f = 5
	graph[5]->adj[0] = 1;
	graph[5]->adj[1] = 2;
	graph[5]->adj[2] = -1;

}


Graph::~Graph()
{
	for (int i = 0; i < 6; i++)
	{
		delete graph[i];
	}
	delete graph;
}

void Graph::BFS()
{
	counter = 0;
	int u;
	for (int i = 0; i < 6; i++)
	{
		graph[i]->color = 0;
		graph[i]->pi = nullptr;
		graph[i]->d = INFINITY;
	}
	graph[0]->color = 1;
	graph[0]->d = 0;
	graph[0]->pi = nullptr;
	std::queue<int> q;
	q.push(graph[0]->data);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			//-1 means no adj node
			//if the color of the adj node is white
			if (graph[u]->adj[i] != -1 && graph[graph[u]->adj[i]]->color == 0)
			{
				graph[graph[u]->adj[i]]->color = 1;
				graph[graph[u]->adj[i]]->d = graph[u]->d + 1;
				graph[graph[u]->adj[i]]->pi = graph[u];
				q.push(graph[u]->adj[i]);
			}
		}
		graph[u]->color = 2;
		tree[counter++] = u;
	}
}

void Graph::DFS()
{
	time = 0;
	counter = 0;
	for (int i = 0; i < 6; i++)
	{
		graph[i]->color = 0;
		graph[i]->pi = nullptr;
	}
	for (int i = 0; i < 6; i++)
	{
		if(graph[i]->color == 0)
		{
			DfsVisit(i);
		}
	}
}

void Graph::DfsVisit( int u)
{
	time = time + 1;
	graph[u]->d = time;
	graph[u]->color = 1;

	tree[counter++] = graph[u]->data;

	for (int i = 0; i < 3; i++)
	{
		//-1 means no adj node
		//if the color of the adj node is white
		if(graph[u]->adj[i] != -1 && graph[graph[u]->adj[i]]->color == 0)
		{
			graph[graph[u]->adj[i]]->pi = graph[u];
			DfsVisit(graph[u]->adj[i]);
		}
	}
	graph[u]->color = 2;
	time = time + 1;
	graph[u]->f = time;

}

void Graph::PrintTree()
{
	for (int i = 0; i < 6; i++)
	{
		std::cout << tree[i] << " ";
	}
	std::cout << "\n";
}
