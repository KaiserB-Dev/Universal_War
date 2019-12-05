#include "windowScene.hh"

//Constructor Por Defecto
/*Inicializa las variables, carga la textura y el sprite del fondo de pantalla, carga el
sonido del jugador cuando recibe daño, y carga la musica de fondo y de muerte del jugador.*/
windowScene::windowScene(){
	//Se inicializan las variables
	x = 0;
	y = 0;
	cont = 0;
	
	//Se carga el archivo para la textura y se asigna al sprite
	bg_texture.loadFromFile("../Sprites/Spr_Space.jpg");
	bg_sprite.setTexture(bg_texture);
	
	//Se carga el archivo para el buffer, se asigna al sonido, y se le asigna un volumen
	buffer.loadFromFile("../Audio/explosion.ogg");
	explosion.setBuffer(buffer);
	explosion.setVolume(50.0f);
	
	//Se cargan los archivos para la musica
	back_music.openFromFile("../Audio/back_audio.ogg");
	death.openFromFile("../Audio/death_theme.ogg");
	
	//Se cicla la musica de fondo
	back_music.setLoop(true);
	
	//Se inicializa la variable isListening con el valor true
	isListening = true;
	
	//Se asigna el volumen a la musica de fondo y se reproduce
	back_music.setVolume(100.0f);
	back_music.play();
	
	//Se inicializan las variables para los enemigos
	maxEnemies = 5;
	enemySpawnTimer = 0;
	enemySpawnTimerMax = 15;
}

//Funcion para mostrar el juego
/*Se implementa el codigo para que diversas acciones se realizen en los
diferentes objetos y se muestren en la ventana recibida como parametro.*/
void windowScene::play(sf::RenderWindow &window){
	//Se genera una semilla para poder generar números aleatorios
	/*Es usada para generar una posicion aleatoria para los enemigos.*/
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	
	//Mientras la ventana este abierta, se realizarán las acciones
	while (window.isOpen()){
		//Se asigna un limite de Cuadros por Segundo a la ventana
		window.setFramerateLimit(60);	
			
       	//Se obtiene la posicion en X y en Y del jugador, y se asigna a las variables
       	x = player.getX();
		y = player.getY();
		
		//Crea un objeto de eventos
       	sf::Event event;
       	
		//Ciclo para validacion de eventos
       	while (window.pollEvent(event)){
			//Valida el evento del boton Cerrar
            if (event.type == sf::Event::Closed)
               	window.close(); //Se cierra la Ventana
            
            //Valida la musica de muerte
            if(!isListening && event.type == sf::Event::KeyPressed && cont == 0){
            	death.setLoop(true);	//Se cicla la musica de muerte
				death.play();			//Reproduce la musica de muerte
				cont = 1;				//Se asigna el valor de 1 a cont
			}
		}
		
		//Se llama a las funciones implementadas
		shootTimer();
		playerMove();
        enemyActions(window);
		
		window.clear();		//Se limpia la ventana
		drawGame(window);	//Se dibujan los elementos del juego en la ventana
        window.display();	//Se muestra la ventana
    }
}

//Funcion para controlar el tiempo entre cada disparo del jugador
/*Asigna el tiempo transcurrido, y con ello se permite que
el jugador dispare cada cierto intervalo de tiempo.*/
void windowScene::shootTimer(){
	//Se asigna el tiempo transcurrido al objeto Time
	time = clock.getElapsedTime();
	
	/*Si el tiempo es mayor a 0.5 seg, el jugador podrá disparar
	si presiona la tecla Space y si su vida es mayor a 0.*/
	if(time.asSeconds() >= 0.5f){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			if(lifes.getLife() > 0)
            	player.Shoot(bullet);
            clock.restart();	//Se reinicia el objeto Clock
        }
	}
}

//Funcion para mover al jugador dentro de una zona delimitada
/*Detecta la posicion del jugador y verifica si esta dentro de
la zona delimitada para permitir el movimiento del jugador.*/
void windowScene::playerMove(){
	//Detecta la posicion del jugador
	player.detect_Position();
	
	/*Si el jugador se encuentra dentro de la zona delimitada y si su vida
	es mayor a 0, se permite el movimiento del jugador con las teclas.*/
   	if(x <= 505.0f && x >= -5.0f){
     	if(y <= 575.0f && y >= -25.0f){
            if(lifes.getLife() > 0)
				player.Controller();	//Se llama a Controller del objeto player
        }
        //Si llega a cruzar los limites, se coloca al jugador dentro de la zona
    	else{
            player.setPosition(x , 575.0f);	//Se asigna una posicion con respecto a Y
        }
    }
	else{
        player.setPosition(-5.0f , y);	//Se asigna una posicion con respecto a X
    }
}

//Funcion para cambiar la constante de puntos por cada enemigo
/*Dependiendo de la puntuacion del jugador, se incrementa el
valor de los puntos obtenidos al eliminar a los enemigos.*/
void windowScene::changeScore(){
	//Se obtienen 10 puntos por cada enemigo si la puntuacion esta entre 0 y 4000
	if(score.getScore() >= 0 && score.getScore() <= 4000)
		score.setScore(10);
	
	//Se obtienen 15 puntos por cada enemigo si la puntuacion esta entre 4000 y 12000
	if(score.getScore() >= 4000 && score.getScore() <= 12000)
		score.setScore(15);
	
	//Se obtienen 20 puntos por cada enemigo si la puntuacion es mayor a 12000
	if(score.getScore() >= 12000)
		score.setScore(20);
}

