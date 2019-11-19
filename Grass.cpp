#include "Grass.h"
#include "Factory.h"
#include "GameResources.h"

const char symbol = '#';
const std::string Grass::NAME = "Grass";
bool Grass::m_registerIt = Factory::registerGrass("Grass", []() -> std::unique_ptr<Grass> { return std::make_unique<Grass>(); });
const sf::Vector2f IMAGE_SIZE{ 64, 40 };

Grass::Grass():StaticItem(GameResources::instance().getGrassTexture(),IMAGE_SIZE)//CHANGE TO GRASS TEXTURE
{
	m_symbol = symbol;
}
