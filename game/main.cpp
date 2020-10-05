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
int Stay_Fuc(int);
int move_Right_Fuc(int);
int move_Left_Fuc(int);
int Jump_Fuc(int);
void PG_Fuc();
int Flash_Fuc(int);
int J_attack(int);
void statement();

struct Vector
{
	int direct = 0;
} player , jump , PG , J;

int combo = 0;



int main()
{
	player.direct = 1;

	player1.rectSourceplayer.top = 0;
	player1.rectSourceplayer.left = 35;
	player1.rectSourceplayer.width = 80;
	player1.rectSourceplayer.height = 60;

	//player.setFillColor(sf::Color::Cyan);

	
	player1.Texture.loadFromFile("Textures/11.png");
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
				printf("%c\n", event.text.unicode);
				//printf("x= %f  y=%f\n", player1.x, player1.y);
				
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
		combo = 0;
		if (J.direct != 1&& PG.direct != 1)
		{
			player.direct = move_Left_Fuc(player.direct);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		combo = 0;
		if (J.direct != 1&& PG.direct != 1)
		{
			player.direct = move_Right_Fuc(player.direct);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K))
	{
		combo = 0;
		if (J.direct != 1&& PG.direct != 1)
		{
			jump.direct = 1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L))
	{
		
		combo = 0;
		if (J.direct != 1&& jump.direct != 1&& PG.direct != 1)
		{
			player.direct = Flash_Fuc(player.direct);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J))
	{
		if (J.direct == 0 && jump.direct != 1 && PG.direct != 1 &&combo<3)
		{
			player.direct = Stay_Fuc(player.direct);
			J.direct = 1;
			clockJ.restart();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		combo = 0;
		PG_Fuc();
		PG.direct = 1;
	}
	else if (J.direct != 1)
	{
		
		if (PG.direct == 1)
		{
			player1.rectSourceplayer.left = 35; // left default
			PG.direct = 0;
		}
		player1.rectSourceplayer.top = 0; // top default
		player.direct = Stay_Fuc(player.direct);
	}
	
	

	if (J.direct == 1)
	{
		
		if (clockJ.getElapsedTime().asSeconds() > 0.65f)
		{
			J.direct = 0;
			clockJ.restart();
			player1.rectSourceplayer.top = 0;  // top default
			player.direct = Stay_Fuc(player.direct);
			combo++;
		}
		else
		{
			player.direct = J_attack(player.direct);
		}

	}
	jump.direct = Jump_Fuc(jump.direct);

}
int Stay_Fuc(int direct)
{
	if (direct == 1 || direct == 2)
	{
		player1.rectSourceplayer.left = 35; //left default left 
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
		if (player1.rectSourceplayer.left == 431) //stay max left 
		{
			player1.rectSourceplayer.left = 35; //stay default left 
			combo = 0;
		}
		else
		{
			player1.rectSourceplayer.left += 132; //plus left 
		}
		sprite_player1.setTextureRect(player1.rectSourceplayer);
		cloc.restart();
		
		
	}
	return direct;

}

int move_Right_Fuc(int direct)
{
	
	if (direct == 11)
	{
		player1.rectSourceplayer.left = 563; //move left,right default left 
	}

	if (direct != 1 && direct != 11)
	{
		player1.x -= 160;
		sprite_player1.setScale({ 1, 1 });
		player1.rectSourceplayer.left = 563; //move left,right default left 

	}
	direct = 1;
	if (player1.x < 1040)
	{
		player1.x += 0.5f;
	}

	if (cloc.getElapsedTime().asSeconds() > 0.100f)
	{
		if (player1.rectSourceplayer.left == 1091) //move left,right max left 
		{
			player1.rectSourceplayer.left = 563; //move left,right default left 
		}
		else
		{
			player1.rectSourceplayer.left += 132; //plus left 
		}
		sprite_player1.setTextureRect(player1.rectSourceplayer);
		cloc.restart();


	}

	return direct;
}

int move_Left_Fuc(int direct)
{
	
	
	if (direct == 22)
	{
		player1.rectSourceplayer.left = 563; //move left,right default left 
	}

	if (direct != 2 && direct != 22)
	{
		player1.x += 160;
		sprite_player1.setScale({ -1, 1 });
		player1.rectSourceplayer.left = 563; //move left,right default left 
	}
	direct = 2;
	if (player1.x >= 160)
	{
		player1.x += -0.5f;
	}
	
	if (cloc.getElapsedTime().asSeconds() > 0.100f)
	{
		if (player1.rectSourceplayer.left == 1091) //move left,right max left 
		{
			player1.rectSourceplayer.left = 563; //move left,right default left 

		}
		else
		{
			player1.rectSourceplayer.left += 132; //plus
		}
		
		sprite_player1.setTextureRect(player1.rectSourceplayer);
		cloc.restart();


	}

	return direct;
}
int Jump_Fuc(int directjump)
{
	
	if (directjump == 1)
	{
		player1.rectSourceplayer.top = 200; 
		player1.rectSourceplayer.left = 35; //jump defualt left 

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
			player1.rectSourceplayer.top = 0; // top defualt 
		}

	}
	return directjump;
}

