#pragma once
#include "Predator.h"
//#include "TextBox.h"
// animation indexes




class Lion :
	public Predator

{
public:


	Lion();

	virtual void computeOffset(float deltaTime) override;
	std::string getPrice() { return m_price; }

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
	std::string m_price = "13500";
	//char m_symbol = 'l';
	//TextBox text;
};

