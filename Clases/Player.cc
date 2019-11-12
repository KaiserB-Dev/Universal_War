#include "Player.hh"

Player::Player(){

shipTexture.loadFromFile("../Sprites/space_playerModel.png"); //Carga el archivo de Textura

	this -> setTexture(shipTexture); //Carga la Textura al Player

	position.x = 255.f; //Indica la pocicion inicial del player
	position.y = 700.f;

	this -> setPosition(position); //Setea la posicion inicial en el player

	this -> setScale(0.15f,0.15f); //reescala el sprite

    this -> setRotation(-90.f); //Asigna un valor de rotacion al sprite

	/*buffer.loadFromFile("../Audio/ship.ogg");

	sound_ship.setBuffer(buffer);

	sound_ship.setLoop(true);

	sound_ship.play();*/



}


void Player::Controller(){ //Metodo de controles

    position = this -> getPosition(); //Obtiene la posicion del Player, retorna un objeto de tipo Vector2f 
    x = position.x; //Almacena la posicion en X
	y = position.y;   //Almacena la posicion en Y

    //Inicia la deteccion de teclado y modifica la posicio inicial

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))		
        this -> setPosition(x, y - 10.0000);

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this -> setPosition(x - 10.0000, y);
            		

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))	
        this -> setPosition(x, y + 10.0000);
            	
            		

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this -> setPosition(x + 10.0000, y);

    //Termina la deteccion de teclado      		

}

float Player::Get_axis_x(){ //Obtiene la posicion en X

    return x;

}

float Player::Get_axis_y(){ //Obtiene la posicion en Y

    return y;

}