//Funcion para controlar a los enemigos
/*Se controlan diferentes acciones de los enemigos,
como su aparicion, cambio de aspecto, interaccion
con el jugador y con la bala.
Tambien se controlan las acciones correspondientes
por si el jugador muere.
Recibe como parametro la ventana para poder realizar
la accion de volver al menu.*/
void windowScene::enemyActions(sf::RenderWindow &window){
	//Aparicion de los Enemigos
	/*Coloca a los enemigos en posiciones aleatorias, los inserta en el vector enemies
	y controla el tiempo de aparicion de los enemigos*/
    if(this -> enemies.size() < this -> maxEnemies){
    	if(this -> enemySpawnTimer >= this -> enemySpawnTimerMax){
    		this -> enemy.setPosition(static_cast<float>(rand() % static_cast<int>(500.0f - 27.0f)),0.0f);
    		this -> enemies.push_back(this -> enemy);
    		this -> enemySpawnTimer = 0.0f;
		}
		else
			this -> enemySpawnTimer += 2.5f;
	}
	
	//Acciones de los Enemigos
	for(unsigned i = 0; i < this -> enemies.size(); ++i){
		//Movimiento de los Enemigos
		/*Controla la velocidad y el aspecto de los enemigos
		en base a la puntuacion del jugador.*/
		/*Se asigna una velocidad lenta a los enemigos
		si la puntuacion esta entre 0 y 4000.*/
		if(score.getScore() >= 0 && score.getScore() <= 4000)
			this -> enemies[i].move(0.0f,5.0f);
		
		/*Se asigna una velocidad intermedia y un aspecto distinto a
		los enemigos si la puntuacion esta entre 4000 y 12000.*/
		if(score.getScore() >= 4000 && score.getScore() <= 12000){
			enemy.change_sprite("../Sprites/alien_amarillo1.png");
			this -> enemies[i].move(0.0f,7.0f);
		}
		
		/*Se asigna una velocidad rapida y un aspecto distinto
		a los enemigos si la puntuacion es mayor a 12000.*/
		if(score.getScore() >= 12000){
			enemy.change_sprite("../Sprites/alien_morado1.png");
			this -> enemies[i].move(0.0f,9.0f);
		}
		
		/*Si la bala del jugador toca a un enemigo, este es eliminado
		del vector y asigna los puntos a la puntuacion del jugador.*/
		if(bullet.collide_Enemy(this->enemies[i])){
			this -> enemies.erase(this -> enemies.begin() + i);	
			/*Llama a la funcion changeScore() para asignar los
			puntos dependiendo de la puntuacion del jugador.*/
			changeScore();
		}
		
		//Si un enemigo llega al final de la pantalla, es eliminado del vector
		if(this->enemies[i].getPosition().y > window.getSize().y)
			this -> enemies.erase(this -> enemies.begin() + i);
		
		//Si la vida del jugador llega a 0, el juego termina
		if(lifes.getLife() <= 0){
			player.setColor(sf::Color::Red);	//Se cambia el color del jugador
			back_music.stop();					//Se detiene la musica de fondo
			
			//Se muestra el mensaje de Game Over en medio de la pantalla
			lifes.setString("GAME OVER: Presione Esc para reiniciar.");
			lifes.setPosition(120.0f, 350.0f);
			
			//Se muestra la puntuacion final del jugador en medio de la pantalla
			score.setPosition(170.0f, 400.0f);
			score.setCharacterSize(50);
			
			//Se asigna a la variable el valor false
			isListening = false;
			
			//Si el jugador presiona la tecla Enter, se muestra el menu
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				//Se detiene la musica de muerte
				death.stop();
				
				//Se crea el objeto Menu y llama a la funcion run()
				Menu menu;
				menu.run(window);
			}
		}
		else{
			/*Si el jugador choca con un enemigo, este es eliminado
			del vector y se le disminuye vida al jugador.*/ 
			if(player.collide_Enemy(this->enemies[i])){
				this -> enemies.erase(this -> enemies.begin() + i);
				lifes.setLife(5);
				
				//Se reproduce un sonido de explosion
				explosion.play();
			}
		}
	}
}

//Funcion para dibujar los elementos del juego en la ventana
/*Dibuja el fondo de pantalla, dibuja a los enemigos, controla
el movimiento de la bala, y llama a las funciones draw de los
objetos player, bullet, lifes y score.*/
void windowScene::drawGame(sf::RenderWindow &window){
	//Dibuja el fondo en la ventana
    window.draw(bg_sprite);
    
    //Dibuja al sprite de los enemigos
	window.draw(enemy);
	
	//Ciclo para dibujar el contenido del vector enemies
    for(auto &e : this->enemies)
		window.draw(e);	//Dibuja a cada enemigo del vector
	
	//Dibuja al jugador, su vida y su puntuacion en la ventana
    player.draw(window);
	lifes.draw(window);
	score.draw(window);
	
    //Se asigna una velocidad a la bala
    bullet.move(0.0f,-20.0f);
    
	//Dibuja la bala en la ventana
    bullet.draw(window);
}
