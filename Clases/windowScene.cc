#include "windowScene.hh"

//Constructor Por Defecto de windowScene
windowScene::windowScene(){
	//Carga el fondo de la carpeta Sprites
	background_tex.loadFromFile("../Sprites/Spr_Space.jpg");
	//Asigna la textura al objeto fondo
	background.setTexture(background_tex);
	
	buffer.loadFromFile("../Audio/explosion.ogg");


	death.openFromFile("../Audio/death_theme.ogg");
	//Carga al objeto el archivo de audio
	back_music.openFromFile("../Audio/back_audio.ogg");
	//Cicla la musica
	back_music.setLoop(true);
	//Reproduce la pista y ajusta el volumen
	back_music.setVolume(100.0f);
	back_music.play();
	isListening = true;
	explosion.setBuffer(buffer);
	explosion.setVolume(50.0f);
	
	//Inicialización de Variables para los Enemigos
	enemySpawnTimerMax = 15;
	enemySpawnTimer = 0;
	maxEnemies = 5;
	


}

//Funcion para mostrar el juego
void windowScene::play(sf::RenderWindow &window){
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
               	
            if(!isListening)
            	death.play();
		}
		time = clock.getElapsedTime();
		
		if(time.asSeconds() >= 0.5f){
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
				if(lifes.getLifes() > 0)
                	player.Shoot(bullet);
                clock.restart();
            }
		}
		
		player.Detect_Axis();

       	if(x <= 505.0f && x >= -5.0f){
         	if(y <= 575.0f && y >= -25.0f){
                if(lifes.getLifes() > 0)
					player.Controller();
            }
        	else{
                player.setPosition(x , 575.0f);   
            }
        }
		else{
            player.setPosition(-5.0f , y);
        }
        
        //Spawn de los Enemigos
        if(this -> enemies.size() < this -> maxEnemies){
        	if(this -> enemySpawnTimer >= this -> enemySpawnTimerMax){
        		//this -> enemy.setPosition(static_cast<float>(rand() % static_cast<int>(window.getSize().x - 27.0f)),0.0f);
        		this -> enemy.setPosition(static_cast<float>(rand() % static_cast<int>(500.0f - 27.0f)),0.0f);
        		this -> enemies.push_back(this -> enemy);
        		this -> enemySpawnTimer = 0.0f;
			}
			else
				this -> enemySpawnTimer += 2.5f;
			//this -> enemySpawnTimer += 1.0f;
		}
		
		//Acciones de los Enemigos
		for(unsigned i = 0; i < this -> enemies.size(); ++i){
			//Movimiento de los Enemigos
			if(score.getScore() >= 0 && score.getScore() <= 4000)
				this -> enemies[i].move(0.0f,5.0f);

			if(score.getScore() >= 4000 && score.getScore() <= 12000){
			enemy.enemy_sprite("../Sprites/alien_amarillo1.png");
				this -> enemies[i].move(0.0f,7.0f);
		}


			if(score.getScore() >= 12000){

				enemy.enemy_sprite("../Sprites/alien_morado1.png");
				this -> enemies[i].move(0.0f,9.0f);

			}

			
			//Si la bala del jugador toca a un enemigo, este es "eliminado"
			if(bullet.collide_Enemy(this->enemies[i])){
				//this->enemies[i].setPosition(1000.0f, 1000.0f);
				this -> enemies.erase(this -> enemies.begin() + i);	
				score.setScore(10);
			}
			
			if(this->enemies[i].getPosition().y > window.getSize().y)
				this -> enemies.erase(this -> enemies.begin() + i);
					
			
				
			if(lifes.getLifes() <= 0){
				player.setColor(sf::Color::Red);
				window.clear();
				back_music.stop();
				lifes.setString("GAME OVER: Presione Esc para salir");
				lifes.setPosition(120.0f, 350.0f);
				isListening = false;
				score.setPosition(190.0f, 400.0f);
				score.setCharacterSize(50);


				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
					death.stop();
					
					Menu menu;
					menu.run(window);

				}
			}
			else{
				if(player.collide_Enemy(this->enemies[i])){
					this -> enemies.erase(this -> enemies.begin() + i);
					lifes.setLifes(5);
					explosion.play();

				}	
			}
		}

	
		window.clear();
		
		//Dibuja el fondo en la ventana
        window.draw(background);
		//Dibuja el jugador en la ventana
        player.draw_Player(window);
        
		window.draw(enemy);
        for(auto &e : this->enemies)
			window.draw(e);

		lifes.draw(window);
    	score.draw(window);
        //Movimiento y velocidad de la bala
        bullet.move(0.0f,-20.0f);
        //Dibuja la bala en la ventana
        bullet.draw(window);
        
		//Muestra la GUI en pantalla
        window.display();
    }
}

