#include "particleManager.h"

ParticleManager::ParticleManager()
{
	
}

void ParticleManager::addParticleSystem(ParticleSystem* ps)
{
	particlesystems.push_back(ps);
}

void ParticleManager::removeParticleSystem(int id)
{
	int i = 0;
	bool isFound = false;

	for (ParticleSystemIterator it = particlesystems.begin(); it != particlesystems.end(); it++)
	{
		if ((*it)->getSystemID() == id)
		{
			(*it)->~ParticleSystem();
			isFound = true;
			break;
		}
		++i;
	}

	if (isFound)
		particlesystems.erase(particlesystems.begin() + i);
}

void ParticleManager::update(sf::Time dt)
{
	for (ParticleSystemIterator it = particlesystems.begin(); it != particlesystems.end(); it++)
	{
		(*it)->update(dt);
	}
}

void ParticleManager::draw()
{
	for (ParticleSystemIterator it = particlesystems.begin(); it != particlesystems.end(); it++)
	{
		(*it)->draw();
	}
}
