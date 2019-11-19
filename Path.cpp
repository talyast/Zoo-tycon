#include "Path.h"
#include "Factory.h"

const char symbol = '!';
const std::string Path::NAME = "Path";
bool Path::m_registerIt = Factory::registerTerrain(NAME, []() -> std::unique_ptr<Terrain> { return std::make_unique<Path>(); });
const sf::Vector2f IMAGE_SIZE{ 64, 40 };

Path::Path():Terrain(GameResources::instance().getPathTexture(),IMAGE_SIZE)
{
	m_symbol = symbol;
}
