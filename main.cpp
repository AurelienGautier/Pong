#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "Ball.hpp"
#include "Racket.hpp"
#include "Particles.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong !");
	window.setFramerateLimit(60);

	sf::View view(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

	Ball ball;

	// Particles that follow the ball
	Particles particles(10000);
	
	Racket leftRacket('L');
	Racket rightRacket('R');

	sf::Font font;
	font.loadFromFile("BMgermar.TTF");

	// Scores of the two players
	unsigned char player1Score = 0;
	unsigned char player2Score = 0;

	// Texts containing players scores
	sf::Text scoreP1("0", font, 50);
	sf::Text scoreP2("0", font, 50);

	// Set the scores displaying positions
	scoreP1.setPosition(SCREEN_WIDTH / 2 - 100, BALL_SIZE);
	scoreP2.setPosition(SCREEN_WIDTH / 2 + 50, BALL_SIZE);

	// Initialize and place the middle line
	sf::RectangleShape middleLine(sf::Vector2f(LINE_WIDTH, SCREEN_HEIGHT));
	middleLine.setPosition(SCREEN_WIDTH/2-LINE_WIDTH/2, 0);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;

		window.clear();

		window.setView(view);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		ball.move();

		// Set the particles around the ball
		particles.setEmitter(sf::Vector2f(ball.getPosition().x + BALL_SIZE / 2, ball.getPosition().y + BALL_SIZE / 2));

		sf::Time elapsed = clock.restart();
		particles.update(elapsed);

		// Collision between the ball and rackets
		if (ball.getHitBox().intersects(rightRacket.getHitBox()))
		{
			ball.changeDirection(rightRacket.getPosition());
		}
		else if (ball.getHitBox().intersects(leftRacket.getHitBox()))
		{
			ball.changeDirection(leftRacket.getPosition());
		}

		// Controls for the left racket
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			leftRacket.moveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			leftRacket.moveDown();
		}

		// Controls the right racket
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			rightRacket.moveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			rightRacket.moveDown();
		}

		// Add a point when the ball get off the screen
		if (ball.getPosition().x <= 0)
		{
			player2Score++;
		}
		else if (ball.getPosition().x >= SCREEN_WIDTH - BALL_SIZE)
		{
			player1Score++;
		}
		
		// Set scores texts
		scoreP1.setString(std::to_string(player1Score));
		scoreP2.setString(std::to_string(player2Score));

		// Display scores
		window.draw(scoreP1);
		window.draw(scoreP2);

		unsigned short pointPos = BALL_SIZE;

		window.draw(middleLine);

		ball.draw(window);

		particles.draw(window);

		leftRacket.draw(window);
		rightRacket.draw(window);

		window.display();
	}

	return 0;
}