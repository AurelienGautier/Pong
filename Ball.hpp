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
	Position getPosition();
	
private:
	sf::RectangleShape shape;
	Position position;
	float movementX;
	float mouvementY;
};

