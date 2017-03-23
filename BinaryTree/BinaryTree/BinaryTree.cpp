// BinaryTree.cpp : Defines the entry point for the console application.
// Andrew Nash


#include <iostream>
#include <sstream>
#include "Tree.h"

int main()
{
	std::string in = "";
	bool quit = false;
	bool q = false;
	std::string select = "";
	Tree* tree = new Tree;
	Tree::Node* ptr;

	//menu
	while (!quit)
	{
		quit = false;
		select = "";
		std::cout << "1) Create a new tree" << std::endl;
		std::cout << "2) Add values to tree" << std::endl;
		std::cout << "3) Delete a value" << std::endl;
		std::cout << "4) print the tree" << std::endl;
		std::cout << "5) check if the tree is balanced" << std::endl;
		std::cout << "6) find the height of a value or root" << std::endl;
		std::cout << "7) find the depth of a value or root" << std::endl;
		std::cout << "8) find the size of a sub tree or root" << std::endl;
		std::cout << "9) delete tree and quit" << std::endl;

		std::getline(std::cin, select);

		//what was picked
		switch (atoi(select.c_str()))
		{
		case 1:
			tree->CearTree();
		case 2:
			q = false;
			while (!q)
			{
				std::cout << "enter an int or type q to return to menu" << std::endl;
				std::getline(std::cin, in);
				if (in == "q")
				{
					q = true;
				}
				else
				{
					tree->Insert(atoi(in.c_str()));
				}
			}
			break;
		case 3:
			q = false;
			while (!q)
			{
				std::cout << "enter an int or type q to return to menu" << std::endl;
				std::getline(std::cin, in);
				if (in == "q")
				{
					q = true;
				}
				else
				{
					ptr = tree->Find(atoi(in.c_str()));
					tree->DeleteNode(ptr);
				}
			}
			break;
		case 4:
			tree->PrintTree(tree->Head, 0);
			break;
		case 5:
			if (tree->IsBalanced())
			{
				std::cout << "the tree is balnced!" << std::endl;
			}
			else
			{
				std::cout << "the tree is not balnced!" << std::endl;
			}
			break;
		case 6:
			std::cout << "enter an int or type r for root" << std::endl;
			std::getline(std::cin, in);
			if (in == "r")
			{
				std::cout << "height is:" << tree->FindHeight(tree->Head) << std::endl;
			}
			else
			{
				ptr = tree->Find(atoi(in.c_str()));
				std::cout << "height is:" << tree->FindHeight(ptr) << std::endl;
			}
			break;
		case 7:
			std::cout << "enter an int or type r for root" << std::endl;
			std::getline(std::cin, in);
			if (in == "r")
			{
				std::cout << "depth is:" << tree->FindDepth(tree->Head) << std::endl;
			}
			else
			{
				ptr = tree->Find(atoi(in.c_str()));
				std::cout << "deepth is:" << tree->FindDepth(ptr) << std::endl;
			}
			break;
		case 8:
			std::cout << "enter an int or type r for root" << std::endl;
			std::getline(std::cin, in);
			if (in == "r")
			{
				std::cout << "Size is:" << tree->FindSize(tree->Head) << std::endl;
			}
			else
			{
				ptr = tree->Find(atoi(in.c_str()));
				std::cout << "size is:" << tree->FindSize(ptr) << std::endl;
			}
			break;
		case 9:
			quit = true;
			break;
		default:
			std::cout << "I didnt understand your selection" << std::endl;
			break;
		}
	}
	delete tree;
	return 0;
}