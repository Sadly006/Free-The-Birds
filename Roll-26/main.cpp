#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Game");
	
	sf::RectangleShape paddle(sf::Vector2f(200, 15));
	sf::CircleShape ball(10.0f);

	sf::Vector2f ballposition;
	sf::Vector2f paddleposition;


	paddle.setPosition(sf::Vector2f(600, 705));
	ball.setPosition(50, 50);
	float bx = 1, by = 0.7;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		paddleposition = paddle.getPosition();
		if (paddleposition.x  <= 1080 && paddleposition.x >= 0) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				paddle.move(3, 0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				paddle.move(-3, 0);
			}

		}
		else if (paddleposition.x > 1080) paddle.setPosition(sf::Vector2f(1080, 705));
		else if (paddleposition.x < 0) paddle.setPosition(sf::Vector2f(0, 705));
		std::cout << paddleposition.x << " " << paddleposition.y <<  std::endl;


		ball.move(bx, by);
		ballposition = ball.getPosition();

		if (ballposition.x >= 1270) bx = bx * (-1);
		else if (ballposition.x <= 0) bx = bx * (-1);
		else if (ballposition.y <= 0) by = by * (-1);
		

		if (ballposition.x >= paddleposition.x && ballposition.y >= 695 && ballposition.x <= paddleposition.x + 200) {
			by *= -1;
		}



		window.clear();
		window.draw(paddle);
		window.draw(ball);
		window.display();
	}

	return 0;
}