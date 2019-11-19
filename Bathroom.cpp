#include "Bathroom.h"
#include "Factory.h"
#include "GameResources.h"
#include "Game.h"
const char symbol = 'b';
const std::string Bathroom::NAME = "Bathroom";
bool Bathroom::m_registerIt = Factory::registerBuilding(NAME, []()->std::unique_ptr<Building> { return std::make_unique<Bathroom>(); });
const sf::Vector2f IMAGE_SIZE{ 70, 70 };

Bathroom::Bathroom():Building(GameResources::instance().getRestroomFrontLeft(),IMAGE_SIZE)
{
	m_symbol = symbol;
}

sf::Texture & Bathroom::changeTexture(unsigned direction)
{
	switch (direction)
	{
	case FRONT_LEFT:
		return *GameResources::instance().getRestroomFrontLeft();
	case FRONT_RIGHT:
		return *GameResources::instance().getRestroomFrontRight();
	case BACK_LEFT:
		return *GameResources::instance().getRestroomBacktLeft();
	case BACK_RIGHT:
		return *GameResources::instance().getRestroomBackRight();
	default:
		break;
	}
}


