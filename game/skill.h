#pragma once
#include <SFML/Graphics.hpp>
#include<stdio.h>
class skill
{
public:
	
	skill(sf::Texture* texture,sf::Vector2u imageCount, float switchTime );
	~skill();

	void Update(int row, float deltaTime);

public:

	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

