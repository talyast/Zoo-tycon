#pragma once
#include "Herbivor.h"



class Giraffe :
	public Herbivor
{
public:
	Giraffe();
	//virtual void move(float deltaTime) override;
	virtual void computeOffset(float deltaTime) override;
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


	static const std::string NAME;
	std::string getPrice() { return m_price; }
private:
	static bool m_registerIt;
	std::string m_price = "7000";
};

