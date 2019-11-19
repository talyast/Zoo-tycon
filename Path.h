#pragma once
#include "Terrain.h"
#include "GameResources.h"

class Path :
	public Terrain
{
public:
	Path();
	static const std::string NAME;
	std::string getPrice() { return m_price; }
private:
	static bool m_registerIt;
	std::string m_price = "50";
};

