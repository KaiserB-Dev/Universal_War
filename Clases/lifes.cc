#include "lifes.hh"
#include <iostream>

Lifes::Lifes(){
	player.set_lifes(100);
	lifes = player.get_lifes();
	font.loadFromFile("../Fonts/Sansation-Regular.ttf");
	
	s_lifes << "Health: " << lifes;
	
	this->setCharacterSize(20);
	this->setFont(font);
	this->setString(s_lifes.str() + "%");
	this->setPosition(5.0f,0.0f);
}

void Lifes::draw(sf::RenderWindow &window){
	window.draw(*this);
}

void Lifes::setLifes(int valor){
	lifes = player.get_lifes();

	lifes -= valor;
	player.set_lifes(player.get_lifes()-valor);
	std::cout<<player.get_lifes()<<std::endl;
	s_lifes.str("");
	s_lifes << "Health: " << lifes;
	this->setString(s_lifes.str() + "%");

}

int Lifes::getLifes(){

	return lifes;

}
