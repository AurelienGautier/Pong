#pragma once

#include "Global.hpp"
#include <SFML/Graphics.hpp>

class Racket
{
public:
	Racket(char side);
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();

private:
	sf::RectangleShape shape;
	sf::Vector2f position;
	char movement;
};
