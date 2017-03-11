#pragma once
#include"board.h"
#include"Dice.h"
#include"Position.h"
#include"player.h"
#include<Windows.h>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<SFML/Audio.hpp>

class myGame
{
private:
	int n;
	bool playing;
	bool rolling;
	bool display;
	bool p1move;
	bool p2move;
	sf::Texture p1texture;
	sf::Texture p2texture;
	sf::Texture tmenu;
	sf::Sprite p1sprite;
	sf::Sprite p2sprite;
	sf::Texture winner;
	sf::RectangleShape shape[2];
	sf::Font font;
	sf::Text text[6];
	sf::Text text1;
	sf::SoundBuffer buffer;
	sf::Sound sound;

public:
	myGame();
	int run1(sf::RenderWindow &window);
	int displaywinner(sf::RenderWindow &window,int x);
};

