#include "writable.hpp"

dom::Storage<gui::Writable::FontCell> gui::Writable::mFontsStorage;

gui::Writable::Writable
(
    str_const_ref   aLayerName,
    str_const_ref   aViewName
) :
    gui::Writable(STANDART_FONT_PATH, aLayerName, aViewName)
{}

gui::Writable::Writable
(
    std::string     aFontPath,
    str_const_ref   aLayerName,
    str_const_ref   aViewName
) :
    mCoordOffset({0.f, 0.f})
{
    setType(gui::GuiOutputBase::GuiObjectType::TEXT);
    setLayer(aLayerName);
    setView(aViewName);
}

gui::Writable::~Writable() {}

void
gui::Writable::draw()
{
    gui::Window::globalWindow.draw(mText);
}

// dom::Pair<float>
// gui::Writable::getPosition()
// {
//     sf::Vector2f pos = mText.getPosition();
//     return  { mCoordOffset.x + pos.x, mCoordOffset.y + pos.y };
// }

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

sf_2f_val
gui::Writable::getPosition()
{
    return mText.getPosition();
}

void 
gui::Writable::setText(std::string aText)
{
    mText.setString(aText);
}