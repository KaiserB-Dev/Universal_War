#ifndef LIFES_HH
#define LIFES_HH

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <sstream>
#include "Player.hh"

class Lifes : public sf::Text{
public:
	Lifes();
	void draw(sf::RenderWindow &window);

	void setLifes(int valor);

	int getLifes();
private:
	sf::Font font;
	sf::Text text_lifes;
	//sf::Text text_score;
	std::ostringstream s_lifes;
	//std::ostringstream s_score;
	int lifes;

	Player player;
	//unsigned score;
};

#endif
