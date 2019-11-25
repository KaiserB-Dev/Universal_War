#ifndef ENEMY_HH
#define ENEMY_HH

#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>

class Enemy : public sf::Sprite
{
	public:
		Enemy();
		void enemy_move(sf::RenderWindow &window);
	private:
		sf::Texture	enemy_texture;
		sf::Vector2f position;
		std::vector<Enemy> enemies;
		float x,y;
		float enemySpawnTimerMax = 15;
		float enemySpawnTimer = 0;
		unsigned maxEnemies = 10;
}; 

#endif
