#include "Rock.h"
#include "Factory.h"
#include "GameResources.h"
const char symbol = 'R';

const std::string Rock::NAME = "Rock";
bool Rock::m_registerIt = Factory::registerConstruction(NAME, []()->std::unique_ptr<ConstructionItem> { return std::make_unique<Rock>(); });
const sf::Vector2f IMAGE_SIZE{ 153, 110 };

Rock::Rock():ConstructionItem(GameResources::instance().getRockTexture(),IMAGE_SIZE)
{
	m_symbol = symbol;
}
