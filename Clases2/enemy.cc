#include "enemy.hh"

Enemy::Enemy()
{
	enemy_texture.loadFromFile("../Sprites/alien_verde1.png");
	this -> setTexture(enemy_texture);
	position.x = 27.0f;
	position.y = 20.0f; 
	this -> setPosition(position);
	this -> setScale(0.7f,0.7f);
}
