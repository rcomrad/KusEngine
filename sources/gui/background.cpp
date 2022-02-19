#include "gui/background.hpp"

//Background::Background(std::string aTexturePath, sf::RenderWindow& aWindow) :
//	Drawable(aTexturePath, aWindow)
sr::Background::Background(std::string aTexturePath) :
	Drawable(aTexturePath, 1)
{
}
sr::Background::~Background() {}

void
sr::Background::update() {}

void
sr::Background::processEvent(Event* aEvent)
{
}