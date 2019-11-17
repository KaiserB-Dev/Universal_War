#ifndef ENEMY_HH
#define ENEMY_HH

#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>

class Enemy : public sf::Sprite
{
	public:
		Enemy();
		float Get_axis_x();
		float Get_axis_y();
		void Detect_Axis();	
		void Movement();
	private:
		sf::Texture	enemy_texture;
		sf::Vector2f position;
		float x,y;
}; 

#endif