#pragma once
#include "Building.h"


class Restaurant :
	public Building
{
public:

	Restaurant();
	static const std::string NAME;
	Restaurant(sf::Texture * texture, sf::Vector2f size);
	virtual std::string getPrice() { return m_price; }
private:

	static bool m_registerIt;
	std::string m_price = "3500";
};

