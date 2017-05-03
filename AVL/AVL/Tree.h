#pragma once
#include <iostream>

class Tree
{
public:
	Tree();
	Tree(int);
	~Tree();
	struct Node
	{
		Node* Parent;
		Node *Left;
		Node *Right;
		int Value;
		int Depth;
		int Height;
		int Size;
		Node(int value)
		{
			Parent = Left = Right = nullptr;
			Value = value;
			Depth = Height = Size = 0;
		}
	};
	Node* Find(int value) const;
	Node* Head = nullptr;
	bool IsBalanced() const;
	static bool IsLeaf(Node * ptr);
	void Insert(int value);
	void PrintTree(Node *ptr, int indent) const;

	//find the min or max of a tree
	static Node* FindMin(Node* ptr);
	static Node* FindMax(Node* ptr);

	//delete and helper
	void DeleteNode(Node* ptr);
	void DeleteTree(Node *ptr) const;
	void CearTree();

	//find successor and predecessor
	static Node* FindSuccessor(Node* ptr);
	Node* FindPredecessor(Node* ptr) const;

	//report hieght/depth/size
	int FindHeight(Node* ptr) const;
	int FindDepth(Node* ptr) const;
	int FindSize(Node* ptr) const;

	//set height size depth
	int SetSize(Node* ptr) const;
	void SetDepth(Node* ptr, int depth) const;
	void SetHeight(Node* ptr, int height) const;
	int RootHeight(Node* ptr) const;
	void SetAll() const;
};