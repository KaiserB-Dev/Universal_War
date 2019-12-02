#include "lifes.hh"

Lifes::Lifes(){
	player.set_Lifes(100);
	lifes = player.get_Lifes();
	
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
	lifes = player.get_Lifes();
	lifes -= valor;
	player.set_Lifes(player.get_Lifes()-valor);
	s_lifes.str("");
	s_lifes << "Health: " << lifes;
	this->setString(s_lifes.str() + "%");
}

void Lifes::setInitialLifes(unsigned valor){
	lifes = valor;
	s_lifes.str("");
	s_lifes << "Health: " << lifes;
	this ->setString(s_lifes.str() + "%");
}

int Lifes::getLifes(){
	return lifes;
}
