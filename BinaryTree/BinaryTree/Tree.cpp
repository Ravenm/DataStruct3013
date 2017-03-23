#include "Tree.h"
#include <algorithm>
#include <iostream>
#include<iomanip>

Tree::Tree()
{
}

Tree::Tree(int value)
{
	Head = new Node(value);
}

Tree::~Tree()
{
}

Tree::Node* Tree::Find(int value) const
{
	if (value == Head->Value) return Head;
	Node* temp = Head;
	//if value isnt found get out or if it is found return
	while(true)
	{
		if (temp == nullptr) return nullptr;
		else if (value < temp->Value) temp = temp->Left;
		else if (value == temp->Value) return temp;
		else temp = temp->Right;
	}
}

// find if the tree is balanced 
// height should be +-1 or 0
bool Tree::IsBalanced() const
{
	//make sure the values are current
	SetAll();
	// if head is a leaf
	if (IsLeaf(Head)) return true;
	//if there is no left subtree
	else if(Head->Left == nullptr)
	{
		if(Head->Right->Size > 1) return false;
		else return true;
	}
	//if there is no right subtree
	else if (Head->Right == nullptr)
	{
		if (Head->Left->Size > 1) return false;
		else return true;
	}
	//if there are both left and right subtrees
	else
	{
		if(Head->Right->Size - Head->Left->Size > 1)return false;
		if (Head->Right->Size - Head->Left->Size < -1)return false;
		else return true;
	}
}

//check if node is a leaf
bool Tree::IsLeaf(Node* ptr)
{
	if (ptr->Left == nullptr && ptr->Right == nullptr) return true;
	else return false;
}

//insert new values or create a new tree
void Tree::Insert(int value)
{ 
	if (Head == nullptr)
	{
		Head = new Node(value);
		return;
	}
	Node* temp = Head;
	while (true)
	{
		//go right
		if (value > temp->Value)
		{
			//next right is empty
			if (temp->Right == nullptr)
			{
				temp->Right = new Node(value);
				temp->Right->Parent = temp;
				SetAll();
				return;
			}
			else temp = temp->Right;
		}
		//go left
		else if (value < temp->Value)
		{
			//next left is empty
			if (temp->Left == nullptr)
			{
				temp->Left = new Node(value);
				temp->Left->Parent = temp;
				SetAll();
				return;
			}
			else temp = temp->Left;			
		}
		//it is equal to a current value so go left
		else if (value == temp->Value)
		{
			if(temp->Left == nullptr)
			{
				temp->Left = new Node(value);
				temp->Left->Parent = temp;
			}
			else
			{
				temp->Left->Parent = new Node(value);
				temp->Left = temp->Left->Parent;
			}
			SetAll();
			return;
		}
	}
}

//ad space for each level go right then print
void Tree::PrintTree(Node* ptr, int indent) const
{
	if (ptr != nullptr) {
		if (ptr->Right) PrintTree(ptr->Right, indent + 4);
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		std::cout << ptr->Value << "\n ";
		if (ptr->Left) PrintTree(ptr->Left, indent + 4);
	}
}

//left most node
Tree::Node* Tree::FindMin(Node* ptr)
{
	while(true)
	{
		if (ptr->Left == nullptr) return ptr;
		ptr = ptr->Left;
	}
}

//right most node
Tree::Node* Tree::FindMax(Node* ptr)
{
	while (true)
	{
		if (ptr->Right == nullptr) return ptr;
		ptr = ptr->Right;
	}
}

