#include "enemy.hh"

//Constructor Por Defecto
/*Asigna el sprite, una posicion y una escala a los enemigos.*/
Enemy::Enemy(){
	//Llama a la funcion change_sprite para asignar el sprite desde el archivo
	this -> change_sprite("../Sprites/alien_verde1.png");
	
	//Se asigna la posicion inicial de los enemigos en el vector y se asigna una escala
	enemy_position.x = 27.0f;
	enemy_position.y = 20.0f; 
	this -> setPosition(enemy_position);
	this -> setScale(0.7f,0.7f);
}

//Funcion para cambiar el sprite de los enemigos
/*Carga el archivo de la textura a traves del string que
se recibe como parametro y se asigna al sprite.*/
void Enemy::change_sprite(const std::string &filename){
	//Se carga el archivo para la textura y se asigna al sprite
	enemy_texture.loadFromFile(filename);
	this -> setTexture(enemy_texture);
}
