#pragma once
#include "ConstructionItem.h"
class HerbivorFood :
	public ConstructionItem
{
public:
	static const std::string NAME;
	HerbivorFood();
	std::string getPrice() { return m_price; }
private:
	static bool m_registerIt;
	std::string m_price = "130";
};

