#include "particle.h"
#include "particleSystem.h"

Particle::Particle(ParticleSystem* pointer)
{
	pointToSystem = pointer;
	id = pointToSystem->getSystemID();
	pos = pointToSystem->getEmitterPos();
	size = pointToSystem->getInitialSize();
	oldPos = pointToSystem->getEmitterPos();
	angle = random(pointToSystem->getInitialAngleRange().x, pointToSystem->getInitialAngleRange().y) * 3.14f / 180.f;
	lifetime = sf::milliseconds((std::rand() % (int)(pointToSystem->getParticleLifeTime() * 1000)));
	easingtime = lifetime;
	speed = random(0, pointToSystem->getInitialSpeed());
	rotation = 0;
	shape.setOrigin(size.x/2, size.y/2);
	shape.setTexture(pointToSystem->getTexture());
	shape.setSize(size);
}

void Particle::reset()
{
	angle = random(pointToSystem->getInitialAngleRange().x, pointToSystem->getInitialAngleRange().y) * 3.14f / 180.f;
	lifetime = sf::milliseconds((std::rand() % (int)(pointToSystem->getParticleLifeTime() * 1000)));
	easingtime = lifetime;
	speed = random(0, pointToSystem->getInitialSpeed());
	pos = pointToSystem->getEmitterPos();
	size = pointToSystem->getInitialSize();
	shape.setSize(size);
}

void Particle::update(sf::Time dt)
{
	lifetime -= dt;
	if (lifetime <= sf::Time::Zero)
		reset();

	switch (id)
	{
	case 1:
		t = easingtime.asSeconds();
		d = dt.asSeconds();
		b = 0;
		c = 0.001;
		t /= d / 2;
		if (t < 1) rotation = c / 2 * t*t*t + b;
		t--;
		rotation = c / 2 * (t*t*t + 2) + b;
		shape.setRotation(rotation);
		easingtime -= dt;
		break;
	case 2:
		t = easingtime.asSeconds();
		d = dt.asSeconds();
		b = 50;
		c = 0.1;
		shape.setSize({ c*t / d + b, c*t / d + b });
		easingtime -= dt;
		break;
	case 3:
		t = easingtime.asSeconds();
		d = dt.asSeconds();
		b = 0;
		c = 0.1;
		speed = c*t / d + b, c*t / d + b;
		easingtime -= dt;
		break;
	case 4:
		t = easingtime.asSeconds();
		d = dt.asSeconds();
		b = 5;
		c = 0.1;
		shape.setSize({ c*t / d + b, c*t / d + b });
		easingtime += dt;
		break;
	case 5:
		float temp;
		t = easingtime.asSeconds();
		d = dt.asSeconds();
		b = 15;
		c = 0.00005;
		t /= d / 2;
		if (t < 1)  temp = c / 2 * t * t + b;
		t--;
		temp = -c / 2 * (t*(t - 2) - 1) + b;
		speed = temp;
		shape.setSize({ temp, temp});
		easingtime -= dt;
		break;
	default:
		break;
	}

	velocity.x = speed * std::cos(angle);
	velocity.y = speed * std::sin(angle);
	pos += velocity * dt.asSeconds();
	shape.setPosition(pos);
}

void Particle::draw()
{
	window.draw(shape);
}