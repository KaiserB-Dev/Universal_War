#include "bullet.hh"

//Constructor Por Defecto
/*Inicializa la textura de la bala del jugador.*/
Bullet::Bullet(){
	//Se carga el archivo para la textura y se asigna una escala
	bullet_texture.loadFromFile("../Sprites/player_bullet.png");
	this -> setScale(0.7f,0.7f);
}

//Funcion para dibujar la bala en la ventana
/*Dibuja la bala en la ventana recibida como parametro.*/
void Bullet::draw(sf::RenderWindow &window){
	window.draw(*this);
}

//Funcion para colocar y mover la bala
/*Coloca la bala en la posicion del jugador dado
por las variables recibidas como parametro.*/
void Bullet::fire(float player_x, float player_y){
	//Se asigna la textura y la posicion del jugador
	this -> setTexture(bullet_texture);
	this -> setPosition(player_x + 31.0f, player_y);
}

//Funcion que detecta si la bala choca con los enemigos
/*Retorna un valor booleano dependiendo de si la bala toca al
objeto Enemy o no, el objeto Enemy es recibido como parametro.*/
bool Bullet::collide_Enemy(Enemy enemy){
	//Si la bala intersecta con el enemigo, se retorna el valor true
	if(this->getGlobalBounds().intersects(enemy.getGlobalBounds())){
		return true;
	}
	//Si lo anterior no ocurre, se retorna el valor false
	return false;
}
