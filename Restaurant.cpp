#include "Restaurant.h"
#include "Factory.h"
#include "GameResources.h"
#include "Building.h"
const std::string Restaurant::NAME = "Restaurant";

bool Restaurant::m_registerIt = Factory::registerBuilding(NAME, []()->std::unique_ptr<Building> { return std::make_unique<Restaurant>(); });
const sf::Vector2f IMAGE_SIZE{ 70, 70 };

Restaurant::Restaurant(sf::Texture * texture, sf::Vector2f size):Building(texture,size)
{
}

Restaurant::Restaurant()
{
}




