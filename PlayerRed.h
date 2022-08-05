#pragma once
#pragma once
#include <SFML/Graphics.hpp>
class PlayerRed
{
private:
	sf::RectangleShape y1;

public:
	PlayerRed(float initialPositionx, float initialPositiony);
	~PlayerRed();
	void draw(sf::RenderWindow& window, int diceno);
	float getPositiony(int movex);
	float getPositionx(int movex);
	float getPosx();
	float getPosy();
	//void move(int);
	float PlayerPositiony[58] = { 0.,100.,166.667,233.333,300.,366.666,433.333,433.333,433.333,433.333,433.333,433.333,
							   500.,566.666,566.666,566.666,566.666,566.666,566.666,633.333,700.,766.669,833.33,900.,966.667,966.667,966.67,900.,833.333,766.669,
							   700.,633.333,566.666,566.666,566.666,566.666,566.666,566.666,500.,433.333,433.333,433.333,433.333,433.333,433.33,
							   366.666,300.,233.333,166.667,100.,33.333,33.33,100.,166.667,233.333,300.,366.666,433.333 };

	float PlayerPositionx[58] = { 0.,566.666,566.666,566.666,566.666,566.666,633.333,700.,766.669,833.33,900.,966.667,966.667 ,966.667,900,833.33,766.666,700.,
								633.33,566.667,566.667 ,566.667 ,566.667 ,566.667 , 566.667,500.,433.33,433.333,433.333,433.333,433.333,433.333,
							   366.666,300.,233.333,166.667,100.,33.333,33.33,33.33,100.,166.667,233.333,300.,366.666,433.333,433.333,433.333,433.333,433.333,433.333,
							   500.,500.,500.,500.,500.,500.,500.};
	void setPosition(float diceno);
	void resetPosition();

private:
	int initialPositionBlue_y = 0;
	int initialPositionBlue_x = 0;
	float firstPositionx;
	float firstPositiony;
};

