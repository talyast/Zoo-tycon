#pragma once
#include "StaticItem.h"
class Building :
	public StaticItem
{
public:
	static const std::string NAME;
	using::StaticItem::StaticItem;
	Building();
	virtual void setTexture(unsigned);
	virtual const sf::FloatRect& getGlobalBounds() const override { return StaticItem::getGlobalBounds(); };

protected:
	double m_income=0;
};

