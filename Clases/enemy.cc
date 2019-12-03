#include "enemy.hh"

Enemy::Enemy(){
	enemySpawnTimerMax = 15;
	enemySpawnTimer = 0;
	maxEnemies = 5;
	
	this -> enemy_sprite("../Sprites/alien_verde1.png");	
	enemy_position.x = 27.0f;
	enemy_position.y = 20.0f; 
	this -> setPosition(enemy_position);
	this -> setScale(0.7f,0.7f);
}

void Enemy::enemy_move(sf::RenderWindow &window){
	
	if(enemies.size() < maxEnemies){
    	if(enemySpawnTimer >= enemySpawnTimerMax){
    		this->setPosition(static_cast<float>(rand() % static_cast<int>(500.0f - 27.0f)),0.0f);
    		enemies.push_back(*this);
    		enemySpawnTimer = 0.0f;
		}
		else
			enemySpawnTimer += 2.5f;
	}
	
	for(unsigned i = 0; i < enemies.size(); ++i){
		enemies[i].move(0.0f,5.0f);
		
		if(enemies[i].getPosition().y > window.getSize().y)
			enemies.erase(enemies.begin() + i);
	}
}

void Enemy::draw(sf::RenderWindow &window){
	window.draw(*this);
	
	for(auto &e : enemies)
		window.draw(e);
}

void Enemy::enemy_sprite(const std::string &filename){

	enemy_texture.loadFromFile(filename);
	this -> setTexture(enemy_texture);


}
