#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <vector>
#include "particleSystem.h"

#ifndef PARTICLEMANAGER_H
#define PARTICLEMANAGER_H

typedef std::vector<ParticleSystem*>::iterator ParticleSystemIterator;

class ParticleManager
{
private:
	sf::Font font;
	sf::Text particleCount;
	sf::Text fpsCount;
	sf::Time time;
	sf::Clock clock;
	int particleNum;
	float fps;
	std::vector<ParticleSystem*> particlesystems;
public:
	sf::Texture tex1;
	sf::Texture tex2;
	sf::Texture tex3;
	sf::Texture tex4;
	sf::Texture tex5;
	ParticleManager();
	void addParticleSystem(ParticleSystem* ps);
	void removeParticleSystem(int id);
	void update(sf::Time dt);
	void draw();
};

#endif // !PARTICLEMANAGER_H