/*#include "windowScene.hh"

//Constructor Por Defecto de windowScene
windowScene::windowScene(){
	//Carga el fondo de la carpeta Sprites
	background_tex.loadFromFile("../Sprites/Spr_Space.jpg");
	//Asigna la textura al objeto fondo
	background.setTexture(background_tex);
	
	death.openFromFile("../Audio/death_theme.ogg");
	//Carga al objeto el archivo de audio
	back_music.openFromFile("../Audio/back_audio.ogg");
	//Cicla la musica
	back_music.setLoop(true);
	//Reproduce la pista y ajusta el volumen
	back_music.setVolume(100.0f);
	back_music.play();
	isListening = true;
	explosion.setBuffer(buffer);
	
	//Inicialización de Variables para los Enemigos
	enemySpawnTimerMax = 15;
	enemySpawnTimer = 0;
	maxEnemies = 5;
	
	buffer.loadFromFile("../Audio/explosion.ogg");
}

//Funcion para mostrar el juego
//void windowScene::play(){
int windowScene::Run(sf::RenderWindow &window){
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
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
               	return -1; //Cierra la Ventana
               	
            if(!isListening)
            	death.play();
		}
		time = clock.getElapsedTime();
		
		if(time.asSeconds() >= 0.5f){
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
				if(lifes.getLifes() > 0)
                	player.Shoot(bullet);
                clock.restart();
            }
		}
		
		player.Detect_Axis();

       	if(x <= 505.0f && x >= -5.0f){
         	if(y <= 575.0f && y >= -25.0f){
                if(lifes.getLifes() > 0)
					player.Controller();
            }
        	else{
                player.setPosition(x , 575.0f);   
            }
        }
		else{
            player.setPosition(-5.0f , y);
        }
        
        //Spawn de los Enemigos
        if(this -> enemies.size() < this -> maxEnemies){
        	if(this -> enemySpawnTimer >= this -> enemySpawnTimerMax){
        		//this -> enemy.setPosition(static_cast<float>(rand() % static_cast<int>(window.getSize().x - 27.0f)),0.0f);
        		this -> enemy.setPosition(static_cast<float>(rand() % static_cast<int>(500.0f - 27.0f)),0.0f);
        		this -> enemies.push_back(this -> enemy);
        		this -> enemySpawnTimer = 0.0f;
			}
			else
				this -> enemySpawnTimer += 2.5f;
			//this -> enemySpawnTimer += 1.0f;
		}
		
		//Acciones de los Enemigos
		for(unsigned i = 0; i < this -> enemies.size(); ++i){
			//Movimiento de los Enemigos
			this -> enemies[i].move(0.0f,5.0f);
			
			//Si la bala del jugador toca a un enemigo, este es "eliminado"
			if(bullet.collide_Enemy(this->enemies[i])){
				//this->enemies[i].setPosition(1000.0f, 1000.0f);
				this -> enemies.erase(this -> enemies.begin() + i);	
				score.setScore(10);
			}
			
			if(this->enemies[i].getPosition().y > window.getSize().y)
				this -> enemies.erase(this -> enemies.begin() + i);
				
			if(lifes.getLifes() <= 0){
				player.setColor(sf::Color::Red);
				window.clear();
				back_music.stop();
				lifes.setString("GAME OVER: Presione Esc para salir");
				lifes.setPosition(120.0f, 350.0f);
				isListening = false;
			}
			else{
				if(player.collide_Enemy(this->enemies[i])){
					this -> enemies.erase(this -> enemies.begin() + i);
					lifes.setLifes(5);
				}	
			}
		}
		window.clear();
		
		draw(window);
        
		//Muestra la GUI en pantalla
        window.display();
    }
    return -1;
}

void windowScene::draw(sf::RenderWindow &window){
	//Dibuja el fondo en la ventana
    window.draw(background);
	//Dibuja el jugador en la ventana
    window.draw(player);
    
	window.draw(enemy);
    for(auto &e : enemies)
		window.draw(e);

	window.draw(lifes);
	window.draw(score);
    //Movimiento y velocidad de la bala
    bullet.move(0.0f,-20.0f);
    //Dibuja la bala en la ventana
    window.draw(bullet);
}*/
