#ifndef WIN_SCENE_HH
#define WIN_SCENE_HH

//Librerias, la que se usa es la SFML

#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include "Player.hh"
#include "bullet.hh"
#include "enemy.hh"


class windowScene{

public:

	windowScene();

	void play();

private:

	sf::RenderWindow window; //Objeto de la ventana
	
	sf::Texture background_tex; //Textura del fondo

	sf::Sprite background; //Objeto del fondo para cargar su textura

	sf::Music back_music; //Musica

	sf::Clock clock;

	sf::Time time;

	sf::RectangleShape frontier;
	
	Player player; //Jugador

	Bullet bullet; //Balas
	
	Enemy enemy;		
};


#endif