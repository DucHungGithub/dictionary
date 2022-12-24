#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;
#include <iostream>
using namespace std;
int main()
{
	Clock clock;
	Time elapse1 = clock.getElapsedTime();
	cout << elapse1.asMilliseconds() << endl;
	clock.restart();
	Time elapse2 = clock.getElapsedTime();
	cout << elapse2.asMicroseconds() << endl;




	return 0;
}