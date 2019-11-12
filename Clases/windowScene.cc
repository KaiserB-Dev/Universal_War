#include "windowScene.hh"

#include <iostream>

windowScene::windowScene(){

	window.create(sf::VideoMode(600, 700, 32),"JUEGO POO", sf::Style::Close); //Creacion de la ventana de las dimensiones establecidad y BBP

	window.setVerticalSyncEnabled(true); //Impide la pantalla completa

	background_tex.loadFromFile("../Sprites/background.jpg"); //Carga el fondo de la carpeta Sprites

	background.setTexture(background_tex); //Asigna la textura al objeto fondo

	back_music.openFromFile("../Audio/soundtrack.ogg"); //Carga al objeto el archivo de audio

	back_music.setLoop(true); //Cicla la musica

	back_music.play(); //Reproduce la pista
}
	

void windowScene::play(){

	int x,y; 


		while (window.isOpen()){ //Inicia el loop de la ventana siempre que la ventana este abierta		
			
       		sf::Event event; //Crea el objeto de eventos
       		x = player.Get_axis_x(); //Obtiene la posicion en X del jugador
            y = player.Get_axis_y(); //Obtiene la posicion en Y del jugador 

        	while (window.pollEvent(event)){ //loop de validacion de eventos
				
            	if (event.type == sf::Event::Closed) //Valida el evento del boton cerrar
                	window.close(); //Cierra la Ventana

            	std::cout << "X= "<<x<<std::endl;
            	std::cout << "Y= "<<y<<std::endl;
            	
            			player.Controller(); //Invoca el metodo controller 


        	}

        	window.draw(background); //Dibuja el fondo en la vemtana

        	window.draw(player); //Dibuja el jugador en la ventana

        	window.display(); //Muestra la GUI en pantalla

        }


}
