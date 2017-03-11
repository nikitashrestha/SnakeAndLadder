#pragma once
#include"Game.h"
#include"Control.h"
#include<SFML\Graphics.hpp>

class mainmenu
{
private:
	bool playing;
	sf::Texture tmenu;
	sf::RectangleShape shape;
	sf::Text text[4];
	sf::Font font;
	
public:
	mainmenu();
	int run2(sf::RenderWindow &window);
};

