#include "Player.hh"

//Constructor Por Defecto
/*Inicializa las variables, las texturas del jugador y el sonido de disparo.*/
Player::Player(){
	//Se inicializan las variables
	life = 0;
	x = 0;
	y = 0;
	
	//Se cargan los archivos para las texturas
    player_Texture1.loadFromFile("../Sprites/player_model1.png");
    player_Texture2.loadFromFile("../Sprites/player_model2.png");
    player_Texture3.loadFromFile("../Sprites/player_model3.png");

	//Se asigna la Textura No. 1
    this -> setTexture(player_Texture1);
	
	//Se asigna la posicion inicial del jugador en el vector y se asigna una escala
	player_position.x = 260.0f;
	player_position.y = 560.0f;
	this -> setPosition(player_position);
	this -> setScale(0.7f,0.7f);
	
	//Se carga el archivo para el buffer, se asigna al sonido, y se le asigna un volumen
    buffer.loadFromFile("../Audio/efecto-de-sonido.ogg");
    sound_ship.setBuffer(buffer);
    sound_ship.setVolume(50.0f);
}

//Funcion para detectar la posicion del jugador
/*Obtiene la posicion del jugador y lo asigna a las variables "x" y "y".*/
void Player::detect_Position(){
	//Se obtiene la posicion del sprite del jugador y lo asigna al vector
    player_position = this -> getPosition();
    
    //Se asignan los valores del vector a las variables "x" y "y"
    x = player_position.x;
    y = player_position.y;
}

//Funcion para dibujar al jugador en la ventana
/*Dibuja al jugador en la ventana recibida como parametro.*/
void Player::draw(sf::RenderWindow &window){
	window.draw(*this);
}

//Funcion que controla el movimiento del jugador con el teclado
/*Se inicia la deteccion del teclado, el jugador se moverá hacia una
direccion determinada dependiendo de la tecla que presione.*/
void Player::Controller(){
	//Movimiento hacia adelante si se presiona la tecla W
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    	//Condicion para que el jugador no pueda ir a una zona delimitada
		if(y != -20.0f){
    		//Asigna la posicion
			this -> setPosition(x, y - 10.0f);
			//Se asigna la Textura No. 3
	        this -> setTexture(player_Texture3);
		}
    }
    //Movimiento hacia la izquierda si se presiona la tecla A
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
    	//Condicion para que el jugador no pueda ir a una zona delimitada
    	if(x != 0.0f){
    		//Asigna la posicion
    		this -> setPosition(x - 10.0f, y);
    		//Se asigna la Textura No. 2
	        this -> setTexture(player_Texture2);
		}
    }
    //Movimiento hacia atras si se presiona la tecla S
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    	//Condicion para que el jugador no pueda ir a una zona delimitada
    	if(y != 570.0f){
    		//Asigna la posicion
    		this -> setPosition(x, y + 10.0f);
    		//Se asigna la Textura No. 3
	        this -> setTexture(player_Texture3);
		}
    }
    //Movimiento hacia la derecha si se presiona la tecla D
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    	//Condicion para que el jugador no pueda ir a una zona delimitada
    	if(x != 500.0f){
    		//Asigna la posicion
    		this -> setPosition(x + 10.0f, y);
    		//Se asigna la Textura No. 2
	        this -> setTexture(player_Texture2);
		}
    }
    //Si el jugador no presiona ninguna tecla antes mencionada, se asigna la Textura No. 1
    else
        this -> setTexture(player_Texture1);
}

//Funcion para obtener la posicion en el eje X del jugador
/*Retorna el valor de la variable "x".*/
float Player::getX(){
    return x;
}

//Funcion para obtener la posicion en el eje Y del jugador
/*Retorna el valor de la variable "y".*/
float Player::getY(){
    return y;
}

//Funcion para realizar el disparo del jugador
/*Realiza el disparo del jugador y reproduce un efecto de sonido.*/
void Player::Shoot(Bullet &bullet){
    //Manda llamar a la funcion fire() de la clase Bullet
	bullet.fire(x , y);
	//Se reproduce el efecto de sonido de disparo
    sound_ship.play();
}

//Funcion que detecta si el jugador choca con los enemigos
/*Retorna un valor booleano dependiendo de si el jugador toca al
objeto Enemy o no, el objeto Enemy es recibido como parametro.*/
bool Player::collide_Enemy(Enemy enemy){
	//Si el jugador intersecta con el enemigo, se retorna el valor true
	if(this->getGlobalBounds().intersects(enemy.getGlobalBounds())){
		return true;
	}
	//Si lo anterior no ocurre, se retorna el valor false
	return false;
}

//Funcion para modificar la vida del jugador
/*Asigna el valor de la variable recibida como parametro a la variable "life".*/
void Player::set_Life(int health){
	this -> life = health;
}

//Funcion para obtener la vida del jugador
/*Retorna el valor de la variable "life".*/
int Player::get_Life(){
	return life;
}
