#include "menu.hh"

//Constructor Por Defecto
/*Inicializa las variables, la fuente y el texto de las opciones,
asi como la textura y el sprite del titulo del videojuego.*/
Menu::Menu(){
	//Inicializa la variable "option_selected"
	option_selected = 0;
	
	//Se carga la textura del archivo, se asigna al sprite y se le asigna una posicion y escala
	title_texture.loadFromFile("../Sprites/universal_war_title.png");
	title_sprite.setTexture(title_texture);
	title_sprite.setPosition(65.0f, 100.0f);
	title_sprite.setScale(10.0f,10.0f);
	
	//Se carga la textura del archivo y se le asigna al sprite
	bg_texture.loadFromFile("../Sprites/Spr_Space.jpg");
	bg_sprite.setTexture(bg_texture);
	
	//Se carga la fuente del archivo
	options_font.loadFromFile("../Fonts/Sansation-Regular.ttf");
	
	//Se le asigna la fuente, el color, el texto y la posicion a cada elemento del arreglo
	//Primer Elemento
	options_text[0].setFont(options_font);
	options_text[0].setColor(sf::Color::Magenta);
	options_text[0].setString("Jugar");
	options_text[0].setPosition(265.0f, 300.0f);
	
	//Segundo Elemento
	options_text[1].setFont(options_font);
	options_text[1].setColor(sf::Color::White);
	options_text[1].setString("Salir");
	options_text[1].setPosition(265.0f, 400.0f);
}

//Funcion para mostrar el menu
/*Se muestra el menu en la ventana que se recibe como parametro, se implementan
las funciones creadas y se implementan las acciones para cada opcion del menu.*/
void Menu::run(sf::RenderWindow &window){
	//Mientras la ventana este abierta, se realizarán las acciones
	while(window.isOpen()){
		//Declaracion de evento
		sf::Event event;
		
		//Ciclo para controlar diferentes eventos
		while (window.pollEvent(event)){
			//Valida el evento del boton cerrar
            if (event.type == sf::Event::Closed)
               	window.close();	//Se cierra la Ventana
        }
        
        //Se llama a la funcion move()
        move();
        
        //Acciones a realizar si el usuario presiona Enter
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        	//Llama a la funcion get_option y asigna el valor a la variable
        	int option = get_option();
        	
        	//Si el valor de la opcion es 0, muestra el juego
        	if(option == 0){
				windowScene win;
				win.play(window);
			}
			//Si el valor es 1, cierra la ventana
			else if(option == 1){
				window.close();
			}
		}
		
		window.clear();		//Se limpia la ventana
		draw(window);		//Se dibujan los elementos del menu en la ventana
		window.display();	//Se muestra la ventana
	}
}

//Funcion para dibujar el menu en la ventana
/*Dibuja el sprite del titulo y los textos del menu en la ventana recibida como parametro.*/
void Menu::draw(sf::RenderWindow &window){
	//Dibuja el sprite del fondo del menu
	window.draw(bg_sprite);
	
	//Dibuja el sprite del titulo
	window.draw(title_sprite);
	
	//Ciclo para dibujar los textos de las opciones del mneu
	for(unsigned i = 0; i < 2; ++i)
		window.draw(options_text[i]);
}

//Funcion para moverse entre las opciones del menu
/*Detecta las teclas de Up y Down, cambia el color de los texto y el valor
de la variable "option_selected" dependiendo de la tecla oprimida.*/
void Menu::move(){
	//Si se presiona la tecla Up, la opcion "Jugar" sera seleccionada
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		options_text[1].setColor(sf::Color::White);
		option_selected = 0;
		options_text[0].setColor(sf::Color::Magenta);
	}
	//Si se presiona la tecla Up, la opcion "Salir" sera seleccionada
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		options_text[0].setColor(sf::Color::White);
		option_selected = 1;
		options_text[1].setColor(sf::Color::Magenta);
	}
}

//Funcion para obtener la opcion seleccionada
/*Retorna el valor de la variable "option_selected".*/
int Menu::get_option(){
	return option_selected;
}


