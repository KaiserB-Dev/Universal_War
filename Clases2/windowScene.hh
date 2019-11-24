#ifndef WIN_SCENE_HH
#define WIN_SCENE_HH

//Librerias, la que se usa es la SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>
#include "Player.hh"
#include "bullet.hh"
#include "lifes.hh"
#include "score.hh"
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
	std::vector<Enemy> enemies;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	Player player; //Jugador
	Bullet bullet;
	Lifes lifes;
	Score score;
	Enemy enemy;
};

#endif
