#include"Game.h"
#include"menu.h"

myGame::myGame() //constructor
{
	rolling = false;
	playing = true;
	display = false;
}

int myGame::run1(sf::RenderWindow &window) //Game window
{

	//loading Contents

	if (!font.loadFromFile("ALGER.ttf"))
	{
		std::cout << "failed to load text";
	}

	if (!p1texture.loadFromFile("red.png"))
	{
		std::cout << "Failed to load texture";
	}

	if (!p2texture.loadFromFile("blue.png"))
	{
		std::cout << "Failed to load texture";
	}

	if (!tmenu.loadFromFile("back.png"))
	{
		std::cout << "error...";
	}

	if (!buffer.loadFromFile("rollmusic.wav"))
	{
		std::cout << "cannot load from file";
	}
	
	
	
	p1sprite.setTexture(p1texture);
	p2sprite.setTexture(p2texture);


	shape[1].setTexture(&tmenu);
	shape[1].setSize(sf::Vector2f(1200,800));

	text1.setFont(font);
	text1.setFillColor(sf::Color::Green);
	text1.setCharacterSize(35);

	for (int i = 0; i < 6; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(40);
	}
	
	sound.setBuffer(buffer);
	
	text[2].setString("PLAYER 1");
	text[2].setPosition(sf::Vector2f(750, 200));

	text[3].setString("PLAYER 2");
	text[3].setPosition(sf::Vector2f(1000, 200));

	text[4].setStyle(sf::Text::Bold);
	text[4].setPosition(sf::Vector2f(700, 100));

	int turn = 0;
	int count = 0;

	bool running = true;
	sf::Event(event);

	myboard b;
	player p1;
	mainmenu m;
	player p2;
	position po;
	dice d;
	


	while (running) //Beginning of Game loop
	{
		while (window.pollEvent(event)) //beginning of events
		{
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					m.run2(window);
					break;

				case sf::Keyboard::Space:

					rolling = true;
					display = false;

					if (turn % 2 != 0)
					{
						text[2].setFillColor(sf::Color::Red);
						text[3].setFillColor(sf::Color::Green);
					}
					else
					{
						text[2].setFillColor(sf::Color::Green);
						text[3].setFillColor(sf::Color::Blue);
					}
					text1.setString("IS ROLLING");
					text1.setPosition(sf::Vector2f(850, 500));
					sound.setBuffer(buffer);
					sound.play();
					sound.setVolume(100);
					break;
				}
			}


			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Space:
					sound.stop();
					d.rolldice();
					rolling = false;
					display = true;
					turn = turn + 1;
					d.display(d.getdicevalue());
					int n = d.getdicevalue();

					if (turn % 2 != 0)
					{
						po.setdata();
						text[2].setFillColor(sf::Color::Green);
						text[3].setFillColor(sf::Color::Blue);
						if ((n == 1||n==6) && p1.getPlayerNewScore() == 0)
						{

							p1.setPlayerScore(1);
							p1.setPlayerPosition(p1);
							p1sprite.setPosition(sf::Vector2f((float)p1.getX(), (float)p1.getY()));
							window.draw(p1sprite);
							window.display();
							Sleep(300);
							p1.checkforLadders(p1.getPlayerNewScore());
							p1.checkforSnakes(p1.getPlayerNewScore());
							p1.setPlayerPosition(p1);
							p1sprite.setPosition(sf::Vector2f((float)p1.getX(), (float)p1.getY()));
							window.draw(p1sprite);
							window.display();
						}

						else if ((n >= 1 || n <= 6 )&& p1.getPlayerNewScore() != 0)
						{

							p1.setPlayerScore(n);
					
							for (int i = p1.getPlayerCurrentScore(); i <= p1.getPlayerNewScore(); i++)
							{
								po.setdata();
								po.setposition(i);
								p1sprite.setPosition(sf::Vector2f((float)po.getx(), (float)po.gety()));
								d.Render(window);
								window.draw(p1sprite);
								window.display();
								Sleep(200);
								
							}
							p1.checkforLadders(p1.getPlayerNewScore());
							p1.checkforSnakes(p1.getPlayerNewScore());
							p1.setPlayerPosition(p1);
							p1sprite.setPosition(sf::Vector2f((float)p1.getX(), (float)p1.getY()));
							d.Render(window);
							window.draw(p1sprite);
							window.display();

							if (p1.getPlayerNewScore() == 100)
							{
								n = 1;
								displaywinner(window,n);
							}
							text[4].setString("PLAYER 2 TURN TO ROLL");
							text[4].setFillColor(sf::Color::Blue);
							}

						else
						{

							text[4].setString("PLAYER 2 TURN TO ROLL");
							text[4].setFillColor(sf::Color::Blue);

						}
					}

					else
					{

						text[3].setFillColor(sf::Color::Green);
						text[2].setFillColor(sf::Color::Red);
						po.setdata();
						if ((n == 1||n==6) && p2.getPlayerNewScore() == 0)
						{
							p2.setPlayerScore(1);
							p2.setPlayerPosition(p2);
							p2sprite.move(sf::Vector2f((float)po.getx() - p2sprite.getPosition().x, (float)po.gety() - p2sprite.getPosition().y));
							window.draw(p2sprite);
							window.display();
							Sleep(300);
							p2.checkforLadders(p2.getPlayerNewScore());
							p2.checkforSnakes(p2.getPlayerNewScore());
							p2.setPlayerPosition(p2);
							p2sprite.setPosition(sf::Vector2f((float)p2.getX(), (float)p2.getY()));

							window.draw(p2sprite);
							window.display();
							
						}

						else if ((n >= 1 || n <= 6) && p2.getPlayerNewScore() != 0)
						{
							
							text[4].setString("PLAYER 1 TURN TO ROLL");
							text[4].setFillColor(sf::Color::Red);

							p2.setPlayerScore(n);
							for (int i = p2.getPlayerCurrentScore(); i <= p2.getPlayerNewScore(); i++)
							{
								po.setdata();
								po.setposition(i);
								p2sprite.setPosition(sf::Vector2f((float)po.getx(), (float)po.gety()));
								d.Render(window);
								window.draw(p2sprite);
								window.display();
								Sleep(200);
							}
							p2.checkforLadders(p2.getPlayerNewScore());
							p2.checkforSnakes(p2.getPlayerNewScore());
							p2.setPlayerPosition(p2);
							p2sprite.setPosition(sf::Vector2f((float)p2.getX(), (float)p2.getY()));
							if (p2.getPlayerNewScore() == 100)
							{
								n = 2;
								displaywinner(window,n);
							}
							d.Render(window);
							window.draw(p2sprite);
							window.display();
							
						}

						else
						{
							text[4].setString("PLAYER 1 TURN TO ROLL");
							text[4].setFillColor(sf::Color::Red);

						}

					}
					

				}
			}

		}		//Event loop Ends

		//Drawing Objects

		if (playing)
		{
			window.clear();
			window.draw(shape[1]);
			b.Render(window);
			if (!rolling)
			{
				d.Render(window);
			}
			if (rolling)
			{
				window.draw(text1);
			}
			window.draw(text[2]);
			window.draw(text[3]);
			if (display)
			{
				window.draw(text[4]);

			}
		    window.draw(p1sprite);
			window.draw(p2sprite);
			window.display();
		}

	}	//Game Loop Ends
	return 0;
}


