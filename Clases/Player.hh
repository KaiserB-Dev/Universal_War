#ifndef PLAYER_HH
#define PLAYER_HH

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



class Player : public sf::Sprite{

public:

Player();

void Controller();

float Get_axis_x();

float Get_axis_y();

private:

	sf::Texture shipTexture;

	sf::Vector2f position;

	//sf::SoundBuffer buffer;

	//sf::Sound sound_ship;

	float x,y;



};
	
#endif