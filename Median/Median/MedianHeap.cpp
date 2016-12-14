#include "MedianHeap.h"

MedianHeap::MedianHeap(): comparisonCount(0)
{
	left = new Heap(true);
	right = new Heap(false);
	root = NULL;
}


MedianHeap::~MedianHeap()
{
}

//*******************************************************************
//                      ObjectName::Insert()
//     insert into either left or right heap
//********************************************************************
void MedianHeap::Insert(int i)
{
	if(comparisonCount++ && root == NULL)
	{
		root = i;
	}

	if(comparisonCount++ && i >= root)
	{
		right.InsertElement(i);
	}
	else
	{
		left.InsertElement(i);
	}
	RollOver();
}

//*******************************************************************
//                      ObjectName::MethodName()
//     Get the median value and rollover
//********************************************************************
int MedianHeap::GetMedian()
{
	int median = root;
	root = NULL;
	RollOver();
	return median;
}

//*******************************************************************
//                      ObjectName::Rollover()
//      Roll the heap over to replace median
//********************************************************************
void MedianHeap::RollOver()
{
	int temp = root;
	if(comparisonCount++ && temp == NULL)
	{
		root = right.GetRoot();
		temp = root;
	}
	if(comparisonCount++ && left.hSize > right.hSize)
	{
		root = left.GetRoot();
		right.InsertElement(temp);
	}
	if(comparisonCount++ && right.hSize - left.hSize > 1)
	{
		temp = root;
		root = right.GetRoot();
		left.InsertElement(temp);
	}
}

void MedianHeap::ZeroComparison()
{
	comparisonCount = 0;
	left.ZeroComparison();
	right.ZeroComparison();
}

int MedianHeap::GetComparison()
{
	return left.GetComparison() + right.GetComparison() + comparisonCount;
}
