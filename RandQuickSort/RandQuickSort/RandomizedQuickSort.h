#pragma once
class RandomizedQuickSort
{
public:
	RandomizedQuickSort();
	~RandomizedQuickSort();
	void Sort(int [], int start, int end);
	int GetCount();
	void ClearCount();
	int count = 0;
};

