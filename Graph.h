#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Building.h"
#include "ConstructionItem.h"
#include "Path.h"
#include "Map.h"
#include "consts.h"

const float HALF_PLAYER_SIZE = 12.0f;

const int UP_LEFT_NEIGHBOR = 0;
const int UP_RIGHT_NEIGHBOR = 1;
const int DOWN_RIGHT_NEIGHBOR = 2;
const int DOWN_LEFT_NEIGHBOR = 3;
const int MAX_NEIGHBORS = 4;

const int UP_LEFT_NIEGHBOR_FUCTOR_UP_TRY = -1;
const int UP_RIGHT_NEIGHBOR_FUCTOR_UP_TRY = 0;
const int DOWN_LEFT_NEIGHBOR_FUCTOR_UP_TRY = 1;
const int DOWN_RIGHT_NEIGHBOR_FUCTOR_UP_TRY = 2;

const int UP_LEFT_NIEGHBOR_FUCTOR_DOWN_TRY = -2;
const int UP_RIGHT_NEIGHBOR_FUCTOR_DOWN_TRY = -1;
const int DOWN_LEFT_NEIGHBOR_FUCTOR_DOWN_TRY = 0;
const int DOWN_RIGHT_NEIGHBOR_FUCTOR_DOWN_TRY = 1;

const int UP_LEFT_NIEGHBOR_FUCTOR_MIDDLE_TRY = -1;
const int UP_RIGHT_NEIGHBOR_FUCTOR_MIDDLE_TRY = 0;
const int DOWN_LEFT_NEIGHBOR_FUCTOR_MIDDLE_TRY = 0;
const int DOWN_RIGHT_NEIGHBOR_FUCTOR_MIDDLE_TRY = 1;


class Map;

struct GraphData {
	// init the members in the strtuct, -1 as infinity
	GraphData() : visited(false), isNode(true), distance(-1), predecessor({ -1, -1 }) {}
	bool visited;
	bool isNode;
	int distance;
	sf::Vector2f predecessor;
	int neighbors[4] = { -1, -1, -1, -1 }; // for left, right, up and down neighbors
};

class Graph
{
public:
	Graph(Map& map, int rowsCols);

	// initial graph data- set static items not nodes in the map 
	template<class T>
	void initData(const std::vector < std::unique_ptr<T>>& mapItems);
	// BFS algorithm on the nodes on the board
	void BFS(const sf::Vector2f& startNode);
	// get guards next move on the board by their predeccesor
	move_t getNextMove(const sf::Vector2f& currentPosition, move_t prevMov);
	// set the graph to need to not initialize from the beguining
	void setNoNeedInitialize() { m_firstInit = false; }
	// set graph need to be initialized
	void setNeedToBeInitialized() { m_firstInit = true; }

private:
	// set for each node its neighbors
	void setNeighbors();
	// move on the nodes in the array and add for each node its neighbors
	template<class T>
	void initNodes(const std::vector<std::unique_ptr<T>>& mapItems);
	void addNeighbors(int node, int numOfRow);
	int findNumOfRow(int node);
	// check if the neighbor is in ligal position on the map
	bool isLigalNeighbor(int cell, int row);
	// convert node on the graph to its coords position
	const sf::Vector2f& convertNodeToSFCoords(int node) const;
	void createEmptyGraph() { m_graphData = std::make_unique<std::vector<GraphData>>(m_rowsCols + 1); }

	Map & m_map;
	// pointer for vector that represents the graph
	std::unique_ptr<std::vector<GraphData>> m_graphData;

	// num of rows and columns of the map
	int m_rowsCols;
	bool m_firstInit = false;

};

//this function initializes all the data for building the graph of the empty paths on the board
template<class T>
inline void Graph::initData(const std::vector<std::unique_ptr<T>>& mapItems)
{
	if (m_firstInit) // holds one line of all the nodes that will be kept as neighbors
		createEmptyGraph();

	if (!m_graphData) // if create graph failed
		exit(EXIT_FAILURE);

	initNodes(mapItems);

	setNoNeedInitialize();
}

//this function initializes all the nodes in the graph. if the position contains static items
//then they are not nodes in our graph
template<class T>
inline void Graph::initNodes(const std::vector<std::unique_ptr<T>>& mapItems)
{
	sf::Vector2f positionInPixels;
	int node = 0;

	if (!mapItems.empty())
		for (size_t i = 0; i < mapItems.size(); ++i) {
			positionInPixels = mapItems[i]->getPosition(); // set position for static items
			node = m_map.convertCoordsToMapCellIndex(positionInPixels); // convert position to vector2u
			m_graphData->at(node).isNode = false;
		}
	setNeighbors();
}
