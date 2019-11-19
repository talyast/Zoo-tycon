#include "BuildingMenuCommand.h"
#include "ToolBar.h"



void BuildingMenuCommand::execute()
{
	if (m_toolBar.getSideMenuIndex() == BUILDINGS_SM) {
		m_toolBar.setSideMenuIndex(NONE_SM);
	}
	else {
		m_toolBar.setSideMenuIndex(BUILDINGS_SM);
	}
}