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
	std::vector<ParticleSystem*> particlesystems;
public:
	ParticleManager();
	void addParticleSystem(ParticleSystem* ps);
	void removeParticleSystem(int id);
	void update(sf::Time dt);
	void draw();
};

#endif // !PARTICLEMANAGER_H