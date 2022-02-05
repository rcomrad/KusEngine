#include "spaceship.hpp"

#define DAY_SPEED float(3000)

//Spaceship::Spaceship(std::string aTexturePath, sf::RenderWindow& aWindow) :
//	Drawable(aTexturePath, aWindow)
Spaceship::Spaceship
(
	std::string aTexturePath, 
	uint_8 aLayer
) :
	SpaceObject(aTexturePath, aLayer),
	mSpeed(1)
{
	mSpeed = 10;
	mTargetCoord = MyDrawable::getPosition();
}
Spaceship::~Spaceship(){}

void
Spaceship::move(Pair<float> aCoord)
{
	mTargetCoord = aCoord;
	//Pair<int> dist = aCoord - MyDrawable::getPosition();

	//MyDrawable::moveSprite();
}

void 
Spaceship::update()
{
	double dDay = MyTime::getDTime() / DAY_SPEED;
	Pair<float> dist = mTargetCoord - MyDrawable::getPosition();
	dist.x *= dDay * mSpeed;
	dist.y *= dDay * mSpeed;
	MyDrawable::moveSprite(dist);
}