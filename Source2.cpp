#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace std;
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(900, 500), "Tutorial", Style::Default);
	window.setFramerateLimit(60);
	RectangleShape player(Vector2f(100.f, 150.f));
	RectangleShape hello(Vector2f(100.f, 100.f));
	hello.setPosition(Vector2f(50.f, 100.f));
	player.setPosition(0.f, 0.f);
	player.setOrigin(50.f, 50.f);
	Texture playerTexture;
	playerTexture.loadFromFile("hobeo.jpg");
	player.setTexture(&playerTexture);
	player.setSize(sf::Vector2f(500, 400));
	
	while (window.isOpen())
	{
		Event event;
		int x;
		int y;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::Resized:
				cout << "New window: " << event.size.width << " " << event.size.height << endl;
				break;
			case Event::TextEntered:
				if (event.text.unicode < 128)
				{
					printf("%c", event.text.unicode);
				}
				break;
			case Event::KeyPressed:
				break;
			
			case Event::MouseMoved:
				x = event.mouseMove.x;
				y = event.mouseMove.y;
				if (x > 50 && y < 50)
				{
					hello.setFillColor(Color::Red);
				}
				else
				{
					hello.setFillColor(Color::White);
				}
				break;

			default:
				break;
			}
		}
		//keyboard
		if (Keyboard::isKeyPressed(Keyboard::Key::A))
		{
			player.move(-1.f, 0.f);
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::D))
		{
			player.move(1.f, 0.f);
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::W))
		{
			player.move(0.f, -1.f);
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::S))
		{
			player.move(0.f, 1.f);
		}


		//mouse
		if (Mouse::isButtonPressed(Mouse::Left	))
		{
			/*Vector2i mouseposition = Mouse::getPosition(window);
			player.setPosition((float)mouseposition.x,static_cast<float>(mouseposition.y));*/
			
		}

		//update

		
		//clear
		window.clear();

		//draw
		window.draw(player);
		window.draw(hello);


		//display
		window.display();
	}
}