#include "ConstructionMenuCommand.h"
#include "ToolBar.h"

void ConstructionMenuCommand::execute()
{
	if (m_toolBar.getSideMenuIndex() == CONSTRUCTION_SM) {
		m_toolBar.setSideMenuIndex(NONE_SM);
	}
	else {
		m_toolBar.setSideMenuIndex(CONSTRUCTION_SM);
	}
}
