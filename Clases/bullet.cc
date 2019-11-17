#include "bullet.hh"

Bullet::Bullet(){

	bullet_texture.loadFromFile("../Sprites/nave_bullet.png");

	this -> setTexture(bullet_texture);

//	this -> setScale(0.1f,0.1f);

	//this -> setRotation(-90.0f);

}


void Bullet::Detect_Axis(){
    position_bullet = this -> getPosition(); //Obtiene la posicion del Player, retorna un objeto de tipo Vector2f 
    x = position_bullet.x; //Almacena la posicion en X
    y = position_bullet.y;   //Almacena la posicion en Y
}

float 	Bullet::Get_axis_x(){
	
	return x;
}

float Bullet::Get_axis_y(){

	return y;
}


void Bullet::draw(sf::RenderWindow &window){

	window.draw(*this);

}

void Bullet::fire(int speed, float x, float y){

	this -> setPosition(x , y);

	//this ->setPosition(this -> Get_axis_x(), this -> Get_axis_y() + speed);

}

