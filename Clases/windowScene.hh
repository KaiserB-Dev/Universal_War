#ifndef WIN_SCENE_HH
#define WIN_SCENE_HH

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.hh"


class windowScene{

public:

	windowScene();

	void play();

private:

	sf::RenderWindow window;
	
	sf::Texture background_tex;

	sf::Sprite background;

	sf::Music back_music;
	
	Player player;
	
};


#endif