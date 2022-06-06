#include "space/spaceship.hpp"

#define DAY_SPEED float(3000)

//Spaceship::Spaceship(std::string aTexturePath, sf::RenderWindow& aWindow) :
//	Drawable(aTexturePath, aWindow)
sr::Spaceship::Spaceship
(
	std::string aTexturePath, 
	str_const_ref aLayer
) :
	SpaceObject(aTexturePath, aLayer),
	mSpeed(1)
{
	mSpeed = 10;
	mTargetCoord = getPosition();
	setAnimationLimit(100);
	setRect({0, 500}, 145, 100);
	setRectChange(145, 0);	
	setRectXLimits(650);
}

std::shared_ptr<sr::Spaceship>
sr::Spaceship::create		
(
	std::string aTexturePath, 
	str_const_ref aLayer
)
{
	std::shared_ptr<sr::Spaceship> result (new Spaceship(aTexturePath, aLayer));
	result->SpaceObject::create();
	return result;
}

void
sr::Spaceship::create()
{
	this->SpaceObject::create();
}

void
sr::Spaceship::move(dom::Pair<float> aCoord)
{
	mTargetCoord = aCoord;
	//Pair<int> dist = aCoord - MyDrawable::getPosition();

	//MyDrawable::moveSprite();
}

void 
sr::Spaceship::update(float adTime)
{
	dom::Pair<float> dist = mTargetCoord - Drawable::getPosition();
	double dSpace = adTime / DAY_SPEED * mSpeed;
	dist.x *= dSpace;
	dist.y *= dSpace;
	Drawable::move(dist);
	updateAnimation(adTime);
}