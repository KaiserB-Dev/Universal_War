#include "Player.hh"

Player::Player(){

    shipTexture.loadFromFile("../Sprites/space_playerModel1.png");

    shipTexture2.loadFromFile("../Sprites/space_playerModel2.png");

    shipTexture3.loadFromFile("../Sprites/space_playerModel3.png");

    shipTexture4.loadFromFile("../Sprites/space_playerModel4.png");

    this -> setTexture(shipTexture); //Carga la textura principal

	position.x = 230.0f; //Indica la pocicion inicial del player
	position.y = 380.0f;

	this -> setPosition(position); //Setea la posicion inicial en el player

	this -> setScale(0.7f,0.7f); //reescala el sprite

	/*buffer.loadFromFile("../Audio/ship.ogg");

	sound_ship.setBuffer(buffer);

	sound_ship.setLoop(true);

	sound_ship.play();*/
    

}

void Player::Detect_Axis(){
    position = this -> getPosition(); //Obtiene la posicion del Player, retorna un objeto de tipo Vector2f 
    x = position.x; //Almacena la posicion en X
    y = position.y;   //Almacena la posicion en Y
}

void Player::Controller(){ //Metodo de controles
    //Inicia la deteccion de teclado y modifica la posicio inicial



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
	        this -> setPosition(x, y - 5.0f); //Setea la posicion haciendo efecto movimiento

            this -> setTexture(shipTexture3); //Carga la textura al player 

            //Se implementa cuando el usuario presiona la tecla RSHIFT Acelera la nave es por eso el set position mas 10

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){

            this -> setPosition(x, y - 10.0f);

            this -> setTexture(shipTexture4);

        }

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        
        this -> setPosition(x - 5.0f, y);
        
        this -> setTexture(shipTexture2);   

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){

            this -> setPosition(x - 10.0f, y);

            this -> setTexture(shipTexture4);  
         }    
    }
            		

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){	
        this -> setPosition(x, y + 5.0f);
        
        this -> setTexture(shipTexture3);

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){

            this -> setPosition(x, y + 10.0f);

            this -> setTexture(shipTexture4);  
         }    

    }
            		

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this -> setPosition(x + 5.0f, y);
        this -> setTexture(shipTexture2);   

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){

            this -> setPosition(x + 10.0f, y);

            this -> setTexture(shipTexture4);  
         }        

    }

    else
        this -> setTexture(shipTexture);

    //Termina la deteccion de teclado      		

}

float Player::Get_axis_x(){ //Obtiene la posicion en X

    return x;

}

float Player::Get_axis_y(){ //Obtiene la posicion en Y

    return y;

}


void Player::Shoot(){


}
