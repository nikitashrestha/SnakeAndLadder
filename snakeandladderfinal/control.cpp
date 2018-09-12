#include"Control.h"
#include"menu.h"
#include"Game.h"

int control::run(sf::RenderWindow &window) //function to draw control menu 
{
	mainmenu m;
	myGame gm;
	sf::Font font;
	if (!font.loadFromFile("ALGER.TTF"))
	{
		std::cout << "error...";
	}

	if (!ctexture.loadFromFile("MENU1.png"))
	{
		std::cout << "error...";
	}
	
	shape.setTexture(&ctexture);
	shape.setSize(sf::Vector2f((float)window.getSize().x,(float) window.getSize().y));
	for (int i = 0; i<2; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(75);
		text[i].setStyle(sf::Text::Bold);
	}

	text[0].setString("MAIN MENU");
	text[1].setString("PLAY GAME");

	text[0].setFillColor(sf::Color(10, 87, 255));
	text[1].setFillColor(sf::Color(10, 87, 255));

	text[0].setOrigin(-500, -505);
	text[1].setOrigin(-500, -605);

	int mouse_x1, mouse_y1;

	sf::Event event;
	while (1)//while loop begin
	{
		while (window.pollEvent(event)) //event begin
		{
			switch (event.type) //switch statement begin
			{

			case sf::Event::MouseMoved:
				mouse_x1 = event.mouseMove.x;
				mouse_y1 = event.mouseMove.y;

				if ((mouse_x1 >= 450 && mouse_x1 <= 950) && (mouse_y1 >= 600 && mouse_y1 <= 700))
				{
					text[1].setFillColor(sf::Color(10, 87, 255));
				}
				else if ((mouse_x1 >= 450 && mouse_x1 <= 950) && (mouse_y1 >= 490 && mouse_y1 <= 590))
				{
					text[0].setFillColor(sf::Color(10, 87, 255));
				}
				else
					for (int i = 0; i<2; i++)
						text[i].setFillColor(sf::Color(17, 17, 17));
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					int mouse_x = event.mouseButton.x;
					int mouse_y = event.mouseButton.y;
					if (mouse_x >= 450 && mouse_x <= 950 && mouse_y >= 600 && mouse_y <= 700)
					{
						text[1].setFillColor(sf::Color::Red);
						gm.run1(window);
						return -1;
					}
					else if (mouse_x >= 450 && mouse_x <= 950 && mouse_y >= 490 && mouse_y <= 590)
					{
						text[0].setFillColor(sf::Color::Red);
						m.run2(window);
					}
				}
				break;

			case sf::Event::MouseButtonReleased:
				text[0].setFillColor(sf::Color(17, 17, 17));
				text[1].setFillColor(sf::Color(17, 17, 17));
				break;

			default:
				break;

			}//end of switch statement

		}//end of event

		//drawing content on windows
		window.clear();
		window.draw(shape);
		for (int i = 0; i<2; i++)
		{
			window.draw(text[i]);
		}

		window.display();

	}//while loop ends
	return -1;
}
