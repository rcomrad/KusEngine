#include "gui_drawable.hpp"

dom::Storage<gui::Drawable::TextureCell> gui::Drawable::mTextureStorage;

gui::Drawable::Drawable(std::string aTexturePath)
{
    setType(gui::GuiOutputBase::GuiObjectType::SPRITE);

    sf::Texture texture = mTextureStorage.getCell(aTexturePath).val;
    mSprite.setTexture(texture);
    sf::Vector2u temp = texture.getSize();
    mTextureSize = {temp.x, temp.y};

    mPositionOffset.x = mSprite.getGlobalBounds().height / 2;
    mPositionOffset.y = mSprite.getGlobalBounds().width / 2;
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
        (aCoord.x - mPositionOffset.x),
        (aCoord.y - mPositionOffset.y)
    });
}

void
gui::Drawable::setSpriteScale(dom::Pair<float> aCoord)
{
    mSprite.setScale({ float(aCoord.x), float(aCoord.y) });

    mPositionOffset.x = mSprite.getGlobalBounds().height / 2;
    mPositionOffset.y = mSprite.getGlobalBounds().width / 2;
}

void
gui::Drawable::setRect(dom::Pair<int> aPosition, int aWidth, int aHeight)
{

    mRect = sf::IntRect(aPosition.x, aPosition.y, aWidth, aHeight);
}

void
gui::Drawable::setRectChange(int dX, int dY)
{
    mRectOffset = {dX, dY};
}

sf_2f_val
gui::Drawable::getSpritePosition()
{
    return  mSprite.getPosition();
}
