#include "space/planet.hpp"

#define PLANET_TEXTURE TEXTURES "planet.png"

sr::Planet::Planet() :
	SpaceObject	(PLANET_TEXTURE, "Planet")
{
	setScale({0.1, 0.1});
	setView("Player");

}

std::shared_ptr<sr::Planet>
sr::Planet::create()
{
	std::shared_ptr<sr::Planet> result (new Planet);
	result->addTag("Planet");
	result->SpaceObject::create();
	return result;
}

void
sr::Planet::update(float adTime) 
{
	float x1 = x0 + (r * cos((a) / 100.));
	float y1 = y0 + (r * sin((a) / 100.));
	a += adTime / 10.;
	while (a > 36000) a -= 36000;

	//for (int i = 0; i < 1e7; ++i);

	//Pair<float> dist = mTargetCoord - Drawable::getPosition();
	//double dSpace = Time::getDTime() / DAY_SPEED * mSpeed;
	//dist.x *= dSpace;
	//dist.y *= dSpace;
	//std::cout << x1 << " " << y1 << std::endl;
	//Drawable::moveSprite({x1, y1});
	resetPosition({ x1, y1 });
}

void
sr::Planet::move(dom::Pair<float> aCoord)
{

}