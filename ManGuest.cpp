#include "ManGuest.h"
#include "Factory.h"
const char symbol = 'M';
const std::string ManGuest::NAME = "ManGuest";
bool ManGuest::m_registerIt = Factory::registerGuest(NAME, []() -> std::unique_ptr<Guest> { return std::make_unique<ManGuest>(); });



ManGuest::ManGuest()
{
	m_symbol = symbol;
}


ManGuest::~ManGuest()
{
}

void ManGuest::computeOffset(float deltaTime)
{
}

void ManGuest::walkAnimation()
{
}

void ManGuest::walkDownAnimation()
{
}

void ManGuest::walkLeftAnimation()
{
}

void ManGuest::walkRightAnimation()
{
}

void ManGuest::eatAnimation()
{
}

void ManGuest::eatBackAnimation()
{
}

void ManGuest::runAnimation()
{
}

void ManGuest::runDownAnimation()
{
}
void ManGuest::standFrontAnimation()
{
}

void ManGuest::standBackAnimation()
{
}

void ManGuest::specialAnimation()
{
}
