#include "MenuController.h"
#include "GameResources.h"

MenuController::MenuController(sf::RenderWindow& window)
	:m_window(window), m_bgTexture(GameResources::instance().getMapBackgroundTexture())

{
	//button gets a texture and location and size
	m_buttons.push_back(std::make_unique<Button>(GameResources::instance().getStartButtonTexture(), sf::Vector2f({ 350.f ,550.f }), m_menuButtonSize));
	m_buttons.push_back(std::make_unique<Button>(GameResources::instance().getResumeButtonTexture(), sf::Vector2f({ 700.f ,550.f }), m_menuButtonSize));
	m_buttons.push_back(std::make_unique<Button>(GameResources::instance().getExitButtonTexture(), sf::Vector2f({ 1050.f ,550.f }), m_menuButtonSize));
}

choice_t MenuController::run()
{
	while (m_window.isOpen()) {
		m_window.clear();
		draw();
		m_window.display();


		sf::Event event;
		while (m_window.pollEvent(event))//every event do somthing
		{
			switch (event.type)//types of events
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				m_window.close();
				break;
			case sf::Event::MouseButtonPressed:
				choice_t choice = checkWhatIsPressed(m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));
				if (choice != NONE_BTN)
					return choice;
				break;
			}
		}
	}
	
	return NONE_BTN;
}

void MenuController::initBackground(sf::RenderWindow& window)
{
	m_rect->setSize(sf::Vector2f((float) window.getSize().x, (float) window.getSize().y));
	m_rect->setTexture(m_bgTexture);
}

void MenuController::draw()
{
	m_window.draw(*m_rect);
	for (auto& button : m_buttons)
		button->draw(m_window);
}

choice_t MenuController::checkWhatIsPressed(sf::Vector2f position)
{
	int size = (int) m_buttons.size();
	for (int i = 0; i < size; ++i)
		if (m_buttons[i]->isPressed(position))
			return static_cast<choice_t>(i);
	return NONE_BTN;
}
