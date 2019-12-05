#ifndef LIFES_HH
#define LIFES_HH

//Librerias utilizadas para la puntuacion del jugador
/*Se utiliza la libreria <sstream> para usar
el objeto std::ostringstream, y de esa forma
poder controlar el macador de puntuacion.*/
#include <SFML/Graphics.hpp>
#include <sstream>
#include "Player.hh"

//Clase Derivada Lifes que hereda la clase sf::Text
class Lifes : public sf::Text{
public:
	//Constructor Por Defecto
	Lifes();
	
	//Funcion para dibujar el marcador de vida en la ventana
	void draw(sf::RenderWindow &window);
	//Funcion para modificar el marcador de vida
	void setLife(int health);
	//Funcion para inicializar el marcador de vida
	void setInitialLife(unsigned health);
	//Funcion para obtener la vida del jugador
	int getLife();
	
private:
	unsigned life;		//Variable para la vida
	
	Player player;					//Objeto Player
	sf::Font life_font;				//Fuente para el marcador de vida
	std::ostringstream string_life;	//Objeto ostringstream para el marcador de vida
};

#endif
