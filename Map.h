#pragma once
#include<SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include "MapItem.h"
#include "Grass.h"

class OddNumberOfRowsForMap : std::exception {
public:
	const char* what() const noexcept override {
		return "Map must have an even number of rows";
	}
};

class Map
{
public:
	Map(unsigned rows, sf::RenderWindow& window);
	void draw();

	bool isOnMap(const sf::Vector2f& position) const;
	// save the grass map
	void saveMap(std::ofstream & file)const ;
	// load grass to the map
	void loadMap(char symbol, std::string x, std::string y);
	// used to map a board cell (x, y coordinates) into an index in an array with
	// size same as number of cells in the board
	unsigned convertCoordsToMapCellIndex(const sf::Vector2f& position);
	const sf::Vector2f& convertNodeToSFCoordsMap(int node) const ;

	unsigned getMapRowsSize() const;
	int getMapLastCellIndex() const { return m_lastCellIndex; }
	// find number of line in the map of the requested cell
	int getNumOfRow(int cell);
	// check if requested cell is in the sent row
	bool isInRow(int cell, int row);

private:
	void addSprite(const sf::Texture * grassTexture, sf::Vector2f &position, unsigned int col);
	static int triangularN(int n) { return (n * (n + 1)) / 2; }
	void createBorderNormalVectors();
	int offsetFor(int row, int col) const;
	// set map borders in convex shape that holds the positions of the corners
	void setMapBorders();
	const std::unique_ptr<Grass>& getItemAt(unsigned int row, unsigned int col) const;

	std::vector<std::unique_ptr<Grass>> m_grassMap;

	sf::RenderWindow& m_window;
	sf::Vector2f m_topCorner, m_bottomCorner, m_rightCorner, m_leftCorner;
	sf::Vector2f m_topRightNormal, m_bottomLeftNormal, m_topLeftNormal, m_bottomRightNormal;
	unsigned m_rows;
	int m_lastCellIndex = 2499;

	// hold map information for conberting pixels to cell on the map
	size_t m_mapRowHeight;
	size_t m_mapColWidth;
	// hold map information for conberting pixels to cell on the ma
	sf::ConvexShape m_mapBorder;
	// save map information - what is the range of the cell numbers in each row of the map
	std::vector<std::pair<int, int>> m_mapInfo;
	std::unique_ptr<sf::Sprite> m_gate = std::make_unique<sf::Sprite>();
};

double operator*(const sf::Vector2f& left, const sf::Vector2f& right);
