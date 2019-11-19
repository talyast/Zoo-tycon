#include "DynamicItem.h"

const size_t ANIM_WALK_UP = 0;
const size_t ANIM_WALK_DOWN = 1;
const size_t ANIM_WALK_LEFT = 2;
const size_t ANIM_WALK_RIGHT = 3;

void DynamicItem::play(float deltaTime, sf::RenderWindow& window)
{
	m_multimedia[m_animationIdx].first->playAnimation(deltaTime, window);
	m_multimedia[m_animationIdx].second->playSound();
}

void DynamicItem::move(float deltaTime, Map& map, move_t move)
{
	switch (move) {
	case up_left_mov:
		m_action = ANIM_WALK_UP;
		computeOffset(deltaTime);
		break;
	case up_right_mov:
		m_action = ANIM_WALK_RIGHT;
		computeOffset(deltaTime);
		break;
	case down_right_mov:
		m_action = ANIM_WALK_LEFT;
		computeOffset(deltaTime);
		break;
	case down_left_mov:
		m_action = ANIM_WALK_DOWN;
		computeOffset(deltaTime);
		break;
	case no_mov:
		// no move
		if (m_timeAccumulator == 0.0f) {
			m_action = rand() % 2;
			for (int i = 0; i < 2; ++i) {
				m_action = (m_action + 1) % 2;
				computeOffset(deltaTime);
			}
		}
	}
	m_move = move;
	// attempt move if movment not on boarders of the map
	m_multimedia[m_animationIdx].first->move(m_offset);

	//m_multimedia[m_animationIdx].first->move(m_offset);
	if (!map.isOnMap(m_multimedia[m_animationIdx].first->getPosition()))
		m_multimedia[m_animationIdx].first->move(-m_offset);
	//m_dynamicAnimation->move(m_offset);
	m_timeAccumulator += deltaTime;
	if (m_timeAccumulator >= 5.0f)
		m_timeAccumulator = 0.0f;
}

void DynamicItem::computeOffset(float deltaTime)
{
	//m_action = 1;
	switch (m_action)
	{
	case ANIM_WALK_UP:
		walkAnimation();
		m_offset = { -getSpeed().y * deltaTime , -getSpeed().y * deltaTime };
		break;
	case ANIM_WALK_DOWN:
		walkDownAnimation();
		m_offset = { getSpeed().y * deltaTime , getSpeed().y * deltaTime };
		break;
	case ANIM_WALK_LEFT:
		walkLeftAnimation();
		m_offset = { -getSpeed().y * deltaTime , getSpeed().y * deltaTime };
		break;
	case ANIM_WALK_RIGHT:
		walkRightAnimation();
		m_offset = { -getSpeed().y * deltaTime , getSpeed().y * deltaTime };
	}
		/*break;
		walkRightAnimation();
		m_offset = { getSpeed().y * deltaTime , -getSpeed().y * deltaTime };
		break;
		/*
	case ANIM_EAT_FRONT:
		changeAnimation(ANIM_EAT_FRONT);
		break;
	case ANIM_EAT_BACK:
		changeAnimation(ANIM_EAT_BACK);
		break;
	case ANIM_REST_FRONT:
		changeAnimation(ANIM_REST_FRONT);
		break;
	case ANIM_REST_BACK:
		changeAnimation(ANIM_REST_BACK);
		break;
	case ANIM_STRACH:
		changeAnimation(ANIM_STRACH);
		break;
	case ANIM_STAND_UP_POSITION:
		changeAnimation(ANIM_STAND_UP_POSITION);
		break;
	case ANIM_STAND_DOWN_POSITION:
		changeAnimation(ANIM_STAND_DOWN_POSITION);
		break;*/
}


const sf::Vector2f& DynamicItem::getPosition()
{
	return m_multimedia[m_animationIdx].first->getPosition();
}

const sf::FloatRect& DynamicItem::getGlobalBounds() const
{
	return m_multimedia[m_animationIdx].first->getGlobalBounds();

}

void DynamicItem::changeAnimation(size_t index)
{
	m_multimedia[index].first->setPosition(m_multimedia[m_animationIdx].first->getPosition());
	m_animationIdx = index;
}

//bool DynamicItem::isPressed(const sf::Vector2f & pos)
//{
//	return m_multimedia[m_animationIdx].first->getGlobalBounds().contains(pos);
//	//return false;
//}

void DynamicItem::stopAnimation()
{
	m_multimedia[m_animationIdx].first->pause();

}

void DynamicItem::startAnimation()
{
	m_multimedia[m_animationIdx].first->unPause();

}

void DynamicItem::setPosition(sf::Vector2f position)
{
	m_multimedia[m_animationIdx].first->setPosition(position);
	m_position = position;
}
void DynamicItem::increaseHappiness(double amount)
{
	if (m_happiness <= 100)
		m_happiness += amount;
}

void DynamicItem::changeScale()
{
	m_multimedia[m_animationIdx].first->changeScale();
}

void DynamicItem::setDefaultScale()
{
	m_multimedia[m_animationIdx].first->setDefaultScale();
}

void DynamicItem::changePeopleScale()
{
	m_rect->setScale(1.0f, -1.0);
}
