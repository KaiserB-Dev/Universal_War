#include "windowScene.hh"
#include <iostream>
#include <sstream>

windowScene::windowScene(){
	//Creacion de la ventana de las dimensiones establecidad y BBP
	window.create(sf::VideoMode(600, 700, 32),"Universal War", sf::Style::Close);
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
	//Reproduce la pista y ajusta el volumen
	back_music.setVolume(35.0f);
	back_music.play();
	//Se reinicia el clock
	//time = clock.restart();
	
	//Alexis
	enemySpawnTimerMax = 15;
	enemySpawnTimer = 0;
	maxEnemies = 5;
}

void windowScene::play(){
	int x,y;
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	
	//Inicia el loop de la ventana siempre que la ventana este abierta
	while (window.isOpen()){
		window.setFramerateLimit(60);		
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
        	//else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            //      player.Shoot(bullet);
            //}
		}
		time = clock.getElapsedTime();
		
		if(time.asSeconds() >= 0.5f){
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                player.Shoot(bullet);
                clock.restart();
            }
		}
		//Detecta la pocicion del objeto en los ejes x & y
        player.Detect_Axis();
        //std::cout << "X= "<<x<<std::endl;
        //std::cout << "Y= "<<y<<std::endl;
		//Nota: Las condiciones implementadas permiten hacer
		//la deteccion de los bordes de la ventana y limita
		//el movimiento de la nave, aun hay un bug por
		//arreglar pero es minimo.

       	if(x <= 505.0f && x >= -5.0f){
         	if(y <= 575.0f && y >= -25.0f){
                //Invoca el metodo controller
				player.Controller();
				//std::cout<<"DENTRO DEL LIMITE"<<std::endl; 
            }
        	else{
				//std::cout<<"FUERA DEL LIMITE"<<std::endl; 
                player.setPosition(x , 575.0f);   
            }
        }
		else{ 
        	//std::cout<<"FUERA DEL LIMITE"<<std::endl; 
            player.setPosition(-5.0f , y);
        }
        
        //Enemigos
        if(this -> enemies.size() < this -> maxEnemies){
        	if(this -> enemySpawnTimer >= this -> enemySpawnTimerMax){
        		this -> enemy.setPosition(static_cast<float>(rand() % static_cast<int>(window.getSize().x - 27.0f)),0.0f);
        		this -> enemies.push_back(this -> enemy);
        		this -> enemySpawnTimer = 0.0f;
			}
			else
				this -> enemySpawnTimer += 1.0f;
		}
		
		for(unsigned i = 0; i < this -> enemies.size(); ++i){
			bool deleted = false;
			this -> enemies[i].move(0.0f,5.0f);
			
			if(bullet.collide_Enemy(this->enemies[i])){
				this->enemies[i].setPosition(1000.0f, 1000.0f);	
				score.setScore(10);
			}

			if(player.collide_Enemy(this->enemies[i])){

				lifes.setLifes(1);
			}

			
			if(this->enemies[i].getPosition().y > window.getSize().y)
				this -> enemies.erase(this -> enemies.begin() + i);
		}
		//Termina la deteccion del borde de la pantalla
		window.clear();
		//Dibuja el fondo en la ventana
        window.draw(background);
		//Dibuja el jugador en la ventana
        player.draw_Player(window);

		window.draw(enemy);
        for(auto &e : this->enemies)
			window.draw(e);
		//enemy.enemy_move(window);
    	lifes.draw(window);
    	score.draw(window);
        //Movimiento y velocidad de la bala
        bullet.move(sf::Vector2f(0,-20));
        //Dibuja la bala en la ventana
        bullet.draw(window);
		//Muestra la GUI en pantalla
        window.display();


    }

}
