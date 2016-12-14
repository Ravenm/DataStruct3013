#include "BST.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
using namespace std;


//*******************************************************************
//                      ObjectName::RightDelete()
//                    Parameters: ptr a Node and value an int
//		left over from previous bst project deletes using a rotation				
//********************************************************************
BST::Node* BST::RightDelete(Node *ptr, int Value)
{
	if (comparisonCount++ && !ptr) return ptr;
	else if (comparisonCount++ && Value < ptr->Value) ptr->Left = 
		RightDelete(ptr->Left, Value);
	else if (comparisonCount++ && Value > ptr->Value) ptr->Right = 
		RightDelete(ptr->Right, Value);
	else {
			// Case 1: No Child
		if (comparisonCount++ && !ptr->Left && !ptr->Right) {
			delete ptr;
			ptr = nullptr;
			// Case 2: one child
		}
		else if (comparisonCount++ && !ptr->Left) {
			struct Node *temp = ptr;
			ptr = ptr->Right;
		}
		else {
			struct Node *temp = GetSmallest(ptr->Left);
			ptr->Value = temp->Value;
			ptr->Left = RightDelete(ptr->Left, temp->Value);
		}
	}
	return ptr;
}

//*******************************************************************
//                      ObjectName::Rollover()
//                    Parameters: none
//     This is used to balance out the sub tree number of nodes
//	to get the median value as root
//********************************************************************
void BST::RollOver()
{
	int sizediff = leftSize - rightSize;
	if (comparisonCount++ && sizediff == 0 || sizediff == -1)
	{
		return;
	}
	int temp, insert;
	Node *ptr = nullptr;
	if(comparisonCount++ && sizediff < -1)
	{
		temp = root->Value;
		insert = GetSmallest(root->Right)->Value;
		ptr = RightDelete(root,insert);
		rightSize--;
		root->Value = insert;
		_Insert(temp, root);

	}
	if(comparisonCount++ && sizediff > 0)
	{
		temp = root->Value;
		insert = GetLargest(root->Left)->Value;
		ptr = RightDelete(root, insert);
		leftSize--;
		root->Value = insert;
		_Insert(temp, root);
	}
	
}

//*******************************************************************
//                      ObjectName::GetSmalles()
//                    Parameters: ptr a node pointer
//     finds the smallest value. just recurses left
//********************************************************************
BST::Node *BST::GetSmallest(Node* ptr)
{
	while (comparisonCount++ && ptr->Left) ptr = ptr->Left;
	return ptr;
}


BST::Node* BST::GetLargest(Node* ptr)
{
	while (comparisonCount++ && ptr->Right) ptr = ptr->Right;
	return ptr;
}

//*******************************************************************
//                      ObjectName::_Insert()
//      private method to insert values into tree. attempting to
//	balance as it does.
//********************************************************************
void BST::_Insert(int value, Node* ptr)
{
	if (comparisonCount++ &&  !root) {
		root = new Node;
		root->Value = value;
		root->Left = nullptr;
		root->Right = nullptr;
		return;
	}
	Node *back = nullptr;
	while(comparisonCount++ && ptr)
	{
		back = ptr;
		if(comparisonCount++ && value < ptr->Value)
		{
			ptr = ptr->Left;
		}
		else
		{
			ptr = ptr->Right;
		}
	}
	if(comparisonCount++ && value < back->Value)
	{
		back->Left = new Node;
		back->Left->Value = value;
		back->Left->Left = nullptr;
		back->Left->Right = nullptr;
	}
	else
	{
		back->Right = new Node;
		back->Right->Value = value;
		back->Right->Left = nullptr;
		back->Right->Right = nullptr;
	}
	return;
}

BST::BST(): size(0), root(nullptr), comparisonCount(0),
	leftSize(0), rightSize(0)
{
}

BST::~BST()
{
	DeleteBST(root);
}

//*******************************************************************
//                      ObjectName::Insert()
//     insert a node check if root is null and then pick a subtree
//********************************************************************
void BST::Insert(int value, Node * ptr)
{
	if (comparisonCount++ &&  root != nullptr)
	{
		value >= root->Value ? rightSize++ : leftSize++;
		comparisonCount++;
	}
		
	_Insert(value, ptr);
	RollOver();
}

//*******************************************************************
//                      ObjectName::GetMedian()
//		Gets the root value and deletes it
//********************************************************************
int BST::GetMedian()
{
	int temp = root->Value;
	RightDelete(root, root->Value);
	return temp;
}

void BST::ZeroComparison()
{
	comparisonCount = 0;
}

int BST::GetComparison() const
{
	return comparisonCount;
}

//*******************************************************************
//                      ObjectName::PrintBST()
//  debug method
//********************************************************************
void BST::PrintBST(Node *ptr)
{
	if (comparisonCount++ &&  ptr == nullptr)
	{
		return;
	}
	PrintBST(ptr->Left);
	cout << ptr->Value << endl;
	PrintBST(ptr->Right);
}

//*******************************************************************
//                      ObjectName::DeleteBST()
//       deletes the bst called by destrutor
//********************************************************************
void BST::DeleteBST(Node *ptr) const
{
	delete ptr->Left;
	delete ptr->Right;
}
