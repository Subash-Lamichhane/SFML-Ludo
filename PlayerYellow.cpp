#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include "PlayerYellow.h"
#include <iostream>

PlayerYellow::PlayerYellow(float initialPositionx, float initialPositiony) {

	y1.setPosition(initialPositionx, initialPositiony);
	firstPositionx = initialPositionx;
	firstPositiony = initialPositiony;
	PlayerPositiony[0] = initialPositiony;
	PlayerPositionx[0] = initialPositionx;
	y1.setPosition(firstPositionx, firstPositiony);
}
PlayerYellow::~PlayerYellow() {}


void PlayerYellow::draw(sf::RenderWindow& window, int diceno) {
	sf::RectangleShape y1(sf::Vector2f(100.0f, 100.0f));
	sf::Texture playerb;
	playerb.loadFromFile("Gotti/yellow.png");
	y1.setTexture(&playerb);

	if (initialPosition_x == 0 && initialPosition_y == 0) {
		if (diceno == 1) {
			y1.setPosition(getPositionx(diceno), getPositiony(diceno));
		}
		else {
			y1.setPosition(firstPositionx, firstPositiony);

		}
	}
	else {
		y1.setPosition(getPositionx(diceno), getPositiony(diceno));
	}


	//y1.setPosition(PlayerPositionx[initialPosition_x]-50, PlayerPositiony[initialPosition_y]-50);
	window.draw(y1);
}
float PlayerYellow::getPositiony(int movex) {

	initialPosition_y += movex;

	if (initialPosition_y > 58) {
		initialPosition_y = 58 - (initialPosition_y - 58);
	}
	return PlayerPositiony[initialPosition_y] - 50;

}
float PlayerYellow::getPositionx(int movex) {

	initialPosition_x += movex;
	if (initialPosition_x > 58) {
		initialPosition_x = 58 - (initialPosition_x - 58);
	}
	return PlayerPositionx[initialPosition_x] - 50;

}
void PlayerYellow::resetPosition() {
	initialPosition_x = 0;
	initialPosition_y = 0;
	y1.setPosition(firstPositionx, firstPositiony);
}
float PlayerYellow::getPosx() {
	return y1.getPosition().x;
	std::cout << "called";

}
float PlayerYellow::getPosy() {
	return y1.getPosition().y;
}





