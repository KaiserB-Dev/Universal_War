#ifndef SCORE_HH
#define SCORE_HH

//Librerias utilizadas para la puntuacion del jugador
/*Se utiliza la libreria <sstream> para usar
el objeto std::ostringstream, y de esa forma
poder controlar el macador de puntuacion.*/
#include <SFML/Graphics.hpp>
#include <sstream>

//Clase Derivada Score que hereda la clase sf::Text
class Score : public sf::Text{
public:
	//Constructor Por Defecto
	Score();
	
	//Funcion para dibujar el marcador de puntuacion en la ventana
	void draw(sf::RenderWindow &window);
	//Funcion para modificar el marcador de puntuacion
	void setScore(unsigned points);
	//Funcion para obtener la puntuacion del jugador
	unsigned getScore();
	
private:
	unsigned score;		//Variable para la puntuacion
	
	sf::Font score_font;				//Fuente para el marcador de puntuacion
	std::ostringstream string_score;	//Objeto ostringstream para el marcador de puntuacion
};

#endif
