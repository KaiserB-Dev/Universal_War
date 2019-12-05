#ifndef ENEMY_HH
#define ENEMY_HH

//Librerias utilizadas para los enemigos
#include <SFML/Graphics.hpp> 

//Clase Derivada Enemy que hereda la clase sf::Sprite
class Enemy : public sf::Sprite{
public:
	//Constructor Por Defecto
	Enemy();
	
	//Funcion para cambiar el sprite de los enemigos
	void change_sprite(const std::string &filename);

private:
	sf::Texture	enemy_texture;		//Textura de los enemigos
	sf::Vector2f enemy_position;	//Posicion de los enemigos	
}; 

#endif
