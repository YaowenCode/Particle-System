#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <random>

#ifndef PARTICLE_H
#define PARTICLE_H
#define random(a, b) (rand()%(b - a + 1) + a)

extern sf::RenderWindow window;

class ParticleSystem;

class Particle
{
private:
	sf::Vector2f pos;
	sf::Vector2f velocity;
	sf::Vector2f oldPos;
	sf::Vector2f size;
	sf::RectangleShape shape;
	sf::Time lifetime;
	float angle;
	float speed;
	ParticleSystem* pointToSystem;
	void reset();
public:
	Particle(ParticleSystem* pointer);
	void update(sf::Time dt);
	void draw();
};


#endif // !PARTICLE_H
