#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "particle.h"
#include "particleSystem.h"
#include "particleManager.h"

sf::RenderWindow window;

int main()
{	
	window.create(sf::VideoMode(1600, 900), "Yaowen's Particles");

	sf::Clock clock;
	
	ParticleManager pm;

	ParticleSystem ps1(1, &pm.tex1, { 800, 450 }, { 50, 50 }, { 0, 360 }, 50, 20, 2000);
	ParticleSystem ps2(2, &pm.tex2, { 150, 350 }, { 50, 50 }, { -90, 0 }, 30, 30, 2000);
	ParticleSystem ps3(3, &pm.tex3, { 150, 750 }, { 50, 50 }, { -90, 0 }, 30, 30, 2000);
	ParticleSystem ps4(4, &pm.tex4, { 1450, 350 }, { 5, 5 }, { -180, -90 }, 30, 50, 2000);
	ParticleSystem ps5(5, &pm.tex5, { 1450, 750 }, { 15, 15 }, { 0, 90 }, 30, 15, 2000);

	pm.addParticleSystem(&ps1);
	pm.addParticleSystem(&ps2);
	pm.addParticleSystem(&ps3);
	pm.addParticleSystem(&ps4);
	pm.addParticleSystem(&ps5);

	sf::Time dt = clock.restart();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		window.clear();
		pm.update(dt);
		pm.draw();
		window.display();
	}

	return 0;
}