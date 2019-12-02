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
	void setInitialLifes(unsigned valor);
	int getLifes();
private:
	sf::Font font;
	sf::Text text_lifes;
	std::ostringstream s_lifes;
	unsigned lifes;
	Player player;
};

#endif
