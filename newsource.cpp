// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include<SFML/Window.hpp>
// #include<SFML/System.hpp>
// #include "PlayerYellow.h"
// #include "PlayerBlue.h"
// #include "PlayerGreen.h"
// #include "PlayerRed.h"
// #include "dice.cpp"
// #include "Menu.hpp"



// using namespace std;

// int main()
// {
//     //Variable declaration
//     int Playerturn = 1;
//     int moveBluePlayer = 10, moveYellowPlayer = 10 , moveGreenPlayer = 10,moveRedPlayer=10;
//     float Yellow1PosX, Yellow1PosY ,Yellow2PosX,Yellow2PosY,Yellow3PosX,Yellow3PosY,Yellow4PosX,Yellow4PosY;
//     float Blue1PosX, Blue1PosY, Blue2PosX, Blue2PosY, Blue3PosX, Blue3PosY, Blue4PosX, Blue4PosY;
//     float Green1PosX, Green1PosY, Green2PosX, Green2PosY, Green3PosX, Green3PosY, Green4PosX, Green4PosY;
//     float Red1PosX, Red1PosY, Red2PosX, Red2PosY, Red3PosX, Red3PosY, Red4PosX, Red4PosY;
//     float MousePosY, MousePosX;


//     sf::RenderWindow window, MENU_WINDOW;
//     sf::View view(sf::Vector2f(750, 750), sf::Vector2f(1500, 1500));
//     MENU_WINDOW.create(sf::VideoMode(800, 600), "Main Menu");
//     Menu menu(MENU_WINDOW.getSize().x, MENU_WINDOW.getSize().y);

//     sf::Texture texture;
//     if (!texture.loadFromFile("gotti/main_menu.jfif"))
//     {
//         std::cout << "Error loading menu background image.";
//     }
//     sf::Sprite menuBackground(texture);



//     while (MENU_WINDOW.isOpen())
//     {
//         sf::Event event;


//         while (MENU_WINDOW.pollEvent(event))
//         {
//             sf::Vector2i mouseClickPosition = sf::Mouse::getPosition(MENU_WINDOW);
//             menu.checkUsingMouse(mouseClickPosition);
//             if (event.type == sf::Event::Closed)
//                 MENU_WINDOW.close();

//             //while

//             if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
//             {
//                 //	Up arrow key pressed
//                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
//                 {
//                     //	Shift selected label to down
//                     menu.moveUp();
//                 }
//                 //	Down arrow key pressed
//                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
//                 {
//                     //	Shift selected label to down
//                     menu.moveDown();
//                 }


//                 sf::Vector2i mouseClickPos = sf::Mouse::getPosition(MENU_WINDOW);
//                 //	Enter key pressed

//                 if (event.key.code == sf::Keyboard::Enter || event.type == sf::Event::MouseButtonPressed)
//                 {
//                     if (menu.getPressedLabel() == 1 || menu.returnClickedValue(mouseClickPos) == 1)
//                     {
//                         //credits here
//                     }
//                     if (menu.getPressedLabel() == 0 || menu.returnClickedValue(mouseClickPos) == 0)
//                     {

//                         MENU_WINDOW.close();
//                         //Main game loop here


//                         window.create(sf::VideoMode(1000, 1000), "LUDO");

//                         sf::RectangleShape background(sf::Vector2f(1000.0f, 1000.0f));
//                         sf::Font font;
//                         sf::Text t1;
//                         sf::Texture boardTexture;
//                         sf::Texture playerb;
//                         sf::Texture player;


//                         //Yellow Player object declaration
//                         PlayerYellow yellowPlayer1(207.f, 800.f);
//                         PlayerYellow yellowPlayer2(93.f, 800.f);
//                         PlayerYellow yellowPlayer3(93.f, 685.f);
//                         PlayerYellow yellowPlayer4(207.f, 685.f);

//                         PlayerBlue bluePlayer1(807.f, 800.f);
//                         PlayerBlue bluePlayer2(692.f, 800.f);
//                         PlayerBlue bluePlayer3(807.f, 692.f);
//                         PlayerBlue bluePlayer4(692.f, 685.f);

