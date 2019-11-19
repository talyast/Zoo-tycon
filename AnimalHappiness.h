#pragma once
class AnimalHappiness
{
public:
	AnimalHappiness();
	~AnimalHappiness();
	// return the current money the user have
	int getCurrentHappiness() { return (int)m_happiness; }
	// update the current money 
	void update(double price);
private:
	//happiness of all animals
	double m_happiness = 0;
};

