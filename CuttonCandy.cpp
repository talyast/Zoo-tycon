#include "CuttonCandy.h"
#include "Factory.h"
#include "GameResources.h"
#include "Building.h"
#include "Game.h"
const std::string CuttonCandy::NAME = "CuttonCandy";
const char symbol = 'q';
bool CuttonCandy::m_registerIt = Factory::registerBuilding(NAME, []()->std::unique_ptr<Building> { return std::make_unique<CuttonCandy>(); });
const sf::Vector2f IMAGE_SIZE{ 70, 70 };


CuttonCandy::CuttonCandy():Restaurant(GameResources::instance().getCuttonCandyLeft(),IMAGE_SIZE)
{
	m_symbol = symbol;
}


CuttonCandy::~CuttonCandy()
{
}

sf::Texture & CuttonCandy::changeTexture(unsigned direction)
{
	switch (direction)
	{
	case FRONT_LEFT:
		return *GameResources::instance().getCuttonCandyLeft();
	case FRONT_RIGHT:
		return *GameResources::instance().getCuttonCandyRight();
	case BACK_LEFT:
		return *GameResources::instance().getCuttonCandyBackLeft();
	case BACK_RIGHT:
		return *GameResources::instance().getCuttonCandyBackRight();
	}
}

