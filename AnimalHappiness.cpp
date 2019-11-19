#include "AnimalHappiness.h"



AnimalHappiness::AnimalHappiness()
{
}


AnimalHappiness::~AnimalHappiness()
{
}

void AnimalHappiness::update(double price)
{
	if (m_happiness <= 100)
		m_happiness = price;
}

