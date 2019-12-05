#ifndef WIN_SCENE_HH
#define WIN_SCENE_HH

//Librerias utilizadas para los eventos en la ventana
/*Se utilizó la libreria <vector> para crear un
vector que contenga objetos de tipo Enemy.
Se utilizó la libreria <ctime> para crear numeros aleatorios
que nos servirían para la aparicion de los enemigos.*/
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
	//Constructor Por Defecto
	windowScene();
	
	//Funcion para mostrar el juego
	void play(sf::RenderWindow &window);
	//Funcion para controlar el tiempo entre cada disparo del jugador
	void shootTimer();
	//Funcion para mover al jugador dentro de una zona delimitada
	void playerMove();
	//Funcion para cambiar la constante de puntos por cada enemigo
	void changeScore();
	//Funcion para controlar a los enemigos
	void enemyActions(sf::RenderWindow &window);
	//Funcion para dibujar los elementos del juego en la ventana
	void drawGame(sf::RenderWindow &window);
	
private:
	float x;					//Variable para la posicion en el eje X del jugador
	float y;					//Variable para la posicion en el eje Y del jugador
	unsigned cont;				//Variable contador para controlar la musica de muerte
	int maxEnemies;				//Numero maximo de enemigos en pantalla
	bool isListening;			//Variable para saber si la musica de fondo esta sonando
	float enemySpawnTimer;		//Tiempo de aparicion de los enemigos
	float enemySpawnTimerMax;	//Tiempo maximo de aparicion de los enemigos
	
	Player player; 				//Objeto del jugador
	Bullet bullet;				//Objeto de la bala del jugador
	Lifes lifes;				//Objeto de la vida del jugador
	Score score;				//Objeto de la puntuacion del jugador
	Enemy enemy;				//Objeto del enemigo
	sf::Time time;				//Objeto para almacenar el tiempo transcurrido
	sf::Clock clock;			//Objeto para contar el tiempo transcurrido
	sf::Texture bg_texture; 	//Textura del fondo del juego
	sf::Sprite bg_sprite; 		//Sprite del fondo del juego
	sf::Music back_music; 		//Musica de fondo
	sf::Music death;			//Musica de fondo cuando el jugador muere
	std::vector<Enemy> enemies;	//Vector de los enemigos
	sf::Sound explosion;		//Sonido de explosion para cuando el jugador recibe daño
	sf::SoundBuffer buffer;		//Buffer del Sonido para cuando el jugador recibe daño
};

#endif
