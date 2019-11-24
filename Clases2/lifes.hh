#ifndef LIFES_HH
#define LIFES_HH

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <sstream>

class Lifes : public sf::Text{
public:
	Lifes();
	void draw(sf::RenderWindow &window);
private:
	sf::Font font;
	sf::Text text_lifes;
	//sf::Text text_score;
	std::ostringstream s_lifes;
	//std::ostringstream s_score;
	unsigned lifes;
	//unsigned score;
};

#endif
