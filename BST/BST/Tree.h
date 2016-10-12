#pragma once
#include <iostream>

class Tree
{
public:
	Tree();
	~Tree();
	struct Node
	{
		Node *Left;
		Node *Right;
		int Value;
	};
	Node* Find(int value);
	Node* Head = NULL;
	bool IsSwitch;
	int GetIPL(Node * r, int depth);
	Node* LeftDelete(Node *ptr,int value);
	bool IsLeaf(Node * ptr);
	Node* RightDelete(Node *ptr, int value);
	void SyncDelete(int value);
	Node* Insert(int value, Node* ptr);
	void PrintTree(Node *ptr);
	Node* FindMin(Node* ptr);
	Node* FindMax(Node* ptr);
	void DeleteTree(Node *ptr);
	void ASyncDelete(int value);
};

