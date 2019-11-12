#ifndef PLAYER_HH
#define PLAYER_HH

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



class Player : public sf::Sprite{ //Declaracion de la clase heredando la clase  Sprite

	public:

		Player();

		void Controller();

		float Get_axis_x();

		float Get_axis_y();

	private:

		sf::Texture shipTexture; //Objeto que carga la textura a la nave

		sf::Vector2f position; //Objeto posicion 

		//sf::SoundBuffer buffer;

		//sf::Sound sound_ship;

		float x,y; //Almacenamiento de posicion



};
	
#endif