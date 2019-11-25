#ifndef BASE_HH
#define BASE_HH

//Bibliotecas
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio.hpp>

class Base : public sf::Sprite{
public:
	Base();
	void draw(sf::RenderWindow &window);
	//void set_Position(float p_X, float p_Y);
	float get_X();
	float get_Y();
protected:
	sf::Texture	b_Texture;
	sf::Sprite b_Sprite;
	sf::Vector2f b_Position;
	float b_X;
	float b_Y;
};

#endif
