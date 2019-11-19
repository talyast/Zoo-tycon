#include "Controller.h"
#include "MenuController.h"
#include "GameController.h"
#include "Game.h"

// run the game. this is the main run function and the only one called from main.
// when this function returns, the program shuts down.
void Controller::run()
{
	srand((unsigned)time(nullptr));
	choice_t menuChoice;
	
	// create the window and set the frame rate limit
	m_window->create(sf::VideoMode(1600, 700), "Zoo Tycoon"/*, sf::Style::Fullscreen*/);
	m_window->setVerticalSyncEnabled(true);
	
	m_bgMenuSound->playSound();
	m_menuController->initBackground(*m_window);

	while (m_window->isOpen()) {

		// display the menu and get the selected action

		menuChoice = m_menuController->run();

		// perform the selected action
		switch (menuChoice) {
		case START_BTN:
			
			break;
		case LOAD_BTN:
			m_gameController->loadAGame();
			menuChoice = START_BTN;
			break;
		case EXIT_BTN:
			m_window->close();
			break;
		}
		m_bgMenuSound->stop();
		// play the game
		m_gameController->play();
	}
	m_window->close();
}