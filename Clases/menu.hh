#ifndef MENU_HH
#define MENU_HH

//Librerias utilizadas para el menu
#include <SFML/Graphics.hpp>
#include "windowScene.hh"

//Clase Menu
class Menu{
public:
	//Constructor Por Defecto
	Menu();
	
	//Funcion para mostrar el menu
	void run(sf::RenderWindow &window);
	//Funcion para dibujar el menu en la ventana
	void draw(sf::RenderWindow &window);
	//Funcion para moverse entre las opciones del menu
	void move();
	//Funcion para obtener la opcion seleccionada
	int get_option();

private:
	int option_selected;		//Variable para la opcion seleccionada
	sf::Font options_font;		//Fuente para las opciones del menu
	sf::Text options_text[2];	//Arreglo que almacena el texto de las opciones del menu
	sf::Texture title_texture;	//Textura del titulo del videojuego
	sf::Sprite title_sprite;	//Sprite del titulo del videojuego
	sf::Texture bg_texture;		//Textura del fondo del menu
	sf::Sprite bg_sprite;		//Sprite del fondo del menu
};

#endif

