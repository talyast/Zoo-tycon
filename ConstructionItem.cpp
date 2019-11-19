#include "ConstructionItem.h"



void ConstructionItem::setTexture(unsigned pos)
{
	
	StaticItem::setTexture(&changeTexture(pos));
}