//                         PlayerGreen greenPlayer1(206.f, 191.f);
//                         PlayerGreen greenPlayer2(92.f, 191.f);
//                         PlayerGreen greenPlayer3(207.f, 77.f);
//                         PlayerGreen greenPlayer4(92.f, 77.f);


//                         PlayerRed redPlayer1(807.f, 77.f);
//                         PlayerRed redPlayer2(692.f, 77.f);
//                         PlayerRed redPlayer3(807.f, 191.f);
//                         PlayerRed redPlayer4(692.f, 191.f);


//                         dice d;
//                         int diceno = 0;




//                         boardTexture.loadFromFile("ludo-board.png");
//                         playerb.loadFromFile("Gotti/blue.png");
//                         player.loadFromFile("Gotti/PlayerTexture.png");
//                         font.loadFromFile("Chocolate Covered Raindrops.ttf");

//                         sf::Vector2u playertexturesize = player.getSize();

//                         t1.setFont(font);
//                         t1.setCharacterSize(32);
//                         t1.setString("Home");
//                         t1.setPosition(window.getSize().x / 2.2f, 400.f);


//                         background.setOrigin(500.0f, 500.0f);
//                         background.setPosition(500.0f, 500.0f);
//                         background.setTexture(&boardTexture);

//                         playertexturesize.x /= 4;


//                         sf::Text text;
//                         text.setString("Home");
//                         text.setCharacterSize(24);
//                         text.setStyle(sf::Text::Bold);

//                         //game window
//                         while (window.isOpen())
//                         {
//                             sf::Event event;
//                             while (window.pollEvent(event))
//                             {
//                                 if (event.type == sf::Event::Closed) {
//                                     window.close();
//                                 }
//                             }

//                             window.clear();
//                             window.draw(background);



//                             //Players Turn
//                             if (Playerturn == 1) {                  //For yellow player movement

//                                 window.pollEvent(event);


//                                 if (moveYellowPlayer == 1) {
//                                     yellowPlayer1.draw(window, diceno);
//                                     cout << "\n \n Player green turn";
//                                     Playerturn += 1;
//                                 }
//                                 else if (moveYellowPlayer == 2) {
//                                     yellowPlayer2.draw(window, diceno);
//                                     cout << "\n \n Player green turn";
//                                     Playerturn += 1;

//                                 }
//                                 else if (moveYellowPlayer == 3) {
//                                     yellowPlayer3.draw(window, diceno);
//                                     cout << "\n \n Player green turn";
//                                     Playerturn += 1;

//                                 }
//                                 else if (moveYellowPlayer == 4) {
//                                     yellowPlayer4.draw(window, diceno);
//                                     cout << "\n \n Player green turn";
//                                     Playerturn += 1;

//                                 }

//                             }
//                             else if (Playerturn == 2) {             //For Green Player movement

//                                 window.pollEvent(event);

//                                 if (moveGreenPlayer == 1) {
//                                     greenPlayer1.draw(window, diceno);
//                                     cout << "\n \n Player red turn";
//                                     Playerturn += 1;
//                                 }
//                                 else if(moveGreenPlayer == 2) {
//                                     greenPlayer2.draw(window, diceno);
//                                     cout << "\n \n Player red turn";
//                                     Playerturn += 1;
//                                 }
//                                 else if (moveGreenPlayer == 3) {
//                                     greenPlayer3.draw(window, diceno);
//                                     cout << "\n \n Player red turn";
//                                     Playerturn += 1;
//                                 }
//                                 else if (moveGreenPlayer == 3) {
//                                     greenPlayer3.draw(window, diceno);
//                                     cout << "\n \n Player red turn";
//                                     Playerturn += 1;
//                                 }

//                             }
//                             else if (Playerturn == 3) {                 //Move Red Player

//                                 window.pollEvent(event);

