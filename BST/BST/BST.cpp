//
//
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Tree.h"
#include <iomanip>
#define TREE_SIZE 128
using namespace std;

double GetFloatPrecision(double value, double precision)
{
	return (floor((value * pow(10, precision) + 0.5)) / pow(10, precision));
}

int main()
{
	vector<double> Aipl(100, 0);
	vector<double> Bipl(100, 0);
	vector<int> Values(TREE_SIZE, 0);
	srand(time(0));
	for (int z = 0; z < 100; z++)
	{
		int foo = rand() % 100000 + 1;
		Tree *TreeA = new Tree();
		Tree *TreeB = new Tree();
		TreeA->Insert(foo, NULL);
		TreeB->Insert(foo, NULL);
		Values[0] = foo;
		//fill trees with TREE_SIZE number of elements
		for (int c = 1; c < TREE_SIZE; c++)
		{
			foo = rand() % 100000 + 1;
			while (std::find(Values.begin(), Values.end(), foo) != Values.end())
			{
				foo = rand() % 100000 + 1;
			}
			Values[c] = foo;
			TreeA->Insert(foo, TreeA->Head);
			TreeB->Insert(foo, TreeB->Head);
		}

		TreeB->IsSwitch = true;
		for (int i = 0; i < 100000; i++)
		{
			if (i % 1000 == 0)
			{
				Aipl[i / 1000] = Aipl[i / 1000] + TreeA->GetIPL(TreeA->Head, 0);
				Bipl[i / 1000] = Bipl[i / 1000] + TreeB->GetIPL(TreeB->Head, 0);
			}
			//pick a random vector index to get a value from
			foo = rand() % TREE_SIZE;

			TreeA->ASyncDelete(Values[foo]);
			TreeB->SyncDelete(Values[foo]);
			//generate new value and stick it in vector
			Values[foo] = rand() % 100000 + 1;

			//insert values into trees
			TreeA->Insert(Values[foo], TreeA->Head);
			TreeB->Insert(Values[foo], TreeB->Head);
		}

		delete TreeA;
		delete TreeB;
	}

	for (int i = 0; i < 100; i++)
	{
		int ipl = Aipl[i] / 100;
		double avg = ipl / ((1.386*TREE_SIZE*(log(TREE_SIZE) / log(2))) - (2.846*TREE_SIZE));
		cout << fixed << setprecision(6) << avg << "\t";
		Aipl[i] = avg;

		ipl = Bipl[i] / 100;
		avg = ipl / ((1.386*TREE_SIZE*(log(TREE_SIZE) / log(2))) - (2.846*TREE_SIZE));
		Bipl[i] = avg;
		cout << fixed << setprecision(6) << avg << endl;
	}

    return 0;
}


