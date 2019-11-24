#include "base.hh"

Base::Base() : b_X(0), b_Y(0){ }

void Base::draw(sf::RenderWindow &window){
	window.draw(*this);
}

/*void Base::set_Position(float X, float Y){
	b_X = X;
	b_Y = Y;
}*/

float Base::get_X(){
	return b_X;
}

float Base::get_Y(){
	return b_Y;
}