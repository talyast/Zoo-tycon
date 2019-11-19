#pragma once
#include "Predator.h"



class PollarBear :
	public Predator
{
public:
	PollarBear();
	static const std::string NAME;
	//virtual void move(float deltaTime) override;
	virtual void computeOffset(float deltaTime) override;
	std::string getPrice() { return m_price; }

	//animate the animals
	virtual void walkAnimation() override;
	virtual void walkDownAnimation() override;
	virtual void walkLeftAnimation() override;
	virtual void walkRightAnimation() override;
	virtual void eatAnimation() override;
	virtual void eatBackAnimation() override;
	virtual void runAnimation() override;
	virtual void runDownAnimation() override;
	virtual void standFrontAnimation() override;
	virtual void standBackAnimation() override;
	virtual void specialAnimation() override;

private:
	static bool m_registerIt;
	std::string m_price="15000";
};

