#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "drawable.hpp"

class Spaceship : public MyDrawable
{
public:
	//Spaceship(std::string aTexturePath, sf::RenderWindow& aWindow);
	Spaceship(std::string aTexturePath);
	virtual ~Spaceship();

private:
};

#endif // !SPACESHIP_H