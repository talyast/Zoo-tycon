#pragma once
#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <string>

class MapItem
{
public:
	static const std::string NAME;
	virtual char getSymbol()const { return m_symbol; };
	virtual const sf::FloatRect& getGlobalBounds() const = 0;
	virtual void increaseZooMoney(int amount) {m_price +=amount; };
	virtual void decreaseZooMoney(int amount) { m_price-=amount; };
	virtual double getHappiness()const { return m_happiness; };
	virtual int getMoney();
	virtual void changeAnimation(size_t index);
	//virtual char updadeHappinees()const { return m_Happinees; };
	virtual const sf::Vector2f& getPosition() { return m_rect->getPosition(); }
	virtual void setPosition(sf::Vector2f) = 0;
	virtual std::string getPrice() = 0;
	//stop the animation until floatin item false
	virtual void stopAnimation();
	//start the animation
	virtual void startAnimation();
	virtual sf::Texture & changeTexture(unsigned) { return m_texture; }
	bool isOnMapCell(const sf::Vector2f& pos) { return m_rect->getGlobalBounds().contains(pos); }

protected:
	std::unique_ptr<sf::RectangleShape> m_rect = std::make_unique<sf::RectangleShape>();
	sf::FloatRect m_globalBounds;
	sf::Vector2f m_position;
	sf::Texture m_texture;
	char m_symbol;
	double m_happiness = 90;
	int m_price = 0;
	
private:
	Animation* m_animation; //need to move to dynamic

};

