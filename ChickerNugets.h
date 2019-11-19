#pragma once
#include "Restaurant.h"
class ChickerNugets :
	public Restaurant
{
public:
	static const std::string NAME;

	ChickerNugets();
	~ChickerNugets();

	sf::Texture & changeTexture(unsigned direction) override ;
private:
	static bool m_registerIt;
	std::string m_price = "600";
};

