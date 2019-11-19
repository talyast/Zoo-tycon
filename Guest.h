#pragma once
#include "DynamicItem.h"
class Guest : public DynamicItem
{
public:
	using DynamicItem::DynamicItem;
	virtual const sf::FloatRect& getGlobalBounds() const override;
	//virtual void setPosition(sf::Vector2f &) override;
	virtual std::string getPrice()override;
	void addSumPeople(int number) { m_sumPeople += number; };
	void setStartingTime(float deltaTime);
	void checkIfTimeToLeave(float deltaTime);
	virtual void changePeopleScale() override;
	void exitZoo();
	Guest();
	~Guest();
protected:
	float m_stayingTime;
	float m_startTime;
private:
	int m_sumPeople = 0;
	float randomTime();
	
};

