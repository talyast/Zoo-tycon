#include "Burger.h"
#include "GameResources.h"
#include "Factory.h"
#include "Building.h"
#include "Game.h"
const std::string Burger::NAME = "Burger";
const char symbol = 'm';
bool Burger::m_registerIt = Factory::registerBuilding(NAME, []()->std::unique_ptr<Building> { return std::make_unique<Burger>(); });
const sf::Vector2f IMAGE_SIZE{ 70, 70 };



Burger::Burger():Restaurant(GameResources::instance().getBurgerFrontLeft(),IMAGE_SIZE)
{
	m_symbol = symbol;
}

Burger::~Burger()
{
}

sf::Texture & Burger::changeTexture(unsigned direction)
{
	switch (direction)
	{
	case FRONT_LEFT:
		return *GameResources::instance().getBurgerFrontLeft();
	case FRONT_RIGHT:
		return *GameResources::instance().getBurgerFrontRight();
	case BACK_LEFT:
		return *GameResources::instance().getBurgerBacktLeft();
	case BACK_RIGHT:
		return *GameResources::instance().getBurgerBackRight();
	}
}

