#pragma once
class CirLinkList
{
	struct Node {
		int val;
		int size;
		Node * next;
		Node * back;
		//Here is a constructor that works with a struct as we discussed.
		Node(int v, Node * b, Node * n) { val = v; next = n; back = b; } // Node constructor!
	};
	Node* start;//Node we start at. This can change
	int nodect;// store node ct as well
public:
	CirLinkList();// Does nothing at this moment.
	void Build(int ct);// Creates a circular linked list of ct nodes numbered 1 to ct
	~CirLinkList();// destroys the entire linked list
	void Dump();// Displays the data in the linked list both forward and backward
	int Kill();//returns number of nodes left after destroying the node start points at and   relinking
	void Advance(int k);// Moves the start point ahead k steps
	int GetStart();// Returns the value of the node that start points at
};