void PG_Fuc()
{
	player1.rectSourceplayer.top = 100; //PG top
	player1.rectSourceplayer.left = 695;//PG left
	
}

int Flash_Fuc(int direct)
{
	if (direct == 1 || direct == 11)
	{
		if (direct == 11)
		{
			player1.rectSourceplayer.left = 563; //move left,right default left
		}

		if (direct != 1 && direct != 11)
		{
			player1.x -= 160;
			sprite_player1.setScale({ 1, 1 });
			player1.rectSourceplayer.left = 563; //move left,right default left

		}
		direct = 1;

		if (player1.x < 1040)
		{
			player1.x += 3.0f;
		}

		if (cloc.getElapsedTime().asSeconds() > 0.100f)
		{
			if (player1.rectSourceplayer.left == 1091) //move left,right  max left
			{
				player1.rectSourceplayer.left = 563; //move left,right default left
			}
			else
			{
				player1.rectSourceplayer.left += 132; // plus left 
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
			player1.rectSourceplayer.left = 563; //move left,right default left
		}

		if (direct != 2 && direct != 22)
		{
			player1.x += 160;
			sprite_player1.setScale({ -1, 1 });
			player1.rectSourceplayer.left = 563; //move left,right default left
		}
		direct = 2;
		if (player1.x >= 160)
		{
			player1.x += -3.0f;
		}
		if (cloc.getElapsedTime().asSeconds() > 0.100f)
		{
			if (player1.rectSourceplayer.left == 1091) //move left,right max left
			{
				player1.rectSourceplayer.left = 563; //move left,right default left

			}
			else
			{
				player1.rectSourceplayer.left += 132; //plus left
			}

			sprite_player1.setTextureRect(player1.rectSourceplayer);
			cloc.restart();


		}

		return direct;
	}
	
}
int J_attack(int direct)
{
	if (direct == 1 || direct == 11)
	{
		if (direct == 11)
		{
			player1.rectSourceplayer.left = 563; //attack  default left
			player1.rectSourceplayer.top = 950; //attack  default top
		}
		if (direct != 1 && direct != 11)
		{
			player1.x -= 160;
			sprite_player1.setScale({ 1, 1 });
			player1.rectSourceplayer.left = 563; //attack  default left
		}
		if (player1.x < 1040)
		{
			player1.x += 0.03f;
		}
		direct = 1;
		if (cloc.getElapsedTime().asSeconds() > 0.120f)
		{
			if (player1.rectSourceplayer.left == 1223) //attack  max left
			{
				player1.rectSourceplayer.left = 563; //attack  default left
			}
			else
			{
				player1.rectSourceplayer.left += 132; // plus left
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
			player1.rectSourceplayer.left = 563; //attack  default left
			player1.rectSourceplayer.top = 950; //attack  default top
		}
		if (direct != 2 && direct != 22)
		{
			player1.x += 160;
			sprite_player1.setScale({ -1, 1 });
			player1.rectSourceplayer.left = 563; //attack  default left
		}
		if (player1.x >= 160)
		{
			player1.x += -0.03f;
		}
		direct = 2;
		if (cloc.getElapsedTime().asSeconds() > 0.120f)
		{
			if (player1.rectSourceplayer.left == 1223) //attack  max left
			{
				player1.rectSourceplayer.left = 563; //attack  default left
			}
			else
			{
				player1.rectSourceplayer.left += 132; //plus left
			}
			sprite_player1.setTextureRect(player1.rectSourceplayer);
			cloc.restart();
		}
		return direct;
	}

}