#include "ChickerNugets.h"
#include "Factory.h"
#include"GameResources.h"
#include "Building.h"
#include "Game.h"

const std::string ChickerNugets::NAME = "ChickerNugets";
const char symbol = 'k';
bool ChickerNugets::m_registerIt = Factory::registerBuilding(NAME, []()->std::unique_ptr<Building> { return std::make_unique<ChickerNugets>(); });
const sf::Vector2f IMAGE_SIZE{ 70, 70 };


ChickerNugets::ChickerNugets():Restaurant(GameResources::instance().getChickenBackLeft(),IMAGE_SIZE)
{
	m_symbol = symbol;
}


ChickerNugets::~ChickerNugets()
{
}

sf::Texture & ChickerNugets::changeTexture(unsigned direction)
{
	switch (direction)
	{
	case FRONT_LEFT:
		return *GameResources::instance().getChickenFrontLeft();
	case FRONT_RIGHT:
		return *GameResources::instance().getChickenFrontRight();
	case BACK_LEFT:
		return *GameResources::instance().getChickenBackLeft();
	case BACK_RIGHT:
		return *GameResources::instance().getChickenBackRight();
	}
}
