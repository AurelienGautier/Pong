#include "Particles.hpp"

Particles::Particles(unsigned int count) : 
	m_particles(count),
	m_vertices(sf::Points, count),
	m_lifetime(sf::seconds(3)),
	m_emitter(0.f, 0.f)
{
}

void Particles::setEmitter(sf::Vector2f position)
{
	m_emitter = position;
}

void Particles::update(sf::Time elapsed)
{
	for (unsigned int i = 0; i < m_particles.size(); i++)
	{
		Particle& p = m_particles[i];
		p.lifetime -= elapsed;

		if (p.lifetime <= sf::Time::Zero)
		{
			resetParticle(i);
		}

		m_vertices[i].position += p.velocity * elapsed.asSeconds();

		float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
		m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
	}
}

void Particles::draw(sf::RenderWindow& window)
{
	window.draw(m_vertices);
}

void Particles::resetParticle(int index)
{
	float angle = (std::rand() % 360) * 3.14 / 180.f;
	float speed = (std::rand() % 50) + 50.f;

	m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);

	m_vertices[index].position = m_emitter;
}