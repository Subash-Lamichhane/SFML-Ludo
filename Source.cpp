#include <SFML/Graphics.hpp>
#include <iostream>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include "PlayerYellow.h"
#include "dice.cpp"
#include "Menu.hpp"

using namespace std;

int main()
{


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
                    cout << "called move down";
                    menu.moveDown();
                }

                //	Enter key pressed

                if (event.key.code == sf::Keyboard::Enter)
                {
                    if (menu.getPressedLabel() == 1)
                    {
                        //credits here
                    }
                    if (menu.getPressedLabel() == 0)
                    {
                        
                        //Main game loop here
                        window.create(sf::VideoMode(1000, 1000), "LUDO");
                        //sf::RectangleShape b1(sf::Vector2f(100.0f, 100.0f));
                        sf::RectangleShape background(sf::Vector2f(1000.0f, 1000.0f));
                        //sf::CircleShape g1(40.0f);
                        sf::Font font;
                        sf::Text t1;
                        sf::Texture boardTexture;
                        sf::Texture playerb;
                        sf::Texture player;

                           //Yellow Player
                        PlayerYellow yellowPlayer1(100.f, 100.f);
                        PlayerYellow yellowPlayer2(100.f, 100.f);
                        PlayerYellow yellowPlayer3(200.f, 200.f);
                        PlayerYellow yellowPlayer4(200.f, 200.f);

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


                        cout << playertexturesize.x << "/n" << playertexturesize.y;
                        //b1.setOrigin(playertexturesize.x / 2, playertexturesize.y / 2);
                        //b1.setPosition(840.f, 830.f);

                        sf::Text text;
                        text.setString("Home");
                        text.setCharacterSize(24);
                        text.setStyle(sf::Text::Bold);

                        cout << "/n You got: " << diceno << endl;
                        yellowPlayer1.setPosition(diceno);

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

                                cout << "/n You got: " << diceno << endl;
                                yellowPlayer1.setPosition(diceno);

                                /*
                                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                                     g1.move(0.0f, -0.1f);
                                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                                     g1.move(-0.1f, 0.0f);
                                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                                     g1.move(0.1f, 0.0f);
                                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                                     g1.move(0.0f, 0.1f);*/


                                window.clear();
                                window.draw(background);
                                //window.draw(b1);
                                yellowPlayer1.draw(window);
                                //window.draw(g1); 
                                window.draw(t1);
                                window.display();


                                diceno = d.askToRollDice();
                                //playerx.display(window);

                        }



                        /*
                         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                             g1.move(0.0f, -0.1f);
                         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                             g1.move(-0.1f, 0.0f);
                         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                             g1.move(0.1f, 0.0f);
                         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                             g1.move(0.0f, 0.1f);*/


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