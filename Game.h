#pragma once
#include <memory>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Animal.h"
#include "Building.h"
#include "Path.h"
#include "Graph.h"
#include "ConstructionItem.h"
#include "TextBoxAnimal.h"
#include "TextBoxBuilding.h"
#include "TextBoxConstruction.h"
#include "Economy.h"
#include "Guest.h"
#include "Grass.h"


class MapItem;
class Map;

enum floating_item_t { ANIMAL_F, CONST_F, BUILDING_F, NONE_F, TERRAIN_F };
enum direction_t {FRONT_LEFT , FRONT_RIGHT , BACK_RIGHT, BACK_LEFT};
class Game
{
public:
	Game(Map& map);
	// load the game by reading from a file
	void loadGame(char symbol, std::string x, std::string y);
	//draw all items in the game
	void draw(float deltaTime, sf::RenderWindow& window);
	//draw text
	void drawTextBox(sf::RenderWindow& window);
	//to unable terrain on objects
	bool isOnMap(sf::Vector2f position) const;
	void unFloatItem(const sf::Vector2f& pos);
	void resetFloatItem() { m_floatingItem = NONE_F; }
	void addAnimal(const std::string& animalName);
	//add building 
	void addBuilding(const std::string& buildingName);
	//add construction item
	bool addConstruction(const std::string& constructionName);
	//add terrain item
	void addTerrain(const std::string& terrainName);
	//add guest
	void addGuest(float deltaTime);
	// save the game by copying the item to a file
	void saveGame(std::ofstream & file);
	// init graph
	void initGraphData();
	//gets the animal happiness in persentage
	double getAnimalHappinessPer();
	//  get the price of pressed object
	int getPrice(floating_item_t getFlotingItem);
	void processMouseMovedEvent(const sf::Vector2f& position);
	// process mouse press on the map while holding an object
	bool processMousePressWithObj(const sf::Vector2f& position);
	// return if game has floating item
	bool hasFloatingItem();
	// remove existing item from the game
	void removeFloatingItem();
	// call graph BFS on moving object
	void BFS(const sf::Vector2f& position);
	// print the price of object on screen
	void setPrice();
	// move animal and guests on the map
	void moveDynamicItems(float deltaTime);
	// return if need to initialize graph- if were added items to the map
	bool needToInitGraph() const { return m_BFSinit; }
	void resetBFSInit() { m_BFSinit = false; }
	void setBFSInit() { m_BFSinit = true; }
	//set direction to building object
	void setDirection(direction_t direction) { m_dir = direction; };
	//check its time for the person to leave
	void checkIfTimeToLeave(float deltaTime);
	//return the direction object
	direction_t getDirection() { return m_dir; };
	// return which item is floating
	floating_item_t getFlotingItem() const { return m_floatingItem; }
	std::string  getTerrainName() const { return m_terrainName; };
	virtual const sf::Vector2f& getItemPosition() const ;
	//collision between objects
	void handleCollisions();
	//handle fence position
	void handleFence(const sf::Vector2f & pos);
	//function that finds each pair in vector
	template <typename FwdIt, typename Fn>
	void for_each_pair(FwdIt begin, FwdIt end, Fn fn);
	//if the item we want to put down is on an existing item
	bool isOnItem(sf::Vector2f position) const;
	//gets the people happiness by percantage
	double getPeopleHappinessPer();
	//double getincome();
	bool collide(MapItem& a, MapItem& b) const;
	//gets the number of visitors in the zoo
	int getNumberOfVisitors()const { return (int)m_guest.size(); };
	//delete the item - with the tractor 
	void deleteItem(sf::Vector2f position);
private:
	void moveAnimals(float deltaTime);
	void moveGuests(float deltaTime);
	
	Map& m_map;
	TextBoxAnimal m_textAnimal;
	TextBoxBuilding m_textBulding;
	TextBoxConstruction m_textConstruction;
	std::vector<std::unique_ptr<Animal>> m_itemAnimal;
	std::vector<std::unique_ptr<ConstructionItem>> m_itemConstruction;
	std::vector<std::unique_ptr<Terrain>> m_terrain;
	std::vector<std::unique_ptr<Building>> m_itemBuilding;
	std::vector<std::unique_ptr<Guest>> m_guest;
	floating_item_t m_floatingItem = NONE_F;
	// path vector
	std::vector<std::unique_ptr<Path>> m_path;

	direction_t m_dir = FRONT_LEFT;

	// graph for AI calculations: represents the board as a graph and performs BFS on it to find the
	// shortest path from the robot to every board cell (used by clever guards)
	std::unique_ptr<Graph> m_animalsGraph;
	std::unique_ptr<Graph> m_guestsGraph;

	// BFS init if construction or building was added
	bool m_BFSinit = false;
	bool m_save = false;
	// save terrain name from the toolbar to create more
	std::string m_terrainName;
};

template<typename FwdIt, typename Fn>
inline void Game::for_each_pair(FwdIt begin, FwdIt end, Fn fn)
{
	for (; begin != end; ++begin)
		for (FwdIt second = begin + 1; second != end; ++second)
			fn(*begin, *second);
}