//                                 if (moveRedPlayer == 1) {
//                                     redPlayer1.draw(window, diceno);
//                                     cout << "\n \n Player blue turn";
//                                     Playerturn += 1;
//                                 }
//                                 else if(moveRedPlayer == 2) {
//                                     redPlayer2.draw(window, diceno);
//                                     cout << "\n \n Player blue turn";
//                                     Playerturn += 1;
//                                 }
//                                 else if (moveRedPlayer == 3) {
//                                     redPlayer3.draw(window, diceno);
//                                     cout << "\n \n Player blue turn";
//                                     Playerturn += 1;
//                                 }
//                                 else if (moveRedPlayer == 4) {
//                                     redPlayer4.draw(window, diceno);
//                                     cout << "\n \n Player blue turn";
//                                     Playerturn += 1;
//                                 }
//                             }
//                             else if (Playerturn == 4) {                 //Move blue Player

//                                 window.pollEvent(event);


//                                 if (moveBluePlayer == 1) {
//                                     bluePlayer1.draw(window, diceno);
//                                     cout << "\n \n Player yellow turn";
//                                     Playerturn = 1;
//                                 }
//                                 else if (moveBluePlayer == 2) {
//                                     bluePlayer2.draw(window, diceno);
//                                     cout << "\n \n Player yellow turn";
//                                     Playerturn = 1;
//                                 }
//                                 else if (moveBluePlayer == 3) {
//                                     bluePlayer3.draw(window, diceno);
//                                     cout << "\n \n Player yellow turn";
//                                     Playerturn = 1;
//                                 }
//                                 else if (moveBluePlayer == 4) {
//                                     bluePlayer4.draw(window, diceno);
//                                     cout << "\n \n Player yellow turn";
//                                     Playerturn = 1;
//                                 }
//                             }

//                             yellowPlayer1.draw(window, 0);
//                             yellowPlayer2.draw(window, 0);
//                             yellowPlayer3.draw(window, 0);
//                             yellowPlayer4.draw(window, 0);

//                             bluePlayer1.draw(window, 0);
//                             bluePlayer2.draw(window, 0);
//                             bluePlayer3.draw(window, 0);
//                             bluePlayer4.draw(window, 0);

//                             greenPlayer1.draw(window, 0);
//                             greenPlayer2.draw(window, 0);
//                             greenPlayer3.draw(window, 0);
//                             greenPlayer4.draw(window, 0);

//                             redPlayer1.draw(window, 0);
//                             redPlayer2.draw(window, 0);
//                             redPlayer3.draw(window, 0);
//                             redPlayer4.draw(window, 0);

//                             window.draw(t1);
//                             window.display();

//                             diceno = d.askToRollDice();
//                             cout << "/n You got: " << diceno << endl;


//                             moveYellowPlayer = 10;
//                             moveBluePlayer = 10;
//                             moveGreenPlayer = 10;
//                             moveRedPlayer = 10;

//                             //Select players among same colors

//                             if (Playerturn == 1) {
//                                 //For Yellow Player selection

//                                 do
//                                 {

//                                     if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

//                                         Yellow1PosX = yellowPlayer1.getPosx();
//                                         Yellow1PosY = yellowPlayer1.getPosy();
//                                         Yellow2PosX= yellowPlayer2.getPosx();
//                                         Yellow2PosY= yellowPlayer2.getPosy();
//                                         Yellow3PosX = yellowPlayer3.getPosx();
//                                         Yellow3PosY = yellowPlayer3.getPosy();
//                                         Yellow4PosX = yellowPlayer4.getPosx();
//                                         Yellow4PosY = yellowPlayer4.getPosy();

//                                         MousePosX = sf::Mouse::getPosition(window).x;
//                                         MousePosY = sf::Mouse::getPosition(window).y;


//                                         if ((MousePosX >= yellowPlayer1.getPositionx(0) + 30 && MousePosX <= yellowPlayer1.getPositionx(0) + 80 && MousePosY >= yellowPlayer1.getPositiony(0) + 30 && MousePosY <= yellowPlayer1.getPositiony(0) + 80
//                                            ) || (MousePosX >= Yellow1PosX + 30 && MousePosX <= Yellow1PosX + 80 &&
//                                                 MousePosY >= Yellow1PosY + 30 && MousePosY <= Yellow1PosY + 80)) {
//                                             moveYellowPlayer = 1;
//                                         }

