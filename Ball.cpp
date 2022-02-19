#include "Ball.hpp"
#include <iostream> // temporaire

Ball::Ball()
{
	shape.setSize(sf::Vector2f(BALL_SIZE, BALL_SIZE));

	position.x = SCREEN_WIDTH/2;
	position.y = SCREEN_HEIGHT/2;

	shape.setPosition(position.x, position.y);

	movementX = 5;
	movementY = 2.5;
}

void Ball::draw(sf::RenderWindow& window)
{
	// Draw the balle
	this->shape.setPosition(this->position.x, this->position.y);
	window.draw(this->shape);
}

void Ball::move()
{
	this->position.x += this->movementX;

	if (this->position.x > SCREEN_WIDTH - BALL_SIZE || this->position.x < 0)
	{
		this->position.x = SCREEN_WIDTH / 2;
	}

	this->position.y += this->movementY;

	if (this->position.y <= 0)
	{
		this->position.y = 0;
		this->movementY = 0 - this->movementY;
	}
	else if (this->position.y >= SCREEN_HEIGHT - BALL_SIZE)
	{
		this->position.y = SCREEN_HEIGHT - BALL_SIZE;
		this->movementY = 0 - this->movementY;
	}
}

sf::FloatRect Ball::getHitBox()
{
	return sf::FloatRect(this->position.x, this->position.y, BALL_SIZE, BALL_SIZE);
}

void Ball::changeDirection(sf::Vector2f racketPos)
{
	if (this->movementX < 0)
	{
		while (this->position.x < racketPos.x + RACKET_WIDTH)
		{
			this->position.x++;
		}
	}
	else if (this->movementX > 0)
	{
		while (this->position.x + BALL_SIZE > racketPos.x)
		{
			this->position.x--;
		}
	}

	this->movementX = 0 - this->movementX;

	this->movementY = ((this->position.y + BALL_SIZE / 2) - (RACKET_HEIGHT / 2) - racketPos.y) / 10;
}

sf::Vector2f Ball::getPosition()
{
	return this->position;
}