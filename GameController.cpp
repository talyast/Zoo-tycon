#include "GameController.h"
#include "Game.h"
#include "Map.h"
#include "GameResources.h"
#include "wintools.h"
#include <sstream>
#include <iterator>

//const std::string GameController::SAVE_FILE_NAME = "save_game";

GameController::GameController(sf::RenderWindow& window, Map& map, Game& game)
	:m_window(window), m_game(game), m_map(map)
{
}

void GameController::play()
{
	sf::Vector2f startPoint = {};
	sf::Vector2i centerOfView = {};

	sf::Vector2f oldPos;
	bool moving = false;
	float Time = m_peopleClock->restart().asSeconds();
	sf::Time passTime = sf::seconds(15);
	float gameTime = m_gameTimeClock->restart().asSeconds();
	float zoom = 1;
	
	// initialize the zoom
	setZoom(zoom);
	// run the program as long as the window is open
	while (m_window.isOpen())
	{
		float deltaTime = m_gameTimeClock->restart().asSeconds();
		m_bgGameSound->playSound();
		m_bgGameSound->loop();
		draw(deltaTime);

		handleEvents(moving, oldPos, zoom);
		m_game.handleCollisions();
		if (m_peopleClock->getElapsedTime().asSeconds() > passTime.asSeconds())
		{
			if (m_game.getAnimalHappinessPer() != 0) {
				m_game.addGuest(deltaTime);
				m_zooManeger.increaseMoney(ENTRANCE_FEE);
				m_game.checkIfTimeToLeave(gameTime);
			}
			m_peopleClock->restart().asSeconds();
		}

		//if (m_game.needToInitGraph()) {
		//	m_game.initGraphData(); // init when static item are on the map only 
		//	m_game.BFS(m_game.getItemPosition());
		//}

		m_game.resetBFSInit(); // reset init graph as false
		updateStatusBar();
		updateZooManager();
	
			
		//m_zooManeger.increaseMoney(m_game.get);
		if (!moving)
			m_game.moveDynamicItems(deltaTime);
	}
}


void GameController::setZoom(float zoom)
{
	m_gameView.setSize(m_window.getDefaultView().getSize()); // Reset the size
	m_gameView.zoom(zoom); // Apply the zoom level (this transforms the view)
	m_window.setView(m_gameView);
}

