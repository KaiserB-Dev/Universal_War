#include "bullet.hh"

Bullet::Bullet(){
	bullet_texture.loadFromFile("../Sprites/player_bullet.png");
	this -> setScale(0.7f,0.7f);
	
}

void Bullet::Detect_Axis(){
	//Obtiene la posicion del Player, retorna un objeto de tipo Vector2f
    position_bullet = this -> getPosition(); 
    //Almacena la posicion en X
	x = position_bullet.x;
	//Almacena la posicion en Y
    y = position_bullet.y;
}

float Bullet::Get_axis_x(){
	return x;
}

float Bullet::Get_axis_y(){
	return y;
}

void Bullet::draw(sf::RenderWindow &window){
	window.draw(*this);
}

void Bullet::fire(float x_func, float y_func){
	this -> setTexture(bullet_texture);
	this -> setPosition(x_func + 31.0f, y_func);
}

bool Bullet::collide_Enemy(Enemy enemy){
	if(this->getGlobalBounds().intersects(enemy.getGlobalBounds())){
		return true;
	}
	return false;
}
