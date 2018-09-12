#pragma once
#include"Game.h"
#include"Control.h"
#include<SFML\Graphics.hpp>

class mainmenu
{
private:
	bool running;
	sf::Texture tmenu;
	sf::RectangleShape shape;
	sf::Text text[4];
	sf::Font font;
	sf::SoundBuffer buffer1;
	sf::Sound sound1;

	
public:
	mainmenu();
	int run2(sf::RenderWindow &window);
	void stop();
};

