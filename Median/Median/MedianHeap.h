#pragma once
#include "Heap.h"

class MedianHeap
{
public:
	MedianHeap();
	~MedianHeap();
	int root;
	Heap left;
	Heap right;
	int comparisonCount;

	void Insert(int);
	int GetMedian();
	void RollOver();
	void ZeroComparison();
	int GetComparison();
};

