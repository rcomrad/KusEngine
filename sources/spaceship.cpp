#include "spaceship.hpp"

//Spaceship::Spaceship(std::string aTexturePath, sf::RenderWindow& aWindow) :
//	Drawable(aTexturePath, aWindow)
Spaceship::Spaceship
(
	std::string aTexturePath, 
	uint_8 aLayer
) :
	SpaceObject(aTexturePath, aLayer)
{

}
Spaceship::~Spaceship(){}

void
Spaceship::move(Pair<int> aCoord)
{
	MyDrawable::moveSprite(aCoord);
}