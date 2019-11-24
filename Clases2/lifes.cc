#include "lifes.hh"

Lifes::Lifes(){
	lifes = 3;
	
	font.loadFromFile("../Fonts/Sansation-Regular.ttf");
	
	s_lifes << "Lifes: " << lifes;
	
	this->setCharacterSize(20);
	this->setFont(font);
	this->setString(s_lifes.str());
}

void Lifes::draw(sf::RenderWindow &window){
	window.draw(*this);
}
