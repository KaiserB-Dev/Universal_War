#ifndef WIN_SCENE_HH
#define WIN_SCENE_HH

//Librerias usadas para windowScene
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>
#include "Player.hh"
#include "bullet.hh"
#include "lifes.hh"
#include "score.hh"
#include "enemy.hh"
#include "menu.hh"

//Clase windowScene
class windowScene{
public:
	windowScene();	//Constructor Por Defecto
	void play(sf::RenderWindow &window);	//Funcion para mostrar el juego
private:
	//sf::RenderWindow window; //Objeto de la ventana
	sf::Texture background_tex; //Objeto de la Textura del Fondo
	sf::Sprite background; //Objeto del Fondo donde se cargará la textura
	sf::Music back_music; //Objeto de la Musica de Fondo
	sf::Clock clock;
	sf::Time time;
	std::vector<Enemy> enemies;	//Vector de los Enemigos
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	long unsigned int maxEnemies;	//Numero Maximo de Enemigos en Pantalla
	Player player; 	//Objeto del Jugador
	Bullet bullet;	//Objeto de las Balas del Jugador
	Lifes lifes;	//Objeto de las Vidas del Jugador
	Score score;	//Objeto de la Puntuacion del Jugador
	Enemy enemy;	//Objeto del Enemigo
	sf::Sound explosion;
	sf::SoundBuffer buffer;
	sf::Music death;
	bool isListening;

	unsigned i;
	

};

#endif

