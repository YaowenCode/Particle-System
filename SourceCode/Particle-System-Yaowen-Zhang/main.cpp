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
	window.create(sf::VideoMode(800, 600), "SFML works!");

	sf::Clock clock;

	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	sf::Texture tex1;
	sf::Texture tex2;
	tex1.loadFromFile("test.png");
	tex2.loadFromFile("test2.png");
	
	ParticleManager pm;

	ParticleSystem ps(1, &tex1, { 300, 200 }, { 30, 30 }, {-30, 30}, 100, 10);
	ParticleSystem ps1(3, &tex2, { 400, 300 }, { 30, 30 }, {0, 90}, 1, 10);

	ps.addParticles(10);
	ps1.addParticles(10);

	pm.addParticleSystem(&ps);
	pm.addParticleSystem(&ps1);

	sf::Time dt = clock.restart();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		pm.update(dt);
		pm.draw();
		window.display();
	}

	return 0;
}