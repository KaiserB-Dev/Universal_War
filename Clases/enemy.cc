#include "enemy.hh"

Enemy::Enemy()
{
	enemy_texture.loadFromFile("../Sprites/enemy.png");
	this -> setTexture(enemy_texture);
	position.x = 27.0f; //7 veces
	position.y = 20.0f; //10 veces
	this -> setPosition(position);
	this -> setScale(0.1f,0.1f);
}

void Enemy::Movement()
{
	this -> setPosition(x+78, y);
}

void Enemy::Detect_Axis()
{
    position = this -> getPosition(); //Obtiene la posicion del enemy, retorna un objeto de tipo Vector2f 
    x = position.x; //Almacena la posicion en X
    y = position.y;   //Almacena la posicion en Y
}

float Enemy::Get_axis_x() //Obtiene la posicion en X
{
    return x;
}

float Enemy::Get_axis_y() //Obtiene la posicion en Y
{
    return y;
}

