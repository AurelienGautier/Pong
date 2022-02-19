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
	void changeDirection(sf::Vector2f racketPos);
	sf::Vector2f getPosition();
	
private:
	sf::RectangleShape shape;
	sf::Vector2f position;
	float movementX;
	float movementY;
};

