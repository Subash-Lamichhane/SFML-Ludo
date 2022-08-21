#include "PlayerBlue.h"
#include "PlayerGreen.h"
#include "PlayerRed.h"
#include "PlayerYellow.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Menu.hpp"
#include "dice_animations.hpp"
#include"credits.hpp"

using namespace std;

int generateRandomNum();
int resultAnimation(int);
int dicerollfunc(sf::RenderWindow& window, int playerTurn);
int main()
{
	//Variable declaration
	int Playerturn = 1;
	int moveBluePlayer = 10, moveYellowPlayer = 10, moveGreenPlayer = 10, moveRedPlayer = 10;
	float Yellow1PosX, Yellow1PosY, Yellow2PosX, Yellow2PosY, Yellow3PosX, Yellow3PosY, Yellow4PosX, Yellow4PosY;
	float Blue1PosX, Blue1PosY, Blue2PosX, Blue2PosY, Blue3PosX, Blue3PosY, Blue4PosX, Blue4PosY;
	float Green1PosX, Green1PosY, Green2PosX, Green2PosY, Green3PosX, Green3PosY, Green4PosX, Green4PosY;
	float Red1PosX, Red1PosY, Red2PosX, Red2PosY, Red3PosX, Red3PosY, Red4PosX, Red4PosY;
	float MousePosY, MousePosX;
	bool is720P = 0;
	float viewRatio = 1;

	sf::RenderWindow window, MENU_WINDOW;
	sf::View view(sf::Vector2f(750, 750), sf::Vector2f(1500, 1500));
	MENU_WINDOW.create(sf::VideoMode(800, 600), "Main Menu");
	Menu menu(MENU_WINDOW.getSize().x, MENU_WINDOW.getSize().y);

	sf::Texture texture;
	if (!texture.loadFromFile("gotti/main_menu.jfif"))
	{
		std::cout << "Error loading menu background image.";
	}
	sf::Sprite menuBackground(texture);

	while (MENU_WINDOW.isOpen())
	{
		sf::Event event;

		while (MENU_WINDOW.pollEvent(event))
		{
			sf::Vector2i mouseClickPosition = sf::Mouse::getPosition(MENU_WINDOW);
			menu.checkUsingMouse(mouseClickPosition);
			if (event.type == sf::Event::Closed)
				MENU_WINDOW.close();

			//while

			if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
			{
				//	Up arrow key pressed
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
				{
					//	Shift selected label to down
					menu.moveUp();
				}
				//	Down arrow key pressed
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
				{
					//	Shift selected label to down
					menu.moveDown();
				}

				sf::Vector2i mouseClickPos = sf::Mouse::getPosition(MENU_WINDOW);
				//	Enter key pressed

				if (event.key.code == sf::Keyboard::Enter || event.type == sf::Event::MouseButtonPressed)
				{
					if (menu.getPressedLabel() == 1 || menu.returnClickedValue(mouseClickPos) == 1)
					{
						//credits here
						Credits credits;
						credits.openCreditsWindow(MENU_WINDOW);
					}
					if (menu.getPressedLabel() == 0 || menu.returnClickedValue(mouseClickPos) == 0)
					{

						MENU_WINDOW.close();
						//Main game loop here

						window.create(sf::VideoMode(1000, 1000), "LUDO", sf::Style::Default);
						window.setPosition(sf::Vector2i(0, 0));

						sf::RectangleShape background(sf::Vector2f(1000.0f, 1000.0f));
						sf::Font font;
						sf::Text t1;
						sf::Texture boardTexture;
						sf::Texture playerb;
						sf::Texture player;

						//Yellow Player object declaration
						PlayerYellow yellowPlayer1(207.f, 800.f);
						PlayerYellow yellowPlayer2(93.f, 800.f);
						PlayerYellow yellowPlayer3(93.f, 685.f);
						PlayerYellow yellowPlayer4(207.f, 685.f);

						PlayerBlue bluePlayer1(807.f, 800.f);
						PlayerBlue bluePlayer2(692.f, 800.f);
						PlayerBlue bluePlayer3(807.f, 692.f);
						PlayerBlue bluePlayer4(692.f, 685.f);

						PlayerGreen greenPlayer1(206.f, 191.f);
						PlayerGreen greenPlayer2(92.f, 191.f);
						PlayerGreen greenPlayer3(207.f, 77.f);
						PlayerGreen greenPlayer4(92.f, 77.f);

						PlayerRed redPlayer1(807.f, 77.f);
						PlayerRed redPlayer2(692.f, 77.f);
						PlayerRed redPlayer3(807.f, 191.f);
						PlayerRed redPlayer4(692.f, 191.f);

						int diceno = 0;

						boardTexture.loadFromFile("ludo-board.png");
						playerb.loadFromFile("Gotti/blue.png");
						player.loadFromFile("Gotti/PlayerTexture.png");
						font.loadFromFile("Chocolate Covered Raindrops.ttf");

						sf::Vector2u playertexturesize = player.getSize();

						t1.setFont(font);
						t1.setCharacterSize(32);
						t1.setString("Home");
						t1.setPosition(window.getSize().x / 2.2f, 400.f);

						background.setOrigin(500.0f, 500.0f);
						background.setPosition(500.0f, 500.0f);
						background.setTexture(&boardTexture);

						playertexturesize.x /= 4;

						sf::Text text;
						text.setString("Home");
						text.setCharacterSize(24);
						text.setStyle(sf::Text::Bold);

							//for writing the turn of player
							sf::Font instfont;
							instfont.loadFromFile("NotoSans-Black.ttf");

							sf::Text insttext;
							insttext.setFont(instfont);
							insttext.setCharacterSize(20);
							insttext.setFillColor(sf::Color::Red);
							insttext.setOrigin(900,100);
							insttext.setPosition(100,200);
							insttext.setString("ROlling the dice");

							sf::Text ytext;
							ytext.setFont(instfont);
							ytext.setCharacterSize(20);
							ytext.setFillColor(sf::Color::Red);
							ytext.setOrigin(900,100);
							ytext.setPosition(100,200);
							ytext.setString("Yellow PLayer Turn");

							sf::Text btext;
							btext.setFont(instfont);
							btext.setCharacterSize(20);
							btext.setFillColor(sf::Color::Red);
							btext.setOrigin(900,100);
							btext.setPosition(100,200);
							btext.setString("Blue player Turn");

							sf::Text gtext;
							gtext.setFont(instfont);
							gtext.setCharacterSize(20);
							gtext.setFillColor(sf::Color::Red);
							gtext.setOrigin(900,100);
							gtext.setPosition(100,200);
							gtext.setString("Green Player turn");

							sf::Text rtext;
							rtext.setFont(instfont);
							rtext.setCharacterSize(20);
							rtext.setFillColor(sf::Color::Red);
							rtext.setOrigin(900,100);
							rtext.setPosition(100,200);
							rtext.setString("Red Player Turn");

						//game window
						while (window.isOpen())
						{
							sf::Event event;
							while (window.pollEvent(event))
							{
								if (event.type == sf::Event::Closed)
								{
									window.close();
								}
							}
							if (is720P)
							{
								window.setView(view);
								viewRatio = 1.5;
							}

							window.clear();
							window.draw(background);

							//Players Turn
							if (Playerturn == 1)
							{ //For yellow player movement

								window.pollEvent(event);

								if (moveYellowPlayer == 1)
								{
									yellowPlayer1.draw(window, diceno);
									//for checking checkpoints
									// while(diceno==6||diceno==1)
									// {
									// 	yellowPlayer1.draw(window,diceno);
									// }
									if ((yellowPlayer1.getPositionx(0) != 433.333 || yellowPlayer1.getPositionx(0) != 166.667 || yellowPlayer1.getPositionx(0) != 100. || yellowPlayer1.getPositionx(0) != 433.333 || yellowPlayer1.getPositionx(0) != 566.667 || yellowPlayer1.getPositionx(0) != 566.666 || yellowPlayer1.getPositionx(0) != 833.33 || yellowPlayer1.getPositionx(0) != 900.) && (yellowPlayer1.getPositiony(0) != 900. || yellowPlayer1.getPositiony(0) != 566.666 || yellowPlayer1.getPositiony(0) != 433.333 || yellowPlayer1.getPositiony(0) != 166.667 || yellowPlayer1.getPositiony(0) != 100. || yellowPlayer1.getPositiony(0) != 433.333 || yellowPlayer1.getPositiony(0) != 566.666 || yellowPlayer1.getPositiony(0) != 833.333))
									{
										//for common blue
										if ((yellowPlayer1.getPositionx(0) == bluePlayer1.getPositionx(0)) && yellowPlayer1.getPositiony(0) == bluePlayer1.getPositiony(0))
										{
											bluePlayer1.resetPosition();
											bluePlayer1.draw(window, 0);
										}
										if ((yellowPlayer1.getPositionx(0) == bluePlayer2.getPositionx(0)) && yellowPlayer1.getPositiony(0) == bluePlayer2.getPositiony(0))
										{
											bluePlayer2.resetPosition();
											bluePlayer2.draw(window, 0);
										}
										if ((yellowPlayer1.getPositionx(0) == bluePlayer3.getPositionx(0)) && yellowPlayer1.getPositiony(0) == bluePlayer3.getPositiony(0))
										{
											bluePlayer3.resetPosition();
											bluePlayer3.draw(window, 0);
										}
										if ((yellowPlayer1.getPositionx(0) == bluePlayer4.getPositionx(0)) && yellowPlayer1.getPositiony(0) == bluePlayer4.getPositiony(0))
										{
											bluePlayer4.resetPosition();
											bluePlayer4.draw(window, 0);
										}
										//for common green
										if ((yellowPlayer1.getPositionx(0) == greenPlayer1.getPositionx(0)) && yellowPlayer1.getPositiony(0) == greenPlayer1.getPositiony(0))
										{
											greenPlayer1.resetPosition();
											greenPlayer1.draw(window, 0);
										}
										if ((yellowPlayer1.getPositionx(0) == greenPlayer2.getPositionx(0)) && yellowPlayer1.getPositiony(0) == greenPlayer2.getPositiony(0))
										{
											greenPlayer2.resetPosition();
											greenPlayer2.draw(window, 0);
										}
										if ((yellowPlayer1.getPositionx(0) == greenPlayer3.getPositionx(0)) && yellowPlayer1.getPositiony(0) == greenPlayer3.getPositiony(0))
										{
											greenPlayer3.resetPosition();
											greenPlayer3.draw(window, 0);
										}
										if ((yellowPlayer1.getPositionx(0) == greenPlayer4.getPositionx(0)) && yellowPlayer1.getPositiony(0) == greenPlayer4.getPositiony(0))
										{
											greenPlayer4.resetPosition();
											greenPlayer4.draw(window, 0);
										}
										//for common red
										if ((yellowPlayer1.getPositionx(0) == redPlayer1.getPositionx(0)) && yellowPlayer1.getPositiony(0) == redPlayer1.getPositiony(0))
										{
											redPlayer1.resetPosition();
											redPlayer1.draw(window, 0);
										}
										if ((yellowPlayer1.getPositionx(0) == redPlayer2.getPositionx(0)) && yellowPlayer1.getPositiony(0) == redPlayer2.getPositiony(0))
										{
											redPlayer2.resetPosition();
											redPlayer2.draw(window, 0);
										}
										if ((yellowPlayer1.getPositionx(0) == redPlayer3.getPositionx(0)) && yellowPlayer1.getPositiony(0) == redPlayer3.getPositiony(0))
										{
											redPlayer3.resetPosition();
											redPlayer3.draw(window, 0);
										}
										if ((yellowPlayer1.getPositionx(0) == redPlayer4.getPositionx(0)) && yellowPlayer1.getPositiony(0) == redPlayer4.getPositiony(0))
										{
											redPlayer4.resetPosition();
											redPlayer4.draw(window, 0);
										}
									}
									if ((yellowPlayer1.getPositionx(0) == 500. && yellowPlayer2.getPositionx(0) == 500. && yellowPlayer3.getPositionx(0) == 500. && yellowPlayer4.getPositionx(0) == 500.)
										&& (yellowPlayer1.getPositiony(0) == 566.666 && yellowPlayer2.getPositiony(0) == 566.666 && yellowPlayer3.getPositiony(0) == 566.666 && yellowPlayer4.getPositiony(0) == 566.666))
									{
										void resultAnimation(sf::RenderWindow& window, int winner= 1);
									}
									window.draw(insttext);
									window.draw(gtext);

									std::cout << "\n \n Player green turn";
									Playerturn += 1;
								}
								else if (moveYellowPlayer == 2)
								{
									yellowPlayer2.draw(window, diceno);
									// while(diceno==6||diceno==1)
									// {
									// 	yellowPlayer2.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((yellowPlayer2.getPositionx(0) != 433.333 || yellowPlayer2.getPositionx(0) != 166.667 || yellowPlayer2.getPositionx(0) != 100. || yellowPlayer2.getPositionx(0) != 433.333 || yellowPlayer2.getPositionx(0) != 566.667 || yellowPlayer2.getPositionx(0) != 566.666 || yellowPlayer2.getPositionx(0) != 833.33 || yellowPlayer2.getPositionx(0) != 900.) && (yellowPlayer2.getPositiony(0) != 900. || yellowPlayer2.getPositiony(0) != 566.666 || yellowPlayer2.getPositiony(0) != 433.333 || yellowPlayer2.getPositiony(0) != 166.667 || yellowPlayer2.getPositiony(0) != 100. || yellowPlayer2.getPositiony(0) != 433.333 || yellowPlayer2.getPositiony(0) != 566.666 || yellowPlayer2.getPositiony(0) != 833.333))
									{
										//for common blue
										if ((yellowPlayer2.getPositionx(0) == bluePlayer1.getPositionx(0)) && yellowPlayer2.getPositiony(0) == bluePlayer1.getPositiony(0))
										{
											bluePlayer1.resetPosition();
											bluePlayer1.draw(window, 0);
										}
										if ((yellowPlayer2.getPositionx(0) == bluePlayer2.getPositionx(0)) && yellowPlayer2.getPositiony(0) == bluePlayer2.getPositiony(0))
										{
											bluePlayer2.resetPosition();
											bluePlayer2.draw(window, 0);
										}
										if ((yellowPlayer2.getPositionx(0) == bluePlayer3.getPositionx(0)) && yellowPlayer2.getPositiony(0) == bluePlayer3.getPositiony(0))
										{
											bluePlayer3.resetPosition();
											bluePlayer3.draw(window, 0);
										}
										if ((yellowPlayer2.getPositionx(0) == bluePlayer4.getPositionx(0)) && yellowPlayer2.getPositiony(0) == bluePlayer4.getPositiony(0))
										{
											bluePlayer4.resetPosition();
											bluePlayer4.draw(window, 0);
										}
										//for common green
										if ((yellowPlayer2.getPositionx(0) == greenPlayer1.getPositionx(0)) && yellowPlayer2.getPositiony(0) == greenPlayer1.getPositiony(0))
										{
											greenPlayer1.resetPosition();
											greenPlayer1.draw(window, 0);
										}
										if ((yellowPlayer2.getPositionx(0) == greenPlayer2.getPositionx(0)) && yellowPlayer2.getPositiony(0) == greenPlayer2.getPositiony(0))
										{
											greenPlayer2.resetPosition();
											greenPlayer2.draw(window, 0);
										}
										if ((yellowPlayer2.getPositionx(0) == greenPlayer3.getPositionx(0)) && yellowPlayer2.getPositiony(0) == greenPlayer3.getPositiony(0))
										{
											greenPlayer3.resetPosition();
											greenPlayer3.draw(window, 0);
										}
										if ((yellowPlayer2.getPositionx(0) == greenPlayer4.getPositionx(0)) && yellowPlayer2.getPositiony(0) == greenPlayer4.getPositiony(0))
										{
											greenPlayer4.resetPosition();
											greenPlayer4.draw(window, 0);
										}
										//for common red
										if ((yellowPlayer2.getPositionx(0) == redPlayer1.getPositionx(0)) && yellowPlayer2.getPositiony(0) == redPlayer1.getPositiony(0))
										{
											redPlayer1.resetPosition();
											redPlayer1.draw(window, 0);
										}
										if ((yellowPlayer2.getPositionx(0) == redPlayer2.getPositionx(0)) && yellowPlayer2.getPositiony(0) == redPlayer2.getPositiony(0))
										{
											redPlayer2.resetPosition();
											redPlayer2.draw(window, 0);
										}
										if ((yellowPlayer2.getPositionx(0) == redPlayer3.getPositionx(0)) && yellowPlayer2.getPositiony(0) == redPlayer3.getPositiony(0))
										{
											redPlayer3.resetPosition();
											redPlayer3.draw(window, 0);
										}
										if ((yellowPlayer2.getPositionx(0) == redPlayer4.getPositionx(0)) && yellowPlayer2.getPositiony(0) == redPlayer4.getPositiony(0))
										{
											redPlayer4.resetPosition();
											redPlayer4.draw(window, 0);
										}
									}
									if ((yellowPlayer2.getPositionx(0) == 500. && yellowPlayer2.getPositionx(0) == 500. && yellowPlayer3.getPositionx(0) == 500. && yellowPlayer4.getPositionx(0) == 500.)
										&& (yellowPlayer2.getPositiony(0) == 566.666 && yellowPlayer2.getPositiony(0) == 566.666 && yellowPlayer3.getPositiony(0) == 566.666 && yellowPlayer4.getPositiony(0) == 566.666))
									{
										void resultAnimation(sf::RenderWindow& window, int winner = 1);
									}
									std::cout << "\n \n Player green turn";
									Playerturn += 1;
								}
								else if (moveYellowPlayer == 3)
								{
									yellowPlayer3.draw(window, diceno);
									// while(diceno==6||diceno==1)
									// {
									// 	yellowPlayer3.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((yellowPlayer3.getPositionx(0) != 433.333 || yellowPlayer3.getPositionx(0) != 166.667 || yellowPlayer3.getPositionx(0) != 100. || yellowPlayer3.getPositionx(0) != 433.333 || yellowPlayer3.getPositionx(0) != 566.667 || yellowPlayer3.getPositionx(0) != 566.666 || yellowPlayer3.getPositionx(0) != 833.33 || yellowPlayer3.getPositionx(0) != 900.) && (yellowPlayer3.getPositiony(0) != 900. || yellowPlayer3.getPositiony(0) != 566.666 || yellowPlayer3.getPositiony(0) != 433.333 || yellowPlayer3.getPositiony(0) != 166.667 || yellowPlayer3.getPositiony(0) != 100. || yellowPlayer3.getPositiony(0) != 433.333 || yellowPlayer3.getPositiony(0) != 566.666 || yellowPlayer3.getPositiony(0) != 833.333))
									{
										//for common blue
										if ((yellowPlayer3.getPositionx(0) == bluePlayer1.getPositionx(0)) && yellowPlayer3.getPositiony(0) == bluePlayer1.getPositiony(0))
										{
											bluePlayer1.resetPosition();
											bluePlayer1.draw(window, 0);
										}
										if ((yellowPlayer3.getPositionx(0) == bluePlayer2.getPositionx(0)) && yellowPlayer3.getPositiony(0) == bluePlayer2.getPositiony(0))
										{
											bluePlayer2.resetPosition();
											bluePlayer2.draw(window, 0);
										}
										if ((yellowPlayer3.getPositionx(0) == bluePlayer3.getPositionx(0)) && yellowPlayer3.getPositiony(0) == bluePlayer3.getPositiony(0))
										{
											bluePlayer3.resetPosition();
											bluePlayer3.draw(window, 0);
										}
										if ((yellowPlayer3.getPositionx(0) == bluePlayer4.getPositionx(0)) && yellowPlayer3.getPositiony(0) == bluePlayer4.getPositiony(0))
										{
											bluePlayer4.resetPosition();
											bluePlayer4.draw(window, 0);
										}
										//for common green
										if ((yellowPlayer3.getPositionx(0) == greenPlayer1.getPositionx(0)) && yellowPlayer3.getPositiony(0) == greenPlayer1.getPositiony(0))
										{
											greenPlayer1.resetPosition();
											greenPlayer1.draw(window, 0);
										}
										if ((yellowPlayer3.getPositionx(0) == greenPlayer2.getPositionx(0)) && yellowPlayer3.getPositiony(0) == greenPlayer2.getPositiony(0))
										{
											greenPlayer2.resetPosition();
											greenPlayer2.draw(window, 0);
										}
										if ((yellowPlayer3.getPositionx(0) == greenPlayer3.getPositionx(0)) && yellowPlayer3.getPositiony(0) == greenPlayer3.getPositiony(0))
										{
											greenPlayer3.resetPosition();
											greenPlayer3.draw(window, 0);
										}
										if ((yellowPlayer3.getPositionx(0) == greenPlayer4.getPositionx(0)) && yellowPlayer3.getPositiony(0) == greenPlayer4.getPositiony(0))
										{
											greenPlayer4.resetPosition();
											greenPlayer4.draw(window, 0);
										}
										//for common red
										if ((yellowPlayer3.getPositionx(0) == redPlayer1.getPositionx(0)) && yellowPlayer3.getPositiony(0) == redPlayer1.getPositiony(0))
										{
											redPlayer1.resetPosition();
											redPlayer1.draw(window, 0);
										}
										if ((yellowPlayer3.getPositionx(0) == redPlayer2.getPositionx(0)) && yellowPlayer3.getPositiony(0) == redPlayer2.getPositiony(0))
										{
											redPlayer2.resetPosition();
											redPlayer2.draw(window, 0);
										}
										if ((yellowPlayer3.getPositionx(0) == redPlayer3.getPositionx(0)) && yellowPlayer3.getPositiony(0) == redPlayer3.getPositiony(0))
										{
											redPlayer3.resetPosition();
											redPlayer3.draw(window, 0);
										}
										if ((yellowPlayer3.getPositionx(0) == redPlayer4.getPositionx(0)) && yellowPlayer3.getPositiony(0) == redPlayer4.getPositiony(0))
										{
											redPlayer4.resetPosition();
											redPlayer4.draw(window, 0);
										}
									}
									if ((yellowPlayer3.getPositionx(0) == 500. && yellowPlayer3.getPositionx(0) == 500. && yellowPlayer3.getPositionx(0) == 500. && yellowPlayer4.getPositionx(0) == 500.)
										&& (yellowPlayer3.getPositiony(0) == 566.666 && yellowPlayer3.getPositiony(0) == 566.666 && yellowPlayer3.getPositiony(0) == 566.666 && yellowPlayer4.getPositiony(0) == 566.666))
									{
										void resultAnimation(sf::RenderWindow& window, int winner = 1);
									}
									std::cout << "\n \n Player green turn";
									Playerturn += 1;
								}
								else if (moveYellowPlayer == 4)
								{
									yellowPlayer4.draw(window, diceno);
									 while(diceno==1||diceno==6)
									 {
									 	yellowPlayer4.draw(window,diceno);
									 }
									//for checking checkpoints
									if ((yellowPlayer4.getPositionx(0) != 433.333 || yellowPlayer4.getPositionx(0) != 166.667 || yellowPlayer4.getPositionx(0) != 100. || yellowPlayer4.getPositionx(0) != 433.333 || yellowPlayer4.getPositionx(0) != 566.667 || yellowPlayer4.getPositionx(0) != 566.666 || yellowPlayer4.getPositionx(0) != 833.33 || yellowPlayer4.getPositionx(0) != 900.) && (yellowPlayer4.getPositiony(0) != 900. || yellowPlayer4.getPositiony(0) != 566.666 || yellowPlayer4.getPositiony(0) != 433.333 || yellowPlayer4.getPositiony(0) != 166.667 || yellowPlayer4.getPositiony(0) != 100. || yellowPlayer4.getPositiony(0) != 433.333 || yellowPlayer4.getPositiony(0) != 566.666 || yellowPlayer4.getPositiony(0) != 833.333))
									{
										//for common blue
										if ((yellowPlayer4.getPositionx(0) == bluePlayer1.getPositionx(0)) && yellowPlayer4.getPositiony(0) == bluePlayer1.getPositiony(0))
										{
											bluePlayer1.resetPosition();
											bluePlayer1.draw(window, 0);
										}
										if ((yellowPlayer4.getPositionx(0) == bluePlayer2.getPositionx(0)) && yellowPlayer4.getPositiony(0) == bluePlayer2.getPositiony(0))
										{
											bluePlayer2.resetPosition();
											bluePlayer2.draw(window, 0);
										}
										if ((yellowPlayer4.getPositionx(0) == bluePlayer3.getPositionx(0)) && yellowPlayer4.getPositiony(0) == bluePlayer3.getPositiony(0))
										{
											bluePlayer3.resetPosition();
											bluePlayer3.draw(window, 0);
										}
										if ((yellowPlayer4.getPositionx(0) == bluePlayer4.getPositionx(0)) && yellowPlayer4.getPositiony(0) == bluePlayer4.getPositiony(0))
										{
											bluePlayer4.resetPosition();
											bluePlayer4.draw(window, 0);
										}
										//for common green
										if ((yellowPlayer4.getPositionx(0) == greenPlayer1.getPositionx(0)) && yellowPlayer4.getPositiony(0) == greenPlayer1.getPositiony(0))
										{
											greenPlayer1.resetPosition();
											greenPlayer1.draw(window, 0);
										}
										if ((yellowPlayer4.getPositionx(0) == greenPlayer2.getPositionx(0)) && yellowPlayer4.getPositiony(0) == greenPlayer2.getPositiony(0))
										{
											greenPlayer2.resetPosition();
											greenPlayer2.draw(window, 0);
										}
										if ((yellowPlayer4.getPositionx(0) == greenPlayer3.getPositionx(0)) && yellowPlayer4.getPositiony(0) == greenPlayer3.getPositiony(0))
										{
											greenPlayer3.resetPosition();
											greenPlayer3.draw(window, 0);
										}
										if ((yellowPlayer4.getPositionx(0) == greenPlayer4.getPositionx(0)) && yellowPlayer4.getPositiony(0) == greenPlayer4.getPositiony(0))
										{
											greenPlayer4.resetPosition();
											greenPlayer4.draw(window, 0);
										}
										//for common red
										if ((yellowPlayer4.getPositionx(0) == redPlayer1.getPositionx(0)) && yellowPlayer4.getPositiony(0) == redPlayer1.getPositiony(0))
										{
											redPlayer1.resetPosition();
											redPlayer1.draw(window, 0);
										}
										if ((yellowPlayer4.getPositionx(0) == redPlayer2.getPositionx(0)) && yellowPlayer4.getPositiony(0) == redPlayer2.getPositiony(0))
										{
											redPlayer2.resetPosition();
											redPlayer2.draw(window, 0);
										}
										if ((yellowPlayer4.getPositionx(0) == redPlayer3.getPositionx(0)) && yellowPlayer4.getPositiony(0) == redPlayer3.getPositiony(0))
										{
											redPlayer3.resetPosition();
											redPlayer3.draw(window, 0);
										}
										if ((yellowPlayer4.getPositionx(0) == redPlayer4.getPositionx(0)) && yellowPlayer4.getPositiony(0) == redPlayer4.getPositiony(0))
										{
											redPlayer4.resetPosition();
											redPlayer4.draw(window, 0);
										}
									}
									if ((yellowPlayer4.getPositionx(0) == 500. && yellowPlayer4.getPositionx(0) == 500. && yellowPlayer4.getPositionx(0) == 500. && yellowPlayer4.getPositionx(0) == 500.)
										&& (yellowPlayer4.getPositiony(0) == 566.666 && yellowPlayer4.getPositiony(0) == 566.666 && yellowPlayer4.getPositiony(0) == 566.666 && yellowPlayer4.getPositiony(0) == 566.666))
									{
										void resultAnimation(sf::RenderWindow& window, int winner = 1);
									}
									std::cout << "\n \n Player green turn";
									Playerturn += 1;
								}
							}
							else if (Playerturn == 2)
							{ //For Green Player movement

								window.pollEvent(event);

								if (moveGreenPlayer == 1)
								{
									greenPlayer1.draw(window, diceno);
									// while(diceno==6||diceno==1)
									// {
									// 	greenPlayer1.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((greenPlayer1.getPositionx(0) != 100. || greenPlayer1.getPositionx(0) != 433.333 || greenPlayer1.getPositionx(0) != 566.666 || greenPlayer1.getPositionx(0) != 833.333 || greenPlayer1.getPositionx(0) != 900. || greenPlayer1.getPositionx(0) != 566.666 || greenPlayer1.getPositionx(0) != 433.333 || greenPlayer1.getPositionx(0) != 166.667) && (greenPlayer1.getPositiony(0) != 433.333 || greenPlayer1.getPositiony(0) != 166.67 || greenPlayer1.getPositiony(0) != 100. || greenPlayer1.getPositiony(0) != 433.333 || greenPlayer1.getPositiony(0) != 566.666 || greenPlayer1.getPositiony(0) != 833.333 || greenPlayer1.getPositiony(0) != 900. || greenPlayer1.getPositiony(0) != 566.667))
									{
										//for common blue
										if ((greenPlayer1.getPositionx(0) == bluePlayer1.getPositionx(0)) && greenPlayer1.getPositiony(0) == bluePlayer1.getPositiony(0))
										{
											bluePlayer1.resetPosition();
											bluePlayer1.draw(window, 0);
										}
										if ((greenPlayer1.getPositionx(0) == bluePlayer2.getPositionx(0)) && greenPlayer1.getPositiony(0) == bluePlayer2.getPositiony(0))
										{
											bluePlayer2.resetPosition();
											bluePlayer2.draw(window, 0);
										}
										if ((greenPlayer1.getPositionx(0) == bluePlayer3.getPositionx(0)) && greenPlayer1.getPositiony(0) == bluePlayer3.getPositiony(0))
										{
											bluePlayer3.resetPosition();
											bluePlayer3.draw(window, 0);
										}
										if ((greenPlayer1.getPositionx(0) == bluePlayer4.getPositionx(0)) && greenPlayer1.getPositiony(0) == bluePlayer4.getPositiony(0))
										{
											bluePlayer4.resetPosition();
											bluePlayer4.draw(window, 0);
										}
										//for common yellow
										if ((greenPlayer1.getPositionx(0) == yellowPlayer1.getPositionx(0)) && greenPlayer1.getPositiony(0) == yellowPlayer1.getPositiony(0))
										{
											yellowPlayer1.resetPosition();
											yellowPlayer1.draw(window, 0);
										}
										if ((greenPlayer1.getPositionx(0) == yellowPlayer2.getPositionx(0)) && greenPlayer1.getPositiony(0) == yellowPlayer2.getPositiony(0))
										{
											yellowPlayer2.resetPosition();
											yellowPlayer2.draw(window, 0);
										}
										if ((greenPlayer1.getPositionx(0) == yellowPlayer3.getPositionx(0)) && greenPlayer1.getPositiony(0) == yellowPlayer3.getPositiony(0))
										{
											yellowPlayer3.resetPosition();
											yellowPlayer3.draw(window, 0);
										}
										if ((greenPlayer1.getPositionx(0) == yellowPlayer4.getPositionx(0)) && greenPlayer1.getPositiony(0) == yellowPlayer4.getPositiony(0))
										{
											yellowPlayer4.resetPosition();
											yellowPlayer4.draw(window, 0);
										}
										//for common red
										if ((greenPlayer1.getPositionx(0) == redPlayer1.getPositionx(0)) && greenPlayer1.getPositiony(0) == redPlayer1.getPositiony(0))
										{
											redPlayer1.resetPosition();
											redPlayer1.draw(window, 0);
										}
										if ((greenPlayer1.getPositionx(0) == redPlayer2.getPositionx(0)) && greenPlayer1.getPositiony(0) == redPlayer2.getPositiony(0))
										{
											redPlayer2.resetPosition();
											redPlayer2.draw(window, 0);
										}
										if ((greenPlayer1.getPositionx(0) == redPlayer3.getPositionx(0)) && greenPlayer1.getPositiony(0) == redPlayer3.getPositiony(0))
										{
											redPlayer3.resetPosition();
											redPlayer3.draw(window, 0);
										}
										if ((greenPlayer1.getPositionx(0) == redPlayer4.getPositionx(0)) && greenPlayer1.getPositiony(0) == redPlayer4.getPositiony(0))
										{
											redPlayer4.resetPosition();
											redPlayer4.draw(window, 0);
										}
									}
									if ((greenPlayer1.getPositionx(0) == 433.333 && greenPlayer2.getPositionx(0) == 433.333 && greenPlayer3.getPositionx(0) == 433.333 && greenPlayer4.getPositionx(0) == 433.333)
										&& (greenPlayer1.getPositiony(0) == 500. && greenPlayer2.getPositiony(0) == 500. && greenPlayer3.getPositiony(0) == 500. && greenPlayer4.getPositiony(0) == 500.))
									{
										void resultAnimation(sf::RenderWindow& window, int winner=2);
									}
									std::cout << "\n \n Player red turn";
									Playerturn += 1;
								}
								else if (moveGreenPlayer == 2)
								{
									greenPlayer2.draw(window, diceno);
									//chance to roll again for 6
									// while(diceno==6||diceno==1)
									// {
									// 	greenPlayer2.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((greenPlayer2.getPositionx(0) != 100. || greenPlayer2.getPositionx(0) != 433.333 || greenPlayer2.getPositionx(0) != 566.666 || greenPlayer2.getPositionx(0) != 833.333 || greenPlayer2.getPositionx(0) != 900. || greenPlayer2.getPositionx(0) != 566.666 || greenPlayer2.getPositionx(0) != 433.333 || greenPlayer2.getPositionx(0) != 166.667) && (greenPlayer2.getPositiony(0) != 433.333 || greenPlayer2.getPositiony(0) != 166.67 || greenPlayer2.getPositiony(0) != 100. || greenPlayer2.getPositiony(0) != 433.333 || greenPlayer2.getPositiony(0) != 566.666 || greenPlayer2.getPositiony(0) != 833.333 || greenPlayer2.getPositiony(0) != 900. || greenPlayer2.getPositiony(0) != 566.667))
									{
										//for common blue
										if ((greenPlayer2.getPositionx(0) == bluePlayer1.getPositionx(0)) && greenPlayer2.getPositiony(0) == bluePlayer1.getPositiony(0))
										{
											bluePlayer1.resetPosition();
											bluePlayer1.draw(window, 0);
										}
										if ((greenPlayer2.getPositionx(0) == bluePlayer2.getPositionx(0)) && greenPlayer2.getPositiony(0) == bluePlayer2.getPositiony(0))
										{
											bluePlayer2.resetPosition();
											bluePlayer2.draw(window, 0);
										}
										if ((greenPlayer2.getPositionx(0) == bluePlayer3.getPositionx(0)) && greenPlayer2.getPositiony(0) == bluePlayer3.getPositiony(0))
										{
											bluePlayer3.resetPosition();
											bluePlayer3.draw(window, 0);
										}
										if ((greenPlayer2.getPositionx(0) == bluePlayer4.getPositionx(0)) && greenPlayer2.getPositiony(0) == bluePlayer4.getPositiony(0))
										{
											bluePlayer4.resetPosition();
											bluePlayer4.draw(window, 0);
										}
										//for common yellow
										if ((greenPlayer2.getPositionx(0) == yellowPlayer1.getPositionx(0)) && greenPlayer2.getPositiony(0) == yellowPlayer1.getPositiony(0))
										{
											yellowPlayer1.resetPosition();
											yellowPlayer1.draw(window, 0);
										}
										if ((greenPlayer2.getPositionx(0) == yellowPlayer2.getPositionx(0)) && greenPlayer2.getPositiony(0) == yellowPlayer2.getPositiony(0))
										{
											yellowPlayer2.resetPosition();
											yellowPlayer2.draw(window, 0);
										}
										if ((greenPlayer2.getPositionx(0) == yellowPlayer3.getPositionx(0)) && greenPlayer2.getPositiony(0) == yellowPlayer3.getPositiony(0))
										{
											yellowPlayer3.resetPosition();
											yellowPlayer3.draw(window, 0);
										}
										if ((greenPlayer2.getPositionx(0) == yellowPlayer4.getPositionx(0)) && greenPlayer2.getPositiony(0) == yellowPlayer4.getPositiony(0))
										{
											yellowPlayer4.resetPosition();
											yellowPlayer4.draw(window, 0);
										}
										//for common red
										if ((greenPlayer2.getPositionx(0) == redPlayer1.getPositionx(0)) && greenPlayer2.getPositiony(0) == redPlayer1.getPositiony(0))
										{
											redPlayer1.resetPosition();
											redPlayer1.draw(window, 0);
										}
										if ((greenPlayer2.getPositionx(0) == redPlayer2.getPositionx(0)) && greenPlayer2.getPositiony(0) == redPlayer2.getPositiony(0))
										{
											redPlayer2.resetPosition();
											redPlayer2.draw(window, 0);
										}
										if ((greenPlayer2.getPositionx(0) == redPlayer3.getPositionx(0)) && greenPlayer2.getPositiony(0) == redPlayer3.getPositiony(0))
										{
											redPlayer3.resetPosition();
											redPlayer3.draw(window, 0);
										}
										if ((greenPlayer2.getPositionx(0) == redPlayer4.getPositionx(0)) && greenPlayer2.getPositiony(0) == redPlayer4.getPositiony(0))
										{
											redPlayer4.resetPosition();
											redPlayer4.draw(window, 0);
										}
									}
									if ((greenPlayer2.getPositionx(0) == 433.333 && greenPlayer2.getPositionx(0) == 433.333 && greenPlayer3.getPositionx(0) == 433.333 && greenPlayer4.getPositionx(0) == 433.333)
										&& (greenPlayer2.getPositiony(0) == 500. && greenPlayer2.getPositiony(0) == 500. && greenPlayer3.getPositiony(0) == 500. && greenPlayer4.getPositiony(0) == 500.))
									{
										void resultAnimation(sf::RenderWindow& window, int winner= 2);
									}
									std::cout << "\n \n Player red turn";
									Playerturn += 1;
								}
								else if (moveGreenPlayer == 3)
								{
									greenPlayer3.draw(window, diceno);
									// while(diceno==6||diceno==1)
									// {
									// 	greenPlayer3.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((greenPlayer3.getPositionx(0) != 100. || greenPlayer3.getPositionx(0) != 433.333 || greenPlayer3.getPositionx(0) != 566.666 || greenPlayer3.getPositionx(0) != 833.333 || greenPlayer3.getPositionx(0) != 900. || greenPlayer3.getPositionx(0) != 566.666 || greenPlayer3.getPositionx(0) != 433.333 || greenPlayer3.getPositionx(0) != 166.667) && (greenPlayer3.getPositiony(0) != 433.333 || greenPlayer3.getPositiony(0) != 166.67 || greenPlayer3.getPositiony(0) != 100. || greenPlayer3.getPositiony(0) != 433.333 || greenPlayer3.getPositiony(0) != 566.666 || greenPlayer3.getPositiony(0) != 833.333 || greenPlayer3.getPositiony(0) != 900. || greenPlayer3.getPositiony(0) != 566.667))
									{
										//for common blue
										if ((greenPlayer3.getPositionx(0) == bluePlayer1.getPositionx(0)) && greenPlayer3.getPositiony(0) == bluePlayer1.getPositiony(0))
										{
											bluePlayer1.resetPosition();
											bluePlayer1.draw(window, 0);
										}
										if ((greenPlayer3.getPositionx(0) == bluePlayer2.getPositionx(0)) && greenPlayer3.getPositiony(0) == bluePlayer2.getPositiony(0))
										{
											bluePlayer2.resetPosition();
											bluePlayer2.draw(window, 0);
										}
										if ((greenPlayer3.getPositionx(0) == bluePlayer3.getPositionx(0)) && greenPlayer3.getPositiony(0) == bluePlayer3.getPositiony(0))
										{
											bluePlayer3.resetPosition();
											bluePlayer3.draw(window, 0);
										}
										if ((greenPlayer3.getPositionx(0) == bluePlayer4.getPositionx(0)) && greenPlayer3.getPositiony(0) == bluePlayer4.getPositiony(0))
										{
											bluePlayer4.resetPosition();
											bluePlayer4.draw(window, 0);
										}
										//for common yellow
										if ((greenPlayer3.getPositionx(0) == yellowPlayer1.getPositionx(0)) && greenPlayer3.getPositiony(0) == yellowPlayer1.getPositiony(0))
										{
											yellowPlayer1.resetPosition();
											yellowPlayer1.draw(window, 0);
										}
										if ((greenPlayer3.getPositionx(0) == yellowPlayer2.getPositionx(0)) && greenPlayer3.getPositiony(0) == yellowPlayer2.getPositiony(0))
										{
											yellowPlayer2.resetPosition();
											yellowPlayer2.draw(window, 0);
										}
										if ((greenPlayer3.getPositionx(0) == yellowPlayer3.getPositionx(0)) && greenPlayer3.getPositiony(0) == yellowPlayer3.getPositiony(0))
										{
											yellowPlayer3.resetPosition();
											yellowPlayer3.draw(window, 0);
										}
										if ((greenPlayer3.getPositionx(0) == yellowPlayer4.getPositionx(0)) && greenPlayer3.getPositiony(0) == yellowPlayer4.getPositiony(0))
										{
											yellowPlayer4.resetPosition();
											yellowPlayer4.draw(window, 0);
										}
										//for common red
										if ((greenPlayer3.getPositionx(0) == redPlayer1.getPositionx(0)) && greenPlayer3.getPositiony(0) == redPlayer1.getPositiony(0))
										{
											redPlayer1.resetPosition();
											redPlayer1.draw(window, 0);
										}
										if ((greenPlayer3.getPositionx(0) == redPlayer2.getPositionx(0)) && greenPlayer3.getPositiony(0) == redPlayer2.getPositiony(0))
										{
											redPlayer2.resetPosition();
											redPlayer2.draw(window, 0);
										}
										if ((greenPlayer3.getPositionx(0) == redPlayer3.getPositionx(0)) && greenPlayer3.getPositiony(0) == redPlayer3.getPositiony(0))
										{
											redPlayer3.resetPosition();
											redPlayer3.draw(window, 0);
										}
										if ((greenPlayer3.getPositionx(0) == redPlayer4.getPositionx(0)) && greenPlayer3.getPositiony(0) == redPlayer4.getPositiony(0))
										{
											redPlayer4.resetPosition();
											redPlayer4.draw(window, 0);
										}
									}
									if ((greenPlayer3.getPositionx(0) == 433.333 && greenPlayer3.getPositionx(0) == 433.333 && greenPlayer3.getPositionx(0) == 433.333 && greenPlayer4.getPositionx(0) == 433.333)
										&& (greenPlayer3.getPositiony(0) == 500. && greenPlayer3.getPositiony(0) == 500. && greenPlayer3.getPositiony(0) == 500. && greenPlayer4.getPositiony(0) == 500.))
									{
										void resultAnimation(sf::RenderWindow& window, int winner= 2);
									}
									std::cout << "\n \n Player red turn";
									Playerturn += 1;
								}
								else if (moveGreenPlayer == 4)
								{
									greenPlayer4.draw(window, diceno);
									// while(diceno==6||diceno==1)
									// {
									// 	greenPlayer4.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((greenPlayer4.getPositionx(0) != 100. || greenPlayer4.getPositionx(0) != 433.333 || greenPlayer4.getPositionx(0) != 566.666 || greenPlayer4.getPositionx(0) != 833.333 || greenPlayer4.getPositionx(0) != 900. || greenPlayer4.getPositionx(0) != 566.666 || greenPlayer4.getPositionx(0) != 433.333 || greenPlayer4.getPositionx(0) != 166.667) && (greenPlayer4.getPositiony(0) != 433.333 || greenPlayer4.getPositiony(0) != 166.67 || greenPlayer4.getPositiony(0) != 100. || greenPlayer4.getPositiony(0) != 433.333 || greenPlayer4.getPositiony(0) != 566.666 || greenPlayer4.getPositiony(0) != 833.333 || greenPlayer4.getPositiony(0) != 900. || greenPlayer4.getPositiony(0) != 566.667))
									{
										//for common blue
										if ((greenPlayer4.getPositionx(0) == bluePlayer1.getPositionx(0)) && greenPlayer4.getPositiony(0) == bluePlayer1.getPositiony(0))
										{
											bluePlayer1.resetPosition();
											bluePlayer1.draw(window, 0);
										}
										if ((greenPlayer4.getPositionx(0) == bluePlayer2.getPositionx(0)) && greenPlayer4.getPositiony(0) == bluePlayer2.getPositiony(0))
										{
											bluePlayer2.resetPosition();
											bluePlayer2.draw(window, 0);
										}
										if ((greenPlayer4.getPositionx(0) == bluePlayer3.getPositionx(0)) && greenPlayer4.getPositiony(0) == bluePlayer3.getPositiony(0))
										{
											bluePlayer3.resetPosition();
											bluePlayer3.draw(window, 0);
										}
										if ((greenPlayer4.getPositionx(0) == bluePlayer4.getPositionx(0)) && greenPlayer4.getPositiony(0) == bluePlayer4.getPositiony(0))
										{
											bluePlayer4.resetPosition();
											bluePlayer4.draw(window, 0);
										}
										//for common yellow
										if ((greenPlayer4.getPositionx(0) == yellowPlayer1.getPositionx(0)) && greenPlayer4.getPositiony(0) == yellowPlayer1.getPositiony(0))
										{
											yellowPlayer1.resetPosition();
											yellowPlayer1.draw(window, 0);
										}
										if ((greenPlayer4.getPositionx(0) == yellowPlayer2.getPositionx(0)) && greenPlayer4.getPositiony(0) == yellowPlayer2.getPositiony(0))
										{
											yellowPlayer2.resetPosition();
											yellowPlayer2.draw(window, 0);
										}
										if ((greenPlayer4.getPositionx(0) == yellowPlayer3.getPositionx(0)) && greenPlayer4.getPositiony(0) == yellowPlayer3.getPositiony(0))
										{
											yellowPlayer3.resetPosition();
											yellowPlayer3.draw(window, 0);
										}
										if ((greenPlayer4.getPositionx(0) == yellowPlayer4.getPositionx(0)) && greenPlayer4.getPositiony(0) == yellowPlayer4.getPositiony(0))
										{
											yellowPlayer4.resetPosition();
											yellowPlayer4.draw(window, 0);
										}
										//for common red
										if ((greenPlayer4.getPositionx(0) == redPlayer1.getPositionx(0)) && greenPlayer4.getPositiony(0) == redPlayer1.getPositiony(0))
										{
											redPlayer1.resetPosition();
											redPlayer1.draw(window, 0);
										}
										if ((greenPlayer4.getPositionx(0) == redPlayer2.getPositionx(0)) && greenPlayer4.getPositiony(0) == redPlayer2.getPositiony(0))
										{
											redPlayer2.resetPosition();
											redPlayer2.draw(window, 0);
										}
										if ((greenPlayer4.getPositionx(0) == redPlayer3.getPositionx(0)) && greenPlayer4.getPositiony(0) == redPlayer3.getPositiony(0))
										{
											redPlayer3.resetPosition();
											redPlayer3.draw(window, 0);
										}
										if ((greenPlayer4.getPositionx(0) == redPlayer4.getPositionx(0)) && greenPlayer4.getPositiony(0) == redPlayer4.getPositiony(0))
										{
											redPlayer4.resetPosition();
											redPlayer4.draw(window, 0);
										}
									}
									if ((greenPlayer4.getPositionx(0) == 433.333 && greenPlayer4.getPositionx(0) == 433.333 && greenPlayer4.getPositionx(0) == 433.333 && greenPlayer4.getPositionx(0) == 433.333)
										&& (greenPlayer4.getPositiony(0) == 500. && greenPlayer4.getPositiony(0) == 500. && greenPlayer4.getPositiony(0) == 500. && greenPlayer4.getPositiony(0) == 500.))
									{
										void resultAnimation(sf::RenderWindow& window, int winner= 2);
									}
									std::cout << "\n \n Player red turn";
									Playerturn += 1;
								}
							}
							else if (Playerturn == 3)
							{ //Move Red Player

								window.pollEvent(event);

								if (moveRedPlayer == 1)
								{
									redPlayer1.draw(window, diceno);
									// while(diceno==6||diceno==1)
									// {
									// 	redPlayer1.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((redPlayer1.getPositionx(0) != 566.666 || redPlayer1.getPositionx(0) != 833.333 || redPlayer1.getPositionx(0) != 900. || redPlayer1.getPositionx(0) != 566.666 || redPlayer1.getPositionx(0) != 433.333 || redPlayer1.getPositionx(0) != 166.666 || redPlayer1.getPositionx(0) != 100. || redPlayer1.getPositionx(0) != 433.333) && (redPlayer1.getPositiony(0) != 100. || redPlayer1.getPositiony(0) != 433.333 || redPlayer1.getPositiony(0) != 566.666 || redPlayer1.getPositiony(0) != 833.333 || redPlayer1.getPositiony(0) != 900. || redPlayer1.getPositiony(0) != 566.666 || redPlayer1.getPositiony(0) != 433.333 || redPlayer1.getPositiony(0) != 166.667))
									{
										//for common blue
										if ((redPlayer1.getPositionx(0) == bluePlayer1.getPositionx(0)) && redPlayer1.getPositiony(0) == bluePlayer1.getPositiony(0))
										{
											bluePlayer1.resetPosition();
											bluePlayer1.draw(window, 0);
										}
										if ((redPlayer1.getPositionx(0) == bluePlayer2.getPositionx(0)) && redPlayer1.getPositiony(0) == bluePlayer2.getPositiony(0))
										{
											bluePlayer2.resetPosition();
											bluePlayer2.draw(window, 0);
										}
										if ((redPlayer1.getPositionx(0) == bluePlayer3.getPositionx(0)) && redPlayer1.getPositiony(0) == bluePlayer3.getPositiony(0))
										{
											bluePlayer3.resetPosition();
											bluePlayer3.draw(window, 0);
										}
										if ((redPlayer1.getPositionx(0) == bluePlayer4.getPositionx(0)) && redPlayer1.getPositiony(0) == bluePlayer4.getPositiony(0))
										{
											bluePlayer4.resetPosition();
											bluePlayer4.draw(window, 0);
										}
										//for common yellow
										if ((redPlayer1.getPositionx(0) == yellowPlayer1.getPositionx(0)) && redPlayer1.getPositiony(0) == yellowPlayer1.getPositiony(0))
										{
											yellowPlayer1.resetPosition();
											yellowPlayer1.draw(window, 0);
										}
										if ((redPlayer1.getPositionx(0) == yellowPlayer2.getPositionx(0)) && redPlayer1.getPositiony(0) == yellowPlayer2.getPositiony(0))
										{
											yellowPlayer2.resetPosition();
											yellowPlayer2.draw(window, 0);
										}
										if ((redPlayer1.getPositionx(0) == yellowPlayer3.getPositionx(0)) && redPlayer1.getPositiony(0) == yellowPlayer3.getPositiony(0))
										{
											yellowPlayer3.resetPosition();
											yellowPlayer3.draw(window, 0);
										}
										if ((redPlayer1.getPositionx(0) == yellowPlayer4.getPositionx(0)) && redPlayer1.getPositiony(0) == yellowPlayer4.getPositiony(0))
										{
											yellowPlayer4.resetPosition();
											yellowPlayer4.draw(window, 0);
										}
										//for common green
										if ((redPlayer1.getPositionx(0) == greenPlayer1.getPositionx(0)) && redPlayer1.getPositiony(0) == greenPlayer1.getPositiony(0))
										{
											greenPlayer1.resetPosition();
											greenPlayer1.draw(window, 0);
										}
										if ((redPlayer1.getPositionx(0) == greenPlayer2.getPositionx(0)) && redPlayer1.getPositiony(0) == greenPlayer2.getPositiony(0))
										{
											greenPlayer2.resetPosition();
											greenPlayer2.draw(window, 0);
										}
										if ((redPlayer1.getPositionx(0) == greenPlayer3.getPositionx(0)) && redPlayer1.getPositiony(0) == greenPlayer3.getPositiony(0))
										{
											greenPlayer3.resetPosition();
											greenPlayer3.draw(window, 0);
										}
										if ((redPlayer1.getPositionx(0) == greenPlayer4.getPositionx(0)) && redPlayer1.getPositiony(0) == greenPlayer4.getPositiony(0))
										{
											greenPlayer4.resetPosition();
											greenPlayer4.draw(window, 0);
										}
									}
									if ((redPlayer1.getPositionx(0) == 500. && redPlayer1.getPositionx(0) == 500. && redPlayer1.getPositionx(0) == 500. && redPlayer1.getPositionx(0) == 500.)
										&& (redPlayer1.getPositiony(0) == 433.333 && redPlayer1.getPositiony(0) == 433.333 && redPlayer1.getPositiony(0) == 433.333 && redPlayer1.getPositiony(0) == 433.333))
									{

										void resultAnimation(sf::RenderWindow& window, int winner= 3);
									}
									std::cout << "\n \n Player blue turn";
									Playerturn += 1;
								}
								else if (moveRedPlayer == 2)
								{
									redPlayer2.draw(window, diceno);
									// while(diceno==6||diceno==1)
									// {
									// 	redPlayer2.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((redPlayer2.getPositionx(0) != 566.666 || redPlayer2.getPositionx(0) != 833.333 || redPlayer2.getPositionx(0) != 900. || redPlayer2.getPositionx(0) != 566.666 || redPlayer2.getPositionx(0) != 433.333 || redPlayer2.getPositionx(0) != 166.666 || redPlayer2.getPositionx(0) != 100. || redPlayer2.getPositionx(0) != 433.333) && (redPlayer2.getPositiony(0) != 100. || redPlayer2.getPositiony(0) != 433.333 || redPlayer2.getPositiony(0) != 566.666 || redPlayer2.getPositiony(0) != 833.333 || redPlayer2.getPositiony(0) != 900. || redPlayer2.getPositiony(0) != 566.666 || redPlayer2.getPositiony(0) != 433.333 || redPlayer2.getPositiony(0) != 166.667))
									{
										//for common blue
										if ((redPlayer2.getPositionx(0) == bluePlayer1.getPositionx(0)) && redPlayer2.getPositiony(0) == bluePlayer1.getPositiony(0))
										{
											bluePlayer1.resetPosition();
											bluePlayer1.draw(window, 0);
										}
										if ((redPlayer2.getPositionx(0) == bluePlayer2.getPositionx(0)) && redPlayer2.getPositiony(0) == bluePlayer2.getPositiony(0))
										{
											bluePlayer2.resetPosition();
											bluePlayer2.draw(window, 0);
										}
										if ((redPlayer2.getPositionx(0) == bluePlayer3.getPositionx(0)) && redPlayer2.getPositiony(0) == bluePlayer3.getPositiony(0))
										{
											bluePlayer3.resetPosition();
											bluePlayer3.draw(window, 0);
										}
										if ((redPlayer2.getPositionx(0) == bluePlayer4.getPositionx(0)) && redPlayer2.getPositiony(0) == bluePlayer4.getPositiony(0))
										{
											bluePlayer4.resetPosition();
											bluePlayer4.draw(window, 0);
										}
										//for common yellow
										if ((redPlayer2.getPositionx(0) == yellowPlayer1.getPositionx(0)) && redPlayer2.getPositiony(0) == yellowPlayer1.getPositiony(0))
										{
											yellowPlayer1.resetPosition();
											yellowPlayer1.draw(window, 0);
										}
										if ((redPlayer2.getPositionx(0) == yellowPlayer2.getPositionx(0)) && redPlayer2.getPositiony(0) == yellowPlayer2.getPositiony(0))
										{
											yellowPlayer2.resetPosition();
											yellowPlayer2.draw(window, 0);
										}
										if ((redPlayer2.getPositionx(0) == yellowPlayer3.getPositionx(0)) && redPlayer2.getPositiony(0) == yellowPlayer3.getPositiony(0))
										{
											yellowPlayer3.resetPosition();
											yellowPlayer3.draw(window, 0);
										}
										if ((redPlayer2.getPositionx(0) == yellowPlayer4.getPositionx(0)) && redPlayer2.getPositiony(0) == yellowPlayer4.getPositiony(0))
										{
											yellowPlayer4.resetPosition();
											yellowPlayer4.draw(window, 0);
										}
										//for common green
										if ((redPlayer2.getPositionx(0) == greenPlayer1.getPositionx(0)) && redPlayer2.getPositiony(0) == greenPlayer1.getPositiony(0))
										{
											greenPlayer1.resetPosition();
											greenPlayer1.draw(window, 0);
										}
										if ((redPlayer2.getPositionx(0) == greenPlayer2.getPositionx(0)) && redPlayer2.getPositiony(0) == greenPlayer2.getPositiony(0))
										{
											greenPlayer2.resetPosition();
											greenPlayer2.draw(window, 0);
										}
										if ((redPlayer2.getPositionx(0) == greenPlayer3.getPositionx(0)) && redPlayer2.getPositiony(0) == greenPlayer3.getPositiony(0))
										{
											greenPlayer3.resetPosition();
											greenPlayer3.draw(window, 0);
										}
										if ((redPlayer2.getPositionx(0) == greenPlayer4.getPositionx(0)) && redPlayer2.getPositiony(0) == greenPlayer4.getPositiony(0))
										{
											greenPlayer4.resetPosition();
											greenPlayer4.draw(window, 0);
										}
									}
									if ((redPlayer2.getPositionx(0) == 500. && redPlayer2.getPositionx(0) == 500. && redPlayer2.getPositionx(0) == 500. && redPlayer2.getPositionx(0) == 500.)
										&& (redPlayer2.getPositiony(0) == 433.333 && redPlayer2.getPositiony(0) == 433.333 && redPlayer2.getPositiony(0) == 433.333 && redPlayer2.getPositiony(0) == 433.333))
									{

										void resultAnimation(sf::RenderWindow& window, int winner= 3);
									}
									std::cout << "\n \n Player blue turn";
									Playerturn += 1;
								}
								else if (moveRedPlayer == 3)
								{
									redPlayer3.draw(window, diceno);
									// while(diceno==6||diceno==1)
									// {
									// 	redPlayer3.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((redPlayer3.getPositionx(0) != 566.666 || redPlayer3.getPositionx(0) != 833.333 || redPlayer3.getPositionx(0) != 900. || redPlayer3.getPositionx(0) != 566.666 || redPlayer3.getPositionx(0) != 433.333 || redPlayer3.getPositionx(0) != 166.666 || redPlayer3.getPositionx(0) != 100. || redPlayer3.getPositionx(0) != 433.333) && (redPlayer3.getPositiony(0) != 100. || redPlayer3.getPositiony(0) != 433.333 || redPlayer3.getPositiony(0) != 566.666 || redPlayer3.getPositiony(0) != 833.333 || redPlayer3.getPositiony(0) != 900. || redPlayer3.getPositiony(0) != 566.666 || redPlayer3.getPositiony(0) != 433.333 || redPlayer3.getPositiony(0) != 166.667))
									{
										//for common blue
										if ((redPlayer3.getPositionx(0) == bluePlayer1.getPositionx(0)) && redPlayer3.getPositiony(0) == bluePlayer1.getPositiony(0))
										{
											bluePlayer1.resetPosition();
											bluePlayer1.draw(window, 0);
										}
										if ((redPlayer3.getPositionx(0) == bluePlayer2.getPositionx(0)) && redPlayer3.getPositiony(0) == bluePlayer2.getPositiony(0))
										{
											bluePlayer2.resetPosition();
											bluePlayer2.draw(window, 0);
										}
										if ((redPlayer3.getPositionx(0) == bluePlayer3.getPositionx(0)) && redPlayer3.getPositiony(0) == bluePlayer3.getPositiony(0))
										{
											bluePlayer3.resetPosition();
											bluePlayer3.draw(window, 0);
										}
										if ((redPlayer3.getPositionx(0) == bluePlayer4.getPositionx(0)) && redPlayer3.getPositiony(0) == bluePlayer4.getPositiony(0))
										{
											bluePlayer4.resetPosition();
											bluePlayer4.draw(window, 0);
										}
										//for common yellow
										if ((redPlayer3.getPositionx(0) == yellowPlayer1.getPositionx(0)) && redPlayer3.getPositiony(0) == yellowPlayer1.getPositiony(0))
										{
											yellowPlayer1.resetPosition();
											yellowPlayer1.draw(window, 0);
										}
										if ((redPlayer3.getPositionx(0) == yellowPlayer2.getPositionx(0)) && redPlayer3.getPositiony(0) == yellowPlayer2.getPositiony(0))
										{
											yellowPlayer2.resetPosition();
											yellowPlayer2.draw(window, 0);
										}
										if ((redPlayer3.getPositionx(0) == yellowPlayer3.getPositionx(0)) && redPlayer3.getPositiony(0) == yellowPlayer3.getPositiony(0))
										{
											yellowPlayer3.resetPosition();
											yellowPlayer3.draw(window, 0);
										}
										if ((redPlayer3.getPositionx(0) == yellowPlayer4.getPositionx(0)) && redPlayer3.getPositiony(0) == yellowPlayer4.getPositiony(0))
										{
											yellowPlayer4.resetPosition();
											yellowPlayer4.draw(window, 0);
										}
										//for common green
										if ((redPlayer3.getPositionx(0) == greenPlayer1.getPositionx(0)) && redPlayer3.getPositiony(0) == greenPlayer1.getPositiony(0))
										{
											greenPlayer1.resetPosition();
											greenPlayer1.draw(window, 0);
										}
										if ((redPlayer3.getPositionx(0) == greenPlayer2.getPositionx(0)) && redPlayer3.getPositiony(0) == greenPlayer2.getPositiony(0))
										{
											greenPlayer2.resetPosition();
											greenPlayer2.draw(window, 0);
										}
										if ((redPlayer3.getPositionx(0) == greenPlayer3.getPositionx(0)) && redPlayer3.getPositiony(0) == greenPlayer3.getPositiony(0))
										{
											greenPlayer3.resetPosition();
											greenPlayer3.draw(window, 0);
										}
										if ((redPlayer3.getPositionx(0) == greenPlayer4.getPositionx(0)) && redPlayer3.getPositiony(0) == greenPlayer4.getPositiony(0))
										{
											greenPlayer4.resetPosition();
											greenPlayer4.draw(window, 0);
										}
									}
									if ((redPlayer3.getPositionx(0) == 500. && redPlayer3.getPositionx(0) == 500. && redPlayer3.getPositionx(0) == 500. && redPlayer3.getPositionx(0) == 500.)
										&& (redPlayer3.getPositiony(0) == 433.333 && redPlayer3.getPositiony(0) == 433.333 && redPlayer3.getPositiony(0) == 433.333 && redPlayer3.getPositiony(0) == 433.333))
									{

										void resultAnimation(sf::RenderWindow& window, int winner= 3);
									}
									std::cout << "\n \n Player blue turn";
									Playerturn += 1;
								}
								else if (moveRedPlayer == 4)
								{
									redPlayer4.draw(window, diceno);
									// while(diceno==6||diceno==1)
									// {
									// 	redPlayer4.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((redPlayer4.getPositionx(0) != 566.666 || redPlayer4.getPositionx(0) != 833.333 || redPlayer4.getPositionx(0) != 900. || redPlayer4.getPositionx(0) != 566.666 || redPlayer4.getPositionx(0) != 433.333 || redPlayer4.getPositionx(0) != 166.666 || redPlayer4.getPositionx(0) != 100. || redPlayer4.getPositionx(0) != 433.333) && (redPlayer4.getPositiony(0) != 100. || redPlayer4.getPositiony(0) != 433.333 || redPlayer4.getPositiony(0) != 566.666 || redPlayer4.getPositiony(0) != 833.333 || redPlayer4.getPositiony(0) != 900. || redPlayer4.getPositiony(0) != 566.666 || redPlayer4.getPositiony(0) != 433.333 || redPlayer4.getPositiony(0) != 166.667))
									{
										//for common blue
										if ((redPlayer4.getPositionx(0) == bluePlayer1.getPositionx(0)) && redPlayer4.getPositiony(0) == bluePlayer1.getPositiony(0))
										{
											bluePlayer1.resetPosition();
											bluePlayer1.draw(window, 0);
										}
										if ((redPlayer4.getPositionx(0) == bluePlayer2.getPositionx(0)) && redPlayer4.getPositiony(0) == bluePlayer2.getPositiony(0))
										{
											bluePlayer2.resetPosition();
											bluePlayer2.draw(window, 0);
										}
										if ((redPlayer4.getPositionx(0) == bluePlayer3.getPositionx(0)) && redPlayer4.getPositiony(0) == bluePlayer3.getPositiony(0))
										{
											bluePlayer3.resetPosition();
											bluePlayer3.draw(window, 0);
										}
										if ((redPlayer4.getPositionx(0) == bluePlayer4.getPositionx(0)) && redPlayer4.getPositiony(0) == bluePlayer4.getPositiony(0))
										{
											bluePlayer4.resetPosition();
											bluePlayer4.draw(window, 0);
										}
										//for common yellow
										if ((redPlayer4.getPositionx(0) == yellowPlayer1.getPositionx(0)) && redPlayer4.getPositiony(0) == yellowPlayer1.getPositiony(0))
										{
											yellowPlayer1.resetPosition();
											yellowPlayer1.draw(window, 0);
										}
										if ((redPlayer4.getPositionx(0) == yellowPlayer2.getPositionx(0)) && redPlayer4.getPositiony(0) == yellowPlayer2.getPositiony(0))
										{
											yellowPlayer2.resetPosition();
											yellowPlayer2.draw(window, 0);
										}
										if ((redPlayer4.getPositionx(0) == yellowPlayer3.getPositionx(0)) && redPlayer4.getPositiony(0) == yellowPlayer3.getPositiony(0))
										{
											yellowPlayer3.resetPosition();
											yellowPlayer3.draw(window, 0);
										}
										if ((redPlayer4.getPositionx(0) == yellowPlayer4.getPositionx(0)) && redPlayer4.getPositiony(0) == yellowPlayer4.getPositiony(0))
										{
											yellowPlayer4.resetPosition();
											yellowPlayer4.draw(window, 0);
										}
										//for common green
										if ((redPlayer4.getPositionx(0) == greenPlayer1.getPositionx(0)) && redPlayer4.getPositiony(0) == greenPlayer1.getPositiony(0))
										{
											greenPlayer1.resetPosition();
											greenPlayer1.draw(window, 0);
										}
										if ((redPlayer4.getPositionx(0) == greenPlayer2.getPositionx(0)) && redPlayer4.getPositiony(0) == greenPlayer2.getPositiony(0))
										{
											greenPlayer2.resetPosition();
											greenPlayer2.draw(window, 0);
										}
										if ((redPlayer4.getPositionx(0) == greenPlayer3.getPositionx(0)) && redPlayer4.getPositiony(0) == greenPlayer3.getPositiony(0))
										{
											greenPlayer3.resetPosition();
											greenPlayer3.draw(window, 0);
										}
										if ((redPlayer4.getPositionx(0) == greenPlayer4.getPositionx(0)) && redPlayer4.getPositiony(0) == greenPlayer4.getPositiony(0))
										{
											greenPlayer4.resetPosition();
											greenPlayer4.draw(window, 0);
										}
									}
									if ((redPlayer4.getPositionx(0) == 500. && redPlayer4.getPositionx(0) == 500. && redPlayer4.getPositionx(0) == 500. && redPlayer4.getPositionx(0) == 500.)
										&& (redPlayer4.getPositiony(0) == 433.333 && redPlayer4.getPositiony(0) == 433.333 && redPlayer4.getPositiony(0) == 433.333 && redPlayer4.getPositiony(0) == 433.333))
									{

										void resultAnimation(sf::RenderWindow& window, int winner= 3);
									}
									std::cout << "\n \n Player blue turn";
									Playerturn += 1;
								}
							}
							else if (Playerturn == 4)
							{ //Move blue Player

								window.pollEvent(event);

								if (moveBluePlayer == 1)
								{
									bluePlayer1.draw(window, diceno);
									// while(diceno==6||diceno==1)
									// {
									// 	bluePlayer1.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((bluePlayer1.getPositionx(0) != 566.666 || bluePlayer1.getPositionx(0) != 833.333 || bluePlayer1.getPositionx(0) != 900. || bluePlayer1.getPositionx(0) != 566.666 || bluePlayer1.getPositionx(0) != 433.333 || bluePlayer1.getPositionx(0) != 166.666 || bluePlayer1.getPositionx(0) != 100. || bluePlayer1.getPositionx(0) != 433.333) && (bluePlayer1.getPositiony(0) != 100. || bluePlayer1.getPositiony(0) != 433.333 || bluePlayer1.getPositiony(0) != 566.666 || bluePlayer1.getPositiony(0) != 833.333 || bluePlayer1.getPositiony(0) != 900. || bluePlayer1.getPositiony(0) != 566.666 || bluePlayer1.getPositiony(0) != 433.333 || bluePlayer1.getPositiony(0) != 166.667))
									{
										//for common red
										if ((bluePlayer1.getPositionx(0) == redPlayer1.getPositionx(0)) && bluePlayer1.getPositiony(0) == redPlayer1.getPositiony(0))
										{
											redPlayer1.resetPosition();
											redPlayer1.draw(window, 0);
										}
										if ((bluePlayer1.getPositionx(0) == redPlayer2.getPositionx(0)) && bluePlayer1.getPositiony(0) == redPlayer2.getPositiony(0))
										{
											redPlayer2.resetPosition();
											redPlayer2.draw(window, 0);
										}
										if ((bluePlayer1.getPositionx(0) == redPlayer3.getPositionx(0)) && bluePlayer1.getPositiony(0) == redPlayer3.getPositiony(0))
										{
											redPlayer3.resetPosition();
											redPlayer3.draw(window, 0);
										}
										if ((bluePlayer1.getPositionx(0) == redPlayer4.getPositionx(0)) && bluePlayer1.getPositiony(0) == redPlayer4.getPositiony(0))
										{
											redPlayer4.resetPosition();
											redPlayer4.draw(window, 0);
										}
										//for common yellow
										if ((bluePlayer1.getPositionx(0) == yellowPlayer1.getPositionx(0)) && bluePlayer1.getPositiony(0) == yellowPlayer1.getPositiony(0))
										{
											yellowPlayer1.resetPosition();
											yellowPlayer1.draw(window, 0);
										}
										if ((bluePlayer1.getPositionx(0) == yellowPlayer2.getPositionx(0)) && bluePlayer1.getPositiony(0) == yellowPlayer2.getPositiony(0))
										{
											yellowPlayer2.resetPosition();
											yellowPlayer2.draw(window, 0);
										}
										if ((bluePlayer1.getPositionx(0) == yellowPlayer3.getPositionx(0)) && bluePlayer1.getPositiony(0) == yellowPlayer3.getPositiony(0))
										{
											yellowPlayer3.resetPosition();
											yellowPlayer3.draw(window, 0);
										}
										if ((bluePlayer1.getPositionx(0) == yellowPlayer4.getPositionx(0)) && bluePlayer1.getPositiony(0) == yellowPlayer4.getPositiony(0))
										{
											yellowPlayer4.resetPosition();
											yellowPlayer4.draw(window, 0);
										}
										//for common green
										if ((bluePlayer1.getPositionx(0) == greenPlayer1.getPositionx(0)) && bluePlayer1.getPositiony(0) == greenPlayer1.getPositiony(0))
										{
											greenPlayer1.resetPosition();
											greenPlayer1.draw(window, 0);
										}
										if ((bluePlayer1.getPositionx(0) == greenPlayer1.getPositionx(0)) && bluePlayer1.getPositiony(0) == greenPlayer2.getPositiony(0))
										{
											greenPlayer2.resetPosition();
											greenPlayer2.draw(window, 0);
										}
										if ((bluePlayer1.getPositionx(0) == greenPlayer1.getPositionx(0)) && bluePlayer1.getPositiony(0) == greenPlayer3.getPositiony(0))
										{
											greenPlayer3.resetPosition();
											greenPlayer3.draw(window, 0);
										}
										if ((bluePlayer1.getPositionx(0) == greenPlayer4.getPositionx(0)) && bluePlayer1.getPositiony(0) == greenPlayer4.getPositiony(0))
										{
											greenPlayer4.resetPosition();
											greenPlayer4.draw(window, 0);
										}
									}
									if ((bluePlayer1.getPositionx(0) == 500. && bluePlayer1.getPositionx(0) == 500. && bluePlayer1.getPositionx(0) == 500. && bluePlayer1.getPositionx(0) == 500.)
										&& (bluePlayer1.getPositiony(0) == 433.333 && bluePlayer1.getPositiony(0) == 433.333 && bluePlayer1.getPositiony(0) == 433.333 && bluePlayer1.getPositiony(0) == 433.333))
									{

										void resultAnimation(sf::RenderWindow& window, int winner= 4);
									}
									std::cout << "\n \n Player yellow turn";
									Playerturn = 1;
								}
								else if (moveBluePlayer == 2)
								{
									bluePlayer2.draw(window, diceno);
									// while(diceno==6||diceno==1)
									// {
									// 	bluePlayer2.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((bluePlayer2.getPositionx(0) != 566.666 || bluePlayer2.getPositionx(0) != 833.333 || bluePlayer2.getPositionx(0) != 900. || bluePlayer2.getPositionx(0) != 566.666 || bluePlayer2.getPositionx(0) != 433.333 || bluePlayer2.getPositionx(0) != 166.666 || bluePlayer2.getPositionx(0) != 100. || bluePlayer2.getPositionx(0) != 433.333) && (bluePlayer2.getPositiony(0) != 100. || bluePlayer2.getPositiony(0) != 433.333 || bluePlayer2.getPositiony(0) != 566.666 || bluePlayer2.getPositiony(0) != 833.333 || bluePlayer2.getPositiony(0) != 900. || bluePlayer2.getPositiony(0) != 566.666 || bluePlayer2.getPositiony(0) != 433.333 || bluePlayer2.getPositiony(0) != 166.667))
									{
										//for common red
										if ((bluePlayer2.getPositionx(0) == redPlayer1.getPositionx(0)) && bluePlayer2.getPositiony(0) == redPlayer1.getPositiony(0))
										{
											redPlayer1.resetPosition();
											redPlayer1.draw(window, 0);
										}
										if ((bluePlayer2.getPositionx(0) == redPlayer2.getPositionx(0)) && bluePlayer2.getPositiony(0) == redPlayer2.getPositiony(0))
										{
											redPlayer2.resetPosition();
											redPlayer2.draw(window, 0);
										}
										if ((bluePlayer2.getPositionx(0) == redPlayer3.getPositionx(0)) && bluePlayer2.getPositiony(0) == redPlayer3.getPositiony(0))
										{
											redPlayer3.resetPosition();
											redPlayer3.draw(window, 0);
										}
										if ((bluePlayer2.getPositionx(0) == redPlayer4.getPositionx(0)) && bluePlayer2.getPositiony(0) == redPlayer4.getPositiony(0))
										{
											redPlayer4.resetPosition();
											redPlayer4.draw(window, 0);
										}
										//for common yellow
										if ((bluePlayer2.getPositionx(0) == yellowPlayer1.getPositionx(0)) && bluePlayer2.getPositiony(0) == yellowPlayer1.getPositiony(0))
										{
											yellowPlayer1.resetPosition();
											yellowPlayer1.draw(window, 0);
										}
										if ((bluePlayer2.getPositionx(0) == yellowPlayer2.getPositionx(0)) && bluePlayer2.getPositiony(0) == yellowPlayer2.getPositiony(0))
										{
											yellowPlayer2.resetPosition();
											yellowPlayer2.draw(window, 0);
										}
										if ((bluePlayer2.getPositionx(0) == yellowPlayer3.getPositionx(0)) && bluePlayer2.getPositiony(0) == yellowPlayer3.getPositiony(0))
										{
											yellowPlayer3.resetPosition();
											yellowPlayer3.draw(window, 0);
										}
										if ((bluePlayer2.getPositionx(0) == yellowPlayer4.getPositionx(0)) && bluePlayer2.getPositiony(0) == yellowPlayer4.getPositiony(0))
										{
											yellowPlayer4.resetPosition();
											yellowPlayer4.draw(window, 0);
										}
										//for common green
										if ((bluePlayer2.getPositionx(0) == greenPlayer1.getPositionx(0)) && bluePlayer2.getPositiony(0) == greenPlayer1.getPositiony(0))
										{
											greenPlayer1.resetPosition();
											greenPlayer1.draw(window, 0);
										}
										if ((bluePlayer2.getPositionx(0) == greenPlayer2.getPositionx(0)) && bluePlayer2.getPositiony(0) == greenPlayer2.getPositiony(0))
										{
											greenPlayer2.resetPosition();
											greenPlayer2.draw(window, 0);
										}
										if ((bluePlayer2.getPositionx(0) == greenPlayer3.getPositionx(0)) && bluePlayer2.getPositiony(0) == greenPlayer3.getPositiony(0))
										{
											greenPlayer3.resetPosition();
											greenPlayer3.draw(window, 0);
										}
										if ((bluePlayer2.getPositionx(0) == greenPlayer4.getPositionx(0)) && bluePlayer2.getPositiony(0) == greenPlayer4.getPositiony(0))
										{
											greenPlayer4.resetPosition();
											greenPlayer4.draw(window, 0);
										}
									}
									if ((bluePlayer2.getPositionx(0) == 500. && bluePlayer2.getPositionx(0) == 500. && bluePlayer2.getPositionx(0) == 500. && bluePlayer2.getPositionx(0) == 500.)
										&& (bluePlayer2.getPositiony(0) == 433.333 && bluePlayer2.getPositiony(0) == 433.333 && bluePlayer2.getPositiony(0) == 433.333 && bluePlayer2.getPositiony(0) == 433.333))
									{

										void resultAnimation(sf::RenderWindow& window, int winner= 4);
									}
									std::cout << "\n \n Player yellow turn";
									Playerturn = 1;
								}
								else if (moveBluePlayer == 3)
								{
									bluePlayer3.draw(window, diceno);
									// while(diceno==6||diceno==1)
									// {
									// 	bluePlayer3.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((bluePlayer3.getPositionx(0) != 566.666 || bluePlayer3.getPositionx(0) != 833.333 || bluePlayer3.getPositionx(0) != 900. || bluePlayer3.getPositionx(0) != 566.666 || bluePlayer3.getPositionx(0) != 433.333 || bluePlayer3.getPositionx(0) != 166.666 || bluePlayer3.getPositionx(0) != 100. || bluePlayer3.getPositionx(0) != 433.333) && (bluePlayer3.getPositiony(0) != 100. || bluePlayer3.getPositiony(0) != 433.333 || bluePlayer3.getPositiony(0) != 566.666 || bluePlayer3.getPositiony(0) != 833.333 || bluePlayer3.getPositiony(0) != 900. || bluePlayer3.getPositiony(0) != 566.666 || bluePlayer3.getPositiony(0) != 433.333 || bluePlayer3.getPositiony(0) != 166.667))
									{
										//for common red
										if ((bluePlayer3.getPositionx(0) == redPlayer1.getPositionx(0)) && bluePlayer3.getPositiony(0) == redPlayer1.getPositiony(0))
										{
											redPlayer1.resetPosition();
											redPlayer1.draw(window, 0);
										}
										if ((bluePlayer3.getPositionx(0) == redPlayer2.getPositionx(0)) && bluePlayer3.getPositiony(0) == redPlayer2.getPositiony(0))
										{
											redPlayer2.resetPosition();
											redPlayer2.draw(window, 0);
										}
										if ((bluePlayer3.getPositionx(0) == redPlayer3.getPositionx(0)) && bluePlayer3.getPositiony(0) == redPlayer3.getPositiony(0))
										{
											redPlayer3.resetPosition();
											redPlayer3.draw(window, 0);
										}
										if ((bluePlayer3.getPositionx(0) == redPlayer4.getPositionx(0)) && bluePlayer3.getPositiony(0) == redPlayer4.getPositiony(0))
										{
											redPlayer4.resetPosition();
											redPlayer4.draw(window, 0);
										}
										//for common yellow
										if ((bluePlayer3.getPositionx(0) == yellowPlayer1.getPositionx(0)) && bluePlayer3.getPositiony(0) == yellowPlayer1.getPositiony(0))
										{
											yellowPlayer1.resetPosition();
											yellowPlayer1.draw(window, 0);
										}
										if ((bluePlayer3.getPositionx(0) == yellowPlayer2.getPositionx(0)) && bluePlayer3.getPositiony(0) == yellowPlayer2.getPositiony(0))
										{
											yellowPlayer2.resetPosition();
											yellowPlayer2.draw(window, 0);
										}
										if ((bluePlayer3.getPositionx(0) == yellowPlayer3.getPositionx(0)) && bluePlayer3.getPositiony(0) == yellowPlayer3.getPositiony(0))
										{
											yellowPlayer3.resetPosition();
											yellowPlayer3.draw(window, 0);
										}
										if ((bluePlayer3.getPositionx(0) == yellowPlayer4.getPositionx(0)) && bluePlayer3.getPositiony(0) == yellowPlayer4.getPositiony(0))
										{
											yellowPlayer4.resetPosition();
											yellowPlayer4.draw(window, 0);
										}
										//for common green
										if ((bluePlayer3.getPositionx(0) == greenPlayer1.getPositionx(0)) && bluePlayer3.getPositiony(0) == greenPlayer1.getPositiony(0))
										{
											greenPlayer1.resetPosition();
											greenPlayer1.draw(window, 0);
										}
										if ((bluePlayer3.getPositionx(0) == bluePlayer3.getPositionx(0)) && bluePlayer3.getPositiony(0) == greenPlayer2.getPositiony(0))
										{
											greenPlayer2.resetPosition();
											greenPlayer2.draw(window, 0);
										}
										if ((bluePlayer3.getPositionx(0) == bluePlayer3.getPositionx(0)) && bluePlayer3.getPositiony(0) == greenPlayer3.getPositiony(0))
										{
											greenPlayer3.resetPosition();
											greenPlayer3.draw(window, 0);
										}
										if ((bluePlayer3.getPositionx(0) == greenPlayer4.getPositionx(0)) && bluePlayer3.getPositiony(0) == greenPlayer4.getPositiony(0))
										{
											greenPlayer4.resetPosition();
											greenPlayer4.draw(window, 0);
										}
									}
									if ((bluePlayer3.getPositionx(0) == 500. && bluePlayer3.getPositionx(0) == 500. && bluePlayer3.getPositionx(0) == 500. && bluePlayer3.getPositionx(0) == 500.)
										&& (bluePlayer3.getPositiony(0) == 433.333 && bluePlayer3.getPositiony(0) == 433.333 && bluePlayer3.getPositiony(0) == 433.333 && bluePlayer3.getPositiony(0) == 433.333))
									{

										void resultAnimation(sf::RenderWindow& window, int winner= 4);
									}
									std::cout << "\n \n Player yellow turn";
									Playerturn = 1;
								}
								else if (moveBluePlayer == 4)
								{
									bluePlayer4.draw(window, diceno);
									// while(diceno==6||diceno==1)
									// {
									// 	bluePlayer4.draw(window,diceno);
									// }
									//for checking checkpoints
									if ((bluePlayer4.getPositionx(0) != 566.666 || bluePlayer4.getPositionx(0) != 833.333 || bluePlayer4.getPositionx(0) != 900. || bluePlayer4.getPositionx(0) != 566.666 || bluePlayer4.getPositionx(0) != 433.333 || bluePlayer4.getPositionx(0) != 166.666 || bluePlayer4.getPositionx(0) != 100. || bluePlayer4.getPositionx(0) != 433.333) && (bluePlayer4.getPositiony(0) != 100. || bluePlayer4.getPositiony(0) != 433.333 || bluePlayer4.getPositiony(0) != 566.666 || bluePlayer4.getPositiony(0) != 833.333 || bluePlayer4.getPositiony(0) != 900. || bluePlayer4.getPositiony(0) != 566.666 || bluePlayer4.getPositiony(0) != 433.333 || bluePlayer4.getPositiony(0) != 166.667))
									{
										//for common red
										if ((bluePlayer4.getPositionx(0) == redPlayer1.getPositionx(0)) && bluePlayer4.getPositiony(0) == redPlayer1.getPositiony(0))
										{
											redPlayer1.resetPosition();
											redPlayer1.draw(window, 0);
										}
										if ((bluePlayer4.getPositionx(0) == redPlayer2.getPositionx(0)) && bluePlayer4.getPositiony(0) == redPlayer2.getPositiony(0))
										{
											redPlayer2.resetPosition();
											redPlayer2.draw(window, 0);
										}
										if ((bluePlayer4.getPositionx(0) == redPlayer3.getPositionx(0)) && bluePlayer4.getPositiony(0) == redPlayer3.getPositiony(0))
										{
											redPlayer3.resetPosition();
											redPlayer3.draw(window, 0);
										}
										if ((bluePlayer4.getPositionx(0) == redPlayer4.getPositionx(0)) && bluePlayer4.getPositiony(0) == redPlayer4.getPositiony(0))
										{
											redPlayer4.resetPosition();
											redPlayer4.draw(window, 0);
										}
										//for common yellow
										if ((bluePlayer4.getPositionx(0) == yellowPlayer1.getPositionx(0)) && bluePlayer4.getPositiony(0) == yellowPlayer1.getPositiony(0))
										{
											yellowPlayer1.resetPosition();
											yellowPlayer1.draw(window, 0);
										}
										if ((bluePlayer4.getPositionx(0) == yellowPlayer2.getPositionx(0)) && bluePlayer4.getPositiony(0) == yellowPlayer2.getPositiony(0))
										{
											yellowPlayer2.resetPosition();
											yellowPlayer2.draw(window, 0);
										}
										if ((bluePlayer4.getPositionx(0) == yellowPlayer3.getPositionx(0)) && bluePlayer4.getPositiony(0) == yellowPlayer3.getPositiony(0))
										{
											yellowPlayer3.resetPosition();
											yellowPlayer3.draw(window, 0);
										}
										if ((bluePlayer4.getPositionx(0) == yellowPlayer4.getPositionx(0)) && bluePlayer4.getPositiony(0) == yellowPlayer4.getPositiony(0))
										{
											yellowPlayer4.resetPosition();
											yellowPlayer4.draw(window, 0);

											yellowPlayer4.draw(window, 0);
										}
										//for common green
										if ((bluePlayer4.getPositionx(0) == greenPlayer1.getPositionx(0)) && bluePlayer4.getPositiony(0) == greenPlayer1.getPositiony(0))
										{
											greenPlayer1.resetPosition();
											greenPlayer1.draw(window, 0);
										}
										if ((bluePlayer4.getPositionx(0) == greenPlayer2.getPositionx(0)) && bluePlayer4.getPositiony(0) == greenPlayer2.getPositiony(0))
										{
											greenPlayer2.resetPosition();
											greenPlayer2.draw(window, 0);
										}
										if ((bluePlayer4.getPositionx(0) == greenPlayer3.getPositionx(0)) && bluePlayer4.getPositiony(0) == greenPlayer3.getPositiony(0))
										{
											greenPlayer3.resetPosition();
											greenPlayer3.draw(window, 0);
										}
										if ((bluePlayer4.getPositionx(0) == greenPlayer4.getPositionx(0)) && bluePlayer4.getPositiony(0) == greenPlayer4.getPositiony(0))
										{
											greenPlayer4.resetPosition();
											greenPlayer4.draw(window, 0);
										}
									}
									if ((bluePlayer4.getPositionx(0) == 500. && bluePlayer4.getPositionx(0) == 500. && bluePlayer4.getPositionx(0) == 500. && bluePlayer4.getPositionx(0) == 500.)
										&& (bluePlayer4.getPositiony(0) == 433.333 && bluePlayer4.getPositiony(0) == 433.333 && bluePlayer4.getPositiony(0) == 433.333 && bluePlayer4.getPositiony(0) == 433.333))
									{

										void resultAnimation(sf::RenderWindow& window, int winner= 4);
									}
									std::cout << "\n \n Player yellow turn";
									Playerturn = 1;
								}
							}

							yellowPlayer1.draw(window, 0);
							yellowPlayer2.draw(window, 0);
							yellowPlayer3.draw(window, 0);
							yellowPlayer4.draw(window, 0);

							bluePlayer1.draw(window, 0);
							bluePlayer2.draw(window, 0);
							bluePlayer3.draw(window, 0);
							bluePlayer4.draw(window, 0);

							greenPlayer1.draw(window, 0);
							greenPlayer2.draw(window, 0);
							greenPlayer3.draw(window, 0);
							greenPlayer4.draw(window, 0);

							redPlayer1.draw(window, 0);
							redPlayer2.draw(window, 0);
							redPlayer3.draw(window, 0);
							redPlayer4.draw(window, 0);

							sf::Font instfont;
							instfont.loadFromFile("NotoSans-Black.ttf");

							sf::Text insttext;
							insttext.setFont(instfont);
							insttext.setCharacterSize(20);
							insttext.setFillColor(sf::Color::Red);
							insttext.setOrigin(0,0);
							insttext.setPosition(1100,600);
							insttext.setString("Press R to Roll the dice");



							window.draw(t1);
							window.draw(insttext);
							window.display();

							//updating value of diceno
							diceno = dicerollfunc(window, Playerturn);
							std::cout << "\n You got: " << diceno << endl;

							moveYellowPlayer = 10;
							moveBluePlayer = 10;
							moveGreenPlayer = 10;
							moveRedPlayer = 10;

							//Select players among same colors

							if (Playerturn == 1)
							{
								//For Yellow Player selection

								do
								{

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{

										Yellow1PosX = yellowPlayer1.getPosx();
										Yellow1PosY = yellowPlayer1.getPosy();
										Yellow2PosX = yellowPlayer2.getPosx();
										Yellow2PosY = yellowPlayer2.getPosy();
										Yellow3PosX = yellowPlayer3.getPosx();
										Yellow3PosY = yellowPlayer3.getPosy();
										Yellow4PosX = yellowPlayer4.getPosx();
										Yellow4PosY = yellowPlayer4.getPosy();

										MousePosX = sf::Mouse::getPosition(window).x * viewRatio;
										MousePosY = sf::Mouse::getPosition(window).y * viewRatio;

										if ((MousePosX >= yellowPlayer1.getPositionx(0) + 30. / viewRatio && MousePosX <= yellowPlayer1.getPositionx(0) + 80. / viewRatio && MousePosY >= yellowPlayer1.getPositiony(0) + 30. / viewRatio && MousePosY <= yellowPlayer1.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Yellow1PosX + 30. / viewRatio && MousePosX <= Yellow1PosX + 80. / viewRatio && MousePosY >= Yellow1PosY + 30. / viewRatio && MousePosY <= Yellow1PosY + 80. / viewRatio))
										{
											moveYellowPlayer = 1;
										}

										if ((MousePosX >= yellowPlayer2.getPositionx(0) + 30. / viewRatio && MousePosX <= yellowPlayer2.getPositionx(0) + 80. / viewRatio && MousePosY >= yellowPlayer2.getPositiony(0) + 30. / viewRatio && MousePosY <= yellowPlayer2.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Yellow2PosX + 30. / viewRatio && MousePosX <= Yellow2PosX + 80. / viewRatio && MousePosY >= Yellow2PosY + 30. / viewRatio && MousePosY <= Yellow2PosY + 80. / viewRatio))
										{
											moveYellowPlayer = 2;
											std::cout << "mousePos=" << sf::Mouse::getPosition(window).x << endl;
											std::cout << "PlayerPosition=" << yellowPlayer2.getPosx() << endl
													  << endl;
										}
										if ((MousePosX >= yellowPlayer3.getPositionx(0) + 30. / viewRatio && MousePosX <= yellowPlayer3.getPositionx(0) + 80. / viewRatio && MousePosY >= yellowPlayer3.getPositiony(0) + 30. / viewRatio && MousePosY <= yellowPlayer3.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Yellow3PosX + 30. / viewRatio && MousePosX <= Yellow3PosX + 80. / viewRatio && MousePosY >= Yellow3PosY + 30. / viewRatio && MousePosY <= Yellow3PosY + 80. / viewRatio))
										{
											moveYellowPlayer = 3;
										}
										if ((MousePosX >= yellowPlayer4.getPositionx(0) + 30. / viewRatio && MousePosX <= yellowPlayer4.getPositionx(0) + 80 && MousePosY >= yellowPlayer4.getPositiony(0) + 30. / viewRatio && MousePosY <= yellowPlayer4.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Yellow4PosX + 30. / viewRatio && MousePosX <= Yellow4PosX + 80. / viewRatio && MousePosY >= Yellow4PosY + 30. / viewRatio && MousePosY <= Yellow4PosY + 80. / viewRatio))
										{
											moveYellowPlayer = 4;
										}
									}
								} while (moveYellowPlayer > 4 && Playerturn == 1);
							}
							if (Playerturn == 2)
							{
								//For Green Player selection
								do
								{

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{

										Green1PosX = greenPlayer1.getPosx();
										Green1PosY = greenPlayer1.getPosy();
										Green2PosX = greenPlayer2.getPosx();
										Green2PosY = greenPlayer2.getPosy();
										Green3PosX = greenPlayer3.getPosx();
										Green3PosY = greenPlayer3.getPosy();
										Green4PosX = greenPlayer4.getPosx();
										Green4PosY = greenPlayer4.getPosy();

										MousePosX = sf::Mouse::getPosition(window).x * viewRatio;
										MousePosY = sf::Mouse::getPosition(window).y * viewRatio;

										if ((MousePosX >= greenPlayer1.getPositionx(0) + 30. / viewRatio && MousePosX <= greenPlayer1.getPositionx(0) + 80. / viewRatio && MousePosY >= greenPlayer1.getPositiony(0) + 30. / viewRatio && MousePosY <= greenPlayer1.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Green1PosX + 30. / viewRatio && MousePosX <= Green1PosX + 80. / viewRatio && MousePosY >= Green1PosY + 30. / viewRatio && MousePosY <= Green1PosY + 80. / viewRatio))
										{
											moveGreenPlayer = 1;
										}

										if ((MousePosX >= greenPlayer2.getPositionx(0) + 30. / viewRatio && MousePosX <= greenPlayer2.getPositionx(0) + 80. / viewRatio && MousePosY >= greenPlayer2.getPositiony(0) + 30. / viewRatio && MousePosY <= greenPlayer2.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Green2PosX + 30. / viewRatio && MousePosX <= Green2PosX + 80. / viewRatio && MousePosY >= Green2PosY + 30. / viewRatio && MousePosY <= Green2PosY + 80. / viewRatio))
										{
											moveGreenPlayer = 2;
										}
										if ((MousePosX >= greenPlayer3.getPositionx(0) + 30. / viewRatio && MousePosX <= greenPlayer3.getPositionx(0) + 80. / viewRatio && MousePosY >= greenPlayer3.getPositiony(0) + 30. / viewRatio && MousePosY <= greenPlayer3.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Green3PosX + 30. / viewRatio && MousePosX <= Green3PosX + 80. / viewRatio && MousePosY >= Green3PosY + 30. / viewRatio && MousePosY <= Green3PosY + 80. / viewRatio))
										{
											moveGreenPlayer = 3;
										}
										if ((MousePosX >= greenPlayer4.getPositionx(0) + 30. / viewRatio && MousePosX <= greenPlayer4.getPositionx(0) + 80. / viewRatio && MousePosY >= greenPlayer4.getPositiony(0) + 30 && MousePosY <= greenPlayer4.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Green4PosX + 30. / viewRatio && MousePosX <= Green4PosX + 80. / viewRatio && MousePosY >= Green4PosY + 30. / viewRatio && MousePosY <= Green4PosY + 80. / viewRatio))
										{
											moveGreenPlayer = 4;
										}
									}
								} while (moveGreenPlayer > 4 && Playerturn == 2);
							}
							if (Playerturn == 3)
							{
								//For red Player selection

								do
								{

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{

										Red1PosX = redPlayer1.getPosx();
										Red1PosY = redPlayer1.getPosy();
										Red2PosX = redPlayer2.getPosx();
										Red2PosY = redPlayer2.getPosy();
										Red3PosX = redPlayer3.getPosx();
										Red3PosY = redPlayer3.getPosy();
										Red4PosX = redPlayer4.getPosx();
										Red4PosY = redPlayer4.getPosy();

										MousePosX = sf::Mouse::getPosition(window).x * viewRatio;
										MousePosY = sf::Mouse::getPosition(window).y * viewRatio;

										if ((MousePosX >= redPlayer1.getPositionx(0) + 30. / viewRatio && MousePosX <= redPlayer1.getPositionx(0) + 80. / viewRatio && MousePosY >= redPlayer1.getPositiony(0) + 30. / viewRatio && MousePosY <= redPlayer1.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Red1PosX + 30. / viewRatio && MousePosX <= Red1PosX + 80. / viewRatio && MousePosY >= Red1PosY + 30. / viewRatio && MousePosY <= Red1PosY + 80. / viewRatio))
										{
											moveRedPlayer = 1;
										}

										if ((MousePosX >= redPlayer2.getPositionx(0) + 30 && MousePosX <= redPlayer2.getPositionx(0) + 80. / viewRatio && MousePosY >= redPlayer2.getPositiony(0) + 30. / viewRatio && MousePosY <= redPlayer2.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Red2PosX + 30. / viewRatio && MousePosX <= Red2PosX + 80. / viewRatio && MousePosY >= Red2PosY + 30. / viewRatio && MousePosY <= Red2PosY + 80. / viewRatio))
										{
											moveRedPlayer = 2;
										}
										if ((MousePosX >= redPlayer3.getPositionx(0) + 30 && MousePosX <= redPlayer3.getPositionx(0) + 80. / viewRatio && MousePosY >= redPlayer3.getPositiony(0) + 30. / viewRatio && MousePosY <= redPlayer3.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Red3PosX + 30 && MousePosX <= Red3PosX + 80 && MousePosY >= Red3PosY + 30 && MousePosY <= Red3PosY + 80))
										{
											moveRedPlayer = 3;
										}
										if ((MousePosX >= redPlayer4.getPositionx(0) + 30 && MousePosX <= redPlayer4.getPositionx(0) + 80. / viewRatio && MousePosY >= redPlayer4.getPositiony(0) + 30. / viewRatio && MousePosY <= redPlayer4.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Red4PosX + 30. / viewRatio && MousePosX <= Red4PosX + 80. / viewRatio && MousePosY >= Red4PosY + 30. / viewRatio && MousePosY <= Red4PosY + 80. / viewRatio))
										{
											moveRedPlayer = 4;
										}
									}
								} while (moveRedPlayer > 4 && Playerturn == 3);
							}

							if (Playerturn == 4)
							{
								//for blue player selection

								do
								{

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{

										Blue1PosX = bluePlayer1.getPosx();
										Blue1PosY = bluePlayer1.getPosy();
										Blue2PosX = bluePlayer2.getPosx();
										Blue2PosY = bluePlayer2.getPosy();
										Blue3PosX = bluePlayer3.getPosx();
										Blue3PosY = bluePlayer3.getPosy();
										Blue4PosX = bluePlayer4.getPosx();
										Blue4PosY = bluePlayer4.getPosy();

										MousePosX = sf::Mouse::getPosition(window).x * viewRatio;
										MousePosY = sf::Mouse::getPosition(window).y * viewRatio;

										if ((MousePosX >= bluePlayer1.getPositionx(0) + 30. / viewRatio && MousePosX <= bluePlayer1.getPositionx(0) + 80. / viewRatio && MousePosY >= bluePlayer1.getPositiony(0) + 30. / viewRatio && MousePosY <= yellowPlayer1.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Blue1PosX + 30. / viewRatio && MousePosX <= Blue1PosX + 80. / viewRatio && MousePosY >= Blue1PosY + 30. / viewRatio && MousePosY <= Blue1PosY + 80. / viewRatio))
										{
											moveBluePlayer = 1;
										}

										if ((MousePosX >= bluePlayer2.getPositionx(0) + 30. / viewRatio && MousePosX <= bluePlayer2.getPositionx(0) + 80. / viewRatio && MousePosY >= bluePlayer2.getPositiony(0) + 30. / viewRatio && MousePosY <= bluePlayer2.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Blue2PosX + 30. / viewRatio && MousePosX <= Blue2PosX + 80. / viewRatio && MousePosY >= Blue2PosY + 30. / viewRatio && MousePosY <= Blue2PosY + 80. / viewRatio))
										{
											moveBluePlayer = 2;
										}
										if ((MousePosX >= bluePlayer3.getPositionx(0) + 30. / viewRatio && MousePosX <= bluePlayer3.getPositionx(0) + 80. / viewRatio && MousePosY >= bluePlayer3.getPositiony(0) + 30. / viewRatio && MousePosY <= bluePlayer3.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Blue3PosX + 30. / viewRatio && MousePosX <= Blue3PosX + 80. / viewRatio && MousePosY >= Blue3PosY + 30. / viewRatio && MousePosY <= Blue3PosY + 80. / viewRatio))
										{
											moveBluePlayer = 3;
										}
										if ((MousePosX >= bluePlayer4.getPositionx(0) + 30 && MousePosX <= bluePlayer4.getPositionx(0) + 80 && MousePosY >= bluePlayer4.getPositiony(0) + 30. / viewRatio && MousePosY <= bluePlayer4.getPositiony(0) + 80. / viewRatio) || (MousePosX >= Blue4PosX + 30. / viewRatio && MousePosX <= Blue4PosX + 80. / viewRatio && MousePosY >= Blue4PosY + 30. / viewRatio && MousePosY <= Blue4PosY + 80. / viewRatio))
										{
											moveBluePlayer = 4;
										}
									}
								} while (moveBluePlayer > 4 && Playerturn == 4);
							}
						}
					}
					if (menu.getPressedLabel() == 2 || menu.returnClickedValue(mouseClickPos) == 2)
					{
						MENU_WINDOW.close();
					}
				}
			}
			MENU_WINDOW.clear();

			//	Draw menu background
			MENU_WINDOW.draw(menuBackground);

			//	Member function of menu obj to draw menu
			menu.draw(MENU_WINDOW);

			//	end of current frame

			MENU_WINDOW.display();
		}
	}
	return 0;
}

