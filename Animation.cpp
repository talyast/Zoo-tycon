#include "Animation.h"


Animation::Animation()
{
}
//animation C-tor
Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount,
	sf::Vector2u imageRange, bool loop, sf::Vector2f imageSize , float switchTime)
	:m_imageCount(imageCount), m_switchTime(switchTime), m_rectShape(imageSize)
	, m_imageRange(imageRange), m_loopAnimation(loop) 
{
	init(texture);
}

//this function inittializes all the texture data
void Animation::init(sf::Texture* texture)
{
	m_intRect.width = texture->getSize().x / m_imageCount.x;
	m_intRect.height = texture->getSize().y / m_imageCount.y;
	texture->setSmooth(true);
	m_rectShape.setTexture(texture);
	m_rectShape.setPosition(m_position);
	m_currentImage.x = m_imageRange.x;
	m_rectShape.setOrigin({ m_rectShape.getSize().x / 2.0f, m_rectShape.getSize().y / 2.0f });
}
//draw the animation
void Animation::playAnimation(float deltaTime, sf::RenderWindow& window)
{
	m_rectShape.setTextureRect(m_intRect);
	window.draw(m_rectShape);
}
//set the animation position
void Animation::setPosition(const sf::Vector2f& position)
{
	m_rectShape.setPosition(position);
}
//get the animation position
const sf::Vector2f & Animation::getPosition() 
{
	return m_rectShape.getPosition();
}
//get the global bounds for collision 
const sf::FloatRect & Animation::getGlobalBounds() const
{
	return m_rectShape.getGlobalBounds();
}
const sf::Vector2f& Animation::getOrigin() const
{
	return m_rectShape.getOrigin();
}
//pause
void Animation::pause()
{
	m_pause = true;
}
//unpause
void Animation::unPause()
{
	m_pause = false;
	m_totalTime = 0.0f;
}

void Animation::changeScale()
{
	m_rectShape.setScale(-1.0f, 1.0f);
}

void Animation::setDefaultScale()
{
	m_rectShape.setScale(1.0f, 1.0f);

}
