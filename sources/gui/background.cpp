#include "gui/background.hpp"

//Background::Background(std::string aTexturePath, sf::RenderWindow& aWindow) :
//	Drawable(aTexturePath, aWindow)
sr::Background::Background(std::string aTexturePath) :
	Drawable		(aTexturePath)
{
	setLayer("Background");
	setView("Static");
	//Drawable::resetSprite({ 10000, 10000 });
}
sr::Background::~Background() {}

void
sr::Background::update() {}

void
sr::Background::processEvent(gui::Event* aEvent)
{
}