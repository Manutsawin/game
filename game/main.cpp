#include <SFML/Graphics.hpp>
#include<windows.h>
#include<stdio.h>
#include "skill.h"
#include"HP.h"


struct charecter
{
	float x= 0, y= 530;
	float jump = 1.1;//speed of jump
	sf::Texture Texture;
	sf::IntRect rectSource;

} player1,enamy1,   BG,hpBar_player,hpBar_enamy    ,skillthrow;

sf::RenderWindow window(sf::VideoMode(1200, 800), "Road to champions");
sf::RectangleShape sprite_BG(sf::Vector2f(1200.0f,800.0f));

sf::RectangleShape sprite_player1(sf::Vector2f(160.0f, 120.0f));
sf::RectangleShape sprite_hpBar_enamy(sf::Vector2f(500.0f, 40.0f));
sf::RectangleShape sprite_enamy(sf::Vector2f(160.0f, 120.0f));
sf::RectangleShape sprite_hpBar_player(sf::Vector2f(500.0f, 40.0f));

//skill
sf::RectangleShape sprite_skillthrow(sf::Vector2f(300.0f, 500.0f));



sf::Clock clock_ani_player, clockJ_player , clock_ani_enamy, clockJ_enamy;

//movement control player
int Stay_player_Fuc(int);
int move_Right_player_Fuc(int);
int move_Left_player_Fuc(int);
int Jump_player_Fuc(int);
void PG_player_Fuc();
int Flash_player_Fuc(int);
int J_attack_player_Fuc(int);
void U_player_Fuc();

//movement control enamy
int Stay_enamy_Fuc(int);

//int move_Right_player_Fuc(int);
//int move_Left_player_Fuc(int);
//int Jump_player_Fuc(int);
//void PG_player_Fuc();
//int Flash_player_Fuc(int);
//int J_attack_player_Fuc(int);
//void U_player_Fuc();

void control();
void draw_pic();
void setup();
void hpbar(float);
void hpbar_enamy(float);

struct Vector
{
	int direct = 0;
} player , enamy , jump , PG , J ,Uskill;

int combo_player, combo_enamy = 0;
int damage_player=21, total_hp_playyer =23, damage_enamy = 0, total_hp_enamy = 23; //hp = 1 lose

float deltatime = 0.0f;
float x_playercheak,y_playercheak, x_enamycheak, y_enamycheak;
sf::Clock skill_clock;

