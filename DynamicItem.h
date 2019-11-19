#pragma once
#include "MapItem.h"
#include "DynamicItemAnimation.h"
#include "Sound.h"
#include "Map.h"
#include "consts.h"


class DynamicItem : public MapItem
{
public:
	void stopAnimation();
	void startAnimation();
	virtual void setPosition(sf::Vector2f position) override;
	void play(float deltaTime, sf::RenderWindow & window);
	virtual void move(float deltaTime, Map& map, move_t move);
	virtual void computeOffset(float deltaTime) = 0;
	void setSpeed(const sf::Vector2f & speed) { m_speed = speed; } //set speed to dynamic object
	sf::Vector2f getSpeed() { return m_speed; } //return the object speed
	virtual const sf::Vector2f& getPosition();
	virtual const sf::FloatRect& getGlobalBounds()  const override ;
	virtual void changeAnimation(size_t index) override;
	virtual void increaseHappiness(double amount);
	virtual void decreaseHappiness(double amount) { m_happiness -= amount; }
	//bool isPressed(const sf::Vector2f& pos);//{ return m_rect->getGlobalBounds().contains(pos); }
	virtual move_t getLastMove() const { return m_move; }
protected:

	//animate the animals
	virtual void walkAnimation() =0;
	virtual void walkDownAnimation() = 0;
	virtual void walkLeftAnimation() = 0;
	virtual void walkRightAnimation() = 0;
	virtual void eatAnimation() = 0;
	virtual void eatBackAnimation() = 0;
	virtual void runAnimation() = 0;
	virtual void runDownAnimation() = 0;
	virtual void standFrontAnimation() =0;
	virtual void standBackAnimation() =0;
	virtual void specialAnimation() = 0;
	//change the scale to do mirror animation
	void changeScale();
	void setDefaultScale();
	virtual void changePeopleScale();

	//which
	size_t m_action;
	sf::Vector2f m_offset;
	move_t m_move = no_mov;
	DynamicItemAnimation& getAnimation(unsigned int index) { return *m_multimedia[index].first; }
	void addAnimationAndSound(std::unique_ptr<DynamicItemAnimation> animation , std::unique_ptr<Sound> sound) { m_multimedia.emplace_back(std::make_pair(std::move(animation),std::move(sound))); }
	
	//virtual void attempMove(DynamicItemAnimation* animation, const sf::Vector2f& offset);
private:
	typedef std::pair<std::unique_ptr<DynamicItemAnimation>, std::unique_ptr<Sound>> multimedia;
	std::vector<multimedia> m_multimedia;
	std::unique_ptr< DynamicItemAnimation> m_dynamicAnimation = std::make_unique< DynamicItemAnimation>();
	std::unique_ptr<Sound> m_sound = std::make_unique <Sound>();
	//dynamic item speed
	sf::Vector2f m_speed = { 5.0f,5.0f };
	//for chose animation
	size_t m_animationIdx;
	float m_timeAccumulator = 0.0f;
};

