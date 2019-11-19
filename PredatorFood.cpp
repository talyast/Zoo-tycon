#include "PredatorFood.h"
#include "Factory.h"
#include "GameResources.h"
const char symbol = 'P';
const std::string PredatorFood::NAME = "PredatorFood";
bool PredatorFood::m_registerIt = Factory::registerConstruction(NAME, []()->std::unique_ptr<ConstructionItem> { return std::make_unique<PredatorFood>(); });
const sf::Vector2f IMAGE_SIZE{ 64, 40 };

PredatorFood::PredatorFood():ConstructionItem(GameResources::instance().getpreditorFoodTexture(),IMAGE_SIZE)//CHANGE TO PREDITOR TEXTURE
{
	m_symbol = symbol;
}
