// Andrew Nash
// This program will create an array and fill it with random ints
// after it will sort the array and give the number of comparisons
// needed to sort the array
// NOTES:: it is best to output to a file to be able to view sorted
// array. use the print flag to output the sorted array. use size
// to set the size of array to be filled. Use runtimes to set the
// number of times the program will run.

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RandomizedQuickSort.h"
using namespace std;

int main()
{
	//this is a flag to print the sorted array
	bool print = false;
	//init a count
	int count = 0;
	//size of array to be used
	int size = 5000;
	//number of times to generate randim list and sort
	int runtimes = 10;
	//array to hold ints and be sorted
	int *A;
	A = new int[size];
	//init random
	srand(time(nullptr));
	auto quick_sort = new RandomizedQuickSort;

	//loop 10 times
	for (int i = 0; i < runtimes; i++)
	{
		count = 0;
		//fill array with 5000 random ints
		for (int j = 0; j < size; j++)
		{
			A[j] = rand();
		}

		//call sort then get the compairison count and clear for next run
		quick_sort->Sort(A, 0, size - 1);
		count = quick_sort->GetCount();
		quick_sort->ClearCount();
		cout << "the number of compairisons for run number:: " << i + 1 << " was :: "<< count << endl;

		for (int j = 0;print && j < size; j++)
		{
			cout << A[j] << endl;
		}
	}

	//deallocate memory
	delete quick_sort;
	delete[] A;
    return 0;
}

