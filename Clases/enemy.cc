#include "enemy.hh"

Enemy::Enemy()
{
	enemy_texture.loadFromFile("../Sprites/enemy.png");
	this -> setTexture(enemy_texture);
	position.x = 27.0f; 	position.y = 20.0f; 
	this -> setPosition(position);
	this -> setScale(0.1f,0.1f);
}