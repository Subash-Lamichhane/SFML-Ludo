#include "PlayerRed.h"
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>

PlayerRed::PlayerRed(float initialPositionx, float initialPositiony) {

	y1.setPosition(initialPositionx, initialPositiony);
	firstPositionx = initialPositionx;
	firstPositiony = initialPositiony;
	PlayerPositiony[0] = initialPositiony;
	PlayerPositionx[0] = initialPositionx;
	y1.setPosition(firstPositionx, firstPositiony);
}
PlayerRed::~PlayerRed() {}


void PlayerRed::draw(sf::RenderWindow& window, int diceno) {

	sf::RectangleShape y1(sf::Vector2f(100.0f, 100.0f));
	sf::Texture playerb;
	playerb.loadFromFile("Gotti/red.png");
	y1.setTexture(&playerb);


	if (initialPositionRed_x == 0 && initialPositionRed_y == 0) {
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
float PlayerRed::getPositiony(int movex) {
	initialPositionRed_y += movex;
	if (initialPositionRed_y > 58) {
		initialPositionRed_y = 58 - (initialPositionRed_y - 58);
	}
	return PlayerPositiony[initialPositionRed_y] - 50;

}
float PlayerRed::getPositionx(int movex) {
	initialPositionRed_x += movex;
	if (initialPositionRed_x > 58) {
		initialPositionRed_x = 58 - (initialPositionRed_x - 58);
	}
	return PlayerPositionx[initialPositionRed_x] - 50;

}
void PlayerRed::setPosition(float diceno) {
	if (initialPositionRed_x == 0 && initialPositionRed_y == 0) {
		if (diceno == 1) {
			y1.setPosition(getPositionx(diceno), getPositiony(diceno));
		}
	}
	else {
		y1.setPosition(getPositionx(diceno), getPositiony(diceno));
	}
}


void PlayerRed::resetPosition() {
	initialPositionRed_x = 0;
	initialPositionRed_y = 0;
	y1.setPosition(firstPositionx, firstPositiony);
}
float PlayerRed::getPosx() {
	return y1.getPosition().x;
}
float PlayerRed::getPosy() {
	return y1.getPosition().y;
}