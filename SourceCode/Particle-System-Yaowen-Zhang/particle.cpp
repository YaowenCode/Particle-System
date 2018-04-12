#include "particle.h"
#include "particleSystem.h"

Particle::Particle(ParticleSystem* pointer)
{
	pointToSystem = pointer;
	pos = pointToSystem->getEmitterPos();
	size = pointToSystem->getInitialSize();
	oldPos = pointToSystem->getEmitterPos();
	angle = random(pointToSystem->getInitialAngleRange().x, pointToSystem->getInitialAngleRange().y) * 3.14f / 180.f;
	speed = (std::rand() % 5) + 5.f;
	lifetime = sf::seconds(std::rand() % 2 + pointToSystem->getParticleLifeTime());
	velocity.x = speed * std::cos(angle);
	velocity.y = speed * std::sin(angle);
	shape.setPosition(pos);
	shape.setSize(size);
	shape.setTexture(pointToSystem->getTexture());
}

void Particle::reset()
{
	angle = random(pointToSystem->getInitialAngleRange().x, pointToSystem->getInitialAngleRange().y) * 3.14f / 180.f;
	speed = (std::rand() % 5) + 5.f;
	lifetime = sf::seconds(std::rand() % 2 + pointToSystem->getParticleLifeTime());
	pos = pointToSystem->getEmitterPos();
	velocity.x = speed * std::cos(angle);
	velocity.y = speed * std::sin(angle);
	shape.setPosition(pos);
	size = pointToSystem->getInitialSize();
}

void Particle::update(sf::Time dt)
{
	lifetime -= dt;
	if (lifetime <= sf::Time::Zero)
		reset();
	pos += velocity * dt.asSeconds();
	shape.setPosition(pos);
	shape.setSize(size);
}

void Particle::draw()
{
	window.draw(shape);
}