//                                         if ((MousePosX >= yellowPlayer2.getPositionx(0)+30 && MousePosX <= yellowPlayer2.getPositionx(0) + 80 && MousePosY >= yellowPlayer2.getPositiony(0)+30 && MousePosY <= yellowPlayer2.getPositiony(0) + 80
//                                             )|| (MousePosX >= Yellow2PosX+30 && MousePosX <= Yellow2PosX + 80 &&
//                                             MousePosY >= Yellow2PosY+30 && MousePosY <= Yellow2PosY + 80) ) {
//                                             moveYellowPlayer = 2;
//                                             cout << "mousePos=" << sf::Mouse::getPosition(window).x << endl;
//                                             cout << "PlayerPosition=" << yellowPlayer2.getPosx() << endl << endl;
//                                         }
//                                         if ((MousePosX >= yellowPlayer3.getPositionx(0) + 30 && MousePosX <= yellowPlayer3.getPositionx(0) + 80 && MousePosY >= yellowPlayer3.getPositiony(0) + 30 && MousePosY <= yellowPlayer3.getPositiony(0) + 80
//                                             )|| (MousePosX >= Yellow3PosX + 30 && MousePosX <= Yellow3PosX + 80 &&
//                                                 MousePosY >= Yellow3PosY + 30 && MousePosY <= Yellow3PosY + 80)) {
//                                             moveYellowPlayer = 3;
//                                         }
//                                         if ((MousePosX >= yellowPlayer4.getPositionx(0) + 30 && MousePosX <= yellowPlayer4.getPositionx(0) + 80 && MousePosY >= yellowPlayer4.getPositiony(0) + 30 && MousePosY <= yellowPlayer4.getPositiony(0) + 80
//                                             )|| (MousePosX >= Yellow4PosX + 30 && MousePosX <= Yellow4PosX + 80 &&
//                                                 MousePosY >= Yellow4PosY + 30 && MousePosY <= Yellow4PosY + 80)) {
//                                             moveYellowPlayer = 4;
//                                         }


//                                     }
//                                 } while (moveYellowPlayer > 4 && Playerturn == 1);
//                             }
//                             if (Playerturn == 2) {
//                                 //For Green Player selection
//                                 do
//                                 {

//                                     if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

//                                         Green1PosX = greenPlayer1.getPosx();
//                                         Green1PosY = greenPlayer1.getPosy();
//                                         Green2PosX = greenPlayer2.getPosx();
//                                         Green2PosY = greenPlayer2.getPosy();
//                                         Green3PosX = greenPlayer3.getPosx();
//                                         Green3PosY = greenPlayer3.getPosy();
//                                         Green4PosX = greenPlayer4.getPosx();
//                                         Green4PosY = greenPlayer4.getPosy();

//                                         MousePosX = sf::Mouse::getPosition(window).x;
//                                         MousePosY = sf::Mouse::getPosition(window).y;

//                                         if ((MousePosX >= greenPlayer1.getPositionx(0) + 30 && MousePosX <= greenPlayer1.getPositionx(0) + 80 && MousePosY >= greenPlayer1.getPositiony(0) + 30 && MousePosY <= greenPlayer1.getPositiony(0) + 80
//                                             )|| (MousePosX >= Green1PosX + 30 && MousePosX <= Green1PosX + 80 &&
//                                                 MousePosY >= Green1PosY + 30 && MousePosY <= Green1PosY + 80)) {
//                                             moveGreenPlayer = 1;
//                                         }

//                                         if ((MousePosX >= greenPlayer2.getPositionx(0) + 30 && MousePosX <= greenPlayer2.getPositionx(0) + 80 && MousePosY >= greenPlayer2.getPositiony(0) + 30 && MousePosY <= greenPlayer2.getPositiony(0) + 80
//                                             )|| (MousePosX >= Green2PosX + 30 && MousePosX <= Green2PosX + 80 &&
//                                                 MousePosY >= Green2PosY + 30 && MousePosY <= Green2PosY + 80)) {
//                                             moveGreenPlayer = 2;

