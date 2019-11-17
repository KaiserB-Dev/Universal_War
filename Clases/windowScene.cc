#include "windowScene.hh"

#include <iostream>

windowScene::windowScene(){

	window.create(sf::VideoMode(600, 700, 32),"JUEGO POO", sf::Style::Close); //Creacion de la ventana de las dimensiones establecidad y BBP

	window.setVerticalSyncEnabled(true); //Impide la pantalla completa

	background_tex.loadFromFile("../Sprites/Spr_Space.jpg"); //Carga el fondo de la carpeta Sprites

	background.setTexture(background_tex); //Asigna la textura al objeto fondo

	back_music.openFromFile("../Audio/soundtrack.ogg"); //Carga al objeto el archivo de audio

	back_music.setLoop(true); //Cicla la musica

	back_music.play(); //Reproduce la pista

	time = clock.restart(); //sreinicia el clock
}
	

void windowScene::play()
{
	int x,y; 
	while (window.isOpen()) //Inicia el loop de la ventana siempre que la ventana este abierta		
	{
    sf::Event event; //Crea el objeto de eventos
 		x = player.Get_axis_x(); //Obtiene la posicion en X del jugador
    y = player.Get_axis_y(); //Obtiene la posicion en Y del jugador 
  	while (window.pollEvent(event)) //loop de validacion de eventos
		{		
    	if (event.type == sf::Event::Closed) //Valida el evento del boton cerrar
    	window.close(); //Cierra la Ventana
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      player.Shoot(bullet);
    }
  	player.Detect_Axis(); //Detecta la pocicion del objeto en los ejes x & y
  	/*std::cout << "X= "<<x<<std::endl;
  	std::cout << "Y= "<<y<<std::endl;*/
    //Las condiciones implementadas permiten hacer la deteccion de los bordes de la ventana y limita el movimiento de la nave, aun hay un bug por arreglar pero es minimo   
		if(x <= 475.0f && x >= -45.0f)
    {
  	  if(y <= 405.0f && y >= -195.0f)
      {
        //Invoca el metodo controller
        player.Controller();
  			//std::cout<<"DENTRO DEL LIMITE"<<std::endl; 
  		}
      else
      {
      //std::cout<<"FUERA DEL LIMITE"<<std::endl; 
      player.setPosition(x , 405.0f);                    
      }
   	}
    else
    { 
      //std::cout<<"FUERA DEL LIMITE"<<std::endl; 
      player.setPosition(-20.0f , y);
    }
    //Termina la deteccion del borde de la pantalla
    window.clear();
    window.draw(background); //Dibuja el fondo en la veNtana
  	window.draw(player); //Dibuja el jugador en la ventana
    bullet.draw(window);
    // window.draw(bullet);
  	window.display(); //Muestra la GUI en pantalla
  }
}
