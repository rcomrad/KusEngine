#include "gui/writable.hpp"

#define STANDART_FONT_PATH "font.ttf"

sf::Font* sr::Writable::allFont(NULL);

//sr::Writable::Writable(uint_8 aLayer, std::string aFontPath):
sr::Writable::Writable(uint_8 aLayer) :
GuiOutputBase(GuiOutputBase::TEXT, aLayer)
{
	if (allFont == NULL)
	{
        allFont = new sf::Font();
		allFont->loadFromFile(STANDART_FONT_PATH);
	}
	mText.setFont(*allFont);
}

sr::Writable::~Writable() {}

void 
sr::Writable::draw()
{
	Window::allWindow.draw(mText);
}

void
sr::Writable::moveText(Pair<float> aCoord)
{
    mText.move
    ({
        (aCoord.x),
        (aCoord.y)
        });
}

void
sr::Writable::resetTextPosition(Pair<float> aCoord)
{
    mText.setPosition
    ({
        (aCoord.x - mCoordOffset.x),
        (aCoord.y - mCoordOffset.y)
        });
}


void
sr::Writable::setScale(Pair<float> aCoord)
{
    mText.setScale({ float(aCoord.x), float(aCoord.y) });

    mCoordOffset.x = mText.getGlobalBounds().height / 2;
    mCoordOffset.y = mText.getGlobalBounds().width / 2;
}

Pair<float>
sr::Writable::getPosition()
{
    sf::Vector2f pos = mText.getPosition();
    return  { (mCoordOffset.x + pos.x),
        (mCoordOffset.y + pos.y) };
}

void 
sr::Writable::setText(std::string aText)
{
    mText.setString(aText);
}