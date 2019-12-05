#include "lifes.hh"

//Constructor Por Defecto
/*Inicializa la vida inicial del jugador, inicializa las
variables, la fuente y el texto del marcador de vida.*/
Lifes::Lifes(){
	//Inicializa la vida del jugador en el objeto player
	player.set_Life(100);
	//Obtiene la vida del jugador y se asigna a la variable life
	life = player.get_Life();
	
	//Se carga el archivo de la fuente
	life_font.loadFromFile("../Fonts/Sansation-Regular.ttf");
	
	//Se asigna el texto y el valor de life al objeto ostringstream
	string_life << "Health: " << life;
	
	//Se asigna la fuente, el texto, su tamaño y una posicion
	this -> setCharacterSize(20);
	this -> setFont(life_font);
	this -> setString(string_life.str() + "%");
	this -> setPosition(5.0f,0.0f);
}

//Funcion para dibujar el marcador de vida en la ventana
/*Dibuja el marcador de vida en la ventana recibida como parametro.*/
void Lifes::draw(sf::RenderWindow &window){
	window.draw(*this);
}

//Funcion para modificar el marcador de vida
/*Obtiene la vida del jugador, disminuye su valor de acuerdo a la vida recibida como parametro,
asigna la vida modificada al jugador, actualiza el texto y lo asigna al objeto ostringstream.*/
void Lifes::setLife(int health){
	//Obtiene la vida del jugador y se asigna a la variable life
	life = player.get_Life();
	
	//Se le resta la vida al jugador
	life -= health;
	
	//Se asigna la vida modificada al jugador
	player.set_Life(player.get_Life() - health);
	
	//Limpia el texto, lo actualiza y lo asigna al objeto ostringstream
	string_life.str("");
	string_life << "Health: " << life;
	
	//Asigna el texto
	this -> setString(string_life.str() + "%");
}

//Funcion para inicializar el marcador de vida
/*Asigna la vida recibida como parametro y asigna el texto al objeto ostringstream.*/
void Lifes::setInitialLife(unsigned health){
	//Se asigna la vida recibida a la variable life
	life = health;
	
	//Limpia el texto, lo actualiza y lo asigna al objeto ostringstream
	string_life.str("");
	string_life << "Health: " << life;
	
	//Asigna el texto
	this -> setString(string_life.str() + "%");
}

//Funcion para obtener la vida del jugador
/*Retorna el valor de la variable "life".*/
int Lifes::getLife(){
	return life;
}