//showing animations of result
 int resultAnimation(int a)
 {
	// create the window
	sf::RenderWindow winnerWindow(sf::VideoMode(800, 600), "Winner");
	sf::Font font;
	font.loadFromFile("Chocolate Covered Raindrops.ttf");

	// run the program as long as the window is open
	while (winnerWindow.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (winnerWindow.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				winnerWindow.close();
		}
		sf::Text winner;

		// select the font
		winner.setFont(font); // font is a sf::Font
		// set the character size
		winner.setCharacterSize(100); // in pixels, not points!
		// set the color
		winner.setFillColor(sf::Color::White);
		// set the text style
		winner.setStyle(sf::Text::Bold);
		if (a == 1)
		{
			winner.setString("Yellow Player is the winner");
		}
		if (a == 2)
		{
			winner.setString("Green Player is the winner");
		}
		if (a == 3)
		{
			winner.setString("Red Player is the winner");
		}
		if (a == 4)
		{
			winner.setString("Blue Player is the winner");
		}
// inside the main loop, between window.clear() and window.display()
		winnerWindow.draw(winner);



		// end the current frame


		winnerWindow.display();

		//window.display(winner);
	}
	return 0;

 }





int generateRandomNum()
{
	int dicenum;
	srand(time(0));
	dicenum = 1 + rand() % 6; //  rand()%6 gives numbers from 0 to 5 that's why 1 isadded
	return dicenum;
}




