#ifndef BULLET_HH
#define BULLET_HH

//Librerias
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite{
public:
	Bullet();
	void Detect_Axis();
	float Get_axis_x();
	float Get_axis_y();
	void draw(sf::RenderWindow &window);
	void fire(int speed,  float x, float y);
private:
	sf::Texture bullet_texture;
	sf::Clock clock;
	sf::Time time;
	sf::Vector2f position_bullet;
	float x,y;
};

#endif
