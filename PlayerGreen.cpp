#include "PlayerGreen.h"
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>

PlayerGreen::PlayerGreen(float initialPositionx, float initialPositiony) {

	y1.setPosition(initialPositionx, initialPositiony);
	firstPositionx = initialPositionx;
	firstPositiony = initialPositiony;
	PlayerPositiony[0] = initialPositiony;
	PlayerPositionx[0] = initialPositionx;
	y1.setPosition(firstPositionx, firstPositiony);
}
PlayerGreen::~PlayerGreen() {}


void PlayerGreen::draw(sf::RenderWindow& window, int diceno) {
	sf::RectangleShape y1(sf::Vector2f(100.0f, 100.0f));
	sf::Texture playerb;
	playerb.loadFromFile("Gotti/green.png");
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
float PlayerGreen::getPositiony(int movex) {

	initialPosition_y += movex;
	return PlayerPositiony[initialPosition_y] - 51;

}
float PlayerGreen::getPositionx(int movex) {
	initialPosition_x += movex;
	return PlayerPositionx[initialPosition_x] - 51;

}
float PlayerGreen::getPosx() {
	return y1.getPosition().x;


}
float PlayerGreen::getPosy() {
	return y1.getPosition().y;
}