#pragma once
#include "CommandToolBar.h"
#include "GameResources.h"
#include "SideMenuAnimals.h"

class AnimalMenuCommand : public CommandToolBar
{
public:
	AnimalMenuCommand(ToolBar& toolBar) : CommandToolBar(toolBar) {};
	virtual void execute() override;
};

