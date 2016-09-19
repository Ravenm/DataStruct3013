#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
using namespace std;
int main()
{
	vector<int> inA;
	vector<int> inB;
	vector<int>::iterator it;
	int v;
	int q;
	while (cin >> q)
	{
		for (int i = 0; i<q; ++i)
		{
			cin >> v;
			inA.push_back(v);
			inB.push_back(0);
		}
		inB[0] = 1;
		for (int i = 0; i<q - 1; ++i)
		{
			v = abs(inA[i + 1] - inA[i]);
			if (v>0 && v<q)
				inB[v] = 1;
		}
		it = find(inB.begin(), inB.end(), 0);
		if (it == inB.end())
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
		inA.clear();
		inB.clear();
	}
	return 0;
}