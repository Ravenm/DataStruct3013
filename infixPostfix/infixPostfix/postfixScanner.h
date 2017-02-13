#pragma once
#include "infixScanner.h"
#include <string>

class postfixScanner : public infixScanner
{
public:
	postfixScanner();
	~postfixScanner();
	std::string GetString();
	void Scan();
};