int main()
{
	//skill
	
	setup();

	skill animetion(&skillthrow.Texture, sf::Vector2u(4,1), 0.1f );

	
	while (window.isOpen())
	{
		while (total_hp_playyer > 1)
		{
			//cheak position player
			if (player.direct == 1 || player.direct == 11)
			{
				x_playercheak = player1.x + 80;
			}
			else
			{
				x_playercheak = player1.x - 80;
			}
			//cheak position enamy
			if (enamy.direct == 1 || enamy.direct == 11)
			{
				x_enamycheak = enamy1.x + 80;
			}
			else
			{
				x_enamycheak = enamy1.x - 80;
			}

			deltatime = skill_clock.restart().asSeconds();
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
				if (event.type == sf::Event::TextEntered)
				{
					//printf("%c\n", event.text.unicode);
					//printf("x= %f  y=%f\n", x_playercheak, player1.y);

				}
			}
			printf("x= %f  y=%f\t", x_playercheak, player1.y);
			printf("x= %f  y=%f\n", x_enamycheak, enamy1.y);
			animetion.Update(0, deltatime);
			sprite_skillthrow.setTextureRect(animetion.uvRect);
			draw_pic();
			damage_player = 0;
			damage_enamy = 0;
			control();

		}
	}	
	
	return 0;
}
void setup()
{
	//skill
	
	skillthrow.Texture.loadFromFile("skill/getsuka.png");
	sprite_skillthrow.setTexture(&skillthrow.Texture);

	
	player.direct = 1;
	enamy.direct = 2;
	sprite_enamy.setScale({ -1, 1 });
	//player.setFillColor(sf::Color::Cyan);
	
	//BG
	BG.rectSource.top = 10;
	BG.rectSource.left = 200;
	BG.rectSource.width = 300;
	BG.rectSource.height = 200;

	BG.Texture.loadFromFile("Map/1.png");
	sprite_BG.setTexture(&BG.Texture);
	sprite_BG.setTextureRect(BG.rectSource);

	//player
	player1.x = 0;
	player1.rectSource.top = 0;
	player1.rectSource.left = 35;
	player1.rectSource.width = 80;
	player1.rectSource.height = 60;

	player1.Texture.loadFromFile("Textures/12.png");
	sprite_player1.setTexture(&player1.Texture);
	sprite_player1.setTextureRect(player1.rectSource);

	//enamy
	enamy1.x = 1100;
	enamy1.rectSource.top = 0;
	enamy1.rectSource.left = 35;
	enamy1.rectSource.width = 80;
	enamy1.rectSource.height = 60;

	enamy1.Texture.loadFromFile("Textures/naruto.png");
	sprite_enamy.setTexture(&enamy1.Texture);
	sprite_enamy.setTextureRect(enamy1.rectSource);

	//hp_player
	hpBar_player.Texture.loadFromFile("HP/hpall.png");

	//hp_enamy
	hpBar_enamy.Texture.loadFromFile("HP/hpall.png");

	
}
void draw_pic()
{
	
	

	sprite_player1.setPosition(player1.x, player1.y);
	sprite_enamy.setPosition(enamy1.x, enamy1.y);


	
	sprite_skillthrow.setPosition(skillthrow.x, player1.y);
	total_hp_playyer = hpcalculate(damage_player, total_hp_playyer);
	hpbar(total_hp_playyer);

	total_hp_enamy = hpcalculate(damage_enamy, total_hp_enamy);
	hpbar_enamy(total_hp_enamy);

	window.clear();
	window.draw(sprite_BG);
	window.draw(sprite_enamy);
	window.draw(sprite_player1);
	if (Uskill.direct == 1)
	{
		window.draw(sprite_skillthrow);
	}
	window.draw(sprite_hpBar_player);
	window.draw(sprite_hpBar_enamy);
	window.display();
}

void control()
{
	
	sprite_player1.setTextureRect(player1.rectSource);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		combo_player = 0;
		if (J.direct != 1&& PG.direct != 1 )
		{
			player.direct = move_Left_player_Fuc(player.direct);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		combo_player = 0;
		if (J.direct != 1&& PG.direct != 1 )
		{
			player.direct = move_Right_player_Fuc(player.direct);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K))
	{
		combo_player = 0;
		if (J.direct != 1&& PG.direct != 1 )
		{
			jump.direct = 1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L))
	{
		
		combo_player = 0;
		if (J.direct != 1&& jump.direct != 1&& PG.direct != 1 )
		{
			player.direct = Flash_player_Fuc(player.direct);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J))
	{
		if (J.direct == 0 && jump.direct != 1 && PG.direct != 1 &&combo_player<3)
		{
			player.direct = Stay_player_Fuc(player.direct);
			J.direct = 1;
			clockJ_player.restart();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		combo_player = 0;
		PG_player_Fuc();
		PG.direct = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U))
	{
		combo_player = 0;
		PG_player_Fuc();
		Uskill.direct = 1;
		
	}
	else if (J.direct != 1)
	{
		
		if (PG.direct == 1 || Uskill.direct == 1)
		{
			player1.rectSource.left = 35; // left default
			PG.direct = 0;
			Uskill.direct = 0;
		}
		player1.rectSource.top = 0; // top default
		player.direct = Stay_player_Fuc(player.direct);
	}

	enamy.direct = Stay_enamy_Fuc(enamy.direct);//test anime bot

	if (J.direct == 1)
	{
		
		if (clockJ_player.getElapsedTime().asSeconds() > 0.65f)
		{
			J.direct = 0;
			clockJ_player.restart();
			player1.rectSource.top = 0;  // top default
			player.direct = Stay_player_Fuc(player.direct);
			combo_player++;
		}
		else
		{
			player.direct = J_attack_player_Fuc(player.direct);
		}

	}
	jump.direct = Jump_player_Fuc(jump.direct);

}
int Stay_player_Fuc(int direct)
{
	if (direct == 1 || direct == 2)
	{
		player1.rectSource.left = 35; //left default left 
		if (direct == 1)
		{
			direct = 11;
		}
		else
		{
			direct = 22;
		}

	}
	if (clock_ani_player.getElapsedTime().asSeconds() > 0.150f)
	{
		if (player1.rectSource.left == 431) //stay max left 
		{
			player1.rectSource.left = 35; //stay default left 
			combo_player = 0;
		}
		else
		{
			player1.rectSource.left += 132; //plus left 
		}
		sprite_player1.setTextureRect(player1.rectSource);
		clock_ani_player.restart();
		
		
	}
	return direct;

}

