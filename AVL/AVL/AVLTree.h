#pragma once
#include "Tree.h"
class AVLTree :
	public Tree
{
public:
	AVLTree();
	~AVLTree();
	void AVL_insert(int);
	void AVL_delete(int);
	void left_rotate(Node*);
	void right_rotate(Node*);
	void rebalance(Node*);
};

