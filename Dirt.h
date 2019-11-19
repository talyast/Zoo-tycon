#pragma once
#include "Terrain.h"

class Dirt :
	public Terrain
{
public:
	static const std::string NAME;
	Dirt();
	std::string getPrice() { return m_price; }
private:
	static bool m_registerIt;
	std::string m_price = "50";
};

