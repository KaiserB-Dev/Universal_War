#include "enemy.hh"

Enemy::Enemy()
{
	enemySpawnTimerMax = 15;
	enemySpawnTimer = 0;
	maxEnemies = 10;
	enemy_texture.loadFromFile("../Sprites/alien_verde1.png");
	this -> setTexture(enemy_texture);
	position.x = 27.0f;
	position.y = 20.0f; 
	this -> setPosition(position);
	this -> setScale(0.7f,0.7f);
}

void Enemy::enemy_move(sf::RenderWindow &window){
	//std::srand(static_cast<unsigned>(std::time(nullptr)));
	
	if(enemies.size() < maxEnemies){
    	if(enemySpawnTimer >= enemySpawnTimerMax){
    		this -> setPosition(static_cast<float>(rand() % static_cast<int>(window.getSize().x - 27.0f)),0.0f);
    		enemies.push_back(*this);
    		enemySpawnTimer = 0.0f;
		}
		else
			enemySpawnTimer += 1.0f;
	}
	
	for(unsigned i = 0; i < enemies.size(); ++i){
		bool deleted = false;
		enemies[i].move(0.0f,5.0f);
		
		if(enemies[i].getPosition().y > window.getSize().y)
			enemies.erase(enemies.begin() + i);
	}
	
	window.draw(*this);
    for(auto &e : enemies)
		window.draw(e);
}
