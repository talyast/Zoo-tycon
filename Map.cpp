#include "Map.h"
#include "GameResources.h"
#include "wintools.h"
#include "Terrain.h"
#include "Factory.h"
#include <string>
#include <fstream>
#include "Grass.h"
#include <iostream>


const float TOP_OFFSET = 6.0f;
const float HORIZONTAL_CORNER_VERTICAL_OFFSET = 3.0f;
const float VERTICAL_TEXTURE_OFFSET = 4.0f;

Map::Map(unsigned rows, sf::RenderWindow& window)
	:m_window(window), m_rows(rows)
{
	m_gate->setTexture(*GameResources::instance().getGateTexture());
	m_gate->setPosition(sf::Vector2f(-905, 1005));

	if (rows % 2 != 0)
		throw OddNumberOfRowsForMap();

	sf::Texture* grassTexture = GameResources::instance().getGrassTexture(); 
	sf::Vector2f position{ 0.0f, 0.0f };
	m_mapColWidth = grassTexture->getSize().x / 2;
	m_mapRowHeight = grassTexture->getSize().y / 2;

	// map corners are needed for position in/out of map checking
	m_topCorner = position;
	m_topCorner.x += m_mapColWidth;
	m_topCorner.y += TOP_OFFSET;

	int numOfCells = 0;
	unsigned row = 0;

	// create top triangle of the map
	for (; row < rows / 2; ++row) {

		if (row == rows / 2 - 1) {
			// save the position of the left corner of the map
			m_leftCorner = position;
			m_leftCorner.y += m_mapRowHeight + HORIZONTAL_CORNER_VERTICAL_OFFSET;
		}
		m_mapInfo.push_back(std::make_pair(numOfCells, 0));
		m_mapInfo[row].first = numOfCells; // min value in row
		for (unsigned col = 0; col <= row; ++col) {
			addSprite(grassTexture, position, col);
			numOfCells++;
		}

		m_mapInfo[row].second = numOfCells - 1; // max value in row
		if (row == rows / 2 - 1) {
			// save the position of the right corner of the map
			m_rightCorner = position;
			m_rightCorner.x += m_mapColWidth * (row + 1);
			m_rightCorner.y += m_mapRowHeight + HORIZONTAL_CORNER_VERTICAL_OFFSET;
		}

		// texture size is 64x40 and because of transparent spaces need 4 less pixels in the y axis
		position.x -= m_mapColWidth;
		position.y += m_mapRowHeight - VERTICAL_TEXTURE_OFFSET;
	}

	position.x += grassTexture->getSize().x;

	for (unsigned reduce = 1; row < rows; ++row, reduce += 2) {
		m_mapInfo.push_back(std::make_pair(numOfCells, 0));
		m_mapInfo[row].first = numOfCells; // min value in row
		for (unsigned col = 0; col < row - reduce; ++col) {
			addSprite(grassTexture, position, col);
			numOfCells++;
		}
		m_mapInfo[row].second = numOfCells - 1; // max value in row
		position.x += m_mapColWidth;
		position.y += m_mapRowHeight - VERTICAL_TEXTURE_OFFSET;
	}

	// save the position of the bottom corner of the map
	m_bottomCorner = position;
	m_bottomCorner.x -= m_mapColWidth;
	m_bottomCorner.y += TOP_OFFSET;

	setMapBorders();
	createBorderNormalVectors();
	m_mapInfo.resize(m_mapInfo.size() - 1);
}

void Map::createBorderNormalVectors()
{
	sf::Vector2f topRightVector, topLeftVector, bottomLeftVector, bottomRightVector;
	topRightVector = m_mapBorder.getPoint(1) - m_mapBorder.getPoint(0);
	topLeftVector = m_mapBorder.getPoint(3) - m_mapBorder.getPoint(0);
	bottomLeftVector = m_mapBorder.getPoint(3) - m_mapBorder.getPoint(2);
	bottomRightVector = m_mapBorder.getPoint(1) - m_mapBorder.getPoint(2);
	m_topRightNormal = { topRightVector.y, -topRightVector.x };
	m_topLeftNormal = { -topLeftVector.y, topLeftVector.x };
	m_bottomRightNormal = { -bottomRightVector.y, bottomRightVector.x };
	m_bottomLeftNormal = { bottomLeftVector.y, -bottomLeftVector.x };
}