int Stay_enamy_Fuc(int direct)
{
	if (direct == 1 || direct == 2)
	{
		enamy1.rectSource.left = 35; //left default left 
		if (direct == 1)
		{
			direct = 11;
		}
		else
		{
			direct = 22;
		}

	}
	if (clock_ani_enamy.getElapsedTime().asSeconds() > 0.150f)
	{
		if (enamy1.rectSource.left == 431) //stay max left 
		{
			enamy1.rectSource.left = 35; //stay default left 
			combo_enamy = 0;
		}
		else
		{
			enamy1.rectSource.left += 132; //plus left 
		}
		sprite_enamy.setTextureRect(enamy1.rectSource);
		clock_ani_enamy.restart();


	}
	return direct;

}

int move_Right_player_Fuc(int direct)
{
	
	if (direct == 11)
	{
		player1.rectSource.left = 563; //move left,right default left 
	}

	if (direct != 1 && direct != 11)
	{
		player1.x -= 160;
		sprite_player1.setScale({ 1, 1 });
		player1.rectSource.left = 563; //move left,right default left 

	}
	direct = 1;
	if (player1.x < 1040)
	{
		player1.x += 0.5f;
	}

	if (clock_ani_player.getElapsedTime().asSeconds() > 0.100f)
	{
		if (player1.rectSource.left == 1091) //move left,right max left 
		{
			player1.rectSource.left = 563; //move left,right default left 
		}
		else
		{
			player1.rectSource.left += 132; //plus left 
		}
		sprite_player1.setTextureRect(player1.rectSource);
		clock_ani_player.restart();


	}

	return direct;
}

int move_Left_player_Fuc(int direct)
{
	
	
	if (direct == 22)
	{
		player1.rectSource.left = 563; //move left,right default left 
	}

	if (direct != 2 && direct != 22)
	{
		player1.x += 160;
		sprite_player1.setScale({ -1, 1 });
		player1.rectSource.left = 563; //move left,right default left 
	}
	direct = 2;
	if (player1.x >= 160)
	{
		player1.x += -0.5f;
	}
	
	if (clock_ani_player.getElapsedTime().asSeconds() > 0.100f)
	{
		if (player1.rectSource.left == 1091) //move left,right max left 
		{
			player1.rectSource.left = 563; //move left,right default left 

		}
		else
		{
			player1.rectSource.left += 132; //plus
		}
		
		sprite_player1.setTextureRect(player1.rectSource);
		clock_ani_player.restart();


	}

	return direct;
}
int Jump_player_Fuc(int directjump)
{
	
	if (directjump == 1)
	{
		player1.rectSource.top = 200; 
		player1.rectSource.left = 35; //jump defualt left 

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
			player1.rectSource.top = 0; // top defualt 
		}

	}
	return directjump;
}

void PG_player_Fuc()
{
	player1.rectSource.top = 100; //PG top
	player1.rectSource.left = 695;//PG left
	
}

void U_player_Fuc()
{
	player1.rectSource.top = 100; //PG top
	player1.rectSource.left = 695;//PG left

}

