#include "writable.hpp"

dom::Storage<gui::Writable::FontCell> gui::Writable::mFontsStorage;

gui::Writable::Writable(uint_8 aLayer) :
    gui::Writable(STANDART_FONT_PATH, aLayer)
{}

gui::Writable::Writable(str_const_ref aFontPath, uint_8 aLayer) :
    GuiOutputBase(aLayer),
    mCoordOffset({0.f, 0.f})
{
    //TODO:
    FontCell ff = (mFontsStorage.getCell(aFontPath));
    // sf::Font val = ff.val;
    // FontCell af("jj");
    // sf::Font vall = af.val;
	// mText.setFont((mFontsStorage.getCell(aFontPath)).val);
    mText.setFont(ff.val);
    setType(gui::GuiOutputBase::GuiOutputType::TEXT);
}

gui::Writable::~Writable() {}

void 
gui::Writable::draw()
{
	Window::draw(mText);
}

dom::Pair<float>
gui::Writable::getPosition()
{
    sf::Vector2f pos = mText.getPosition();
    return  { mCoordOffset.x + pos.x, mCoordOffset.y + pos.y };
}

void
gui::Writable::move(dom::Pair<float> aCoord)
{
    mText.move({aCoord.x,aCoord.y});
}

void
gui::Writable::resetPosition(dom::Pair<float> aCoord)
{
    mText.setPosition
    ({
        (aCoord.x - mCoordOffset.x),
        (aCoord.y - mCoordOffset.y)
    });
}

void
gui::Writable::setScale(dom::Pair<float> aCoord)
{
    mText.setScale({ float(aCoord.x), float(aCoord.y) });

    mCoordOffset.x = mText.getGlobalBounds().height / 2;
    mCoordOffset.y = mText.getGlobalBounds().width / 2;
}

void 
gui::Writable::setText(std::string aText)
{
    mText.setString(aText);
}