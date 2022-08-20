// #include "dice_animations.hpp"
// #include <SFML/Graphics.hpp>
// #include <cstdlib>
// #include <ctime>
// #include <iostream>
// int generateRandomNum();
// int main()
// {
// 	sf::RenderWindow window(sf::VideoMode(512, 512), "DICE");
// 	while (window.isOpen())
// 	{
// 		sf::Event roll_event;
// 		while (window.pollEvent(roll_event))
// 		{
// 			switch (roll_event.type)
// 			{
// 				case sf::Event::Closed:
// 					window.close();
// 					break;

// 				case sf::Event::KeyPressed:
// 					//window.setKeyRepeatEnabled(true);
// 					if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
// 					{

// 						int diceno;
// 						diceno = generateRandomNum();

// 						sf::Texture diceTexture;
// 						diceTexture.setSmooth(true);
// 						//choosing animations according to the generated random number
// 						switch (diceno)
// 						{
// 							case 1:
// 								diceTexture.loadFromFile("got_one.png");
// 								break;

// 							case 2:
// 								diceTexture.loadFromFile("got_two.png");
// 								break;

// 							case 3:
// 								diceTexture.loadFromFile("got_three.png");
// 								break;
// 							case 4:
// 								diceTexture.loadFromFile("got_four.png");
// 								break;

// 							case 5:
// 								diceTexture.loadFromFile("got_five.png");
// 								break;

// 							case 6:
// 								diceTexture.loadFromFile("got_six.png");
// 								break;

// 							default:
// 								break;
// 						}

// 						sf::RectangleShape diceroll(sf::Vector2f(150.0f, 150.0f));
// 						diceroll.setOrigin(0.0f, 0.0f);
// 						diceroll.setPosition(100.0f, 200.0f);
// 						diceroll.setTexture(&diceTexture);

// 						dice_animations animation(&diceTexture, sf::Vector2u(7, 1), 0.9f);

// 						float deltaTime = 0.0f;
// 						sf::Clock clock;

// 						//animation process
// 						while (1)

// 						{

// 							deltaTime = clock.restart().asSeconds();
// 							sf::Event dice_event;
// 							while (window.pollEvent(dice_event))
// 							{
// 								switch (dice_event.type)
// 								{
// 									case sf::Event::Closed:
// 										window.close();
// 										break;
// 									default:
// 										break;
// 										case sf::Keyboard::N:
// 										window.close();
// 										break;
// 								}
// 							}
// 							// if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
// 							// 	{
// 							// 		window.clear();
// 							// 	}

// 							animation.Update(0, deltaTime);
// 							// if (loop == 1)
// 							// {
// 							// 	break;
// 							// }

// 							diceroll.setTextureRect(animation.uvRect);
// 							window.clear();
// 							window.draw(diceroll);
// 							window.display();
// 						}
// 					}
// 					break;
// 				default:
// 					break;
// 			}
// 		}
// 	}
// }

// //generating random number
// int generateRandomNum()
// {
// 	int diceFaceNum;
// 	srand(time(0));
// 	diceFaceNum = 1 + rand() % 6; //  rand()%6 gives numbers from 0 to 5 that's why 1 isadded
// 	return diceFaceNum;
// }
