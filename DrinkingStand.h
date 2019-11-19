#pragma once
#include "Building.h"
class DrinkingStand :
	public Building
{
public:
	static const std::string NAME;
	DrinkingStand();
	std::string getPrice() { return m_price; }
	virtual sf::Texture & changeTexture(unsigned direction) override;
private:
	static bool m_registerIt;
	std::string m_price = "2500";
};

