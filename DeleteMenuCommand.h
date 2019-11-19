#pragma once

#include "CommandToolBar.h"
class DeleteMenuCommand : public CommandToolBar
{
public:
	DeleteMenuCommand(ToolBar& toolBar) : CommandToolBar(toolBar) {};
	virtual void execute() override;
};



