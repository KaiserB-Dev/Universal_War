#ifndef PLAYER_HH
#define PLAYER_HH

//Librerias
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "bullet.hh"

//Declaracion de la clase derivada Player heredando la clase base Sprite, que es la clase raiz para el desarrollo del character
class Player : public sf::Sprite{
	public:
		Player();
		void Controller();
		float Get_axis_x();
		float Get_axis_y();
		void Detect_Axis();
		void Shoot(Bullet &bullet);
		void damange();
	private:
		sf::Texture shipTexture; //Objeto que carga la textura a la nave
		sf::Texture shipTexture2;
		sf::Texture shipTexture3;
		sf::Texture shipTexture4;
		sf::Vector2f position; //Objeto posicion 
		sf::SoundBuffer buffer;
		sf::Sound sound_ship;
		Bullet bullet;
		float x,y; //Almacenamiento de posicion

		unsigned int health;

		unsigned int lives;
};
	
#endif
