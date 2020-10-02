#include <SFML/Graphics.hpp>
#include<windows.h>

float x_player=750, y_player=500;
struct data
{
	float x= 0, y= 200;

} player1;
sf::RectangleShape player(sf::Vector2f(150.0f, 150.0f));

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Road to champions");
	
	//player.setFillColor(sf::Color::Cyan);
	player.setPosition(player1.x, player1.y);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Textures/11.png");
	player.setTexture(&playerTexture);

	player.setTextureRect(sf::IntRect( 0,0,150,70));



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
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player1.x+= -0.1f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player1.x+= 0.1f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player1.y+= -0.1f;
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player1.y+= 0.1f;
		}
		player.setPosition(player1.x, player1.y);
		window.clear();
		window.draw(player);
		window.display();
	}
	
	return 0;
}
