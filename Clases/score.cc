#include "score.hh"

//Constructor Por Defecto
/*Inicializa las variables, la fuente y
el texto del marcador de puntuacion.*/
Score::Score(){
	//Se inicializa la variable "score"
	score = 0;
	
	//Se carga el archivo de la fuente
	score_font.loadFromFile("../Fonts/Sansation-Regular.ttf");
	
	//Se asigna el texto y el valor de score al objeto ostringstream
	string_score << "Score: " << score;
	
	//Se asigna la fuente, el texto, su tamaño y una posicion
	this -> setCharacterSize(20);
	this -> setFont(score_font);
	this -> setString(string_score.str());
	this -> setPosition(230.0f,0.0f);
}

//Funcion para dibujar el marcador de puntuacion en la ventana
/*Dibuja el marcador de puntuacion en la ventana recibida como parametro.*/
void Score::draw(sf::RenderWindow &window){
	window.draw(*this);
}

//Funcion para modificar el marcador de puntuacion
/*Acumula los puntos recibidos como parametros en la variable score,
actualiza el texto y lo asigna al objeto ostringstream.*/
void Score::setScore(unsigned points){
	//Acumula los puntos en score
	score += points;
	
	//Limpia el texto, lo actualiza y lo asigna al objeto ostringstream
	string_score.str("");
	string_score << "Score: " << score;
	
	//Asigna el texto
	this -> setString(string_score.str());
}

//Funcion para obtener la puntuacion del jugador
/*Retorna el valor de la variable "score".*/
unsigned Score::getScore(){
	return score;
}
