#include "DynamicItemAnimation.h"


const int DEFAULT_POSITION = 0;

void DynamicItemAnimation::playAnimation(float deltaTime, sf::RenderWindow& window)
{

	m_totalTime += deltaTime; //calculate how much time pass
	if (m_totalTime >= m_switchTime && !m_pause)
	{
		m_totalTime -= m_switchTime;
		if (!m_reverse)
			m_currentImage.x++; //replace picture
		else
			m_currentImage.x--;

		if (!m_loopAnimation) { //keep on image range
			if (m_currentImage.x == m_imageRange.y)
				m_reverse = true;

			if (m_currentImage.x <= m_imageRange.x) {
				m_currentImage.x = DEFAULT_POSITION;
				m_reverse = false;
			}
		}
		else if (m_currentImage.x > m_imageRange.y)
			m_currentImage.x = m_imageRange.x;


	}
	m_intRect.left = m_currentImage.x * m_intRect.width;
	m_intRect.top = m_currentImage.y * m_intRect.height;
	Animation::playAnimation(deltaTime, window);
}

void DynamicItemAnimation::changeScale()
{
	m_rectShape.setScale(-1.0, 1.0);
}

void DynamicItemAnimation::setDefaultScale()
{
	m_rectShape.setScale(1.0f, 1.0f);
}
