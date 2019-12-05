#include "menu.hh"

//Funcion main del programa
/*Dentro de main solo se crea una ventana, se crea
un objeto Menu y se muestra el menu en la ventana.*/
int main(){
	//Se crea la ventana asignando las dimensiones y el titulo de la ventana
	sf::RenderWindow window(sf::VideoMode(600, 700, 32),"Universal War", sf::Style::Close);
	
	//Impide que la ventana ocupe la pantalla completa
	window.setVerticalSyncEnabled(true);
	
	//Se crea un objeto Menu
	Menu menu;
	
	//Muestra el menu en la ventana
	menu.run(window);

	return 0;
}
