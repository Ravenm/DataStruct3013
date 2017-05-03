#pragma once
#include <vector>

class Graph
{
private:
	struct Node
	{
		int data, color, d, f;
		Node *next;
		Node *pi;
		int adj[];

		Node::Node() : data(0), color(0), d(0), f(0), next(nullptr), pi(nullptr)
		{
		}


		Node::Node(int _data, int _color, Node *_next, int _d, Node *_pi, int _f)
		{
			data = _data;
			color = _color;
			next = _next;
			adj[3];
			d = _d;
			pi = _pi;
			f = _f;
		}
	};

public:
	Graph();
	~Graph();
	int tree[7];
	int counter;
	Node *graph[6];
	void BFS();
	void DFS();
	void DfsVisit(int u);
	int time;
	void PrintTree();
};

