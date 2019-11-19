#include "Dirt.h"
#include "Factory.h"
#include "GameResources.h"


const char symbol = '$';
const std::string Dirt::NAME = "Dirt";
bool Dirt::m_registerIt = Factory::registerTerrain(NAME, []() -> std::unique_ptr<Terrain> { return std::make_unique<Dirt>(); });
const sf::Vector2f IMAGE_SIZE{ 64, 40 };

Dirt::Dirt():Terrain(GameResources::instance().getdirtTexture(),IMAGE_SIZE)
{
	m_symbol = symbol;
}

