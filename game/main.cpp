#include <SFML/Graphics.hpp>
#include<windows.h>

float x_player=750, y_player=500;
struct data
{
	float x= 0, y= 480;

} player1;

sf::RenderWindow window(sf::VideoMode(1200, 800), "Road to champions");

sf::RectangleShape player(sf::Vector2f(160.0f, 120.0f));
sf::Texture playerTexture;
sf::IntRect rectSourceplayer(35, 0, 80, 60);
sf::Clock cloc;

void stay();
void run();

int main()
{
	
	//player.setFillColor(sf::Color::Cyan);
	
	
	playerTexture.loadFromFile("Textures/11.png");
	player.setTexture(&playerTexture);
	player.setTextureRect(rectSourceplayer);
	
	int put=0;
	


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
			player1.x+= -0.1f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			
			if (put == 0)
			{
				rectSourceplayer.left = 563;
			}
			put = 1;
			run();
			player1.x += 0.2f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player1.y+= -0.1f;
			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player1.y+= 0.1f;
		}
		else
		{
			if (put == 1)
			{
				rectSourceplayer.left = 35;
				put = 0;
			}
			stay();

		}
		
		player.setPosition(player1.x, player1.y);
		window.clear();
		window.draw(player);
		window.display();
	}
	
	return 0;
}
void stay()
{
	
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
	

}

void run()
{

	if (cloc.getElapsedTime().asSeconds() > 0.150f)
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


}