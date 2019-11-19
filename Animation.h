#pragma once
#include <SFML/Graphics.hpp>

const int IDLE_POS = 1; //idle position
const float SWITCH_TIME_DEFAULT = 0.2f;

class Animation
{
public:

	Animation();
	//constructor that build the animation only without postion
	Animation(sf::Texture* texture, sf::Vector2u imageCount,
		sf::Vector2u imageRange, bool loop,	sf::Vector2f imageSize , float switchTime = SWITCH_TIME_DEFAULT);
	//initialize the texture
	void init(sf::Texture* texture);
	//this function play the animation
	virtual void playAnimation(float deltaTime, sf::RenderWindow& window);
	//set the animation position
	void setPosition(const sf::Vector2f& position);
	//return the position
	const sf::Vector2f& getPosition();
	const sf::FloatRect& getGlobalBounds() const;
	const sf::Vector2f& getOrigin() const;
	//pause and unpause the animation
	virtual void pause();
	virtual void unPause();

	//change the scale to do mirror animation
	virtual void changeScale();
	//set degault scale
	virtual void setDefaultScale();

protected:

	sf::IntRect m_intRect;
	sf::RectangleShape m_rectShape;
	sf::RectangleShape m_centerShape;
	sf::Vector2u m_imageCount; //store how much pictures we have in a row and col 
	sf::Vector2u m_currentImage;
	sf::Vector2f m_position;
	sf::Vector2u m_imageRange;
	float m_totalTime = 0.0f;
	float m_switchTime = 0.9f;  //this member control the speed of the 

	bool m_pause = false;
	bool m_loopAnimation = true;
	//move_t m_dir = no_mov;
};

