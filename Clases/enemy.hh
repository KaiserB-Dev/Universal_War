#ifndef ENEMY_HH
#define ENEMY_HH

#include <SFML/Graphics.hpp> 
#include <vector>
#include <ctime>

class Enemy : public sf::Sprite{
public:
	Enemy();
	void enemy_move(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void enemy_sprite(const std::string &filename);
private:
	sf::Texture	enemy_texture;
	sf::Vector2f enemy_position;
	std::vector<Enemy> enemies;
	float x,y;
	float enemySpawnTimerMax;
	float enemySpawnTimer;
	unsigned maxEnemies;
}; 

#endif
