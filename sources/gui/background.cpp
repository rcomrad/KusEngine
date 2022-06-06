#include "gui/background.hpp"

sr::Background::Background(std::string aTexturePath) :
	Drawable		(aTexturePath)
{
	setLayer("Background");
	setView("Static");
}

std::shared_ptr<sr::Background>
sr::Background::create(std::string aTexturePath)
{
	std::shared_ptr<sr::Background> result (new Background(aTexturePath));
	result->addTag("Background");
	result->Drawable::create();
	return result;
}