//**************************************************************
//                   Project #1 Sum and Reverse
//                    Name: Andrew Nash
//                    Data Structures Date: 09/10/16
//***************************************************************
//I have written the entire program as turned in and have not copied this code, 
//or parts of this code from the internet or another student.Signature____________________
//***************************************************************

#include <iostream>
using namespace std;

//*******************************************************************
//                      ObjectName::Sume()
//                    Parameters: int Num the number to sum 
//                     Complexity: O(N)
//  Computes the sum of all digits of a number
//********************************************************************
int Sum(int num)
{
	if (num <= 0)return 0;
	cout << "Current Sum: " << num << endl;
	return Sum(num / 10) + num % 10;
}

//*******************************************************************
//                      ObjectName::Reverse()
//                    Parameters: Num the number to be reversed
//      			  Parameters: sum a running total to be returend
//                     Complexity: O(N)
//  Computes the reverse integer value of a number
//********************************************************************
int Reverse(int num, int sum = 0)
{
	if (num <= 0)return sum;
	sum = (sum * 10) + (num % 10);
	cout << "Current Sum: " << sum << endl;
	return Reverse(num / 10, sum);
}

int main()
{
	cout << "The sum of the digits 1243 is: " << Sum(1243) << endl;
	cout << "The reverse of 65987835 is:" << Reverse(65987835) << endl;
    return 0;
}


