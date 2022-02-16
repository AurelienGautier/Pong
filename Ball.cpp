#include "Ball.hpp"

Ball::Ball() 
{
	shape.setSize(sf::Vector2f(BALL_SIZE, BALL_SIZE));

	position.x = SCREEN_WIDTH/2;
	position.y = SCREEN_HEIGHT/2;

	shape.setPosition(position.x, position.y);

	movementX = 5;
	mouvementY = 2.5;
}

void Ball::draw(sf::RenderWindow& window)
{
	this->shape.setPosition(this->position.x, this->position.y);
	window.draw(this->shape);
}

void Ball::move()
{
	this->position.x += this->movementX;

	if (this->position.x > SCREEN_WIDTH || this->position.x < 0)
	{
		this->position.x = SCREEN_WIDTH / 2;
	}
}

sf::FloatRect Ball::getHitBox()
{
	return sf::FloatRect(this->position.x, this->position.y, BALL_SIZE, BALL_SIZE);
}

void Ball::changeDirection()
{
	this->movementX = 0 - this->movementX;
}