#pragma once
#include "MapItem.h"
#include <string>

class CommandMenu
{
public:
	CommandMenu(std::string itemName) :m_itemName(itemName) {}
	std::string execute() const { return m_itemName; }
private:
	std::string m_itemName;
};

