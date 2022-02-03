#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "space_object.hpp"

class Spaceship : public SpaceObject
{
public:
	//Spaceship(std::string aTexturePath, sf::RenderWindow& aWindow);
	Spaceship(std::string aTexturePath, uint_8 aLayer = 0);
	virtual ~Spaceship();
	virtual void move(Pair<int> aCoord);

private:
};

#endif // !SPACESHIP_H