#ifndef PLAYER_HH
#define PLAYER_HH

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "bullet.hh"



class Player : public sf::Sprite{ //Declaracion de la clase heredando la clase   Sprite que es la clase raiz para el desarrollo del character

	public:

		Player();

		void Controller();

		float Get_axis_x();

		float Get_axis_y();

		void Detect_Axis();

		void invoke_animation();

		void Shoot();

		void colition();

	private:

		sf::Texture shipTexture; //Objeto que carga la textura a la nave

		sf::Texture shipTexture2;

		sf::Texture shipTexture3;

		sf::Texture shipTexture4;

		sf::Vector2f position; //Objeto posicion 

		//sf::SoundBuffer buffer;

		//sf::Sound sound_ship;

		float x,y; //Almacenamiento de posicion
};
	
#endif