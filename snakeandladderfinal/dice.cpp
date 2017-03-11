#include<iostream>
#include<ctime>
#include<cstdlib>
#include"Dice.h"
using namespace std;

dice::dice()
{
	this->roll = 0;
	initializeTexture();
}

dice::dice(int n)
{
	roll = n;
}
void dice::rolldice() //Generates random numbers
{
	srand(time(NULL));
	 this->roll = (rand() % 6)+1;
}

int dice::getdicevalue()
{
	return this->roll;
}

void dice::display(int n) // sets texts as per the dice value
{
	text1.setFont(font);
	text1.setPosition(sf::Vector2f(880, 300));
	text1.setFillColor(sf::Color::Green);
 
	switch (n)
	{
	case 1:
		shape[0].setTexture(&t1);
		shape[0].setSize(sf::Vector2f(200, 200));
		shape[0].setPosition(sf::Vector2f(850, 400));
		shape[0].setFillColor(sf::Color::Cyan);
		text1.setString(" ROLLED 1");
		break;
	case 2:
		shape[1].setTexture(&t2);
		shape[1].setSize(sf::Vector2f(200, 200));
		shape[1].setFillColor(sf::Color::Red);
		shape[1].setPosition(sf::Vector2f(850, 400));

		text1.setString(" ROLLED 2");
		break;

	case 3:
		shape[2].setTexture(&t3);
		shape[2].setSize(sf::Vector2f(200, 200));
		shape[2].setFillColor(sf::Color::Blue);
		shape[2].setPosition(sf::Vector2f(850, 400));

		text1.setString(" ROLLED 3");
		break;

	case 4:
		shape[3].setTexture(&t4);
		shape[3].setSize(sf::Vector2f(200, 200));
		shape[3].setFillColor(sf::Color::Magenta);
		shape[3].setPosition(sf::Vector2f(850, 400));

		text1.setString("ROLLED 4");
		break;

	case 5:
		shape[4].setTexture(&t5);
		shape[4].setSize(sf::Vector2f(200, 200));
		shape[4].setFillColor(sf::Color::Yellow);
		shape[4].setPosition(sf::Vector2f(850, 400));

		text1.setString("ROLLED 5");
		break;

	case 6:
		shape[5].setTexture(&t6);
		shape[5].setSize(sf::Vector2f(200, 200));
		shape[5].setFillColor(sf::Color(150,200,50,250));
		shape[5].setPosition(sf::Vector2f(850, 400));

		text1.setString("ROLLED 6");
		break;

	default:
		cout << "NON";
	}

}

void dice::Render(sf::RenderWindow &window)const //draws dice on window
{
	
	switch (this->roll)
	{
	case 1:
		window.draw(shape[0]);
			break;
	case 2:
		window.draw(shape[1]);
		break;
	case 3:
		window.draw(shape[2]);
		break;
	case 4:
		window.draw(shape[3]);
		break;
	case 5:
		window.draw(shape[4]);
		break;
	case 6:
		window.draw(shape[5]);
		break;

	default:
		break;
	}
	window.draw(text1);
}


void dice::initializeTexture()
{
	if (!font.loadFromFile("ALGER.ttf"))
	{
		std::cout << "failed to load text";
	}
	if (!t1.loadFromFile("1.png"))
	{
		//handle error
	}
	if (!t2.loadFromFile("2.png"))
	{
		//handle error
	}
	
	if (!t3.loadFromFile("3.png"))
	{
		//handle error
	}
	if (!t4.loadFromFile("4.png"))
	{
		//handle error
	}
	if (!t5.loadFromFile("5.png"))
	{
		//handle error
	}
	if (!t6.loadFromFile("6.png"))
	{
		//handle error
	}
}
