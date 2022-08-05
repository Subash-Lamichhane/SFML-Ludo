
#ifndef DICE_ANIMATIONS_H
#define DICE_ANIMATIONS_H
#include<SFML/Graphics.hpp>

#pragma once

class dice_animations
{
public:
	dice_animations(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~dice_animations();

	void Update(int row, float deltaTime);

public:
	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	//controlling speed of animations

	float totalTime;
	float switchTime;


};

#endif