#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "button.h"
#include "textbox.h"
#include "random4.h"
#include "switch_dataset.h"
int main()
{
	sf::Texture ttPlay;
	sf::Font font;
	sf::Texture anhkhung;
	sf::Texture anhKey;
	font.loadFromFile("font.ttf");
	ttPlay.loadFromFile("playgame.png");
	anhkhung.loadFromFile("anh1.png");
	anhKey.loadFromFile("anh2.png");
	sf::Sprite sPlay;
	sPlay.setTexture(ttPlay);

	sf::RenderWindow windowPlay(sf::VideoMode(ttPlay.getSize().x, ttPlay.getSize().y), "PLAY", sf::Style::Default);

	
	
	//Khung key
	Button khungKey("", { 400.f,90.f }, 22, sf::Color(255, 214, 130), sf::Color::Black);
	khungKey.setFont(font);
	khungKey.settextture(anhKey);
	khungKey.setPosition({ 428.f,210.f }, 25, -22.f);

	TrieNode* rootEnglish = nullptr;
	TrieNode* rootVietNam = nullptr;
	build_data(rootEnglish, rootVietNam);
	std::string key;
	std::string meaning;
	std::vector<std::string> hello;
	vector < std::string > checkdapan{ 4 };
	//Khung dap an
	std::vector<Button> khungDapAn;
	khungDapAn.resize(4);
	for (int i = 0; i < 4; i++)
	{
		khungDapAn[i] = Button("", { 400.f,90.f },15, sf::Color(200, 200, 200), sf::Color::Black);
		khungDapAn[i].settextture(anhkhung);
		khungDapAn[i].setFont(font);
	}
	khungDapAn[0].setPosition({ 188.f,348.f }, 15, 170.f);
	khungDapAn[1].setPosition({ 688.f,348.f }, 15, 170.f);
	khungDapAn[2].setPosition({ 188.f,448.f }, 15, 170.f);
	khungDapAn[3].setPosition({ 688.f,448.f }, 15, 170.f);
	
	while (windowPlay.isOpen())
	{
		sf::Event eventPlay;
		
		while (windowPlay.pollEvent(eventPlay))
		{
			if (eventPlay.type == sf::Event::EventType::Closed)
			{
				windowPlay.close();
			}
			if (eventPlay.type == sf::Event::MouseButtonPressed)
			{
				float posx = sf::Mouse::getPosition(windowPlay).x;
				float posy = sf::Mouse::getPosition(windowPlay).y;
				if (khungDapAn[0].isKickMouse(windowPlay))
				{
					if (checkdapan[0] == meaning)
						khungDapAn[0].setBgColor(sf::Color::Green);
					else
						khungDapAn[0].setBgColor(sf::Color::Red);
				}
				if (khungDapAn[1].isKickMouse(windowPlay))
				{
					if (checkdapan[1] == meaning)
						khungDapAn[1].setBgColor(sf::Color::Green);
					else
						khungDapAn[1].setBgColor(sf::Color::Red);
				}
				if (khungDapAn[2].isKickMouse(windowPlay))
				{
					if (checkdapan[2] == meaning)
						khungDapAn[2].setBgColor(sf::Color::Green);
					else
						khungDapAn[2].setBgColor(sf::Color::Red);
				}
				if (khungDapAn[3].isKickMouse(windowPlay))
				{
					if (checkdapan[3] == meaning)
						khungDapAn[3].setBgColor(sf::Color::Green);
					else
						khungDapAn[3].setBgColor(sf::Color::Red);
				}
				if (posx > 1126 && posx < 1169 && posy>77 && posy < 128)
				{
					windowPlay.close();
				}
				if (posx > 911 && posx < 1095 && posy>221 && posy < 296)
				{
					for (int i = 0; i < 4; i++)
					{
						khungDapAn[i].setBgColor(sf::Color(200, 200, 200));
					}
					hello.clear();
					key.clear();
					meaning.clear();
					random_key_4_def(rootEnglish, rootVietNam, key, hello, meaning);
					for (int i = 0; i < 4; i++)
					{
						checkdapan[i] = hello[i];
						if (hello[i].length() > 42)
						{
							hello[i].erase(hello[i].begin() + 41, hello[i].end());
						}
						khungDapAn[i].setText(hello[i]);
						khungKey.setText(key);
						khungKey.setPosition({ 428.f,210.f }, 25, -22.f);
					}
					
				}
			}
			


		}
		

		windowPlay.clear();
		windowPlay.draw(sPlay);
		for (int i = 0; i < 4; i++)
		{
			khungDapAn[i].drawTo(windowPlay);
		}
		khungKey.drawTo(windowPlay);
		windowPlay.display();
	}


}