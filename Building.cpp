#include "Building.h"

Building::Building()
{
}

void Building::setTexture(unsigned pos)
{
	StaticItem::setTexture(&changeTexture(pos));
}

