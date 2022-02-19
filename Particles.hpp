#pragma once

#include <SFML/Graphics.hpp>

class Particles
{
public:
	Particles(unsigned int count);
	void setEmitter(sf::Vector2f position);
	void update(sf::Time elapsed);
	void draw(sf::RenderWindow &window);

private:
	struct Particle
	{
		sf::Vector2f velocity;
		sf::Time lifetime;
	};

	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	sf::Time m_lifetime;
	sf::Vector2f m_emitter;

	void resetParticle(int index);
};

