#include "Game.h"
#include "Map.h"
#include "Factory.h"
#include <fstream>
#include "CollisionHandling.h"


const sf::Vector2f FRONT_LEFT_DIRECTION = { 80,50 };
const sf::Vector2f FRONT_RIGHT_DIRECTION = { 128 ,50 };
const sf::Vector2f BACK_LEFT_DIRECTION = { 80,100 };
const sf::Vector2f BACK_RIGHT_DIRECTION = { 128,100 };

Game::Game(Map& map)
	:m_map(map), m_animalsGraph(std::make_unique<Graph>(map, map.getMapLastCellIndex())),
	m_guestsGraph(std::make_unique<Graph>(map, map.getMapLastCellIndex()))
{
}

void Game::loadGame(char symbol, std::string x, std::string y)
{
	std::string::size_type sz;     // alias of size_t

	float posX = std::stof(x, &sz);
	float posY = std::stof(y, &sz);
	sf::Vector2f position = { posX, posY };

	switch (symbol)
	{
	case 'F'://fance
		m_itemBuilding.emplace_back(Factory::createBuilding("Fence"));
		m_itemBuilding.back()->setPosition(position);
		break;
	case 'P'://predatorfood
		m_itemConstruction.emplace_back(Factory::createConstruction("PredatorFood"));
		m_itemConstruction.back()->setPosition(position);
		break;
	case 'R'://rock
		m_itemConstruction.emplace_back(Factory::createConstruction("Rock"));
		m_itemConstruction.back()->setPosition(position);
		break;
	case'H'://herbivorFood
		m_itemConstruction.emplace_back(Factory::createConstruction("HerbivorFood"));
		m_itemConstruction.back()->setPosition(position);
		break;
	case 'T'://tree
		m_itemConstruction.emplace_back(Factory::createConstruction("Tree"));
		m_itemConstruction.back()->setPosition(position);
		break;
	case 'm'://Burger
		m_itemBuilding.emplace_back(Factory::createBuilding("Burger"));
		m_itemBuilding.back()->setPosition(position);
		break;
	case 'k'://chickerNugets
		m_itemBuilding.emplace_back(Factory::createBuilding("ChickerNugets"));
		m_itemBuilding.back()->setPosition(position);
		break;
	case 'q'://cuttonCandy
		m_itemBuilding.emplace_back(Factory::createBuilding("CuttonCandy"));
		m_itemBuilding.back()->setPosition(position);
		break;

	case 'b'://BATHROOM
		m_itemBuilding.emplace_back(Factory::createBuilding("Bathroom"));
		m_itemBuilding.back()->setPosition(position);
		break;
	case 'd'://drinkstand
		m_itemBuilding.emplace_back(Factory::createBuilding("DrinkingStand"));
		m_itemBuilding.back()->setPosition(position);
		break;
	case 'e'://elefant
		m_itemAnimal.emplace_back(Factory::createAnimal("Elephant"));
		m_itemAnimal.back()->setPosition(position);
		break;
	case 'g'://giraffe
		m_itemAnimal.emplace_back(Factory::createAnimal("Giraffe"));
		m_itemAnimal.back()->setPosition(position);
		break;
	case 'h'://hippo
		m_itemAnimal.emplace_back(Factory::createAnimal("Hippo"));
		m_itemAnimal.back()->setPosition(position);
		break;
	case 'l'://lion
		m_itemAnimal.emplace_back(Factory::createAnimal("Lion"));
		m_itemAnimal.back()->setPosition(position);
		break;
	case 'p'://pullandbear
		m_itemAnimal.emplace_back(Factory::createAnimal("PollarBear"));
		m_itemAnimal.back()->setPosition(position);
		break;
	case '!': //path
		//factory to path
		m_terrain.emplace_back(Factory::createTerrain("Path"));
		m_terrain.back()->setPosition(position);
		break;
	case '@': //watter
		//factory to watter
		m_terrain.emplace_back(Factory::createTerrain("Water"));
		m_terrain.back()->setPosition(position);
		break;
	case '#': //grass
		//factory to draw
		m_terrain.emplace_back(Factory::createTerrain("Grass"));
		m_terrain.back()->setPosition(position);
		break;
	case '$': //dirt
		//factory to sand
		m_terrain.emplace_back(Factory::createTerrain("Dirt"));
		m_terrain.back()->setPosition(position);
		break;
	case '%'://savana
		m_terrain.emplace_back(Factory::createTerrain("Savannah"));
		m_terrain.back()->setPosition(position);
		break;
	case '^'://jon 
		m_terrain.emplace_back(Factory::createTerrain("Snow"));
		m_terrain.back()->setPosition(position);
		break;
	case 'W'://woman
		m_guest.emplace_back(Factory::createGuest("WomanGuest"));
		m_guest.back()->setPosition(position);
		break;
	case 'M'://man
		m_guest.emplace_back(Factory::createGuest("ManGuest"));
		m_guest.back()->setPosition(position);
		break;
	}
}

