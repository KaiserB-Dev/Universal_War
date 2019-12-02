#ifndef BASE_HH
#define BASE_HH

//Bibliotecas
#include <SFML/Graphics.hpp>

class Windows{
public:
	virtual int run(sf::RenderWindow &window) = 0;
};

#endif
