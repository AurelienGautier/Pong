#include "Racket.hpp"

Racket::Racket(char side)
{
	this->shape.setSize(sf::Vector2f(RACKET_WIDTH, RACKET_HEIGHT));

	if (side == 'L')
	{
		this->position.x = LEFT_RACKET_X;
		this->position.y = SCREEN_HEIGHT / 2;
	}

	else if (side == 'R')
	{
		this->position.x = RIGHT_RACKET_X;
		this->position.y = SCREEN_HEIGHT / 2;
	}

	this->shape.setPosition(this->position.x, this->position.y);

	this->movement = 7;
}

void Racket::draw(sf::RenderWindow& window)
{
	this->shape.setPosition(this->position.x, this->position.y);
	window.draw(this->shape);
}

void Racket::moveUp()
{
	this->position.y -= this->movement;

	if (this->position.y < 0)
	{
		this->position.y = 0;
	}
}

void Racket::moveDown()
{
	this->position.y += this->movement;

	if (this->position.y > SCREEN_HEIGHT - RACKET_HEIGHT)
	{
		this->position.y = SCREEN_HEIGHT - RACKET_HEIGHT;
	}
}

sf::FloatRect Racket::getHitBox()
{
	return sf::FloatRect(this->position.x, this->position.y, RACKET_WIDTH, RACKET_HEIGHT);
}

sf::Vector2f Racket::getPosition()
{
	return this->position;
}