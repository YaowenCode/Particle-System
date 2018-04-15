#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <vector>
#include "particle.h"

#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

typedef std::vector<Particle*>::iterator ParticleIterator;

class ParticleSystem
{
private:
	std::vector<Particle*> particles;
	int activeParticleNum;
	int systemID;
	sf::Vector2f emitterPos;
	sf::Texture* pTexture;
	sf::Vector2f initialSize;
	sf::Vector2i initialAngleRange;
	int initialSpeed;
	int initialParticles;
	float particleLifeTime;
public:
	ParticleSystem(int id, sf::Texture* pTex, sf::Vector2f pos, sf::Vector2f size, sf::Vector2i anglerange, int particlenum, int speed, float lifetime);
	~ParticleSystem();
	int getActiveParticleNum();
	int getSystemID();
	sf::Vector2f getEmitterPos();
	sf::Vector2f getInitialSize();
	sf::Texture* getTexture();
	sf::Vector2i getInitialAngleRange();
	int getInitialSpeed();
	float getParticleLifeTime();
	void addParticles(int num);
	void removeParticles(int num);
	void update(sf::Time dt);
	void draw();
};

#endif // !PARTICLESYSTEM_H