int dicerollfunc(sf::RenderWindow& window, int playerTurn)
{
	 int diceno;
	 bool ifenter = 0;

	 sf::Font font;
	 font.loadFromFile("Chocolate Covered Raindrops.ttf");
	// diceno=generateRandomNum();
	bool continueloop=true;
	sf::RenderWindow dicerollWindow(sf::VideoMode(512,512),"DICE");
	while (dicerollWindow.isOpen())
	{
		dicerollWindow.setPosition(sf::Vector2i(1000, 100));
		sf::Event roll_event;
		while (dicerollWindow.pollEvent(roll_event))
		{

			if (roll_event.type == sf::Event::Closed)
			{
				dicerollWindow.close();
			}

			if (roll_event.type == sf::Event::KeyPressed) {
				window.setKeyRepeatEnabled(true);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				ifenter = 1;
			}
			if (ifenter) {
				diceno = generateRandomNum();

				sf::Texture diceTexture;
				diceTexture.setSmooth(true);
				//choosing animations according to the generated random number
				switch (diceno)
				{
				case 1:
					diceTexture.loadFromFile("got_one.png");
					break;

				case 2:
					diceTexture.loadFromFile("got_two.png");
					break;

				case 3:
					diceTexture.loadFromFile("got_three.png");
					break;
				case 4:
					diceTexture.loadFromFile("got_four.png");
					break;

				case 5:
					diceTexture.loadFromFile("got_five.png");
					break;

				case 6:
					diceTexture.loadFromFile("got_six.png");
					break;

				default:
					break;
				}

				sf::RectangleShape diceroll(sf::Vector2f(150.0f, 150.0f));
				diceroll.setOrigin(0.0f, 0.0f);
				diceroll.setPosition(100.0f, 200.0f);
				diceroll.setTexture(&diceTexture);


				sf::Text player;

				// select the font
				player.setFont(font); // font is a sf::Font

				// set the string to display


				// set the character size
				player.setCharacterSize(25); // in pixels, not points!

				// set the color
				player.setFillColor(sf::Color::White);

				// set the text style
				player.setStyle(sf::Text::Bold);

				dice_animations animation(&diceTexture, sf::Vector2u(7, 1), 0.9f);
				if (playerTurn == 1) {
					player.setString("Yellow Player got.");
				}
				if (playerTurn == 2) {
					player.setString("Green Player got.");
				}
				if (playerTurn == 3) {
					player.setString("Red Player got.");
				}
				if (playerTurn == 4) {
					player.setString("Blue Player got.");
				}
				player.setPosition(0, 10);

				float deltaTime = 0.0f;
				sf::Clock clock;
				//animation process
				while (continueloop)

				{

					deltaTime = clock.restart().asSeconds();
					sf::Event dice_event;
					while (window.pollEvent(dice_event))
					{
						switch (dice_event.type)
						{
						case sf::Event::Closed:
							dicerollWindow.close();
							break;
						default:
							break;

						}

					}



					animation.Update(0, deltaTime);
					if (animation.currentImage.x >= animation.imageCount.x)
					{
						continueloop = false;
						dicerollWindow.close();
					}




					diceroll.setTextureRect(animation.uvRect);
					dicerollWindow.clear();
					dicerollWindow.draw(diceroll);
					dicerollWindow.draw(player);
					dicerollWindow.display();

				}







			}
			else {
			sf::Text play;

			// select the font
			play.setFont(font); // font is a sf::Font

			// set the string to display


			// set the character size
			play.setCharacterSize(25); // in pixels, not points!

			// set the color
			play.setFillColor(sf::Color::White);

			// set the text style
			play.setStyle(sf::Text::Bold);
			play.setString("Press R to roll the dice.");

			dicerollWindow.clear();
			dicerollWindow.draw(play);
			dicerollWindow.display();

			}
			ifenter = 0;


		}

	}



		return (diceno);
}
