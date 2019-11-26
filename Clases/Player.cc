#include "Player.hh"

Player::Player(){
    shipTexture1.loadFromFile("../Sprites/player_model1.png");
    shipTexture2.loadFromFile("../Sprites/player_model2.png");
    shipTexture3.loadFromFile("../Sprites/player_model3.png");

    this -> setTexture(shipTexture1); //Carga la textura principal
	
	//Indica la pocicion inicial del player
	position.x = 260.0f;
	position.y = 560.0f;
	
	//Setea la posicion inicial en el player
	this -> setPosition(position);
	//Reescala el sprite
	this -> setScale(0.7f,0.7f);

    buffer.loadFromFile("../Audio/efecto-de-sonido.ogg");

    sound_ship.setBuffer(buffer);
    sound_ship.setVolume(50.0f);
    lifes = 0;
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
		if(y != -20.0f){
    		//Setea la posicion haciendo efecto movimiento
			this -> setPosition(x, y - 10.0f);
			//Carga la textura al player
	        this -> setTexture(shipTexture3);
		}
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
    	//Condicion para que el jugador no pueda ir a una zona delimitada
    	if(x != 0.0f){
    		this -> setPosition(x - 10.0f, y);
	        this -> setTexture(shipTexture2);
		}
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    	//Condicion para que el jugador no pueda ir a una zona delimitada
    	if(y != 570.0f){
    		this -> setPosition(x, y + 10.0f);
	        this -> setTexture(shipTexture3);
		}
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    	//Condicion para que el jugador no pueda ir a una zona delimitada
    	if(x != 500.0f){
    		this -> setPosition(x + 10.0f, y);
	        this -> setTexture(shipTexture2);
		}
    }
    else
        this -> setTexture(shipTexture1);

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
    bullet.fire(x , y);
    sound_ship.play();
}

void Player::draw_Player(sf::RenderWindow &window){
	window.draw(*this);
}

bool Player::collide_Enemy(Enemy enemy){
	if(this->getGlobalBounds().intersects(enemy.getGlobalBounds())){
        
       return true;

	}
	return false;
}

int Player::get_lifes(){

    return lifes;

}

void Player::set_lifes(int valor){

    this -> lifes = valor;

}