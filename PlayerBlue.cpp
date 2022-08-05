#include "PlayerBlue.h"
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>

PlayerBlue::PlayerBlue(float initialPositionx, float initialPositiony) {

	y1.setPosition(initialPositionx, initialPositiony);
	firstPositionx = initialPositionx;
	firstPositiony = initialPositiony;
	PlayerPositiony[0] = initialPositiony;
	PlayerPositionx[0] = initialPositionx;
	y1.setPosition(firstPositionx, firstPositiony);
}
PlayerBlue::~PlayerBlue() {}


void PlayerBlue::draw(sf::RenderWindow& window,int diceno) {

	sf::RectangleShape y1(sf::Vector2f(100.0f, 100.0f));
	sf::Texture playerb;
	playerb.loadFromFile("Gotti/blue.png");
	y1.setTexture(&playerb);


	if (initialPositionBlue_x == 0 && initialPositionBlue_y == 0) {
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
float PlayerBlue::getPositiony(int movex) {
	initialPositionBlue_y += movex;
	return PlayerPositiony[initialPositionBlue_y] - 50;

}
float PlayerBlue::getPositionx(int movex) {
	initialPositionBlue_x += movex;
	return PlayerPositionx[initialPositionBlue_x] - 50;

}
void PlayerBlue::setPosition(float diceno) {
	if (initialPositionBlue_x == 0 && initialPositionBlue_y == 0) {
		if (diceno == 1) {
			std::cout << "Position" << getPositionx(diceno);
			y1.setPosition(getPositionx(diceno), getPositiony(diceno));
		}
	}
	else {
		y1.setPosition(getPositionx(diceno), getPositiony(diceno));
	}
}


void PlayerBlue::resetPosition() {
	initialPositionBlue_x = 0;
	initialPositionBlue_y = 0;
	y1.setPosition(firstPositionx, firstPositiony);
}
float PlayerBlue::getPosx() {
	return y1.getPosition().x;

}
float PlayerBlue::getPosy() {
	return y1.getPosition().y;
}