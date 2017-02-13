#pragma once
#include <string>
#include <stack>

class infixScanner
{
public:
	infixScanner();
	~infixScanner();
	void Scan();
	void SetString(std::string);
	std::string GetString();
	int mathIt();
protected:
	std::string outString;
	std::string inString;
};

