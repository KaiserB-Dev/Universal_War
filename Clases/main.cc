#include "menu.hh"

int main(){
	sf::RenderWindow window(sf::VideoMode(600, 700, 32),"Universal War", sf::Style::Close);
	//Impide la pantalla completa
	window.setVerticalSyncEnabled(true);
	
	Menu menu;
	//win.play(); //Ejecuta el programa
	menu.run(window);
	
	/*int number_window = 0;
	std::vector<Windows*> windows;
	
	//Creacion de la ventana de las dimensiones establecidad y BBP
	sf::RenderWindow window(sf::VideoMode(600, 700, 32),"Universal War", sf::Style::Close);
	//Impide la pantalla completa
	window.setVerticalSyncEnabled(true);
	
	Menu menu;
	windows.push_back(&menu);
	
	windowScene window_scene;
	windows.push_back(&window_scene);
	
	while(number_window >= 0){
		number_window = windows[number_window]->Run(window);
	}*/

	return 0;
}
