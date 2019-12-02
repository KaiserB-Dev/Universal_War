#ifndef SCORE_HH
#define SCORE_HH

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <sstream>

class Score : public sf::Text{
public:
	Score();
	void draw(sf::RenderWindow &window);
	void setScore(unsigned points);
	unsigned getScore();
private:
	sf::Font font;
	sf::Text text_score;
	std::ostringstream s_score;
	unsigned score;
};

#endif
