#include "gui/drawable.hpp"

dom::Storage<gui::Drawable::TextureCell> gui::Drawable::mTextureStorage;

gui::Drawable::Drawable
(
    std::string     aTexturePath,
    str_const_ref   aLayerName,
    str_const_ref   aViewName
)
{
    mSprite.setTexture( mTextureStorage.getCell(aTexturePath).val);

    mCoordOffset.x = mSprite.getGlobalBounds().height / 2;
    mCoordOffset.y = mSprite.getGlobalBounds().width / 2;

    setType(gui::GuiOutputBase::GuiObjectType::SPRITE);
    setLayer(aLayerName);
    setView(aViewName);
}

gui::Drawable::~Drawable(){}

void
gui::Drawable::draw()
{
    gui::Window::globalWindow.draw(mSprite);
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