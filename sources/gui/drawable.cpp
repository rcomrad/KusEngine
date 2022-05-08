#include "gui/drawable.hpp"

gui::Drawable::Drawable
(
    std::string aTexturePath,
    uint_8 aLayer
) :
    GuiOutputBase       (aLayer)
{
    mSprite.setTexture(mTextureStorage.getCell(aTexturePath).val);

    mCoordOffset.x = mSprite.getGlobalBounds().height / 2;
    mCoordOffset.y = mSprite.getGlobalBounds().width / 2;

    setType(gui::GuiOutputBase::GuiOutputType::SPRITE);
}

gui::Drawable::~Drawable(){}

void
gui::Drawable::draw()
{
    Window::draw(mSprite);
}

dom::Pair<float>
gui::Drawable::getPosition()
{
    sf::Vector2f pos = mSprite.getPosition();
    return  { mCoordOffset.x + pos.x, mCoordOffset.y + pos.y };
}

void
gui::Drawable::move(dom::Pair<float> aCoord)
{
    mSprite.move({aCoord.x, aCoord.y});
}

void
gui::Drawable::resetPosition(dom::Pair<float> aCoord)
{
    mSprite.setPosition
    ({
        (aCoord.x - mCoordOffset.x),
        (aCoord.y - mCoordOffset.y)
    });
}


void
gui::Drawable::setScale(dom::Pair<float> aCoord)
{
    mSprite.setScale({ float(aCoord.x), float(aCoord.y) });

    mCoordOffset.x = mSprite.getGlobalBounds().height / 2;
    mCoordOffset.y = mSprite.getGlobalBounds().width / 2;
}