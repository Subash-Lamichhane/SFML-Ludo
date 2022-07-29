#include <SFML/Graphics.hpp>
#include <iostream>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include "PlayerYellow.h"
#include "PlayerBlue.h"
#include "PlayerGreen.h"
#include "PlayerRed.h"
#include "dice.cpp"
#include "Menu.hpp"

using namespace std;

int main()
{
    //Variable declaration
    int Playerturn = 1,i=0;


    sf::RenderWindow window, MENU_WINDOW;
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
            if (event.type == sf::Event::Closed)
                MENU_WINDOW.close();

            //while

            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
            {
                //	Up arrow key pressed
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up  ))
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
                sf::Vector2i mouseClickPosition = sf::Mouse::getPosition(MENU_WINDOW);
                menu.checkUsingMouse(mouseClickPosition);
                

                //	Enter key pressed

                if (event.key.code == sf::Keyboard::Enter )
                {
                    if (menu.getPressedLabel() == 1)
                    {
                        //credits here
                    }
                    if (menu.getPressedLabel() == 0)
                    {
                        
                        //Main game loop here
                        window.create(sf::VideoMode(1000, 1000), "LUDO");
                        
                        sf::RectangleShape background(sf::Vector2f(1000.0f, 1000.0f));
                        sf::Font font;
                        sf::Text t1;
                        sf::Texture boardTexture;
                        sf::Texture playerb;
                        sf::Texture player;

                           //Yellow Player object declaration
                        PlayerYellow yellowPlayer1(207.f, 800.f);
                        //PlayerYellow yellowPlayer2(100.f, 100.f);
                        //PlayerYellow yellowPlayer3(200.f, 200.f);
                        //PlayerYellow yellowPlayer4(200.f, 200.f);

                        PlayerBlue bluePlayer1(807.f, 800.f);

                        PlayerGreen greenPlayer1(207.f,77.f);

                        PlayerRed redPlayer1(807.f, 77.f);


                        dice d;
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


                        //cout << playertexturesize.x << "\n" << playertexturesize.y;

                        sf::Text text;
                        text.setString("Home");
                        text.setCharacterSize(24);
                        text.setStyle(sf::Text::Bold);

                        //game window
                        while (window.isOpen())
                        {
                            sf::Event event;
                            while (window.pollEvent(event))
                            {
                                if (event.type == sf::Event::Closed) {
                                    window.close();
                                }                       
                            }

                                //Drawing parts
                                window.clear();
                                window.draw(background); 
                                

                                //Players Turn
                                if (Playerturn == 1) {
                                    cout << i;
                                    i++;
                                    yellowPlayer1.draw(window, diceno);
                                    bluePlayer1.draw(window, 0);
                                    greenPlayer1.draw(window, 0);
                                    redPlayer1.draw(window, 0);
                                    cout << "\n \n Player green turn";
                                    Playerturn += 1;
                                }

                                else if (Playerturn == 2) {
                                    cout << "\n\nPlayer red turn 3";
                                    greenPlayer1.draw(window, diceno);
                                    bluePlayer1.draw(window, 0);
                                    yellowPlayer1.draw(window, 0);
                                    redPlayer1.draw(window, 0);
                                    Playerturn++;
                                }

                                else if (Playerturn == 3) {
                                    cout << "\n\nPlayer blue turn";
                                    redPlayer1.draw(window, diceno);
                                    greenPlayer1.draw(window, 0);
                                    bluePlayer1.draw(window, 0);
                                    yellowPlayer1.draw(window, 0);
                                    Playerturn++;
                                }

                                else if (Playerturn == 4) {
                                    cout << "\n\nPlayer yellow turn";
                                    bluePlayer1.draw(window, diceno);
                                    yellowPlayer1.draw(window, 0);
                                    greenPlayer1.draw(window, 0);
                                    redPlayer1.draw(window, 0);
                                    Playerturn = 1;
                                }

                                window.draw(t1);
                                window.display();

                                diceno = d.askToRollDice();
                                cout << "/n You got: " << diceno << endl;
                                
                                //playerx.display(window);

                        }



                    }
                    if (menu.getPressedLabel() == 2)
                    {
                        MENU_WINDOW.close();
                        exit;
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





//yellowPlayer1.setPosition(diceno);

/*
 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
     g1.move(0.0f, -0.1f);
 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
     g1.move(-0.1f, 0.0f);
 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
     g1.move(0.1f, 0.0f);
 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
     g1.move(0.0f, 0.1f);*/