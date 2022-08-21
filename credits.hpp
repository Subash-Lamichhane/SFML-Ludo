
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.hpp"



class Credits
{
public:
	//	Credits animation
	//	Constructor
	Credits();
	//void renderCredits(sf::RenderWindow& window);
	void openCreditsWindow(sf::RenderWindow& window);


private:
	sf::Font font;
	sf::Text creditsText;
	sf::Text escapeText;
	//	Credits text to be displayed
	std::string credits_Info = "Developed By \n Samundra Subedi\n Subash Lamichhane";
	std::string escLetter = "ESC\n";
};