//                                         }
//                                         if ((MousePosX >= greenPlayer3.getPositionx(0) + 30 && MousePosX <= greenPlayer3.getPositionx(0) + 80 && MousePosY >= greenPlayer3.getPositiony(0) + 30 && MousePosY <= greenPlayer3.getPositiony(0) + 80
//                                             )|| (MousePosX >= Green3PosX + 30 && MousePosX <= Green3PosX + 80 &&
//                                                 MousePosY >= Green3PosY + 30 && MousePosY <= Green3PosY + 80)) {
//                                             moveGreenPlayer = 3;
//                                         }
//                                         if ((MousePosX >= greenPlayer4.getPositionx(0) + 30 && MousePosX <= greenPlayer4.getPositionx(0) + 80 && MousePosY >= greenPlayer4.getPositiony(0) + 30 && MousePosY <= greenPlayer4.getPositiony(0) + 80
//                                             )|| (MousePosX >= Green4PosX + 30 && MousePosX <= Green4PosX + 80 &&
//                                                 MousePosY >= Green4PosY + 30 && MousePosY <= Green4PosY + 80)) {
//                                             moveGreenPlayer = 4;
//                                         }


//                                     }
//                                 } while (moveGreenPlayer > 4 && Playerturn == 2);
//                             }
//                             if (Playerturn == 3) {
//                                 //For red Player selection

//                                 do
//                                 {

//                                     if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

//                                         Red1PosX = redPlayer1.getPosx();
//                                         Red1PosY = redPlayer1.getPosy();
//                                         Red2PosX = redPlayer2.getPosx();
//                                         Red2PosY = redPlayer2.getPosy();
//                                         Red3PosX = redPlayer3.getPosx();
//                                         Red3PosY = redPlayer3.getPosy();
//                                         Red4PosX = redPlayer4.getPosx();
//                                         Red4PosY = redPlayer4.getPosy();

//                                         MousePosX = sf::Mouse::getPosition(window).x;
//                                         MousePosY = sf::Mouse::getPosition(window).y;

//                                         if ((MousePosX >= redPlayer1.getPositionx(0) + 30 && MousePosX <= redPlayer1.getPositionx(0) + 80 && MousePosY >= redPlayer1.getPositiony(0) + 30 && MousePosY <= redPlayer1.getPositiony(0) + 80
//                                             )|| (MousePosX >= Red1PosX + 30 && MousePosX <= Red1PosX + 80 &&
//                                                 MousePosY >= Red1PosY + 30 && MousePosY <= Red1PosY + 80)) {
//                                             moveRedPlayer = 1;
//                                         }

//                                         if ((MousePosX >= redPlayer2.getPositionx(0) + 30 && MousePosX <= redPlayer2.getPositionx(0) + 80 && MousePosY >= redPlayer2.getPositiony(0) + 30 && MousePosY <= redPlayer2.getPositiony(0) + 80
//                                             )|| (MousePosX >= Red2PosX + 30 && MousePosX <= Red2PosX + 80 &&
//                                                 MousePosY >= Red2PosY + 30 && MousePosY <= Red2PosY + 80)) {
//                                             moveRedPlayer = 2;

//                                         }
//                                         if ((MousePosX >= redPlayer3.getPositionx(0) + 30 && MousePosX <= redPlayer3.getPositionx(0) + 80 && MousePosY >= redPlayer3.getPositiony(0) + 30 && MousePosY <= redPlayer3.getPositiony(0) + 80
//                                             )|| (MousePosX >= Red3PosX + 30 && MousePosX <= Red3PosX + 80 &&
//                                                 MousePosY >= Red3PosY + 30 && MousePosY <= Red3PosY + 80)) {
//                                             moveRedPlayer = 3;
//                                         }
//                                         if ((MousePosX >= redPlayer4.getPositionx(0) + 30 && MousePosX <= redPlayer4.getPositionx(0) + 80 && MousePosY >= redPlayer4.getPositiony(0) + 30 && MousePosY <= redPlayer4.getPositiony(0) + 80
//                                             )|| (MousePosX >= Red4PosX + 30 && MousePosX <= Red4PosX + 80 &&
//                                                 MousePosY >= Red4PosY + 30 && MousePosY <= Red4PosY + 80)) {
//                                             moveRedPlayer = 4;
//                                         }
//                                     }
//                                 } while (moveRedPlayer > 4 && Playerturn == 3);
//                             }


