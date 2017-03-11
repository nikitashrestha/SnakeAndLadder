#pragma once
#include<iostream>
#include <TGUI/TGUI.hpp>

class dice
{
private:
	int roll;
	sf::Texture t1;
	sf::Texture t2;
	sf::Texture t3;
	sf::Texture t4;
	sf::Texture t5;
	sf::Texture t6;

	sf::RectangleShape shape[6];
	sf::Font font;
	
	sf::Text text1;
	void initializeTexture();

public:
	dice();
	dice(int n);
	void rolldice();
	int getdicevalue();
	void display(int n);
	void Render(sf::RenderWindow &window )const;
};
