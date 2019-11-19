#pragma once
#include "Restaurant.h"
class CuttonCandy :
	public Restaurant
{
public:
	static const std::string NAME;

	CuttonCandy();
	~CuttonCandy();
	//how much CuuttonCandy cost
	std::string getPrice() { return m_price; }
	virtual sf::Texture & changeTexture(unsigned direction) override;
private:
	static bool m_registerIt;
	std::string m_price = "500";
};

