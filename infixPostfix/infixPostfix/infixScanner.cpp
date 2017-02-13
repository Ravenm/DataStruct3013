#include "infixScanner.h"


infixScanner::infixScanner()
{
}


infixScanner::~infixScanner()
{
}

//<summary>Scan a string for numbers and operators
//to create a postfix string</summary>
//<param name=none></param>
//<returns></returns>
void infixScanner::Scan()
{
	std::stack<std::string> operators;
	std::stack<int> prestStack;
	int prest;
	int topPrest;
	char buff;
	std::string temp;

	for (int i = 0; i < inString.length(); i++)
	{
		buff = inString[i];
		switch (buff)
		{
		case '-':
		case '+':
			prest = 2;
			while(!operators.empty() && prestStack.top() >= prest)
			{
				outString += operators.top();
				operators.pop();
				prestStack.pop();
				outString += " ";
			}
			prestStack.push(prest);
			operators.push(std::string(1, buff));
			i++;
			break;
		case '*':
		case '/':
		case '%':
			prest = 3;
			while (!operators.empty() && prestStack.top() >= prest)
			{
				outString += operators.top();
				operators.pop();
				prestStack.pop();
				outString += " ";
			}
			prestStack.push(prest);
			operators.push(std::string(1, buff));
			i++;
			break;
		case '(':
			//lowest prest just push to stack
			operators.push(std::string(1, buff));
			prest = 1;
			prestStack.push(prest);
			break;
		case ')':
			//scan until you find the (
			if(operators.top() == "(")
			{
				prestStack.pop();
				operators.pop();
			}
			else
			{
				while(operators.top() != "(")
				{
					outString += operators.top();
					operators.pop();
					prestStack.pop();
					outString += " ";
				}
				operators.pop();
				prestStack.pop();
			}
			break;
		case ' ':
			break;
		default: //is it a number

			while(buff == '1' || buff == '2' || buff == '3' || buff == '4' || buff == '5' || buff == '6' || 
				buff == '7' || buff == '8' || buff == '9' || buff == '0')
			{
				outString += std::string(1,buff);
				buff = inString[++i];
			}
			i--;
			outString += " ";
			break;
		}
	}

	while(!operators.empty())
	{
		outString += operators.top();
		outString += " ";
		operators.pop();
		prestStack.pop();
	}

}

//<summary>set the input string</summary>
//<param name=></param>
//<returns></returns>
void infixScanner::SetString(std::string in)
{
	inString = in;
	outString = "";
}

//<summary>return the output string</summary>
//<param name=></param>
//<returns>outstring</returns>
std::string infixScanner::GetString()
{
	outString = "";
	infixScanner::Scan();
	return outString;
}

//<summary>solve the problem</summary>
//<param name=none></param>
//<returns></returns>
int infixScanner::mathIt()
{
	outString = "";
	Scan();
	std::stack<char> nums;
	int operand = 0;
	char element;
	for (int i = 0; i < outString.length(); i++)
	{
		element = outString[i];
		switch (element)
		{
		case '-':
			operand = nums.top();
			nums.pop();
			nums.top() -= operand;
			break;
		case '+':
			operand = nums.top();
			nums.pop();
			nums.top() += operand;
			break;
		case '*':
			operand = nums.top();
			nums.pop();
			nums.top() *= operand;
			break;
		case '/':
			operand = nums.top();
			nums.pop();
			nums.top() /= operand;
			break;
		case '%':
			operand = nums.top();
			nums.pop();
			nums.top() %= operand;
			break;
		case ' ':
			break;
		default: //is it a number
			nums.push(element - '0');
			element = outString[++i];
			while(element != ' ')
			{
				nums.push(element - '0');
				element = outString[++i];
			}
			break;
		}
	}
	return nums.top();
}
