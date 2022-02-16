#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "Ball.hpp"
#include "Racket.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong !");
	window.setFramerateLimit(60);

	Ball ball;
	
	Racket leftRacket('L');
	Racket rightRacket('R');

	while (window.isOpen())
	{
		sf::Event event;

		window.clear();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		// Collision between the ball and rackets
		if (ball.getHitBox().intersects(rightRacket.getHitBox()) ||
			ball.getHitBox().intersects(leftRacket.getHitBox()))
		{
			ball.changeDirection();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			leftRacket.moveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			leftRacket.moveDown();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			rightRacket.moveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			rightRacket.moveDown();
		}

		ball.move();

		ball.draw(window);

		leftRacket.draw(window);
		rightRacket.draw(window);

		window.display();
	}

	return 0;
}