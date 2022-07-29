//	Menu.cpp


#include "Menu.hpp"
#include <iostream>

Menu::Menu(float width, float height)
{

	//	Specify positions for labels
	labelWidth = width / 8 - 50;

	if (!font.loadFromFile("Chocolate Covered Raindrops.ttf"))
	{
		//	Error handling
		std::cout << "Error loading font." << std::endl;
	}
	//	Label : PLAY
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("PLAY");
	//	Specify postion for label dynamically
	menu[0].setPosition(sf::Vector2f(labelWidth, height / (MAX_NUMBER_OF_LABELS + 1) * 1));

	//	Label : OPTIONS
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("CREDITS");
	//	Specify postion for label dynamically
	menu[1].setPosition(sf::Vector2f(labelWidth, height / (MAX_NUMBER_OF_LABELS + 1) * 2));

	//	Label : QUIT
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("QUIT");
	//	Specify postion for label
	menu[2].setPosition(sf::Vector2f(labelWidth, height / (MAX_NUMBER_OF_LABELS + 1) * 3));
	selectedLabelIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_LABELS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::moveUp() {
	std::cout << selectedLabelIndex;
	if (selectedLabelIndex - 1 >= 0)
	{
		menu[selectedLabelIndex].setFillColor(sf::Color::White);
		selectedLabelIndex--;
		menu[selectedLabelIndex].setFillColor(sf::Color::Red);

	}
}

void Menu::moveDown() {
	if (selectedLabelIndex + 1 <= MAX_NUMBER_OF_LABELS - 1)
	{
		menu[selectedLabelIndex].setFillColor(sf::Color::White);

		selectedLabelIndex++;
		menu[selectedLabelIndex].setFillColor(sf::Color::Red);

	}
}
void Menu::checkUsingMouse(sf::Vector2i mouseClickPos) {


	//For Play
	if (mouseClickPos.x <= menu[0].getPosition().x + 50 && mouseClickPos.x >= menu[0].getPosition().x && mouseClickPos.y <= menu[0].getPosition().y + 30 && mouseClickPos.y >= menu[0].getPosition().y) {
		//menu[selectedLabelIndex].setFillColor(sf::Color::White);
		menu[1].setFillColor(sf::Color::White);
		menu[2].setFillColor(sf::Color::White);
		selectedLabelIndex = 0;
		menu[0].setFillColor(sf::Color::Red);
	}

	//For credits
	if (mouseClickPos.x <= menu[1].getPosition().x + 80 && mouseClickPos.x >= menu[1].getPosition().x && mouseClickPos.y <= menu[1].getPosition().y + 50 && mouseClickPos.y >= menu[1].getPosition().y) {
		menu[0].setFillColor(sf::Color::White);
		menu[2].setFillColor(sf::Color::White);
		selectedLabelIndex = 1;
		menu[1].setFillColor(sf::Color::Red);
	}

	//For exit
	if (mouseClickPos.x <= menu[2].getPosition().x + 50 && mouseClickPos.x >= menu[2].getPosition().x && mouseClickPos.y <= menu[2].getPosition().y + 30 && mouseClickPos.y >= menu[2].getPosition().y) {
		//menu[selectedLabelIndex].setFillColor(sf::Color::White);
		menu[0].setFillColor(sf::Color::White);
		menu[1].setFillColor(sf::Color::White);
		selectedLabelIndex = 2;
		menu[2].setFillColor(sf::Color::Red);
	}



}
int Menu::returnClickedValue(sf::Vector2i mouseClickPos) {
	if (mouseClickPos.x <= menu[0].getPosition().x + 50 && mouseClickPos.x >= menu[0].getPosition().x && mouseClickPos.y <= menu[0].getPosition().y + 30 && mouseClickPos.y >= menu[0].getPosition().y) {
		return 0;
	}
		
	else if (mouseClickPos.x <= menu[1].getPosition().x + 80 && mouseClickPos.x >= menu[1].getPosition().x && mouseClickPos.y <= menu[1].getPosition().y + 50 && mouseClickPos.y >= menu[1].getPosition().y) {
		return 1;
	}
	else if (mouseClickPos.x <= menu[2].getPosition().x + 50 && mouseClickPos.x >= menu[2].getPosition().x && mouseClickPos.y <= menu[2].getPosition().y + 30 && mouseClickPos.y >= menu[2].getPosition().y) {
		return 2;
	}
	else {
		return 10;
	}
	
}




int Menu::getPressedLabel() {
	std::cout << selectedLabelIndex;
	return selectedLabelIndex;
}