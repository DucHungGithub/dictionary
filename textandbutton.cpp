#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "textbox.h"
#include "button.h"
#include "edit_defination.h"

int main()
{
	/*sf::RenderWindow window(sf::VideoMode(500, 500), "Tutorial", sf::Style::Default);
	window.setFramerateLimit(60);

	Textbox textbox(15, sf::Color::Blue, false);
	sf::Font font;
	font.loadFromFile("font.ttf");
	textbox.setFont(font);
	textbox.setPosition({100,100});
	textbox.setLimit1(true, 10);

	Button add_button("HELLO", { 100.f,100.f }, 20, sf::Color(167, 255, 215), sf::Color::Black);
	add_button.setoutline(sf::Color(191, 189, 234));
	add_button.setPosition({ 100.f,100.f }, 20);
	add_button.setFont(font);
	
	while (window.isOpen())
	{
		sf::Event event;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			textbox.setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			textbox.setSelected(false);
		}
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::TextEntered:
				textbox.typeOn(event);
				break;
			default:
				break;
			}
		}

		window.clear();
		textbox.drawTo(window);
		add_button.drawTo(window);
		window.display();*/
	sf::Font font;
	font.loadFromFile("font.ttf");
	addingWordScreen(font);
}