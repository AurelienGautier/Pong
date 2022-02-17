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

	if (this->position.x > SCREEN_WIDTH - BALL_SIZE || this->position.x < 0)
	{
		this->position.x = SCREEN_WIDTH / 2;
	}

	this->position.y += this->mouvementY;

	if (this->position.y >= SCREEN_HEIGHT - BALL_SIZE || this->position.y <= 0)
	{
		this->mouvementY = 0 - this->mouvementY;
	}
}

sf::FloatRect Ball::getHitBox()
{
	return sf::FloatRect(this->position.x, this->position.y, BALL_SIZE, BALL_SIZE);
}

void Ball::changeDirection(Position racketPos)
{
	this->movementX = 0 - this->movementX;

	this->mouvementY = ((this->position.y + BALL_SIZE / 2) - (RACKET_HEIGHT / 2) - racketPos.y) / 10;
}

Position Ball::getPosition()
{
	return this->position;
}