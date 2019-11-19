#pragma once
#include "Restaurant.h"
class Burger :
	public Restaurant
{
public:
	static const std::string NAME;

	Burger();
	~Burger();
	//price of the stand
	std::string getPrice() { return m_price; }
	virtual sf::Texture & changeTexture(unsigned direction) override;
private:

	
	static bool m_registerIt;
	std::string m_price = "950";
	
};

