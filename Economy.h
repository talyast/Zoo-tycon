#pragma once
class Economy
{
public:
	Economy();
	~Economy();
	// return the current money the user have
	int getCurrentMoney() { return m_money; }
	// update the current money 
	void increaseMoney(int price) { m_money+= price; };
	void decreaseMoney(int price) { m_money -= price; };
	//emplaces the money
	void changeMoney(int amount) { m_money = amount; };
private:
	int m_money = 150000;
};

