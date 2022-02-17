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
	Position getPosition();

private:
	sf::RectangleShape shape;
	Position position;
	char movement;
};