int myGame::displaywinner(sf::RenderWindow &window,int x) //function to display winner
{
	if (x == 1)
	{
		text[5].setString("PLAYER 1 WON THIS GAME...");
	}
	else if (x == 2)
	{
		text[5].setString("PLAYER 2 WON THIS GAME...");

	}
	if (!winner.loadFromFile("winner.jpg"))
	{
		std::cout << "failed to load texture";
	}

	shape[0].setTexture(&winner);
	shape[0].setPosition(sf::Vector2f(600, 0));
	shape[0].setSize(sf::Vector2f(600, 800));

	text[0].setStyle(sf::Text::Bold | sf::Text::Italic);
	text[0].setOrigin(-210, -305);
	text[0].setFillColor(sf::Color(10, 87, 255));
	text[0].setString("BACK TO MAIN MENU");

	text[1].setStyle(sf::Text::Bold | sf::Text::Italic);
	text[1].setFillColor(sf::Color(10, 87, 255));
	text[1].setOrigin(-360, -405);
	text[1].setString("EXIT");

	text[5].setFillColor(sf::Color(10, 87, 255));
	text[5].setStyle(sf::Text::Bold);
	text[5].setPosition(sf::Vector2f(100, 100));
	int mousex;
	int mousey;
	mainmenu m;


	while (1)
	{
		sf::Event event1;
		while (window.pollEvent(event1)) //beginning of events
		{
			if (event1.type == sf::Event::MouseMoved)
			{
				mousex = event1.mouseMove.x;
				mousey = event1.mouseMove.y;
				if ((mousex >= 350 && mousex <= 750) && (mousey >= 400 && mousey <= 500))
				{
					text[1].setFillColor(sf::Color(17, 100, 17));
				}
				else if ((mousex >= 150 && mousex <= 750) && (mousey >= 300 && mousey <= 390))
				{
					text[0].setFillColor(sf::Color(17, 100, 17));
				}
				else
					for (int i = 0; i < 2; i++)
						text[i].setFillColor(sf::Color(10, 87, 255));
			}

			if (event1.type == sf::Event::MouseButtonPressed)
			{
				if (event1.mouseButton.button == sf::Mouse::Left)
				{

					int mousex = event1.mouseButton.x;
					int mousey = event1.mouseButton.y;
					if (mousex >= 350 && mousex <= 750 && mousey >= 400 && mousey <= 500)
					{
						text[1].setFillColor(sf::Color::Red);
						m.stop();
						window.close();
						return 0;
					}
					else if (mousex >= 150 && mousex <= 750 && mousey >= 300 && mousey <= 400)
					{
						text[0].setFillColor(sf::Color::Red);
						m.run2(window);
					}
				}
			}

			if (event1.type == sf::Event::MouseButtonReleased)
			{
				text[0].setFillColor(sf::Color(10, 87, 200));
				text[1].setFillColor(sf::Color(10, 87, 200));
			}
		}

		window.clear();
		window.draw(shape[0]);
		window.draw(text[0]);
		window.draw(text[1]);
		window.draw(text[5]);
		window.display();

	}
	
	return 0;
}

