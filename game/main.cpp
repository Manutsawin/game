#include <SFML/Graphics.hpp>
#include<windows.h>
#include<stdio.h>

struct charecter
{
	float x= 0, y= 530;
	float jump = 1.1;//speed of jump
	sf::Texture Texture;
	sf::IntRect rectSourceplayer;
	
	
} player1;

sf::RenderWindow window(sf::VideoMode(1200, 800), "Road to champions");
sf::RectangleShape sprite_player1(sf::Vector2f(160.0f, 120.0f));

sf::Clock cloc, clockJ;

//ichigoz
int Stay_ichigoz(int);
int Right_ichigoz(int);
int Left_ichigoz(int);
int Jump_ichigoz(int);
void PG_ichigoz();
int flash_ichigoz(int);
int J_ichigoz(int);
void statement();

int direct_player = 1, directjump = 0, directPG = 0, directJ = 0;

int main()
{
	player1.rectSourceplayer.top = 0;
	player1.rectSourceplayer.left = 35;
	player1.rectSourceplayer.width = 80;
	player1.rectSourceplayer.height = 60;

	//player.setFillColor(sf::Color::Cyan);

	//charector ichigoz
	player1.Texture.loadFromFile("Textures/12.png");
	sprite_player1.setTexture(&player1.Texture);
	sprite_player1.setTextureRect(player1.rectSourceplayer);
	
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
		statement();
		window.clear();
		sprite_player1.setPosition(player1.x, player1.y);
		window.draw(sprite_player1);
		window.display();
	}
	
	return 0;
}
void statement()
{
	sprite_player1.setTextureRect(player1.rectSourceplayer);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		if (directJ != 1)
		{
			direct_player = Left_ichigoz(direct_player);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		if (directJ != 1)
		{
			direct_player = Right_ichigoz(direct_player);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K))
	{
		if (directJ != 1)
		{
			directjump = 1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L))
	{
		if (directJ != 1&& directjump != 1)
		{
			direct_player = flash_ichigoz(direct_player);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J))
	{
		if (directJ == 0)
		{
			directJ = 1;
			clockJ.restart();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		PG_ichigoz();
		directPG = 1;
	}
	else if (directJ != 1)
	{
		if (directPG == 1)
		{
			player1.rectSourceplayer.left = 35;
			directPG = 0;
		}
		player1.rectSourceplayer.top = 0;
		direct_player = Stay_ichigoz(direct_player);
	}




	if (directJ == 1)
	{
		if (clockJ.getElapsedTime().asSeconds() > 0.65f)
		{
			directJ = 0;
			clockJ.restart();
			player1.rectSourceplayer.top = 0;
			direct_player = Stay_ichigoz(direct_player);
		}
		else
		{
			direct_player = J_ichigoz(direct_player);
		}

	}
	directjump = Jump_ichigoz(directjump);

}
int Stay_ichigoz(int direct)
{
	if (direct == 1 || direct == 2)
	{
		player1.rectSourceplayer.left = 35;
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
		if (player1.rectSourceplayer.left == 431)
		{
			player1.rectSourceplayer.left = 35;
		}
		else
		{
			player1.rectSourceplayer.left += 132;
		}
		sprite_player1.setTextureRect(player1.rectSourceplayer);
		cloc.restart();
		

	}
	return direct;

}

int Right_ichigoz(int direct)
{
	
	if (direct == 11)
	{
		player1.rectSourceplayer.left = 563;
	}

	if (direct != 1 && direct != 11)
	{
		player1.x -= 160;
		sprite_player1.setScale({ 1, 1 });
		player1.rectSourceplayer.left = 563;

	}
	direct = 1;
	if (player1.x < 1040)
	{
		player1.x += 0.5f;
	}

	if (cloc.getElapsedTime().asSeconds() > 0.100f)
	{
		if (player1.rectSourceplayer.left == 1091)
		{
			player1.rectSourceplayer.left = 563;
		}
		else
		{
			player1.rectSourceplayer.left += 132;
		}
		sprite_player1.setTextureRect(player1.rectSourceplayer);
		cloc.restart();


	}

	return direct;
}

int Left_ichigoz(int direct)
{
	
	
	if (direct == 22)
	{
		player1.rectSourceplayer.left = 563;
	}

	if (direct != 2 && direct != 22)
	{
		player1.x += 160;
		sprite_player1.setScale({ -1, 1 });
		player1.rectSourceplayer.left = 563;
	}
	direct = 2;
	if (player1.x >= 160)
	{
		player1.x += -0.5f;
	}
	
	if (cloc.getElapsedTime().asSeconds() > 0.100f)
	{
		if (player1.rectSourceplayer.left == 1091)
		{
			player1.rectSourceplayer.left = 563;

		}
		else
		{
			player1.rectSourceplayer.left += 132;
		}
		
		sprite_player1.setTextureRect(player1.rectSourceplayer);
		cloc.restart();


	}

	return direct;
}
int Jump_ichigoz(int directjump)
{
	
	if (directjump == 1)
	{
		player1.rectSourceplayer.top = 200;
		player1.rectSourceplayer.left = 35;

		player1.y -= player1.jump;
		if (player1.y < 390)
		{
			player1.jump = player1.jump * -1;
		}
		else if (player1.y >= 530 && player1.jump < 0)
		{
			directjump = 0;
			player1.jump = player1.jump * -1;
			player1.y = 530;
			player1.rectSourceplayer.top = 0;
		}

	}
	return directjump;
}

void PG_ichigoz()
{
	player1.rectSourceplayer.top = 100;
	player1.rectSourceplayer.left = 695;
	
}

int flash_ichigoz(int direct)
{
	if (direct == 1 || direct == 11)
	{
		if (direct == 11)
		{
			player1.rectSourceplayer.left = 563;
		}

		if (direct != 1 && direct != 11)
		{
			player1.x -= 160;
			sprite_player1.setScale({ 1, 1 });
			player1.rectSourceplayer.left = 563;

		}
		direct = 1;

		if (player1.x < 1040)
		{
			player1.x += 3.0f;
		}

		if (cloc.getElapsedTime().asSeconds() > 0.100f)
		{
			if (player1.rectSourceplayer.left == 1091)
			{
				player1.rectSourceplayer.left = 563;
			}
			else
			{
				player1.rectSourceplayer.left += 132;
			}
			sprite_player1.setTextureRect(player1.rectSourceplayer);
			cloc.restart();


		}

		return direct;
	}

	if (direct == 2 || direct == 22)
	{

		if (direct == 22)
		{
			player1.rectSourceplayer.left = 563;
		}

		if (direct != 2 && direct != 22)
		{
			player1.x += 160;
			sprite_player1.setScale({ -1, 1 });
			player1.rectSourceplayer.left = 563;
		}
		direct = 2;
		if (player1.x >= 160)
		{
			player1.x += -3.0f;
		}
		if (cloc.getElapsedTime().asSeconds() > 0.100f)
		{
			if (player1.rectSourceplayer.left == 1091)
			{
				player1.rectSourceplayer.left = 563;

			}
			else
			{
				player1.rectSourceplayer.left += 132;
			}

			sprite_player1.setTextureRect(player1.rectSourceplayer);
			cloc.restart();


		}

		return direct;
	}
	
}
int J_ichigoz(int direct)
{
	if (direct == 1 || direct == 11)
	{
		if (direct == 11)
		{
			player1.rectSourceplayer.left = 563;
			player1.rectSourceplayer.top = 950;
		}
		if (direct != 1 && direct != 11)
		{
			player1.x -= 160;
			sprite_player1.setScale({ 1, 1 });
			player1.rectSourceplayer.left = 563;
		}
		if (player1.x < 1040)
		{
			player1.x += 0.03f;
		}
		direct = 1;
		if (cloc.getElapsedTime().asSeconds() > 0.120f)
		{
			if (player1.rectSourceplayer.left == 1223)
			{
				player1.rectSourceplayer.left = 563;
			}
			else
			{
				player1.rectSourceplayer.left += 132;
			}
			sprite_player1.setTextureRect(player1.rectSourceplayer);
			cloc.restart();
		}

		return direct;
	}
	if (direct == 2 || direct == 22)
	{
		if (direct == 22)
		{
			player1.rectSourceplayer.left = 563;
			player1.rectSourceplayer.top = 950;
		}
		if (direct != 2 && direct != 22)
		{
			player1.x += 160;
			sprite_player1.setScale({ -1, 1 });
			player1.rectSourceplayer.left = 563;
		}
		if (player1.x >= 160)
		{
			player1.x += -0.03f;
		}
		direct = 2;
		if (cloc.getElapsedTime().asSeconds() > 0.120f)
		{
			if (player1.rectSourceplayer.left == 1223)
			{
				player1.rectSourceplayer.left = 563;
			}
			else
			{
				player1.rectSourceplayer.left += 132;
			}
			sprite_player1.setTextureRect(player1.rectSourceplayer);
			cloc.restart();
		}
		return direct;
	}

}