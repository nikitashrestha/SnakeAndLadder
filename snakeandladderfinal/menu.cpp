#include"menu.h"

mainmenu::mainmenu()
{
	playing = false;
}

int mainmenu::run2(sf::RenderWindow &window) // function that calls mainmenu
{
	bool running = true;

	myGame gm;
	control c;

	//loading contents

	if (!font.loadFromFile("ALGER.TTF"))
	{
		std::cout << "error...";
	}

	if (!tmenu.loadFromFile("back.png"))
	{
		std::cout << "error...";
	}

	shape.setTexture(&tmenu);
	shape.setSize(sf::Vector2f(1200, 800));
	
	for (int i = 0; i<4; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(75);
		text[i].setStyle(sf::Text::Bold);
	}

	text[0].setString("PLAY");
	text[1].setString("CONTROLS");
	text[2].setString("EXIT");
	text[0].setFillColor(sf::Color(10, 87, 255));
	text[1].setFillColor(sf::Color(10, 87, 255));
	text[2].setFillColor(sf::Color(10, 87, 255));
	text[0].setOrigin(-510, -205);
	text[1].setOrigin(-440, -405);
	text[2].setOrigin(-520, -605);
	text[3].setString("SNAKES AND LADDER FUN GAME");
	text[3].setStyle(sf::Text::Underlined);
	text[3].setPosition(sf::Vector2f(50, 5));
	text[3].setFillColor(sf::Color(17, 17, 17));


	int mouse_x1, mouse_y1;

	while (running)  //while loop begin
	{
		sf::Event event;
		while (window.pollEvent(event)) //event begin
		{
			switch (event.type) //beginning of switch statement
			{

			case sf::Event::MouseMoved:
				mouse_x1 = event.mouseMove.x;
				mouse_y1 = event.mouseMove.y;

				if ((mouse_x1 >= 450 && mouse_x1 <= 950) && (mouse_y1 >= 600 && mouse_y1 <= 700))
				{
					text[2].setFillColor(sf::Color(10, 87, 255));
				}
				else if ((mouse_x1 >= 450 && mouse_x1 <= 950) && (mouse_y1 >= 400 && mouse_y1 <= 500))
				{
					text[1].setFillColor(sf::Color(10, 87, 255));
				}
				else if ((mouse_x1 >= 450 && mouse_x1 <= 950) && (mouse_y1 >= 200 && mouse_y1 <= 300))
				{
					text[0].setFillColor(sf::Color(10, 87, 255));
				}
				else
					for (int i = 0; i<3; i++)
						text[i].setFillColor(sf::Color(17, 17, 17));
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					int mouse_x = event.mouseButton.x;
					int mouse_y = event.mouseButton.y;
					if (mouse_x >= 450 && mouse_x <= 950 && mouse_y >= 600 && mouse_y <= 700)
					{
						text[2].setFillColor(sf::Color::Red);
						window.close();
						return 0;
					}
					else if (mouse_x >= 450 && mouse_x <= 950 && mouse_y >= 400 && mouse_y <= 500)
					{
						text[1].setFillColor(sf::Color::Red);
						c.run(window);
					}
					else if (mouse_x >= 450 && mouse_x <= 950 && mouse_y >= 200 && mouse_y <= 300)
					{
						text[0].setFillColor(sf::Color::Red);
						gm.run1(window);
					}
				}
				break;

			case sf::Event::MouseButtonReleased:
				text[0].setFillColor(sf::Color(17, 17, 17));
				text[1].setFillColor(sf::Color(17, 17, 17));
				text[2].setFillColor(sf::Color(17, 17, 17));
				break;

			default:
				break;

			} //end of switch statement

		}//end of event

		//drawing content on window
		window.clear();
		window.draw(shape);
		for (int i = 0; i<4; i++)
		{
			window.draw(text[i]);
		}
		window.display();

	}//end of while loop
	return 0;
}
