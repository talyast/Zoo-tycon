#include <queue>
#include "Graph.h"

/*Graph constructor*/

Graph::Graph(Map& map, int rowsCols)
	:m_map(map), m_rowsCols(rowsCols)
{
	m_firstInit = true; // set as first init
	createEmptyGraph();
}

/*this function sets position on the board from a given node*/
const sf::Vector2f& Graph::convertNodeToSFCoords(int node) const
{
	return m_map.convertNodeToSFCoordsMap(node);
}

/*this function sets the neighbors to all the nodes in the graph by calling addNeighbors function to add all four
neighbors around the node if exists*/
void Graph::setNeighbors()
{
	// run on the array the neighbors of the nodes if exists
	for (int i = 0; i <= m_rowsCols; ++i)
		if (m_graphData->at(i).isNode) // if is a node
			addNeighbors(i, findNumOfRow(i)); // sent the nonde and its row to add neighbors
}

/*this function acceptes the node index and its position on the board, set its neighbors*/
void Graph::addNeighbors(int node, int numOfRow)
{
	int neighbor = 0; // initialize neighbor

	if (numOfRow == (m_map.getMapRowsSize() / 2) - 1) {

		neighbor = node + (UP_LEFT_NIEGHBOR_FUCTOR_MIDDLE_TRY - numOfRow);
		if (isLigalNeighbor(neighbor, numOfRow - 1)) { // if not out of range on the left up
			if (m_graphData->at(neighbor).isNode) // if the left neighbor exists
				m_graphData->at(node).neighbors[UP_LEFT_NEIGHBOR] = neighbor;

		}

		neighbor = node + (UP_RIGHT_NEIGHBOR_FUCTOR_MIDDLE_TRY - numOfRow);
		if (isLigalNeighbor(neighbor, numOfRow - 1)) {//  if not out of range on right up
			if (m_graphData->at(neighbor).isNode) // if right neighbor exists
				m_graphData->at(node).neighbors[UP_RIGHT_NEIGHBOR] = neighbor;
		}

		neighbor = node + (DOWN_LEFT_NEIGHBOR_FUCTOR_MIDDLE_TRY + numOfRow);
		if (isLigalNeighbor(neighbor, numOfRow + 1)) { // if not out of range on the left up
			if (m_graphData->at(neighbor).isNode) // if the left neighbor exists
				m_graphData->at(node).neighbors[DOWN_LEFT_NEIGHBOR] = neighbor;
		}

		neighbor = node + (DOWN_RIGHT_NEIGHBOR_FUCTOR_MIDDLE_TRY + numOfRow);
		if (isLigalNeighbor(neighbor, numOfRow + 1)) {//  if not out of range on right up
			if (m_graphData->at(neighbor).isNode) // if right neighbor exists
				m_graphData->at(node).neighbors[DOWN_RIGHT_NEIGHBOR] = neighbor;
		}
	}

	else if (numOfRow < m_map.getMapRowsSize() / 2) { // if on top triangle

		neighbor = node + (UP_LEFT_NIEGHBOR_FUCTOR_UP_TRY - numOfRow);
		if (isLigalNeighbor(neighbor, numOfRow - 1)) {//  if not out of range on up left
			if (m_graphData->at(neighbor).isNode) // if right neighbor exists
				m_graphData->at(node).neighbors[UP_LEFT_NEIGHBOR] = neighbor;
		}

		neighbor = node + (UP_RIGHT_NEIGHBOR_FUCTOR_UP_TRY - numOfRow);
		if (isLigalNeighbor(neighbor, numOfRow - 1)) {//  if not out of range on up right
			if (m_graphData->at(neighbor).isNode) // if buttom neighbor exists
				m_graphData->at(node).neighbors[UP_RIGHT_NEIGHBOR] = neighbor;
		}

		neighbor = node + (DOWN_LEFT_NEIGHBOR_FUCTOR_UP_TRY + numOfRow);
		if (isLigalNeighbor(neighbor, numOfRow + 1)) {//  if not out of range on down left
			if (m_graphData->at(neighbor).isNode) // if right neighbor exists
				m_graphData->at(node).neighbors[DOWN_LEFT_NEIGHBOR] = neighbor;
		}

		neighbor = node + (DOWN_RIGHT_NEIGHBOR_FUCTOR_UP_TRY + numOfRow);
		if (isLigalNeighbor(neighbor, numOfRow + 1)) {//  if not out of range on the button
			if (m_graphData->at(neighbor).isNode) // if button neighbor exists
				m_graphData->at(node).neighbors[DOWN_RIGHT_NEIGHBOR] = neighbor;
		}
	}

	else if (numOfRow >= m_map.getMapRowsSize() / 2) { // if on bottom triangle
		neighbor = node + (UP_LEFT_NIEGHBOR_FUCTOR_DOWN_TRY - (m_map.getMapRowsSize() - numOfRow - 2));

		if (isLigalNeighbor(neighbor, numOfRow - 1)) { // if not out of range on the left up
			if (m_graphData->at(neighbor).isNode) // if the left neighbor exists
				m_graphData->at(node).neighbors[UP_LEFT_NEIGHBOR] = neighbor;
		}

		neighbor = node + (UP_RIGHT_NEIGHBOR_FUCTOR_DOWN_TRY - (m_map.getMapRowsSize() - numOfRow - 2));
		if (isLigalNeighbor(neighbor, numOfRow - 1)) {//  if not out of range on right up
			if (m_graphData->at(neighbor).isNode) // if right neighbor exists
				m_graphData->at(node).neighbors[UP_RIGHT_NEIGHBOR] = neighbor;
		}

		neighbor = node + (DOWN_LEFT_NEIGHBOR_FUCTOR_DOWN_TRY + (m_map.getMapRowsSize() - numOfRow - 2));
		if (isLigalNeighbor(neighbor, numOfRow + 1)) {//  if not out of range on down left
			if (m_graphData->at(neighbor).isNode) // if right neighbor exists
				m_graphData->at(node).neighbors[DOWN_LEFT_NEIGHBOR] = neighbor;
		}

		neighbor = node + (DOWN_RIGHT_NEIGHBOR_FUCTOR_DOWN_TRY + (m_map.getMapRowsSize() - numOfRow - 2));
		if (isLigalNeighbor(neighbor, numOfRow + 1)) {//  if not out of range on the button
			if (m_graphData->at(neighbor).isNode) // if button neighbor exists
				m_graphData->at(node).neighbors[DOWN_RIGHT_NEIGHBOR] = neighbor;
		}
	}		
}

