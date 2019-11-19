#include "DrinkingStand.h"
#include "Factory.h"
#include "GameResources.h"
#include "game.h"

const char symbol = 'd';
const std::string DrinkingStand::NAME = "DrinkingStand";

bool DrinkingStand::m_registerIt = Factory::registerBuilding(NAME, []()->std::unique_ptr<Building> { return std::make_unique<DrinkingStand>(); });
const sf::Vector2f IMAGE_SIZE{ 35, 35 };

DrinkingStand::DrinkingStand():Building(GameResources::instance().getDrinkFrontLeft(), IMAGE_SIZE)
{
	m_symbol = symbol;
}

sf::Texture & DrinkingStand::changeTexture(unsigned direction)
{
	switch (direction)
	{
	case FRONT_LEFT:
		return *GameResources::instance().getDrinkFrontLeft();
	case FRONT_RIGHT:
		return *GameResources::instance().getDrinkFrontRight();
	case BACK_LEFT:
		return *GameResources::instance().getDrinkBacktLeft();
	case BACK_RIGHT:
		return *GameResources::instance().getDrinkBackRight();
	default:
		break;
	}
}
