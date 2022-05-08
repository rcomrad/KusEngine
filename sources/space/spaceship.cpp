#include "space/spaceship.hpp"

#define DAY_SPEED float(3000)

//Spaceship::Spaceship(std::string aTexturePath, sf::RenderWindow& aWindow) :
//	Drawable(aTexturePath, aWindow)
sr::Spaceship::Spaceship
(
	std::string aTexturePath, 
	uint_8 aLayer
) :
	SpaceObject(aTexturePath, aLayer),
	mSpeed(1)
{
	mSpeed = 10;
	mTargetCoord = Drawable::getPosition();
}
sr::Spaceship::~Spaceship(){}

void
sr::Spaceship::move(dom::Pair<float> aCoord)
{
	mTargetCoord = aCoord;
	//Pair<int> dist = aCoord - MyDrawable::getPosition();

	//MyDrawable::moveSprite();
}

void 
sr::Spaceship::update()
{
	dom::Pair<float> dist = mTargetCoord - Drawable::getPosition();
	double dSpace = Time::getDTime() / DAY_SPEED * mSpeed;
	dist.x *= dSpace;
	dist.y *= dSpace;
	Drawable::move(dist);
}