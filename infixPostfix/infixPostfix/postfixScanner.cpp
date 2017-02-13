#include "postfixScanner.h"



postfixScanner::postfixScanner()
{
}


postfixScanner::~postfixScanner()
{
}

//<summary>update output and return it</summary>
//<param name=none></param>
//<returns>outstring</returns>
std::string postfixScanner::GetString()
{
	outString = "";
	Scan();
	return outString;
}

//<summary>Scan a string for numbers and operators
//to create a infix string</summary>
//<param name=none></param>
//<returns></returns>
void postfixScanner::Scan()
{
	outString = "";
	std::stack<std::string> outStack;
	char buff;
	std::string temp;
	for (int i = 0; i < inString.length(); i++)
	{
		buff = inString[i];
		if(buff == '1' || buff == '2' || buff == '3' || buff == '4' || buff == '5' || buff == '6' ||
			buff == '7' || buff == '8' || buff == '9' || buff == '0')
		{
			temp = "";
			temp.append(std::string(1,buff));
			buff = inString[++i];
			while(buff != ' ')
			{
				temp.append(std::string(1, buff));
				buff = inString[++i];
			}
			temp += " ";
			outStack.push(std::string(temp));
		}
		else if (buff == ' ')
		{
			continue;
		}
		else
		{
			temp = outStack.top();
			outStack.pop();
			outStack.top() += std::string(1, buff);
			outStack.top() += " ";
			outStack.top() += temp;
		}
	}
	outString = outStack.top();
}

