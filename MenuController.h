#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Sound.h"
#include "GameResources.h"

enum choice_t { START_BTN, LOAD_BTN, EXIT_BTN, NONE_BTN };

// control the menu window and logic
class MenuController
{
public:
	MenuController(sf::RenderWindow& window);
	void initBackground(sf::RenderWindow& window); // init backgroung sprite and texture
	choice_t run();

private:
	sf::RenderWindow& m_window;
	std::vector<std::unique_ptr<Button>> m_buttons;

	void draw();
	//check which buttom was pressed
	choice_t checkWhatIsPressed(sf::Vector2f coords);
	const sf::Vector2f m_menuButtonSize = { 175, 70 };

	// board background texture. will display on repeat
	std::unique_ptr<sf::RectangleShape> m_rect = std::make_unique<sf::RectangleShape>();
	//menu sound

	sf::Texture* m_bgTexture;
	// board background sprite
};