void Game::draw(float deltaTime, sf::RenderWindow& window)
{
	m_map.draw();
	for (auto& terrain : m_terrain)
		terrain->draw(window);
	for (auto& building : m_itemBuilding)
		building->draw(window);
	for (auto& construction : m_itemConstruction)
		construction->draw(window);
	for (auto& animal : m_itemAnimal)
		animal->play(deltaTime, window);
	for (auto& guest : m_guest)
		guest->play(deltaTime, window);

}

void Game::drawTextBox(sf::RenderWindow & window)
{
	if (ANIMAL_F == getFlotingItem())
		m_textAnimal.draw(window);
	if (BUILDING_F == getFlotingItem())
		m_textBulding.draw(window);
	if (CONST_F == getFlotingItem())
		m_textConstruction.draw(window);
	if (TERRAIN_F == getFlotingItem())
		m_textConstruction.draw(window);
}

bool Game::isOnMap(sf::Vector2f position) const
{
	return m_map.isOnMap(position);
}

void Game::unFloatItem(const sf::Vector2f & pos)
{
	switch (getFlotingItem())
	{
	case ANIMAL_F:
		m_itemAnimal.back()->setPosition(pos);
		break;
	case CONST_F:
		m_itemConstruction.back()->setPosition(pos);
		break;
	case TERRAIN_F:
		m_terrain.back()->setPosition(pos);
		break;
	case BUILDING_F:
		m_itemBuilding.back()->setPosition(pos);
		break;
	}
	resetFloatItem();
}

void Game::addAnimal(const std::string & animalName)
{
	m_itemAnimal.emplace_back(Factory::createAnimal(animalName));
	m_floatingItem = ANIMAL_F;
}

void Game::addBuilding(const std::string & buildingName)
{
	m_itemBuilding.emplace_back(Factory::createBuilding(buildingName));
	if (m_itemBuilding.back() != nullptr) {
		m_itemBuilding.back()->setTexture(getDirection());
		m_floatingItem = BUILDING_F;
		return;
	}
	m_itemBuilding.pop_back();
}

bool Game::addConstruction(const std::string & constructionName)
{
	m_itemConstruction.emplace_back(Factory::createConstruction(constructionName));
	if (m_itemConstruction.back() != nullptr)
	{
		m_floatingItem = CONST_F;
		return true;
	}
	m_itemConstruction.pop_back();
	return false;
}

void Game::addTerrain(const std::string & terrainName)
{
	m_terrainName = terrainName;
	m_terrain.emplace_back(Factory::createTerrain(terrainName));
	m_floatingItem = TERRAIN_F;
}

void Game::saveGame(std::ofstream & file)
{
	for (int i = 0; i < m_itemAnimal.size(); ++i)
		file << "game" << " " << m_itemAnimal[i]->getSymbol() << " " << m_itemAnimal[i]->getPosition().x << " " << m_itemAnimal[i]->getPosition().y << std::endl;
	for (int j = 0; j < m_itemBuilding.size(); j++)
		file << "game" << " " << m_itemBuilding[j]->getSymbol() << " " << m_itemBuilding[j]->getPosition().x << " " << m_itemBuilding[j]->getPosition().y << std::endl;
	for (int k = 0; k < m_itemConstruction.size(); k++)
		file << "game" << " " << m_itemConstruction[k]->getSymbol() << " " << m_itemConstruction[k]->getPosition().x << " " << m_itemConstruction[k]->getPosition().y << std::endl;
	for (int w = 0; w < m_guest.size(); w++)
		file << "game" << " " << m_guest[w]->getSymbol() << " " << m_guest[w]->getPosition().x << " " << m_guest[w]->getPosition().y << std::endl;
	for (int l= 0; l < m_terrain.size(); l++)
		file << "game" << " " << m_terrain[l]->getSymbol() << " " << m_terrain[l]->getPosition().x << " " << m_terrain[l]->getPosition().y << std::endl;
}

