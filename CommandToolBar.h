#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

class ToolBar;

class CommandToolBar
{
public:
	CommandToolBar(ToolBar& toolBar) :m_toolBar(toolBar) {};
	virtual void execute() = 0;
protected:
	ToolBar& m_toolBar;
};

