#include "Fence.h"
#include "Factory.h"
#include "GameResources.h"
#include "Game.h"

const char symbol = 'F';
const std::string Fence::NAME = "Fence";
bool Fence::m_registerIt = Factory::registerBuilding(NAME, []()->std::unique_ptr<Building> { return std::make_unique<Fence>(); });
const sf::Vector2f IMAGE_SIZE{ 50, 50 };

Fence::Fence() :Building(GameResources::instance().getFenceFrontLeftButtonTexture(), IMAGE_SIZE)
{
	m_symbol = symbol;
}

sf::Texture & Fence::changeTexture(unsigned direction)
{
	switch (direction)
	{
	case FRONT_LEFT:
		return *GameResources::instance().getFenceFrontLeftButtonTexture();
	case FRONT_RIGHT:
		return *GameResources::instance().getFenceFrontRightButtonTexture();
	case BACK_LEFT:
		return *GameResources::instance().getFenceLeftButtonTexture();
	case BACK_RIGHT:
		return *GameResources::instance().getFenceRightButtonTexture();

	}
}
