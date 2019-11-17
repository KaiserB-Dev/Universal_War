#include "windowScene.hh"
#include <iostream>

windowScene::windowScene(){
	//Creacion de la ventana de las dimensiones establecidad y BBP
	window.create(sf::VideoMode(600, 700, 32),"JUEGO POO", sf::Style::Close);
	//Impide la pantalla completa
	window.setVerticalSyncEnabled(true);
	//Carga el fondo de la carpeta Sprites
	background_tex.loadFromFile("../Sprites/Spr_Space.jpg");
	//Asigna la textura al objeto fondo
	background.setTexture(background_tex);
	//Carga al objeto el archivo de audio
	back_music.openFromFile("../Audio/soundtrack.ogg");
	//Cicla la musica
	back_music.setLoop(true);
	//Reproduce la pista
	back_music.play();
	//Se reinicia el clock
	time = clock.restart();
}

void windowScene::play(){
	int x,y;
	
	//Inicia el loop de la ventana siempre que la ventana este abierta
	while (window.isOpen()){		
		//Crea el objeto de eventos
       	sf::Event event;
       	//Obtiene la posicion en X del jugador
       	x = player.Get_axis_x();
        //Obtiene la posicion en Y del jugador
		y = player.Get_axis_y();
		//Loop de validacion de eventos
       	while (window.pollEvent(event)){
			//Valida el evento del boton cerrar
            if (event.type == sf::Event::Closed)
               	window.close(); //Cierra la Ventana
            
		}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
				player.Shoot(bullet);
            	      
			}
		
		//Detecta la pocicion del objeto en los ejes x & y
        player.Detect_Axis();
        /*std::cout << "X= "<<x<<std::endl;
        std::cout << "Y= "<<y<<std::endl;*/
		/*Nota: Las condiciones implementadas permiten hacer
		la deteccion de los bordes de la ventana y limita
		el movimiento de la nave, aun hay un bug por
		arreglar pero es minimo.*/

       	if(x <= 475.0f && x >= -45.0f){
         	if(y <= 405.0f && y >= -195.0f){
                //Invoca el metodo controller
				player.Controller();
				//std::cout<<"DENTRO DEL LIMITE"<<std::endl; 
            }
        	else{
				//std::cout<<"FUERA DEL LIMITE"<<std::endl; 
                player.setPosition(x , 405.0f);   
            }
        }
		else{ 
        	//std::cout<<"FUERA DEL LIMITE"<<std::endl; 
            player.setPosition(-20.0f , y);
        }
		//Termina la deteccion del borde de la pantalla
		window.clear();
		//Dibuja el fondo en la ventana
        window.draw(background);
		//Dibuja el jugador en la ventana
        window.draw(player);
                      		    bullet.move(sf::Vector2f(0,-10));

        bullet.draw(window);
		//Muestra la GUI en pantalla
        window.display();
    }
}

