#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "MenuController.h"
#include "GameController.h"
#include "Game.h"
#include "Map.h"
#include "GameResources.h"

const unsigned int MAP_ROWS = 100;

class Controller
{
public:
	void run();

private:
	std::unique_ptr<sf::RenderWindow> m_window = std::make_unique<sf::RenderWindow>();
	// controller for each screen: menu screen, load screen and game screen
	std::unique_ptr<Map> m_map = std::make_unique<Map>(MAP_ROWS, *m_window);
	//all objects that are on the game
	std::unique_ptr<Game> m_game = std::make_unique<Game>(*m_map);
	//hanle the all menus events
	std::unique_ptr<MenuController> m_menuController = std::make_unique<MenuController>(*m_window);
	//gamecontrooler - handles all events og the game
	std::unique_ptr<GameController> m_gameController = std::make_unique<GameController>(*m_window, *m_map, *m_game);
	std::unique_ptr<Sound> m_bgMenuSound = std::make_unique<Sound>(GameResources::instance().getBgMenuBuffer());

};

