#include "gui_drawable.hpp"

dom::Storage<gui::Drawable::TextureCell> gui::Drawable::mTextureStorage;

gui::Drawable::Drawable(std::string aTexturePath)
{
    setType(gui::GuiOutputBase::GuiObjectType::SPRITE);

    mSprite.setTexture(mTextureStorage.getCell(aTexturePath).val);

    mCoordOffset.x = mSprite.getGlobalBounds().height / 2;
    mCoordOffset.y = mSprite.getGlobalBounds().width / 2;
}

gui::Drawable::~Drawable(){}

void
gui::Drawable::drawSprite()
{
    gui::Window::globalWindow.draw(mSprite);
}

void
gui::Drawable::moveSprite(dom::Pair<float> aCoord)
{
    mSprite.move({aCoord.x, aCoord.y});
}

void
gui::Drawable::resetSpritePosition(dom::Pair<float> aCoord)
{
    mSprite.setPosition
    ({
        (aCoord.x - mCoordOffset.x),
        (aCoord.y - mCoordOffset.y)
    });
}

void
gui::Drawable::setSpriteScale(dom::Pair<float> aCoord)
{
    mSprite.setScale({ float(aCoord.x), float(aCoord.y) });

    mCoordOffset.x = mSprite.getGlobalBounds().height / 2;
    mCoordOffset.y = mSprite.getGlobalBounds().width / 2;
}

sf_2f_val
gui::Drawable::getSpritePosition()
{
    return  mSprite.getPosition();
}
