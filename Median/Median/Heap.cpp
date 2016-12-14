#include "Heap.h"
#include<iostream>
#include<climits>
#include<vector>
using namespace std;


Heap::Heap(): isMinHeap(false), hSize(0), comparisonCount(0)
{
}

Heap::Heap(bool isMin)
{
	comparisonCount = 0;
	hSize = 0;
	isMinHeap = isMin;
}


Heap::~Heap()
{
}

//*******************************************************************
//                      ObjectName::InsertElement()
//                    Parameters: int element
//	puts an element into the heap
//********************************************************************
void Heap::InsertElement(int element)
{
	hSize++;
	int i = hSize - 1;
	heap.push_back(element);

	while(comparisonCount++ && i != 0 && heap[parent(i) > heap[i]])
	{
		swap(heap[i], heap[parent(i)]);
		i = parent(i);
	}
}

int Heap::GetComparison() const
{
	return comparisonCount;
}

void Heap::ZeroComparison()
{
	comparisonCount = 0;
}

//*******************************************************************
//                      ObjectName::GetRoot()
//      gets the top value from heap
//********************************************************************
int Heap::GetRoot()
{
	if(comparisonCount++ && heap.size() == 0)
	{
		return INT16_MAX;
	}

	int root = heap[0];
	heap[0] = heap[hSize - 1];
	hSize--;
	HeapIt(0);
	heap.pop_back();

	return root;
}

//*******************************************************************
//                      ObjectName::MethodName()
//		calles either min or max to create max or min heap
//********************************************************************
void Heap::HeapIt(int i)
{
	if (comparisonCount++ && isMinHeap)
	{
		Minimize(i);
	}
	else
		Maximize(i);
}

//*******************************************************************
//                      ObjectName::Minimize()
//      creates a min heap
//********************************************************************
void Heap::Minimize(int i)
{
	int left = leftChild(i);
	int right = rightChild(i);
	int index = i;
	if(comparisonCount++ && left < hSize && heap[left] < heap[i])
	{
		index = left;
	}
	if(comparisonCount++ && right < hSize && heap[right] < heap[i])
	{
		index = right;
	}
	if(comparisonCount++ && index != i )
	{
		swap(heap[i], heap[index]);
		Minimize(index);
	}
}

//*******************************************************************
//                      ObjectName::Maximize()
//     creates a max heap
//********************************************************************
void Heap::Maximize(int i)
{
	int left = leftChild(i);
	int right = rightChild(i);
	int index = i;
	if (comparisonCount++ && left < hSize && heap[left] > heap[i])
	{
		index = left;
	}
	if (comparisonCount++ && right < hSize && heap[right] > heap[i])
	{
		index = right;
	}
	if (comparisonCount++ && index != i)
	{
		swap(heap[i], heap[index]);
		Maximize(index);
	}
}


void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}