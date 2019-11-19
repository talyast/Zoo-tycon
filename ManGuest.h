#pragma once
#include "Guest.h"
class ManGuest :
	public Guest
{
public:
	static const std::string NAME;
	ManGuest();
	~ManGuest();

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


private:
	static bool m_registerIt;
};

