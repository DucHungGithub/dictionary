#include <SFML/Graphics.hpp>
#include "mainmenu.h"
#include "button.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(500,500), "Main menu", sf::Style::Default);
	window.setFramerateLimit(60);
	
	Button nuthome("HOME",{200.f,200.f }, 30, sf::Color(37, 40, 57), sf::Color::White);
	nuthome.setPosition({ 200.f,150.f },30);
	sf::Font font;
	font.loadFromFile("font.ttf");
	nuthome.setFont(font);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();


		nuthome.drawTo(window);
		window.display();
	}
}