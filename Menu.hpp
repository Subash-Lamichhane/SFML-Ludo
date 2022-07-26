//	Menu.hpp
//	Header file for Menu.cpp

#pragma once

#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_LABELS 3

class Menu
{
public:
	// Constructor
	Menu(float width, float height);
	//	Destructor
	~Menu();

	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	int getPressedLabel();
	void checkUsingMouse(sf::Vector2i mouseCLickPos);
	int returnClickedValue(sf::Vector2i mouseClickPos);

private:
	int selectedLabelIndex;
	sf::Font font;
	//	Array of menu elements declared
	sf::Text menu[MAX_NUMBER_OF_LABELS];
	float labelWidth;
};