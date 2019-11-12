#include "Player.hh"

Player::Player(){

shipTexture.loadFromFile("../Sprites/space_playerModel.png");

	this -> setTexture(shipTexture);

	position.x = 255.f;
	position.y = 700.f;

	this -> setPosition(position);

	this -> setScale(0.15f,0.15f);

    this -> setRotation(-90.f);

	/*buffer.loadFromFile("../Audio/ship.ogg");

	sound_ship.setBuffer(buffer);

	sound_ship.setLoop(true);

	sound_ship.play();*/



}


void Player::Controller(){

    position = this -> getPosition();
    x = position.x;
	y = position.y;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))		
        this -> setPosition(x, y - 10.0000);

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this -> setPosition(x - 10.0000, y);
            		

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))	
        this -> setPosition(x, y + 10.0000);
            	
            		

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this -> setPosition(x + 10.0000, y);
       		

}

float Player::Get_axis_x(){

    return x;

}

float Player::Get_axis_y(){

    return y;

}