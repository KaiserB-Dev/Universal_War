#ifndef BULLET_HH
#define BULLET_HH

//Librerias utilizadas para la bala del jugador
#include <SFML/Graphics.hpp>
#include "enemy.hh"

//Clase Derivada Bullet que hereda la clase sf::Sprite
class Bullet : public sf::Sprite{
public:
	//Constructor Por Defecto
	Bullet();
	
	//Funcion para dibujar la bala en la ventana
	void draw(sf::RenderWindow &window);
	//Funcion para colocar y mover la bala
	void fire(float player_x, float player_y);
	//Funcion que detecta si la bala choca con los enemigos
	bool collide_Enemy(Enemy enemy);
	
private:
	sf::Texture bullet_texture;	//Textura de la bala
};

#endif
