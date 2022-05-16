#include "writable.hpp"

dom::Storage<gui::Writable::FontCell> gui::Writable::mFontsStorage;

gui::Writable::Writable
(
    std::string     aFontPath
) :
    mCoordOffset({0.f, 0.f})
{
    setType(gui::GuiOutputBase::GuiObjectType::TEXT);

    mText.setFont(mFontsStorage.getCell(aFontPath).val);
}

gui::Writable::~Writable() {}

void
gui::Writable::drawText()
{
    gui::Window::globalWindow.draw(mText);
}

void
gui::Writable::moveText(dom::Pair<float> aCoord)
{
    mText.move({aCoord.x,aCoord.y});
}

void
gui::Writable::resetTextPosition(dom::Pair<float> aCoord)
{
    mText.setPosition
    ({
        (aCoord.x - mCoordOffset.x),
        (aCoord.y - mCoordOffset.y)
    });
}

void
gui::Writable::setTextScale(dom::Pair<float> aCoord)
{
    mText.setScale({ float(aCoord.x), float(aCoord.y) });

    mCoordOffset.x = mText.getGlobalBounds().height / 2;
    mCoordOffset.y = mText.getGlobalBounds().width / 2;
}

sf_2f_val
gui::Writable::getTextPosition()
{
    return mText.getPosition();
}

void 
gui::Writable::setText(std::string aText)
{
    mText.setString(aText);
}