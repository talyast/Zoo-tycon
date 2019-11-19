#pragma once
#include "ConstructionItem.h"
class Rock :
	public ConstructionItem
{
public:
	static const std::string NAME;
	Rock();
	std::string getPrice() { return m_price; }
private:
	static bool m_registerIt;
	std::string m_price = "170";
};

