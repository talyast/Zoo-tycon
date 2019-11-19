#include "HerbivorFood.h"
#include "Factory.h"
#include "GameResources.h"

const char symbol = 'H';
const std::string HerbivorFood::NAME = "HerbivorFood";
bool HerbivorFood::m_registerIt = Factory::registerConstruction(NAME, []()->std::unique_ptr<ConstructionItem> { return std::make_unique<HerbivorFood>(); });
const sf::Vector2f IMAGE_SIZE{64, 40 };

HerbivorFood::HerbivorFood():ConstructionItem(GameResources::instance().getherbivorFoodTexture(),IMAGE_SIZE) 
{
	m_symbol = symbol;
}
