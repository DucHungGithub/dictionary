#include <SFML/Graphics.hpp>
#include "mainmenu.h"

int main()
{
	sf::Texture bgText;
	bgText.loadFromFile("dictionary.png");
	sf::RenderWindow window(sf::VideoMode(bgText.getSize().x,bgText.getSize().y), "Main menu", sf::Style::Default);
	mainMenu mainMenu(window.getSize().x, window.getSize().y);

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(960, 720));
	sf::Texture maintextture;
	maintextture.loadFromFile("background.jpg");
	background.setTexture(&maintextture);

	sf::RectangleShape pBackground;
	pBackground.setSize(sf::Vector2f(960, 720));
	sf::Texture back_textture;
	back_textture.loadFromFile("gamephoto.jpg");
	pBackground.setTexture(&back_textture);

	sf::RectangleShape oBackground;
	oBackground.setSize(sf::Vector2f(960, 720));
	sf::Texture opTiontexture;
	opTiontexture.loadFromFile("option.jpg");
	oBackground.setTexture(&opTiontexture);

	sf::RectangleShape aBackground;
	aBackground.setSize(sf::Vector2f(960, 720));
	sf::Texture aboutTextture;
	aboutTextture.loadFromFile("about.jpg");
	aBackground.setTexture(&aboutTextture);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					mainMenu.moveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					mainMenu.moveDown();
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					sf::RenderWindow Play(sf::VideoMode(960, 720), "game_name");
					sf::RenderWindow option(sf::VideoMode(960, 720), "options");
					sf::RenderWindow about(sf::VideoMode(960, 720), "about");

					int x = mainMenu.mainMenuPress();
					if (x == 0)
					{
						while (Play.isOpen())
						{

						}
					}
				}
			}
		}
	}
}