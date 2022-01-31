#include "spaceship.hpp"

//Spaceship::Spaceship(std::string aTexturePath, sf::RenderWindow& aWindow) :
//	Drawable(aTexturePath, aWindow)
Spaceship::Spaceship(std::string aTexturePath) :
	MyDrawable(aTexturePath)
{

}
Spaceship::~Spaceship(){}