//                             if (Playerturn == 4) {
//                                 //for blue player selection

//                                 do
//                                 {

//                                     if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

//                                         Blue1PosX = bluePlayer1.getPosx();
//                                         Blue1PosY = bluePlayer1.getPosy();
//                                         Blue2PosX = bluePlayer2.getPosx();
//                                         Blue2PosY = bluePlayer2.getPosy();
//                                         Blue3PosX = bluePlayer3.getPosx();
//                                         Blue3PosY = bluePlayer3.getPosy();
//                                         Blue4PosX = bluePlayer4.getPosx();
//                                         Blue4PosY = bluePlayer4.getPosy();

//                                         MousePosX = sf::Mouse::getPosition(window).x;
//                                         MousePosY = sf::Mouse::getPosition(window).y;

//                                         if ((MousePosX >= bluePlayer1.getPositionx(0) + 30 && MousePosX <= bluePlayer1.getPositionx(0) + 80 && MousePosY >= bluePlayer1.getPositiony(0) + 30 && MousePosY <= yellowPlayer1.getPositiony(0) + 80
//                                             )|| (MousePosX >= Blue1PosX + 30 && MousePosX <= Blue1PosX + 80 &&
//                                                 MousePosY >= Blue1PosY + 30 && MousePosY <= Blue1PosY + 80)) {
//                                             moveBluePlayer = 1;
//                                         }

//                                         if ((MousePosX >= bluePlayer2.getPositionx(0) + 30 && MousePosX <= bluePlayer2.getPositionx(0) + 80 && MousePosY >= bluePlayer2.getPositiony(0) + 30 && MousePosY <= bluePlayer2.getPositiony(0) + 80
//                                             )|| (MousePosX >= Blue2PosX + 30 && MousePosX <= Blue2PosX + 80 &&
//                                                 MousePosY >= Blue2PosY + 30 && MousePosY <= Blue2PosY + 80)) {
//                                             moveBluePlayer = 2;

//                                         }
//                                         if ((MousePosX >= bluePlayer3.getPositionx(0) + 30 && MousePosX <= bluePlayer3.getPositionx(0) + 80 && MousePosY >= bluePlayer3.getPositiony(0) + 30 && MousePosY <= bluePlayer3.getPositiony(0) + 80
//                                             )|| (MousePosX >= Blue3PosX + 30 && MousePosX <= Blue3PosX + 80 &&
//                                                 MousePosY >= Blue3PosY + 30 && MousePosY <= Blue3PosY + 80)) {
//                                             moveBluePlayer = 3;
//                                         }
//                                         if ((MousePosX >= bluePlayer4.getPositionx(0) + 30 && MousePosX <= bluePlayer4.getPositionx(0) + 80 && MousePosY >= bluePlayer4.getPositiony(0) + 30 && MousePosY <= bluePlayer4.getPositiony(0) + 80
//                                             )|| (MousePosX >= Blue4PosX + 30 && MousePosX <= Blue4PosX + 80 &&
//                                                 MousePosY >= Blue4PosY + 30 && MousePosY <= Blue4PosY + 80)) {
//                                             moveBluePlayer = 4;
//                                         }


//                                     }
//                                 } while (moveBluePlayer > 4 && Playerturn == 4);
//                             }



//                         }



//                     }
//                     if (menu.getPressedLabel() == 2 || menu.returnClickedValue(mouseClickPos) == 2)
//                     {
//                         MENU_WINDOW.close();
//                     }
//                 }


//             }
//             MENU_WINDOW.clear();

//             //	Draw menu background
//             MENU_WINDOW.draw(menuBackground);

//             //	Member function of menu obj to draw menu
//             menu.draw(MENU_WINDOW);

//             //	end of current frame

//             MENU_WINDOW.display();
//         }


//     }
//     return 0;
// }


