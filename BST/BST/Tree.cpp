#include "Tree.h"
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;


Tree::Tree()
{
}

Tree::~Tree()
{
	DeleteTree(Head);
}

struct Node
{
	Node *Left = NULL;
	Node *Right = NULL;
	int Value = 0;
};



Tree::Node* Tree::Find(int value)
{
	Node *ptr = Head;

	while (ptr->Value != value)
	{
		if (value > ptr->Value)
			ptr = ptr->Right;
		else
			ptr = ptr->Left;
	}

	return ptr;
}

int Tree::GetIPL(Node *r, int depth = 0)
{
	if (r == NULL)return 0;

	return depth + GetIPL(r->Left, depth + 1) + GetIPL(r->Right, depth + 1);

}

Tree::Node* Tree::FindMin(Node* ptr) {
	while (ptr->Left != NULL) ptr = ptr->Left;
	return ptr;
}

Tree::Node* Tree::FindMax(Node* ptr) {
	while (ptr->Right != NULL) ptr = ptr->Right;
	return ptr;
}

Tree::Node* Tree::LeftDelete(Node *ptr, int Value) {
	if (ptr == NULL) return ptr;
	else if (Value < ptr->Value) ptr->Left = LeftDelete(ptr->Left, Value);
	else if (Value > ptr->Value) ptr->Right = LeftDelete(ptr->Right, Value);
	else {
		// Case 1: No Child
		if (ptr->Left == NULL && ptr->Right == NULL) {
			delete ptr;
			ptr = NULL;
			// Case 2: one child
		}
		else if (ptr->Right == NULL) {
			struct Node *temp = ptr;
			ptr = ptr->Left;
			delete temp;
		}
		else {
			struct Node *temp = FindMin(ptr->Right);
			ptr->Value = temp->Value;
			ptr->Right = LeftDelete(ptr->Right, temp->Value);
		}
	}
	return ptr;
}

Tree::Node* Tree::RightDelete(Node *ptr, int Value) {
	if (ptr == NULL) return ptr;
	else if (Value < ptr->Value) ptr->Left = RightDelete(ptr->Left, Value);
	else if (Value > ptr->Value) ptr->Right = RightDelete(ptr->Right, Value);
	else {
		// Case 1: No Child
		if (ptr->Left == NULL && ptr->Right == NULL) {
			delete ptr;
			ptr = NULL;
			// Case 2: one child
		}
		else if (ptr->Left == NULL) {
			struct Node *temp = ptr;
			ptr = ptr->Right;
			delete temp;
		}
		else {
			struct Node *temp = FindMax(ptr->Left);
			ptr->Value = temp->Value;
			ptr->Left = RightDelete(ptr->Left, temp->Value);
		}
	}
	return ptr;
}

bool Tree::IsLeaf(Node *ptr)
{
	if (ptr->Left == NULL)
		return true;
	else
		return false;
}

void Tree::ASyncDelete(int value)
{
	Head = LeftDelete(Head, value);
	return;
}

void Tree::SyncDelete(int value)
{
	if (IsSwitch == true) 
	{ 
		Head = RightDelete(Head, value); 
		IsSwitch = false;
		return;
	}
	Head = LeftDelete(Head, value);
	IsSwitch = true;
	return;
}


Tree::Node *Tree::Insert(int value, Node *ptr = NULL)
{
	if (Head == NULL) {
		Head = new Node;
		Head->Value = value;
		Head->Left = NULL;
		Head->Right = NULL;
	}
	else if (ptr == NULL)
	{
		ptr = new Node;
		ptr->Value = value;
		ptr->Left = NULL;
		ptr->Right = NULL;
	}
	else if (value < ptr->Value) {
		ptr->Left = Insert(value, ptr->Left);
	}
	else
		ptr->Right = Insert(value, ptr->Right);

	return ptr;
}

void Tree::PrintTree(Node *ptr)
{
	if (ptr == NULL || ptr == 0)
	{
		return;
	}
	PrintTree(ptr->Left);
	cout << ptr->Value << endl;
	PrintTree(ptr->Right);
}

void Tree::DeleteTree(Node *ptr)
{
	if (ptr == NULL || ptr == 0)
	{
		return;
	}
	DeleteTree(ptr->Left);
	DeleteTree(ptr->Right);
	delete ptr;
}
