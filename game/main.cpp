#include <SFML/Graphics.hpp>
#include<windows.h>
#include<stdio.h>

float x_player=750, y_player=500;

float jump = 1.5;

struct data
{
	float x= 0, y= 530;

} player1;

sf::RenderWindow window(sf::VideoMode(1200, 800), "Road to champions");

sf::RectangleShape player(sf::Vector2f(160.0f, 120.0f));
sf::Texture playerTexture;
sf::IntRect rectSourceplayer(35, 0, 80, 60);
sf::Clock cloc;

//ichigoz
int Stay(int);
int Right(int);
int Left(int);
int Jump(int);
void PG();

int main()
{
	
	//player.setFillColor(sf::Color::Cyan);
	
	//charector ichigoz
	playerTexture.loadFromFile("Textures/12.png");
	player.setTexture(&playerTexture);
	player.setTextureRect(rectSourceplayer);
	
	int direct_player=1,directjump=0,directPG=0;
	

	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::TextEntered)
			{
				printf("%c", event.text.unicode);
			}
				
		}
		
		
		player.setTextureRect(rectSourceplayer);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			direct_player =Left(direct_player);
			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			direct_player = Right(direct_player);
			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			directjump = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			
			PG();
			directPG = 1;
			
		}
		else
		{
			if (directPG ==1)
			{
				rectSourceplayer.left = 35;
				directPG = 0;
			}
			rectSourceplayer.top = 0;
			direct_player =Stay(direct_player);

		}
		
		
		
		directjump = Jump(directjump);
		

		window.clear();
		player.setPosition(player1.x, player1.y);
		window.draw(player);
		window.display();
	}
	
	return 0;
}
int Stay(int direct)
{
	if (direct == 1 || direct == 2)
	{
		rectSourceplayer.left = 35;
		if (direct == 1)
		{
			direct = 11;
		}
		else
		{
			direct = 22;
		}

	}
	if (cloc.getElapsedTime().asSeconds() > 0.150f)
	{
		if (rectSourceplayer.left == 431)
		{
			rectSourceplayer.left = 35;
		}
		else
		{
			rectSourceplayer.left += 132;
		}
		player.setTextureRect(rectSourceplayer);
		cloc.restart();
		

	}
	return direct;

}

int Right(int direct)
{
	if (direct == 11)
	{
		rectSourceplayer.left = 563;
	}

	if (direct != 1 && direct != 11)
	{
		player1.x -= 160;
		player.setScale({ 1, 1 });
		rectSourceplayer.left = 563;

	}
	direct = 1;
	player1.x += 0.5f;
	
	if (cloc.getElapsedTime().asSeconds() > 0.100f)
	{
		if (rectSourceplayer.left == 1091)
		{
			rectSourceplayer.left = 563;
		}
		else
		{
			rectSourceplayer.left += 132;
		}
		player.setTextureRect(rectSourceplayer);
		cloc.restart();


	}

	return direct;
}

int Left(int direct)
{
	
	
	if (direct == 22)
	{
		rectSourceplayer.left = 563;
	}

	if (direct != 2 && direct != 22)
	{
		player1.x += 160;
		player.setScale({ -1, 1 });
		rectSourceplayer.left = 563;
	}
	direct = 2;
	player1.x += -0.5f;
	if (cloc.getElapsedTime().asSeconds() > 0.100f)
	{
		if (rectSourceplayer.left == 1091)
		{
			rectSourceplayer.left = 563;

		}
		else
		{
			rectSourceplayer.left += 132;
		}
		
		player.setTextureRect(rectSourceplayer);
		cloc.restart();


	}

	return direct;
}
int Jump(int directjump)
{
	
	if (directjump == 1)
	{
		rectSourceplayer.top = 200;
		rectSourceplayer.left = 35;

		player1.y -= jump;
		if (player1.y < 390)
		{
			jump = jump * -1;
		}
		else if (player1.y >= 530 && jump < 0)
		{
			directjump = 0;
			jump = jump * -1;
			player1.y = 530;
			rectSourceplayer.top = 0;
		}

	}
	return directjump;
}

void PG()
{
	rectSourceplayer.top = 100;
	rectSourceplayer.left = 695;
	
}