int Graph::findNumOfRow(int node)
{
	return m_map.getNumOfRow(node);
}

bool Graph::isLigalNeighbor(int cell, int row)
{
	if (row < 0) // if on first row - no neighbors on up rows
		return false;
	return m_map.isInRow(cell, row);
}

/*this function runs BFS algotithm from the items position to all the nodes in the graph - the unblocked
paths in the board, and sets the shortest path to each wanted item*/
void Graph::BFS(const sf::Vector2f & startNode)
{
	std::queue<int> queue; // for the queue used in the algorithm

	int node = m_map.convertCoordsToMapCellIndex(startNode);

	m_graphData->at(node).visited = true;

	queue.push(node); // enter start node first to the queue
	m_graphData->at(node).distance = 0;

	while (!queue.empty()) { // as long as nodes not checked for their neighbors

		int firstNode = queue.front(); // handle the first node in the queue.
		queue.pop(); // remove the first node from the queue 

		for (int i = 0; i < MAX_NEIGHBORS; ++i)
			// if neighbor exist and first visited the node
			if (m_graphData->at(firstNode).neighbors[i] != -1 &&
				!m_graphData->at(m_graphData->at(firstNode).neighbors[i]).visited) {
				m_graphData->at(m_graphData->at(firstNode).neighbors[i]).visited = true; // mark node as visited node
				// place coordinates in the predecessor node
				m_graphData->at(m_graphData->at(firstNode).neighbors[i]).predecessor = (convertNodeToSFCoords(firstNode));
				m_graphData->at(m_graphData->at(firstNode).neighbors[i]).distance = m_graphData->at(firstNode).distance + 1; // set discovered node distance
				queue.push(m_graphData->at(firstNode).neighbors[i]);
			}
	}
}

//*this function returns the next position for the iten on the shortest path that is needs*/
move_t Graph::getNextMove(const sf::Vector2f & currentPosition, move_t prevMov)
{
	int node = m_map.convertCoordsToMapCellIndex(currentPosition); // convert to a node on the graph

	sf::Vector2f predeccesorCoords = m_graphData->at(node).predecessor;

	// check move by comparing coords

	if (currentPosition.x > predeccesorCoords.x)
		if (currentPosition.y > predeccesorCoords.y) // if pred is found up left
			return up_left_mov;
		else
			return down_left_mov;
	else if (currentPosition.x < predeccesorCoords.x)
		if (currentPosition.y > predeccesorCoords.y) // if pred is found down left
			return up_right_mov;
		else
			return down_right_mov;
	return no_mov;
}
