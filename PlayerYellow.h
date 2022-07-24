#pragma once
#include <SFML/Graphics.hpp>
class PlayerYellow
{
private:
	sf::RectangleShape y1;

public:
	PlayerYellow(float initialPosition_x,float initialPosition_y);
	~PlayerYellow();
	void draw(sf::RenderWindow& window, float position_x, float position_y);
	float getPositiony(int movex,int initialPositiony);
	//void move(int);
	float PlayerPositiony[57] = { 900.,833.333,766.669, 700.,633.333,566.666,566.666,566.666,566.666,566.666,566.666,500.,433.333,433.333,433.333,433.333,433.333,433.333,
							   366.666,300.,233.333,166.667,100.,33.333,33.33,33.33,100.,166.667,233.333,300.,366.666,433.333,433.333,433.333,433.333,433.333,433.333,
							   500.,566.666,566.666,566.666,566.666,566.666,566.666,633.333,700.,766.669,833.33,900.,966.667,966.667,900.,833.333,766.669, 700.,633.333,566.666 };

	float PlayerPositionx[57] = { 433.333,433.333,433.333,433.333,433.333,
							   366.666,300.,233.333,166.667,100.,33.333,33.33,33.33,100.,166.667,233.333,300.,366.666,433.333,433.333,433.333,433.333,433.333,433.333,
							   500.,566.666,566.666,566.666,566.666,566.666,566.666,633.333,700.,766.669,833.33,900.,966.667,966.667 ,966.667,900,833.33,766.666,700.,
								633.33,566.667,566.667 ,566.667 ,566.667 ,566.667 , 566.667,500.,500.,500.,500.,500.,500.,500. };
	void setPosition(float x, float y);
private:
	static int initialPositiony;
	static int initialPositionx;

	
	//int selectedPlayer;
	//int playerTurn
	//int bluePosition[] = {};
	//sf::RectangleShape y1(sf::Vector2f(100.0f, 100.0f));

};

