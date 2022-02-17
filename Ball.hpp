#pragma once

#include "Global.hpp"
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball();
	void draw(sf::RenderWindow &window);
	void move();
	sf::FloatRect getHitBox();
	void changeDirection(Position racketPos);
	
private:
	sf::RectangleShape shape;
	Position position;
	float movementX;
	float mouvementY;
};

