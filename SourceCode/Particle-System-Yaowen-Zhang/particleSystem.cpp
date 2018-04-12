#include "particleSystem.h"

ParticleSystem::ParticleSystem(int id, sf::Texture* pTex, sf::Vector2f pos, sf::Vector2f size, sf::Vector2i anglerange, float speed, float lifetime)
{
	systemID = id;
	emitterPos = pos;
	pTexture = pTex;
	initialSize = size;
	initialAngleRange = anglerange;
	initialSpeed = speed;
	particleLifeTime = lifetime;
}

ParticleSystem::~ParticleSystem()
{
	for (ParticleIterator it = particles.begin(); it != particles.end(); it++)
	{
		delete *it;
	}
}

void ParticleSystem::addParticles(int num)
{
	for (int i = 0; i < num; i++)
	{
		Particle* particle = new Particle(this);
		particles.push_back(particle);
	}
}

void ParticleSystem::update(sf::Time dt)
{
	for (ParticleIterator it = particles.begin(); it != particles.end(); it++)
	{
		(*it)->update(dt);
	}
}

void ParticleSystem::draw()
{
	for (ParticleIterator it = particles.begin(); it != particles.end(); it++)
	{
		(*it)->draw();
	}
}

int ParticleSystem::getActiveParticleNum()
{
	return activeParticleNum;
}

int ParticleSystem::getSystemID()
{
	return systemID;
}

sf::Vector2f ParticleSystem::getEmitterPos()
{
	return emitterPos;
}

sf::Texture* ParticleSystem::getTexture()
{
	return pTexture;
}

sf::Vector2f ParticleSystem::getInitialSize()
{
	return initialSize;
}

sf::Vector2i ParticleSystem::getInitialAngleRange()
{
	return initialAngleRange;
}

float ParticleSystem::getInitialSpeed()
{
	return initialSpeed;
}

float ParticleSystem::getParticleLifeTime()
{
	return particleLifeTime;
}