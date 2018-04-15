#include "particleManager.h"

ParticleManager::ParticleManager()
{
	particleNum = 0;
	font.loadFromFile("arial.ttf");
	tex1.loadFromFile("twitch.png");
	tex2.loadFromFile("battlenet.png");
	tex3.loadFromFile("uplay.png");
	tex4.loadFromFile("steam.png");
	tex5.loadFromFile("origin.png");
	particleCount.setFont(font);
	particleCount.setColor(sf::Color::Green);
	particleCount.setCharacterSize(50);
	particleCount.setPosition(25, 25);
	fpsCount.setFont(font);
	fpsCount.setColor(sf::Color::Green);
	fpsCount.setCharacterSize(50);
	fpsCount.setPosition(25, 100);
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
	time = clock.restart();

	for (ParticleSystemIterator it = particlesystems.begin(); it != particlesystems.end(); it++)
	{
		if (it == particlesystems.begin())
			particleNum = 0;
		if (sf::Keyboard::isKeyPressed((sf::Keyboard::Up)))
		{
			(*it)->addParticles(1);
		}
		if (sf::Keyboard::isKeyPressed((sf::Keyboard::Down)))
		{
			(*it)->removeParticles(10);
		}
		(*it)->update(dt);
		particleNum += (*it)->getActiveParticleNum();
	}

	fps = 1.0f / time.asSeconds();
	particleCount.setString("Particles: " + std::to_string(particleNum));
	fpsCount.setString("FPS: " + std::to_string((int)fps));
}

void ParticleManager::draw()
{
	for (ParticleSystemIterator it = particlesystems.begin(); it != particlesystems.end(); it++)
	{
		(*it)->draw();
	}

	window.draw(particleCount);
	window.draw(fpsCount);
}
