#include"board.h"
#include"initialize.h"
#include<iostream>

myboard::myboard() //costructor
{
	initializeBoard();
	initializeText();

}


void myboard::Render(sf::RenderWindow &window)const //draws board on window
{
	

	for (int i = 0; i < 10; i++)		//for loop begin
	{
		if ((i + 2) % 2 == 0)
		{
			for (int j = 0; j < 10; j++)
			{
				window.draw(board[i][j]);
				

			}
		}
		else
		{
			for (int j = 0; j < 10; j++)
			{
				window.draw(board[i][j]);
				

			}
		}
	} //for loop ends
	
	window.draw(shape);

	for (int i = 0; i < 10; i++) //for loop begins
	{
		if ((i + 2) % 2 == 0)
		{
			for (int j = 0; j < 10; j++)
			{
				
				window.draw(text[i][j]);

			}
		}
		else
		{
			for (int j = 0; j < 10; j++)
			{
			
				window.draw(text[i][j]);

			}
		}
	} //for loop ends

}

void myboard::initializeBoard()			//initialize board contents
{
	
	if (!font.loadFromFile("OpenSans-Bold.ttf"))
	{
		std::cout << "failed to laod text";
	}
	
	if (!btexture.loadFromFile("best.png"))
	{
		std::cout << "failed to load textures";
	}

	
	for (int i = 0; i < 10; i++)
	{
		if ((i + 2) % 2 == 0)
		{
			for (int j = 0; j < 10; j++)
			{
				if ((j + 2) % 2 == 0)
				{
					board[i][j].setFillColor(sf::Color(255, 160, 122));
				}
				else
				{
					board[i][j].setFillColor(sf::Color(255, 255, 255));
				}
				text[i][j].setFont(font);
				text[i][j].setFillColor(sf::Color::Black);
				text[i][j].setPosition(sf::Vector2f((float)(j + 1) * 60 + 20, (float)640 - i * 60));
				board[i][j].setPosition(sf::Vector2f((float)(j * 60) + 60, (float)620 - (60 * i)));
				board[i][j].setSize(sf::Vector2f(60.0, 60.0));

			}
		}

		else
		{
			for (int j = 0; j < 10; j++)
			{
				if ((j + 2) % 2 == 0)
				{
					board[i][j].setFillColor(sf::Color(255, 160, 122));
				}
				else
				{
					board[i][j].setFillColor(sf::Color(255, 255, 255));
				}
				text[i][j].setFont(font);
				text[i][j].setFillColor(sf::Color::Black);
				text[i][j].setPosition(sf::Vector2f((float)620 - (j * 60), (float)640 - (i * 60)));
				board[i][j].setPosition(sf::Vector2f((float)600 - j * 60, (float)620 - (i * 60)));
				board[i][j].setSize(sf::Vector2f(60.0, 60.0));
			}
		}
	}
	shape.setTexture(&btexture);
	shape.setSize(sf::Vector2f(623, 640));
	shape.setPosition(sf::Vector2f(45, 75));
}