//delete a node
void Tree::DeleteNode(Node* ptr)
{
	//does it exist
	if (ptr == nullptr) return;
	//is it a leaf
	if(IsLeaf(ptr))
	{
		if(ptr->Parent->Value > ptr->Value)
		{
			ptr->Parent->Left = nullptr;
			delete ptr;
		}
		else
		{
			ptr->Parent->Right = nullptr;
			delete ptr;
		}
	}
	//has only one child right
	else if (ptr->Left == nullptr)
	{
		if (ptr->Parent->Value > ptr->Value)
		{
			ptr->Parent->Left = ptr->Right;
			ptr->Right->Parent = ptr->Parent;
			delete ptr;
		}
		else
		{
			ptr->Parent->Right = ptr->Right;
			ptr->Right->Parent = ptr->Parent;
			delete ptr;
		}
	}
	//has only left child
	else if(ptr->Right == nullptr)
	{
		if (ptr->Parent->Value > ptr->Value)
		{
			ptr->Parent->Left = ptr->Left;
			ptr->Left->Parent = ptr->Parent;
			delete ptr;
		}
		else
		{
			ptr->Parent->Right = ptr->Left;
			ptr->Left->Parent = ptr->Parent;
			delete ptr;
		}
	}
	//has two children
	else
	{
		//find the successor
		Node* temp = FindSuccessor(ptr);
		//swap values
		ptr->Value = temp->Value;
		//kill left
		if(temp->Value < temp->Parent->Value)
		{
			temp->Parent->Left = nullptr;
		}
		//kill right
		else
		{
			temp->Parent->Right = nullptr;
		}
		delete temp;
	}
}

//go through tree deleting nodes
void Tree::DeleteTree(Node* ptr) const
{
	if (ptr == nullptr) return;
	DeleteTree(ptr->Left);
	DeleteTree(ptr->Right);
	delete ptr;
}

//safely clear the tree setting head to null
void Tree::CearTree()
{
	DeleteTree(Head);
	Head = nullptr;
}

//find successor
Tree::Node* Tree::FindSuccessor(Node* ptr)
{
	//passed null
	if (ptr == nullptr) return nullptr;
	//there is a right child find the left most 
	//for that child
	if (ptr->Right != nullptr)
		{
		return FindMin(ptr->Right);
	}
	//the right is missing so look for next best
	else {
		Node* successor = nullptr;
		Node* ancestor = ptr;
		while (ancestor != ptr) {
			if (ptr->Value < ancestor->Value)
			{
				successor = ancestor;
				ancestor = ancestor->Left;
			}
			else
				ancestor = ancestor->Right;
		}
		return successor;
	}
}

//find the predecessor
Tree::Node* Tree::FindPredecessor(Node* ptr) const
{
	Node* current = Find(ptr->Value);
	if (current == nullptr) return nullptr;
	if (current->Left != nullptr)
	{
		return FindMin(current->Left);
	}
	else {
		Node* predecessor = nullptr;
		Node* ancestor = ptr;
		while (ancestor != current) {
			if (current->Value > ancestor->Value)
			{
				predecessor = ancestor;
				ancestor = ancestor->Right;
			}
			else
				ancestor = ancestor->Left;
		}
		return predecessor;
	}
}

//traverse tree for height
int Tree::FindHeight(Node* ptr) const
{
	if (ptr == nullptr) return 0;

	return 1 + std::max(FindHeight(ptr->Left), FindHeight(ptr->Right));
}

//find the depth
int Tree::FindDepth(Node* ptr) const
{
	SetDepth(Head, 0);
	return ptr->Depth;
}

//find the size of tree
int Tree::FindSize(Node* ptr) const
{
	SetSize(ptr);
	return ptr->Size;
}

//set the size
int Tree::SetSize(Node* ptr) const
{
	if (ptr == nullptr) return 0;
	ptr->Size = 1 + SetSize(ptr->Left) + SetSize(ptr->Right);
	return ptr->Size;
}

//set the depth
void Tree::SetDepth(Node* ptr, int depth) const
{
	if(ptr == nullptr) return;
	ptr->Depth = depth;
	SetDepth(ptr->Left, 1 + depth);
	SetDepth(ptr->Right, 1 + depth);
}

//set the height
void Tree::SetHeight(Node* ptr, int height) const
{
	if (ptr == nullptr) return;
	SetHeight(ptr->Left, height-1);
	ptr->Height = height;
	SetHeight(ptr->Right, height-1);
	return;
}

//find the max hieght
int Tree::RootHeight(Node* ptr) const
{
	if (!ptr) return -1;

	return 1 + std::max(RootHeight(ptr->Left), RootHeight(ptr->Right));
}

//set all values
void Tree::SetAll() const
{
	SetDepth(Head, 0);
	SetHeight(Head, RootHeight(Head));
	SetSize(Head);
}
