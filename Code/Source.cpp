#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(900, 500), "SFML-Tutorial", Style::Close);
	window.setFramerateLimit(60);
	/*RectangleShape rectang(Vector2f(400, 220));
	rectang.setPosition(250, 140);
	rectang.setFillColor(Color::Yellow);*/
	/*Vector2f vec(10.f, 12.f);*/
	//CircleShape shape(50.f);
	//RectangleShape rect(Vector2f(50.f, 100.f));
	//shape.setPosition(Vector2f(50.f, 100.f));
	//rect.setPosition(Vector2f(400.f, 200.f));

	//shape.setFillColor(Color(255, 100, 200, 200));
	//rect.setFillColor(Color(255, 255, 100, 100));
	CircleShape triangle;
	triangle.setRadius(50.f);
	triangle.setPointCount(3);
	triangle.setFillColor(Color::Red);
	triangle.setOutlineThickness(5.f);
	triangle.setOutlineColor(Color::Blue);

	Vertex line[] = { Vertex(Vector2f(100.f,400.f)),Vertex(Vector2f(50.f,100.f)),Vertex(Vector2f(100.f,200.f))};

	ConvexShape convex;
	convex.setPosition(Vector2f(400.f, 50.f));
	convex.setPointCount(5);
	convex.setPoint(0, Vector2f(0, 0));
	convex.setPoint(1, Vector2f(150, 10));
	convex.setPoint(2, Vector2f(120, 90));
	convex.setPoint(3, Vector2f(30, 100));
	convex.setPoint(4, Vector2f(0, 50));
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::EventType::Closed)
			{
				window.close();
			}
			
		}
		/*shape.move(0.1f, 0.f);*/
		/*rect.move(-0.5f, 0.f);*/

		/*rect.rotate(5.f);*/
		//update

		//draw
		window.clear();

		//draw everything
		/*window.draw(shape);
		window.draw(rect);*/
		window.draw(triangle);
		window.draw(line, 3, Triangles);
		window.draw(convex);
		window.display();
	}
	return 0;
}