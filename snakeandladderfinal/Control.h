#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>

class control
{
private:
	sf::Text text[2];
	sf::Texture ctexture;
	sf::RectangleShape shape;
public:
	int run(sf::RenderWindow &window);
};

