#ifndef DICE_ANIMATIONS_H
#define DICE_ANIMATIONS_H
#include<SFML/Graphics.hpp>

#pragma once

class dice_animations
{
public:
    dice_animations(sf::Texture* texture,sf::Vector2u imageCount, float switchTime);
    ~dice_animations();

	void Update(int row, float deltaTime);

public:

sf::IntRect uvRect;
//controlling speed of animations
float totalTime; //totaltime of animationn
float switchTime; //swithing time between one image to another
	sf::Vector2u imageCount;//no of image in each row of the animation
	sf::Vector2u currentImage;

private:




};

#endif