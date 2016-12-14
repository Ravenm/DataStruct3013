#pragma once

class BST
{
public:
	struct Node
	{
		Node *Left;
		Node *Right;
		int Value;
		~Node()
		{
			delete Left;
			delete Right;
		}
	};
	int size;
	Node* root;
	int comparisonCount;
	int leftSize;
	int rightSize;
	Node* RightDelete(Node*, int);
	void RollOver();
	Node* GetSmallest(Node*);
	Node* GetLargest(Node*);
	void _Insert(int val, Node* ptr);

	BST();
	~BST();
	void Insert(int val, Node*);
	int GetMedian();
	void ZeroComparison();
	int GetComparison() const;
	void PrintBST(Node * ptr);
	void DeleteBST(Node * ptr) const;
};

