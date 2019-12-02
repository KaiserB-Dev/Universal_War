#include "menu.hh"

int main(){
	sf::RenderWindow window(sf::VideoMode(600, 700, 32),"Universal War", sf::Style::Close);
	//Impide la pantalla completa
	window.setVerticalSyncEnabled(true);
	
	Menu menu;
	menu.run(window);
	

	return 0;
}
