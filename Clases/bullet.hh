#ifndef BULLET_HH
#define BULLET_HH

#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite{

public:

	Bullet();

	void Detect_Axis();

	float Get_axis_x();

	float Get_axis_y();

private:

	sf::Texture bullet_texture;

	float speed;

	sf::Clock clock;

	sf::Time time;

	sf::Vector2f position_bullet;

	float x,y;




};



#endif