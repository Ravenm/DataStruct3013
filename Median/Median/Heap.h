#pragma once
#include <vector>

class Heap
{
public:
	Heap();
	Heap(bool);
	~Heap();
	bool isMinHeap;
	std::vector<int> heap;
	int hSize;
	int comparisonCount;

	void Minimize(int);
	void Maximize(int);
	void HeapIt(int);
	int GetRoot();
	void InsertElement(int k);
	int GetComparison() const;
	void ZeroComparison();

	static int parent(int i) { return (i - 1) / 2; }
	static int leftChild(int i) { return (2 * i + 1); }
	static int rightChild(int i) { return (2 * i + 2); }
};

