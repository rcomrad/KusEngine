#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "space_object.hpp"
#include "my_time.hpp"

class Spaceship : public SpaceObject
{
public:
	//Spaceship(std::string aTexturePath, sf::RenderWindow& aWindow);
	Spaceship(std::string aTexturePath, uint_8 aLayer = 0);
	virtual ~Spaceship();
	virtual void move(Pair<float> aCoord);
	virtual void update();

private:
	uint_16 mSpeed;
	Pair<float> mTargetCoord;
};

#endif // !SPACESHIP_H