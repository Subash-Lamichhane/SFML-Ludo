#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include "PlayerYellow.h"
#include <iostream>

PlayerYellow::PlayerYellow( float initialPositionx, float initialPositiony) {
	
	y1.setPosition(initialPositionx, initialPositiony);
	firstPositionx = initialPositionx;
	firstPositiony = initialPositiony;
}
PlayerYellow::~PlayerYellow(){}


void PlayerYellow::draw(sf::RenderWindow& window, float position_x, float position_y ){
	sf::RectangleShape y1(sf::Vector2f(100.0f, 100.0f));
	sf::Texture playerb;
	playerb.loadFromFile("Gotti/yellow.png");
	y1.setTexture(&playerb);
	y1.setPosition(position_x, position_y);
	y1.setPosition(PlayerPositionx[initialPosition_x]-50, PlayerPositiony[initialPosition_y]-50);
	window.draw(y1);

	/*sf::RectangleShape y2(sf::Vector2f(100.0f, 100.0f));
	y2.setTexture(&playerb);
	y2.setPosition(position_x, position_y);
	y2.setPosition(PlayerPositionx[initialPosition_x] - 50, PlayerPositiony[initialPosition_y] - 50);
	
	window.draw(y2);*/
	window.draw(y1);
}
float PlayerYellow::getPositiony(int movex) {

	return PlayerPositiony[initialPosition_y + movex];

}
float PlayerYellow::getPositionx(int movex) {

	return PlayerPositionx[initialPosition_y + movex];

}
void PlayerYellow::setPosition(float diceno) {
	if(PlayerPositionx[initialPosition_x] == 100.f && PlayerPositiony[initialPosition_y] == 100.0f) {
		if(diceno !=1)
			y1.setPosition(getPositionx(diceno), getPositiony(diceno));
	}

	initialPosition_x += diceno;
	initialPosition_y += diceno;
}
void PlayerYellow::resetPosition() {
	initialPosition_x = 1;
	initialPosition_y = 1;
	y1.setPosition(firstPositionx, firstPositiony);
}


/*Players::move(int gotti)
{
	if (gotti == 1) {
		y1.................................................
	}
	if (gotti == 2) {

	}
	if (gotti == 3) {

	}
	if (gotti == 4) {

	}
	if (gotti == 5) {

	}
	if (gotti == 6) {

	}
}*/