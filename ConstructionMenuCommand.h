#pragma once
#include "CommandToolBar.h"

class ConstructionMenuCommand: public CommandToolBar
{
public:
	ConstructionMenuCommand(ToolBar& toolBar) : CommandToolBar(toolBar) {};
	virtual void execute() override;
};
