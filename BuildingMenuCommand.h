#pragma once
#include "CommandToolBar.h"
#include "SideMenuBuildings.h"
#include "GameResources.h"

class BuildingMenuCommand : public CommandToolBar
{
public:
	BuildingMenuCommand(ToolBar& toolBar) : CommandToolBar(toolBar) {};
	virtual void execute() override;
};

