#pragma once
#include "StaticItem.h"
class ConstructionItem :
	public StaticItem
{
public:
	using::StaticItem::StaticItem;
	void setTexture(unsigned pos);
};

