#ifndef HIGH_SCORE_HH
#define 

class HighScore{
public:
	HighScore();
	void draw(sf::RenderWindow &window);

private:
	sf::Font font;
	sf::Text text_score;
	std::ostringstream s_score;
	unsigned score;

};

#endif