void Map::addSprite(const sf::Texture * grassTexture, sf::Vector2f &position, unsigned int col)
{
	m_grassMap.emplace_back(Factory::createGrass("Grass"));
	m_grassMap.back()->setPosition({ position.x + col * grassTexture->getSize().x, position.y });
}

void Map::draw()
{
	for (auto& tile : m_grassMap)
		tile->draw(m_window);
	m_window.draw(*m_gate);
}

int Map::offsetFor(int row, int col) const
{
	unsigned int offset;
	if (row < m_rows / 2)
		offset = triangularN(row) + col;
	else
		offset = 2 * triangularN(m_rows / 2) - (m_rows / 2) - triangularN(m_rows - 1 - row) + col;
	return offset;
}

void Map::setMapBorders()
{
	sf::ConvexShape mapBorder(4);

	mapBorder.setPoint(0, sf::Vector2f(-2, -7));
	mapBorder.setPoint(1, sf::Vector2f(1568, 782));
	mapBorder.setPoint(2, sf::Vector2f(-2, 1560));
	mapBorder.setPoint(3, sf::Vector2f(-1578, 782));

	m_mapBorder = mapBorder;
}

const std::unique_ptr<Grass>& Map::getItemAt(unsigned int row, unsigned int col) const
{
	return m_grassMap[offsetFor(row, col)];
}

bool Map::isOnMap(const sf::Vector2f & position) const
{
	sf::Vector2f topPos, bottomPos;
	topPos = position - m_topCorner;
	bottomPos = position - m_bottomCorner;
	bool inTopRight, inTopLeft, inBottomRight, inBottomLeft;
	inTopRight = topPos * m_topRightNormal < 0.0f;
	inTopLeft = topPos * m_topLeftNormal < 0.0f;
	inBottomRight = bottomPos * m_bottomLeftNormal < 0.0f;
	inBottomLeft = bottomPos * m_bottomRightNormal < 0.0f;
	return inTopRight && inTopLeft && inBottomRight && inBottomLeft;
}

void Map::saveMap(std::ofstream & file) const
{
	for (int i = 0; i < m_grassMap.size(); ++i)
		file << "map" << " " << m_grassMap[i]->getSymbol() << " " << m_grassMap[i]->getPosition().x
		<< " " << m_grassMap[i]->getPosition().y << std::endl;
}

void Map::loadMap(char symbol, std::string x, std::string y)
{
	std::string::size_type sz;     // alias of size_t

	sf::Vector2f position(std::stof(x, &sz), std::stof(y, &sz));

	m_grassMap.emplace_back(Factory::createGrass("Grass"));
	m_grassMap.back()->setPosition(position);
}

unsigned Map::convertCoordsToMapCellIndex(const sf::Vector2f & position)
{
	for (int i = 0; i < m_grassMap.size(); ++i) {
		if (m_grassMap[i]->isOnMapCell(sf::Vector2f( position.x, position.y)))
			return i;
	}
	return 0;
}

const sf::Vector2f& Map::convertNodeToSFCoordsMap(int node) const 
{
	return m_grassMap[node]->getPosition();
}

unsigned Map::getMapRowsSize() const
{
	return m_rows;
}

int Map::getNumOfRow(int cell)
{
	// seclude row zero from calculation
	for (int i = 0; i < m_mapInfo.size(); ++i)
		// if cell is in the range of the cell
		if (cell >= m_mapInfo[i].first && cell <= m_mapInfo[i].second)
			return i;
	//if (cell == 0)
	//	return 0;
	//int sumCells = 0;
	//for (int i = 0; i < m_numberOfColsInMapRows.size(); ++i) {
	//	sumCells += m_numberOfColsInMapRows[i];
	//	if (cell < sumCells)
	//		return i;
	//}
}

bool Map::isInRow(int cell, int row)
{
	if (row < 0 || row > m_mapInfo.size() - 1)
		return false;
	return (cell >= m_mapInfo[row].first && cell <= m_mapInfo[row].second);
}

double operator*(const sf::Vector2f & left, const sf::Vector2f & right)
{
	return (double) left.x * (double) right.x + (double) left.y * (double) right.y;
}
