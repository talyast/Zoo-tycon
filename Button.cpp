#include "Button.h"



Button::Button(sf::Texture * texture, const sf::Vector2f& location, const sf::Vector2f& size)
{
	m_rectShape.setTexture(texture);
	m_rectShape.setPosition(location);
	m_rectShape.setSize(size);
	m_rectShape.setOutlineColor(sf::Color::Transparent);
	m_rectShape.setOutlineThickness(1);

}

void Button::draw(sf::RenderWindow &window)
{

	window.draw(m_rectShape);

}

bool Button::isPressed(const sf::Vector2f & position)
{
	return m_rectShape.getGlobalBounds().contains(position);

}