void Game::processMouseMovedEvent(const sf::Vector2f & position)
{
	switch (m_floatingItem)
	{
	case ANIMAL_F:
		m_itemAnimal.back()->setPosition(position);
		break;
	case CONST_F:
		m_itemConstruction.back()->setPosition(position);
		break;
	case BUILDING_F:
		m_itemBuilding.back()->setPosition(position);
		break;
	case TERRAIN_F:
		m_terrain.back()->setPosition(position);
	default:
		break;
	}
}

bool Game::processMousePressWithObj(const sf::Vector2f & position)
{
	return (m_map.isOnMap(position) && getFlotingItem() != NONE_F && !isOnItem(position));
}

bool Game::hasFloatingItem()
{
	return (getFlotingItem() != NONE_F);
}

void Game::removeFloatingItem()
{
	switch (getFlotingItem()) {
	case ANIMAL_F:
		if (!m_itemAnimal.empty() && m_itemAnimal.size() > 0)
			m_itemAnimal.pop_back();
		break;
	case CONST_F:
		if (!m_itemConstruction.empty() && m_itemConstruction.size() > 0)
			m_itemConstruction.pop_back();
		break;
	case BUILDING_F:
		if (!m_itemBuilding.empty() && m_itemBuilding.size() > 0)
			m_itemBuilding.pop_back();
		break;
	case TERRAIN_F:
		if (!m_terrain.empty() && m_terrain.size() > 0)
			m_terrain.pop_back();
	}
	resetFloatItem();
}

void Game::BFS(const sf::Vector2f & position)
{
	// run on loop for all animal and guests, for movment
	if (!m_itemAnimal.empty())
		m_animalsGraph->BFS(position);
}

void Game::setPrice()
{
	switch (m_floatingItem)
	{
	case ANIMAL_F:
		m_textAnimal.setPrice(m_itemAnimal.back()->getPrice());
		break;
	case CONST_F:
		m_textConstruction.setPrice(m_itemConstruction.back()->getPrice());
		break;
	case BUILDING_F:
		m_textBulding.setPrice(m_itemBuilding.back()->getPrice());
		break;
	case TERRAIN_F:
		m_textConstruction.setPrice(m_terrain.back()->getPrice());
		break;
	default:
		break;
	}
}

void Game::moveDynamicItems(float deltaTime)
{
	moveAnimals(deltaTime);
	moveGuests(deltaTime);
}

void Game::addGuest(float deltaTime)
{
	int j;
	j = rand() % 2;
	switch (1)
	{
	case -1:
		m_guest.emplace_back(Factory::createGuest("ManGuest"));
		m_guest.back()->setStartingTime(deltaTime);
		m_guest.back()->setPosition(sf::Vector2f{-730, 950});
		break;
	case 1:
		m_guest.emplace_back(Factory::createGuest("WomanGuest"));
		m_guest.back()->setStartingTime(deltaTime);
		m_guest.back()->setPosition(sf::Vector2f{ -730, 950 });
		break;
	default:
		break;
	}
	

}

void Game::checkIfTimeToLeave(float gameTime)
{
	for (auto& guest : m_guest)
		guest->checkIfTimeToLeave(gameTime);
}

const sf::Vector2f& Game::getItemPosition() const
{
	if (!m_terrain.empty())
		return m_terrain[m_terrain.size() - 2]->getPosition();
	return { 0.0f, 0.0f };
}

void Game::handleCollisions()
{
	for (auto& a : m_itemAnimal)
		for (auto& b : m_itemConstruction)
		{
			if (collide(*a, *b))
			{
				processCollision(*a, *b);
				return;
			}
		}

	for (auto& a : m_itemAnimal)
		for (auto& b : m_itemBuilding)
		{
			if (collide(*a, *b))
			{
				processCollision(*a, *b);
				return;
			}
		}
	for (auto& a : m_itemAnimal)
		for (auto& b : m_itemConstruction)
		{
			if (collide(*a, *b))
			{
				processCollision(*a, *b);
				return;
			}
		}

	for_each_pair(m_itemAnimal.begin(), m_itemAnimal.end(), [&](auto & a, auto & b) {
		if (collide(*a, *b))
		{
			processCollision(*a, *b);
			return;
		}
		});

	for_each_pair(m_itemBuilding.begin(), m_itemBuilding.end(), [&](auto & a, auto & b) {
		if (collide(*a, *b))
		{
			processCollision(*a, *b);
			return;
		}
		});

	for_each_pair(m_itemConstruction.begin(), m_itemConstruction.end(), [&](auto & a, auto & b) {
		if (collide(*a, *b))
		{
			processCollision(*a, *b);
			return;
		}
		});

}

