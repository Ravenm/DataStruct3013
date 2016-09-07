//**************************************************************
//                   Project #1 Josephus
//                    Name: Andrew Nash
//                    Data Structures Date: 09/05/16
//***************************************************************
//      This program solves the Josephus problem by creating a link 
//		to represent the soldiers and traversing the list to remove
//		links.
//*****************************************************************

#include "CirLinkList.h"
#include <iostream>
using namespace std;

int main()
{
	int nodesleft;
	CirLinkList C;
	C.Build(12);
	C.Dump();
	C.Advance(7);
	while (C.Kill() != 1)
		C.Advance(3);
	C.Dump();
	cout << "Remaining node is " << C.GetStart() << endl;
	return 0;
}