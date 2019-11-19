#include "AnimalMenuCommand.h"
#include "ToolBar.h"

void AnimalMenuCommand::execute()
{
	if (m_toolBar.getSideMenuIndex() == ANIMALS_SM) {
		m_toolBar.setSideMenuIndex(NONE_SM);
	}
	else {
		m_toolBar.setSideMenuIndex(ANIMALS_SM);
	}
}
