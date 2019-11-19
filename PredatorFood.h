#pragma once
#include "ConstructionItem.h"

class PredatorFood :
	public ConstructionItem
{
public:
	static const std::string NAME;
	PredatorFood();
	std::string getPrice() { return m_price; }
private:
	static bool m_registerIt;
	std::string m_price = "150";
};