void Game::handleFence(const sf::Vector2f & pos)
{

	if (pos == FRONT_LEFT_DIRECTION)
		setDirection(FRONT_LEFT);
	else if (pos == FRONT_RIGHT_DIRECTION)
		setDirection(FRONT_RIGHT);
	else if (pos == BACK_LEFT_DIRECTION)
		setDirection(BACK_LEFT);
	else setDirection(BACK_RIGHT);
}

bool Game::isOnItem(sf::Vector2f position) const
{
	for (auto& i : m_itemAnimal)
		if (i->getGlobalBounds().contains(position))
			return true;
	for (auto& i : m_itemBuilding)
		if (i->getGlobalBounds().contains(position))
			return true;
	for (auto& i : m_itemConstruction)
		if (i->getGlobalBounds().contains(position))
			return true;
	return false;
}

bool Game::collide(MapItem & a, MapItem & b) const
{
	sf::FloatRect aa = a.getGlobalBounds();
	sf::FloatRect bb = b.getGlobalBounds();
	if (aa.intersects(bb))
		return true;
	return false;
}

void Game::moveAnimals(float deltaTime)
{
	for (int i = 0; i < m_itemAnimal.size(); ++i)
		m_itemAnimal[i]->move(deltaTime, m_map,
			m_animalsGraph->getNextMove(m_itemAnimal[i]->getPosition(), m_itemAnimal[i]->getLastMove()));
}

void Game::deleteItem(sf::Vector2f position)
{

	for (int i = 0; i < m_itemBuilding.size(); ++i)
		if (m_itemBuilding[i]->isOnMapCell(position))
			m_itemBuilding.erase(m_itemBuilding.begin() + i);

	for (int i = 0; i < m_itemAnimal.size(); ++i)
		if (m_itemAnimal[i]->isOnMapCell(position))
			m_itemAnimal.erase(m_itemAnimal.begin() + i);

	for (int i = 0; i < m_itemConstruction.size(); ++i)
		if (m_itemConstruction[i]->isOnMapCell(position))
			m_itemConstruction.erase(m_itemConstruction.begin() + i);

	for (int i = 0; i < m_terrain.size(); ++i)
		if (m_terrain[i]->isOnMapCell(position))
			m_terrain.erase(m_terrain.begin() + i);
}

void Game::moveGuests(float deltaTime)
{
	for (int i = 0; i < m_guest.size(); ++i)
		m_guest[i]->move(deltaTime, m_map,
			m_guestsGraph->getNextMove(m_guest[i]->getPosition(), m_guest[i]->getLastMove()));
}

void Game::initGraphData()
{
	m_animalsGraph->initData(m_itemConstruction);
	m_animalsGraph->initData(m_itemBuilding);
	m_animalsGraph->initData(m_path);

	m_guestsGraph->setNeedToBeInitialized();
	m_guestsGraph->initData(m_terrain);
}

double Game::getAnimalHappinessPer()
{
	double sum = 0;
	for (auto& i : m_itemAnimal)
		sum += i->getHappiness();
	if (m_itemAnimal.size() == 0)
		return sum;
	else
		return (sum / m_itemAnimal.size());
}

double Game::getPeopleHappinessPer()
{
	double sum = 0;
	for (auto& i : m_guest)
		sum += i->getHappiness();
	if (m_guest.size() == 0)
		return sum;
	else
		return (sum / m_guest.size());
}

int Game::getPrice(floating_item_t getFlotingItem)
{
	std::string::size_type sz;     // alias of size_t
	switch (m_floatingItem)
	{
	case ANIMAL_F:
		return std::stol(m_itemAnimal.back()->getPrice(), &sz);
		//open the comment when will be object of building and construction!!!!!!
	case CONST_F:
		return std::stol(m_itemConstruction.back()->getPrice(), &sz);
	case BUILDING_F:
		return std::stol(m_itemBuilding.back()->getPrice(), &sz);
	case TERRAIN_F:
		return std::stol(m_terrain.back()->getPrice(), &sz);
	default:
		return 0;
	}
}

