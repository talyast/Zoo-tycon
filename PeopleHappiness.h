#pragma once
class PeopleHappiness
{
public:
	PeopleHappiness();
	~PeopleHappiness();
	// return the current money the user have
	double getCurrentHappiness() { return m_happiness; }
	void update(double amount) { m_happiness += amount; };
private:
	double m_happiness = 0;
};