void GameController::handleEvents(bool& moving, sf::Vector2f& oldPos, float& zoom)
{
	// check all the window's events that were triggered since the last iteration of the loop
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				saveGame();
				m_window.close();
			}
			break;

		case sf::Event::MouseButtonPressed:
			// Mouse button is pressed, get the position and set moving as active
			if (m_toolBar->inBounds({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
				if (m_game.hasFloatingItem()) // if pressed on tool bar and holds floating item
					m_game.removeFloatingItem();
			if (!moving && event.mouseButton.button == sf::Mouse::Button::Left) {
				moving = true;
				oldPos = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
			}
		
			
			if (m_deleteOn)
			{
				m_game.deleteItem(oldPos);
				m_deleteOn=false;
				m_toolBar->setDeleteStat();
			}
			break;
		case  sf::Event::MouseButtonReleased:
			// Mouse button is released, no longer move

			if (event.mouseButton.button == sf::Mouse::Button::Left)
			{
				moving = false;
				if (m_game.hasFloatingItem() && // if item exists
					m_toolBar->sideMenuButtonIsPressed({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
					m_game.removeFloatingItem();
				

				if (m_toolBar->processMouseClick({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
					if (m_game.hasFloatingItem()) {
						m_game.setPrice();

					}
					else if (m_toolBar->getSaveStat())
					{
						saveGame();
						return;
					}
					else if (m_toolBar->getDeleteStat())
					{
						m_deleteOn = true;
						return;
					}
					else
						break;
					
				//else process click on the map
				else if (m_game.processMousePressWithObj(oldPos))
				{
					m_zooManeger.decreaseMoney(m_game.getPrice(m_game.getFlotingItem()));
					if (!isTerrain()) //  if obj is not terrain
						m_game.unFloatItem(oldPos);
					if (!isAnimal())
						m_game.setBFSInit();
				}
			}
			if (event.mouseButton.button == sf::Mouse::Button::Right) {
				m_game.removeFloatingItem();
			}
			break;
		case sf::Event::MouseMoved:
		{
			if (!moving) {
				m_game.processMouseMovedEvent(m_window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y)));
				break;
			}
			// Determine the new position in world coordinates
			const sf::Vector2f newPos = m_window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
			// Determine how the cursor has moved
			// Swap these to invert the movement direction
			const sf::Vector2f deltaPos = oldPos - newPos;

			// Move our view accordingly and update the window
			m_gameView.setCenter(m_gameView.getCenter() + deltaPos);
			m_window.setView(m_gameView);

			// Save the new position as the old one
			// We're recalculating this, since we've changed the view
			oldPos = m_window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
			break;
		}
		case sf::Event::MouseWheelScrolled:
			// Ignore the mouse wheel unless we're not moving
			if (moving)
				break;

			// Determine the scroll direction and adjust the zoom level
			// Again, you can swap these to invert the direction
			if (event.mouseWheelScroll.delta <= -1)
				zoom = std::min(2.f, zoom + .1f);
			else if (event.mouseWheelScroll.delta >= 1)
				zoom = std::max(.5f, zoom - .1f);

			// Update our view
			setZoom(zoom);
			break;
		}
	}
}

void GameController::loadAGame()
{
	std::ifstream m_file("save_game");
	std::string line;

	while (!m_file.eof())
	{
		getline(m_file, line);
		if (line == "")
			break;
		std::istringstream iss(line);
		std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss},
				  std::istream_iterator<std::string>{} };
		
		if (tokens[0] == "map")
			m_map.loadMap(tokens[1][0], tokens[2], tokens[3]); //the second string the first char
		else if (tokens[0] == "game")
			m_game.loadGame(tokens[1][0], tokens[2], tokens[3]);
		else
			m_statusBar->loadStatusBar(tokens[1], tokens[2]);
		
	}
	m_zooManeger.changeMoney(m_statusBar->getMoney());
}

bool GameController::isTerrain()
{
	if (m_game.getFlotingItem() == TERRAIN_F)
	{
		m_game.addTerrain(m_game.getTerrainName());
		return true;
	}
	return false;
}

bool GameController::isAnimal()
{
	if (m_game.getFlotingItem() == ANIMAL_F)
		return true;
	return false;
}

void GameController::saveGame()
{

	std::ofstream file("save_game");
	
	m_game.saveGame(file);
	m_map.saveMap(file);
	m_statusBar->saveStatusBar(file);

	file.flush();
	file.close();

}

void GameController::draw(float deltaTime)
{
	m_window.clear();

	m_game.draw(deltaTime, m_window);
	
	m_window.setView(m_window.getDefaultView());
	m_statusBar->draw(m_window);
	m_toolBar->draw(m_window);
	//m_game.drawTextBox(m_window);
	m_window.setView(m_gameView);
	m_window.display();
}

void GameController::computePixCoordsToGameCoords(const sf::Vector2f& pos)
{
	m_map.isOnMap(pos);
}

void GameController::updateStatusBar()
{
	m_statusBar->updateMoney(m_zooManeger.getMoney());
	m_statusBar->updateAnimalHappiness(m_game.getAnimalHappinessPer());
	m_statusBar->updatePeopleHappiness(m_game.getPeopleHappinessPer());
	m_statusBar->updateNumberOfVisitiors(m_game.getNumberOfVisitors());
}

void GameController::updateZooManager()
{
	m_zooManeger.updateAnimalHappiness(m_game.getAnimalHappinessPer());
	m_zooManeger.updatePeopleHappiness((m_game.getPeopleHappinessPer()));
	//m_zooManeger.increaseMoney((m_game.getincome()));
	m_zooManeger.updateAmountOfGuests(m_game.getNumberOfVisitors());
}

