#pragma once
#include "StaticItem.h"

class Grass :
	public StaticItem
{
public:
	static const std::string NAME;
	Grass();
	std::string getPrice() { return m_price; }

private:
	static bool m_registerIt;
	std::string m_price = "10";
};