int Flash_player_Fuc(int direct)
{
	if (direct == 1 || direct == 11)
	{
		if (direct == 11)
		{
			player1.rectSource.left = 563; //move left,right default left
		}

		if (direct != 1 && direct != 11)
		{
			player1.x -= 160;
			sprite_player1.setScale({ 1, 1 });
			player1.rectSource.left = 563; //move left,right default left

		}
		direct = 1;

		if (player1.x < 1040)
		{
			player1.x += 3.0f;
		}

		if (clock_ani_player.getElapsedTime().asSeconds() > 0.100f)
		{
			if (player1.rectSource.left == 1091) //move left,right  max left
			{
				player1.rectSource.left = 563; //move left,right default left
			}
			else
			{
				player1.rectSource.left += 132; // plus left 
			}
			sprite_player1.setTextureRect(player1.rectSource);
			clock_ani_player.restart();


		}

		return direct;
	}

	if (direct == 2 || direct == 22)
	{

		if (direct == 22)
		{
			player1.rectSource.left = 563; //move left,right default left
		}

		if (direct != 2 && direct != 22)
		{
			player1.x += 160;
			sprite_player1.setScale({ -1, 1 });
			player1.rectSource.left = 563; //move left,right default left
		}
		direct = 2;
		if (player1.x >= 160)
		{
			player1.x += -3.0f;
		}
		if (clock_ani_player.getElapsedTime().asSeconds() > 0.100f)
		{
			if (player1.rectSource.left == 1091) //move left,right max left
			{
				player1.rectSource.left = 563; //move left,right default left

			}
			else
			{
				player1.rectSource.left += 132; //plus left
			}

			sprite_player1.setTextureRect(player1.rectSource);
			clock_ani_player.restart();


		}

		return direct;
	}
	
}
int J_attack_player_Fuc(int direct)
{
	if (direct == 1 || direct == 11)
	{
		if (direct == 11)
		{
			player1.rectSource.left = 563; //attack  default left
			player1.rectSource.top = 950; //attack  default top
		}
		if (direct != 1 && direct != 11)
		{
			player1.x -= 160;
			sprite_player1.setScale({ 1, 1 });
			player1.rectSource.left = 563; //attack  default left
		}
		if (player1.x < 1040)
		{
			player1.x += 0.03f;
		}
		direct = 1;
		if (clock_ani_player.getElapsedTime().asSeconds() > 0.120f)
		{
			if (player1.rectSource.left == 1223) //attack  max left
			{
				player1.rectSource.left = 563; //attack  default left
			}
			else
			{
				player1.rectSource.left += 132; // plus left
			}
			sprite_player1.setTextureRect(player1.rectSource);
			clock_ani_player.restart();
		}

		return direct;
	}
	if (direct == 2 || direct == 22)
	{
		if (direct == 22)
		{
			player1.rectSource.left = 563; //attack  default left
			player1.rectSource.top = 950; //attack  default top
		}
		if (direct != 2 && direct != 22)
		{
			player1.x += 160;
			sprite_player1.setScale({ -1, 1 });
			player1.rectSource.left = 563; //attack  default left
		}
		if (player1.x >= 160)
		{
			player1.x += -0.03f;
		}
		direct = 2;
		if (clock_ani_player.getElapsedTime().asSeconds() > 0.120f)
		{
			if (player1.rectSource.left == 1223) //attack  max left
			{
				player1.rectSource.left = 563; //attack  default left
			}
			else
			{
				player1.rectSource.left += 132; //plus left
			}
			sprite_player1.setTextureRect(player1.rectSource);
			clock_ani_player.restart();
		}
		return direct;
	}

}
void hpbar(float total_hp)
{
	hpBar_player.rectSource.top = (total_hp-1)*40;
	hpBar_player.rectSource.left = 0;
	hpBar_player.rectSource.width = 500;
	hpBar_player.rectSource.height = 40;
	sprite_hpBar_player.setTexture(&hpBar_player.Texture);
	sprite_hpBar_player.setPosition(15, 35);
	sprite_hpBar_player.setTextureRect(hpBar_player.rectSource);
}
void hpbar_enamy(float total_hp)
{
	hpBar_enamy.rectSource.top = (total_hp - 1) * 40;
	hpBar_enamy.rectSource.left = 0;
	hpBar_enamy.rectSource.width = 500;
	hpBar_enamy.rectSource.height = 40;
	sprite_hpBar_enamy.setScale({ -1, 1 });
	sprite_hpBar_enamy.setTexture(&hpBar_enamy.Texture);
	sprite_hpBar_enamy.setPosition(1185, 35);
	sprite_hpBar_enamy.setTextureRect(hpBar_enamy.rectSource);
}
