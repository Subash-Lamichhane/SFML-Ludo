#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include "PlayerYellow.h"
#include <iostream>

PlayerYellow::PlayerYellow( float initialPosition_x, float initialPosition_y) {
	y1.setPosition(initialPosition_x, initialPosition_y);
}
PlayerYellow::~PlayerYellow(){}


void PlayerYellow::draw(sf::RenderWindow& window, float position_x, float position_y ){
	sf::RectangleShape y1(sf::Vector2f(100.0f, 100.0f));
	sf::Texture playerb;
	playerb.loadFromFile("Gotti/yellow.png");
	y1.setTexture(&playerb);
	y1.setPosition(position_x, position_y);
	y1.setPosition(PlayerPositionx[1]-50, PlayerPositiony[1]-50);
	window.draw(y1);

	sf::RectangleShape y2(sf::Vector2f(100.0f, 100.0f));
	y2.setTexture(&playerb);
	y2.setPosition(position_x, position_y);
	y2.setPosition(PlayerPositionx[50] - 50, PlayerPositiony[50] - 50);
	window.draw(y1);
	window.draw(y2);
}
float PlayerYellow::getPositiony(int movex,int initialPositiony) {

	return PlayerPositiony[initialPositiony + movex];

}
void PlayerYellow::setPosition(float x, float y) {
	y1.setPosition(x, y);

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