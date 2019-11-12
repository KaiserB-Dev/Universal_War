#include "windowScene.hh"

#include <iostream>

windowScene::windowScene(){

	window.create(sf::VideoMode(600, 700, 32),"Space Invaders", sf::Style::Close);

	window.setVerticalSyncEnabled(true);

	background_tex.loadFromFile("../Sprites/background.jpg");

	background.setTexture(background_tex);

	back_music.openFromFile("../Audio/soundtrack.ogg");

	back_music.setLoop(true);

	back_music.play();
}
	

void windowScene::play(){

	int x,y;


		while (window.isOpen()){		
			
       		sf::Event event;
       		x = player.Get_axis_x();
            y = player.Get_axis_y();

        	while (window.pollEvent(event)){
				
            	if (event.type == sf::Event::Closed)
                window.close();

            	x = player.Get_axis_x();
            	y = player.Get_axis_y();

            	//player.Controller();

            	std::cout << "X= "<<x<<std::endl;
            	std::cout << "Y= "<<y<<std::endl;

            			player.Controller();


        	}

        	window.draw(background);

        	window.draw(player);

        	window.display();

        }


}
