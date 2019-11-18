#include "Player.hh"

Player::Player(){
    shipTexture.loadFromFile("../Sprites/space_playerModel1.png");
    shipTexture2.loadFromFile("../Sprites/space_playerModel2.png");
    shipTexture3.loadFromFile("../Sprites/space_playerModel3.png");
    shipTexture4.loadFromFile("../Sprites/space_playerModel4.png");

    this -> setTexture(shipTexture); //Carga la textura principal
	
	//Indica la pocicion inicial del player
	position.x = 230.0f;
	position.y = 380.0f;
	
	//Setea la posicion inicial en el player
	this -> setPosition(position);
	//Reescala el sprite
	this -> setScale(0.7f,0.7f);

    buffer.loadFromFile("../Audio/efecto-de-sonido.ogg");

    sound_ship.setBuffer(buffer);
    sound_ship.setVolume(100.0f);

    health = 20;

    lives = 3;

}

void Player::Detect_Axis(){
	//Obtiene la posicion del Player, retorna un objeto de tipo Vector2f
    position = this -> getPosition(); 
    x = position.x; //Almacena la posicion en X
    y = position.y; //Almacena la posicion en Y
}

//Metodo de controles
void Player::Controller(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    	//Condicion para que el jugador no pueda ir a una zona delimitada
		if(y != -180.0f){
    		//Setea la posicion haciendo efecto movimiento
			this -> setPosition(x, y - 5.0f);
			//Carga la textura al player
	        this -> setTexture(shipTexture3); 
	
	        //Se implementa cuando el usuario presiona la tecla RSHIFT Acelera la nave, es por eso el set position mas 10
	        //Victor: Bug: Al usar el speed, atraviesa la barrera delimitadora. Quitando el speed se soluciona el bug.
	        if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
	            this -> setPosition(x, y - 10.0f);
	            this -> setTexture(shipTexture4);
	        }
		}
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
    	//Condicion para que el jugador no pueda ir a una zona delimitada
    	if(x != -35.0f){
    		this -> setPosition(x - 5.0f, y);
	        this -> setTexture(shipTexture2);  
	 
	        if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
	            this -> setPosition(x - 10.0f, y);
	            this -> setTexture(shipTexture4);
	        }
		}
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    	//Condicion para que el jugador no pueda ir a una zona delimitada
    	if(y != 405.0f){
    		this -> setPosition(x, y + 5.0f);
	        this -> setTexture(shipTexture3);
	
	        if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
	            this -> setPosition(x, y + 10.0f);
	            this -> setTexture(shipTexture4);
	        }
		}
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    	//Condicion para que el jugador no pueda ir a una zona delimitada
    	if(x != 465.0f){
    		this -> setPosition(x + 5.0f, y);
	        this -> setTexture(shipTexture2);
	        
	        //Victor: Bug: Al usar el speed, atraviesa la barrera delimitadora. Quitando el speed se soluciona el bug.
	        if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
	        	this -> setPosition(x + 10.0f, y);
	            this -> setTexture(shipTexture4);
	        }
		}
    }
   /* else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        this -> Shoot(bullet);
    }*/
    else
        this -> setTexture(shipTexture);

    //Termina la deteccion de teclado
}

//Obtiene la posicion en X
float Player::Get_axis_x(){
    return x;
}

//Obtiene la posicion en Y
float Player::Get_axis_y(){
    return y;
}

void Player::Shoot(Bullet &bullet){
    
   bullet.fire(10, x , y);


    sound_ship.play();
}

