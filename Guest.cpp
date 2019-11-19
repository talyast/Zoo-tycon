#include "Guest.h"

Guest::Guest()
{
	m_stayingTime= randomTime();
}

Guest::~Guest()
{
}

const sf::FloatRect & Guest::getGlobalBounds() const
{
	sf::FloatRect n ={};
	return n;
	// TODO: insert return statement here
}

std::string Guest::getPrice()
{
	return std::string();
}

void Guest::setStartingTime(float deltaTime)
{
	m_startTime = deltaTime;
}

void Guest::checkIfTimeToLeave(float gameTime)
{
	if (m_happiness < 60 || m_startTime + m_stayingTime < gameTime)
		exitZoo();

	
}
void Guest::changePeopleScale()
{
	DynamicItem::changePeopleScale();
}
//at the end of this function we need to take this guest out of the vector
void Guest::exitZoo()
{
}


float Guest::randomTime()
{
	int time = rand() % 3;
	switch (time)
	{
	case 0:
		time= 100;
		break;
	case 1:
		time = 200;
		break;
	case 2:
		time = 300;
		break;
	default:
		break;
	}
	return (float)time;
}
