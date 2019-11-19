#pragma once
#include "DynamicItem.h"

class Sound;

class Animal :
	public DynamicItem
{
public:

	using DynamicItem::DynamicItem;
	
protected:
	int m_happiness = 100;
};

