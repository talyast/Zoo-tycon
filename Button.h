#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
class Button
{
public:
	Button(sf::Texture *texture, const sf::Vector2f& location, const sf::Vector2f& size);

	void draw(sf::RenderWindow & window);
	bool isPressed(const sf::Vector2f & position);
private:
	//
	sf::RectangleShape m_rectShape;
};