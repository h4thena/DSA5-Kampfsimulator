//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#define SIZE_X 1280
#define SIZE_Y SIZE_X / 16 * 9
#define FULLSCREEN Default // Fullscreen | Default

#include <SFML/Graphics.hpp>
#include <string>
#include "Entity.h"
#include <iostream>

unsigned battlefieldSize = 12;

void mouseclick(bool right, unsigned int x, unsigned int y) {

}

void renderInfo(sf::RenderWindow &window) {
	sf::RectangleShape rectangle(sf::Vector2f((float)(SIZE_X - SIZE_Y), (float)SIZE_Y));
	rectangle.setPosition(0, 0);
	rectangle.setFillColor(sf::Color::White);
	window.draw(rectangle);
}

void renderBattlefield(sf::RenderWindow &window) {
	sf::RectangleShape rectangle(sf::Vector2f((float)SIZE_Y / battlefieldSize - 2.f, (float)SIZE_Y / battlefieldSize - 2.f));
	rectangle.setFillColor(sf::Color::Green);
	for (unsigned int i = 0, j; i < battlefieldSize; i++) {
		for (j = 0; j < battlefieldSize; j++) {
			rectangle.setPosition((float)(SIZE_X - SIZE_Y) + 1.f + i*((float)SIZE_Y / battlefieldSize), 1.f + j*((float)SIZE_Y / battlefieldSize));
			window.draw(rectangle);
		}
	}
}

int main() {
	srand((unsigned int)time(NULL));


	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;
	sf::RenderWindow window(sf::VideoMode(SIZE_X, SIZE_Y), "DSA5 Kampfsimulator", sf::Style::FULLSCREEN, settings);
	window.setFramerateLimit(10);

	window.clear(sf::Color::Black);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					mouseclick(false, event.mouseButton.x, event.mouseButton.y);
				}
				else if (event.mouseButton.button == sf::Mouse::Right) {
					mouseclick(true, event.mouseButton.x, event.mouseButton.y);
				}
			}
		}

		renderInfo(window);
		renderBattlefield(window);
		window.display();
	}

	return 0;
}