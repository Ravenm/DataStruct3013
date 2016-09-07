#include "CirLinkList.h"
#include <iostream>
using namespace std;


CirLinkList::CirLinkList()
{
}

//Build creates a linked list with length ct
//Params int ct
void CirLinkList::Build(int ct)
{
	if (ct < 0)
	{
		throw new exception("negative or null value");
	}
	start = new Node(1, 0, 0);
	Node *nptr = start;
	for (int i = 2; i <= ct; i++)
	{
		nptr->next = new Node(i, nptr, 0);
		nptr = nptr->next;
	}
	nptr->next = start;
	start->back = nptr;

	nodect = ct;
}


CirLinkList::~CirLinkList()
{
}

//Dump shows a count and a structure of the linked list.
//Params none
void CirLinkList::Dump()
{
	Node *nptr;
	nptr = start;

	cout << "Number of Nodes created is: " << nodect << endl;

	cout << "listed forwards: " << endl;
	cout << nptr->val << " -> ";
	nptr = nptr->next;
	while (nptr != start) 
	{
		cout << nptr->val << " -> ";
		nptr = nptr->next;
	}
	cout << "Head" << endl;

	cout << "listed backwords: " << endl;
	cout << nptr->val << " -> ";
	nptr = nptr->back;
	while (nptr != start)
	{
		cout << nptr->val << " -> ";
		nptr = nptr->back;
	}
	cout << "Head" << endl;
}

//deletes the node start currently points to and returns number of nodes left
//Params None
//Return int
int CirLinkList::Kill()
{
	if (start->next == start) //check if this will kill last node
	{
		//delete start;
		//nodect = 0;
		return 1;
	}
	Node *nptr;
	nptr = start->back; //set nptr to be the node behind start

	nptr->next = start->next; //set nptr-> next to be node ahead of start
	nptr->next->back = nptr; //set node ahead of start ->back to nptr and delete
	delete start;
	start = nptr;

	nodect = nodect - 1; //set count and return
	return nodect;

}

//Moves start k nodes forward
//Params int K
void CirLinkList::Advance(int k)
{
	for (int i = 0; i < k; i++)
	{
		start = start->next;
	}
}

int CirLinkList::GetStart()
{
	return start->val;
}
