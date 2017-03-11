#pragma once
#include<iostream>
#include<sstream>
#include <TGUI/TGUI.hpp>
class myboard
{
private:
	sf::RectangleShape board[10][10];
	sf::RectangleShape shape;
	sf::Texture btexture;
	sf::Sprite bsprite;
	sf::Text text[10][10];
	sf::Font font;
	void initializeBoard();
	void initializeText();
	

public:
	
	myboard();
	void Render(sf::RenderWindow &window)const;
	friend class position;
	
};




