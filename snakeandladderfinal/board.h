#pragma once
#include<iostream>
#include<sstream>
#include<SFML\Graphics.hpp>
class myboard
{
private:
	sf::RectangleShape board[10][10];
	sf::RectangleShape shape;
	sf::Texture btexture;
	sf::Text text[10][10];
	sf::Font font;
	void initializeBoard();
	void initializeText();
	

public:
	
	myboard();
	void Render(sf::RenderWindow &window)const;	
};




