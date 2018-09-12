#include"menu.h"
#include<cmath>
#include<iostream>
#include<cstdlib>

#define EXIT_SUCCESS 0


int main()

{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "MY GAME",sf::Style::Fullscreen);

	mainmenu m;
	
	m.run2(window);
	return 0;
}
	