// infixPostfix.cpp : Defines the entry point for the console application.
//

#include <stack>
#include "infixScanner.h"
#include "postfixScanner.h"
#include <iostream>

int main()
{
	infixScanner inscan;
	char selection;
	bool loop = true;

	//throw out a sample
	std::string ripit = "(1 + 4 - 3) * 10";
	std::cout << "as a sample we will transform " + ripit << std::endl;
	inscan.SetString(ripit);
	std::cout << "as postfix " + inscan.GetString() << std::endl << "the solution " +
		std::to_string(inscan.mathIt()) << std::endl;
	postfixScanner postscan;
	postscan.SetString(inscan.GetString());
	std::cout << "infix once more " + postscan.GetString() << std::endl;

	//menu
	while (loop)
	{
		std::cout << "Which would you like to input: 1) postfix or 2) infix or q Quit" << std::endl;
		std::cin >> selection;
		std::getline(std::cin, ripit);
		switch (selection)
		{
		case '1':
			std::cout << "type your input and press enter" << std::endl;
			std::getline(std::cin, ripit);
			postscan.SetString(ripit);
			std::cout << "solution " + std::to_string(postscan.mathIt()) << std::endl;
			std::cout << "infix order " + postscan.GetString() << std::endl;
			break;
		case '2':
			std::cout << "type your input and press enter" << std::endl;
			std::getline(std::cin, ripit);
			inscan.SetString(ripit);
			std::cout << "solution " + std::to_string(inscan.mathIt()) << std::endl;
			std::cout << "postfix order " + inscan.GetString() << std::endl;
			break;
		case 'q':
		case 'Q':
			loop = false;
			break;
		default:
			std::cout << "you seem to have entered something incorrect" << std::endl;
			break;
		}
	}
    return 0;
}

