#pragma once
#include "Building.h"



class Fence :
	public Building
{
public:
	//using::Building::Building;
	static const std::string NAME;
	Fence();
	std::string getPrice() { return m_price; }
	virtual sf::Texture & changeTexture(unsigned direction) override;
private:
	static bool m_registerIt;
	std::string m_price = "50";
};

