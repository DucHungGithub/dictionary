#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{

	sf::Window window(sf::VideoMode(900, 500), "Mywindow");
	// change the position of the window(relatively to the desktop)
	window.setPosition(sf::Vector2i(10, 50));

	// change the size of the window
	window.setSize(sf::Vector2u(640, 480));

	// change the title of the window
	window.setTitle("SFML window");

	// get the size of the window
	sf::Vector2u size = window.getSize();
	unsigned int width = size.x;
	unsigned int height = size.y;

	// check whether the window has the focus
	bool focus = window.hasFocus();


	return 0;
}