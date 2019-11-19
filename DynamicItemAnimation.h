#pragma once
#include <sfml/graphics.hpp>
#include "Animation.h"

class DynamicItemAnimation
	: public Animation
{
public:
	//using C-tor animation
	using::Animation::Animation;
	//play the animation
	virtual void playAnimation(float deltaTime, sf::RenderWindow& window) override;
	void changeScale();
	void setDefaultScale();
	//move the object with animation
	 void move(const sf::Vector2f& offset) { (m_rectShape.move(offset));};
protected:

private:
	//for reverse animation
	bool m_reverse = false;
protected:
	int m_happiness;
};

