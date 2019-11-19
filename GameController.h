#pragma once
#include <SFML/Graphics.hpp>
#include "Graph.h"
#include "ToolBar.h"
#include "StatusBar.h"
#include "Economy.h"
#include "ZooManeger.h"

class Game;
class Map;

// row and col width of the map
const int ROW_WIDTH = 50;
const int COL_WIDTH = 50;
const int ENTRANCE_FEE = 15;
// controll the game window and logic
class GameController
{
public:
	GameController(sf::RenderWindow& gameWindow, Map& map, Game& game);
	// play the game
	void play();

	void setZoom(float zoom);

	void handleEvents(bool &moving, sf::Vector2f &oldPos, float &zoom);
	//void saveCurrentGame();
	void loadAGame();
	bool isTerrain();
	bool isAnimal();
	void saveGame();

	//static const std::string SAVE_FILE_NAME;
private:

	void draw(float deltaTime);
	void computePixCoordsToGameCoords(const sf::Vector2f& pos);
	void updateStatusBar();
	void updateZooManager();
	// game window
	sf::RenderWindow& m_window;

	// map size
	sf::Vector2i m_mapSize = { 0, 0 };
	
	Game& m_game;
	std::unique_ptr<ToolBar> m_toolBar = std::make_unique<ToolBar>(m_game);
	std::unique_ptr<StatusBar> m_statusBar = std::make_unique<StatusBar>();
	sf::View m_gameView;
	std::unique_ptr<sf::Clock> m_gameTimeClock = std::make_unique<sf::Clock>();
	Map & m_map;
	ZooManeger m_zooManeger;
	bool m_startBFS = false;
	bool m_deleteOn;
	//clock
	std::unique_ptr<sf::Clock> m_peopleClock = std::make_unique<sf::Clock>();
	//background music
	std::unique_ptr<Sound> m_bgGameSound = std::make_unique<Sound>(GameResources::instance().getBgGameBuffer());

};
