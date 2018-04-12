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
	std::vector<Particle*> deadParticles;
	int activeParticleNum;
	int systemID;
	sf::Vector2f emitterPos;
	sf::Texture* pTexture;
	sf::Vector2f initialSize;
	sf::Vector2i initialAngleRange;
	float initialSpeed;
	float particleLifeTime;
public:
	ParticleSystem(int id, sf::Texture* pTex, sf::Vector2f pos, sf::Vector2f size, sf::Vector2i anglerange, float speed, float lifetime);
	~ParticleSystem();
	int getActiveParticleNum();
	int getSystemID();
	sf::Vector2f getEmitterPos();
	sf::Vector2f getInitialSize();
	sf::Texture* getTexture();
	sf::Vector2i getInitialAngleRange();
	float getInitialSpeed();
	float getParticleLifeTime();
	void addParticles(int num);
	void update(sf::Time dt);
	void draw();
};

#endif // !PARTICLESYSTEM_H

