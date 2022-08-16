#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define Max_main_menu 4
class mainMenu
{
public:
	mainMenu(float width, float height)
	{
		if (!font.loadFromFile("font.ttf"))
			std::cout << "No font find" << std::endl;

		//Play
		mainmenu[0].setFont(font);
		mainmenu[0].setFillColor(sf::Color::White);
		mainmenu[0].setString("Play");
		mainmenu[0].setCharacterSize(70);
		mainmenu[0].setPosition(400, 200);
		


		//Options
		mainmenu[1].setFont(font);
		mainmenu[1].setFillColor(sf::Color::White);
		mainmenu[1].setString("Options");
		mainmenu[1].setCharacterSize(70);
		mainmenu[1].setPosition(400, 300);

		//About
		mainmenu[2].setFont(font);
		mainmenu[2].setFillColor(sf::Color::White);
		mainmenu[2].setString("About");
		mainmenu[2].setCharacterSize(70);
		mainmenu[2].setPosition(400, 400);


		//Exit
		mainmenu[3].setFont(font);
		mainmenu[3].setFillColor(sf::Color::White);
		mainmenu[3].setString("Exit");
		mainmenu[3].setCharacterSize(70);
		mainmenu[3].setPosition(400, 500);

	}

	void draw(sf::RenderWindow& window)
	{
		for (int i = 0; i < Max_main_menu; i++)
		{
			window.draw(mainmenu[i]);
		}
	}
	void moveUp()
	{
		if (mainMenuSelected - 1 >= 0)
		{
			mainmenu[mainMenuSelected].setFillColor(sf::Color::White);

			mainMenuSelected--;
			if (mainMenuSelected == -1)
			{
				mainMenuSelected = 3;
			}
			mainmenu[mainMenuSelected].setFillColor(sf::Color::Blue);
		}
	}
	void moveDown()
	{
		if (mainMenuSelected +1<= Max_main_menu)
		{
			mainmenu[mainMenuSelected].setFillColor(sf::Color::White);
			mainMenuSelected++;
			if (mainMenuSelected == 4)
			{
				mainMenuSelected = 0;
			}
			mainmenu[mainMenuSelected].setFillColor(sf::Color::Blue);
		}
	}

	int mainMenuPress()
	{

		return mainMenuSelected;
	}
	~mainMenu();

private:
	int mainMenuSelected;
	sf::Font font;
	sf::Text mainmenu[Max_main_menu];
};

