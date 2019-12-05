#ifndef PLAYER_HH
#define PLAYER_HH

//Librerias utilizadas para el jugador
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "bullet.hh"
#include "enemy.hh"

//Clase Derivada Player que hereda la clase sf::Sprite
class Player : public sf::Sprite{
public:
	//Constructor Por Defecto
	Player();
	
	//Funcion para dibujar al jugador en la ventana
	void draw(sf::RenderWindow &window);
	//Funcion que controla el movimiento del jugador con el teclado
	void Controller();
	//Funcion para detectar la posicion del jugador
	void detect_Position();
	//Funcion para obtener la posicion en el eje X del jugador
	float getX();
	//Funcion para obtener la posicion en el eje Y del jugador
	float getY();
	//Funcion para realizar el disparo del jugador
	void Shoot(Bullet &bullet);
	//Funcion que detecta si el jugador choca con los enemigos
	bool collide_Enemy(Enemy enemy);
	//Funcion para modificar la vida del jugador
	void set_Life(int health);
	//Funcion para obtener la vida del jugador
	int get_Life();
	
private:
	float x;		//Variable para la posicion en el eje X del jugador
	float y;		//Variable para la posicion en el eje Y del jugador
	int life;		//Variable para la vida del jugador
	
	Bullet bullet;					//Objeto Bullet 
	sf::Texture player_Texture1;	//Textura No. 1 del jugador 
	sf::Texture player_Texture2;	//Textura No. 2 del jugador 
	sf::Texture player_Texture3;	//Textura No. 3 del jugador
	sf::Vector2f player_position; 	//Vector para la posicion del jugador
	sf::SoundBuffer buffer;			//Buffer del Sonido para el disparo del jugador
	sf::Sound sound_ship;			//Sonido de disparo del jugador
};
	
#endif
