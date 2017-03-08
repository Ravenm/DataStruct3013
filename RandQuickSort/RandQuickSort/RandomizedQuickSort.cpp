#include "RandomizedQuickSort.h"
#include <cstdlib>


RandomizedQuickSort::RandomizedQuickSort()
{
}


RandomizedQuickSort::~RandomizedQuickSort()
{
}

///RandomizedQuickSort takes an array and attempts to sort
/// using a randomly selected pivot point
/// PARAMS 
/// int array A array to be sorted 
/// int start the start of the pivot
/// int end the end of the pivot
/// RETURN void
void RandomizedQuickSort::Sort(int A[], int start, int end)
{

	int i = start, j = end;
	int tmp;
	//randomly select pivot
	int pivot = A[start + rand()% (end - start) + 1 ];

	// partition
	while (++count && i <= j) {

		while (++count && A[i] < pivot)
			i++;

		while (++count && A[j] > pivot)
			j--;

		if (++count && i <= j) {
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
			
			i++;
			j--;
		}
	};

	//go left or go right
	if (++count && start < j)
		RandomizedQuickSort::Sort(A, start, j);

	if (++count && i < end)
		RandomizedQuickSort::Sort(A, i, end);

}

///Returns the compare count
int RandomizedQuickSort::GetCount()
{
	return count;
}

///clears count
void RandomizedQuickSort::ClearCount()
{
	count = 0;
}
