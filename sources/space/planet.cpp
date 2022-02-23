#include "space/planet.hpp"

#define PLANET_TEXTURE TEXTURES "planet.png"

sr::Planet::Planet() :
	SpaceObject	(PLANET_TEXTURE, 7)
{
	Drawable::setScale({0.1, 0.1});
	//Drawable::resetSprite({ 10000, 10000 });
	//x0 = 10000;
	//y0 = 10000;

}

sr::Planet::~Planet() {}

void
sr::Planet::update() 
{
	float x1 = x0 + (r * cos((a) / 100.));
	float y1 = y0 + (r * sin((a) / 100.));
	a += sr::Time::getDTime();
	if (a > 36000) a = 1;

	//for (int i = 0; i < 1e7; ++i);

	//Pair<float> dist = mTargetCoord - Drawable::getPosition();
	//double dSpace = Time::getDTime() / DAY_SPEED * mSpeed;
	//dist.x *= dSpace;
	//dist.y *= dSpace;
	//std::cout << x1 << " " << y1 << std::endl;
	//Drawable::moveSprite({x1, y1});
	Drawable::resetSprite({ x1, y1 });
}

void
sr::Planet::processEvent(Event* aEvent)
{
}

void
sr::Planet::move(Pair<float> aCoord)
{

}