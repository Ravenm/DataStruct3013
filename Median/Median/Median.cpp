//**************************************************************
//                   Project Median Values
//                    Name: Andrew Nash
//                    Data Structures Date: 11/22/2016
//***************************************************************
//      This is a median value comparison using a binary tree
//	and a heap data stucture. It will compare the number of 
//	comparisons used by both to store a large number of ints
//	and to find the median value.
//	output should be directed to a txt file will display as
//	comma seprated values
//*****************************************************************


#include "BST.h"
#include "Heap.h"
#include <iostream>
#include "MedianHeap.h"

int main()
{
	srand(2);
	std::vector<int> binarySize;
	std::vector<int> heapSize;
	for (int S = 1000; S <= 15000; S = S + 1000)
	{
		int temp = rand();
		BST *binaryTree = new BST();
		MedianHeap* heap = new MedianHeap();
		binaryTree->Insert(temp, nullptr);
		int i = 1;
		for (i = 1; i <= S; i++)
		{
			int temp = rand();
			binaryTree->Insert(temp, binaryTree->root);
			heap->Insert(temp);
		}

		i = i + 1;
		binaryTree->ZeroComparison();
		heap->ZeroComparison();

		for (int i = 0; i < 1000; i++)
		{
			binaryTree->GetMedian();
			heap->GetMedian();
			temp = rand();
			binaryTree->Insert(temp, binaryTree->root);
			heap->Insert(temp);
		}

		binarySize.push_back(binaryTree->GetComparison());
		heapSize.push_back(heap->GetComparison());

		delete heap;
		delete binaryTree;
	}

	for (int i = 0; i < binarySize.size();i++)
	{
		std::cout << binarySize[i] << "," << heapSize[i] << std::endl;
	}

    return 0;
}

