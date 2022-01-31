#include "background.hpp"

//Background::Background(std::string aTexturePath, sf::RenderWindow& aWindow) :
//	Drawable(aTexturePath, aWindow)
Background::Background(std::string aTexturePath) :
	MyDrawable(aTexturePath)
{
}
Background::~Background() {}