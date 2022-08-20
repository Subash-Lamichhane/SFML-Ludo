#include "dice_animations.hpp"
#include<iostream>


dice_animations::dice_animations(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount; //since both have same name in different class(one from variable and one from passed function)
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x=0;
	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);

}
//sf::Texture diceTexture;


dice_animations::~dice_animations()
{

}
void dice_animations::Update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;


	while (totalTime > switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if(currentImage.x>=imageCount.x)
		{
			break;

			//dicerollWindow.close();
			//currentImage.x=0;
		}



		uvRect.left = currentImage.x * uvRect.width;
		uvRect.top = currentImage.y * uvRect.height;
	}

}