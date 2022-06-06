#include "gui_drawable.hpp"

dom::Storage<gui::Drawable::TextureCell> gui::Drawable::mTextureStorage;

gui::Drawable::Drawable(std::string aTexturePath) :
    mAnimationTimer (0),
    mAnimationLimit (0)
{
    setType(gui::GuiOutputBase::GuiObjectType::SPRITE);

    const sf::Texture& texture = mTextureStorage.getCell(aTexturePath).val;
    mSprite.setTexture(texture);
    sf::Vector2u temp = texture.getSize();
    mTextureSize = {temp.x, temp.y};

    mPositionOffset.x = mSprite.getGlobalBounds().height / 2;
    mPositionOffset.y = mSprite.getGlobalBounds().width / 2;
}

void
gui::Drawable::create()
{
    this->GuiOutputBase::create();
}

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
gui::Drawable::setSpritePosition(dom::Pair<float> aCoord)
{
    mSprite.setPosition(sf::Vector2f(aCoord.x, aCoord.y));
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
    mSprite.setTextureRect(mRect);
}

void
gui::Drawable::setRectChange(int dX, int dY)
{
    mRectOffset = {dX, dY};
}

void
gui::Drawable::setRectXLimits(int aX)
{
   mTextureSize.x = aX;
}

void
gui::Drawable::setRectYLimits(int aY)
{
   mTextureSize.x = aY;
}

void
gui::Drawable::setRectLimits(int aX, int aY)
{
   setRectXLimits(aX);
   setRectYLimits(aY);
}

void
gui::Drawable::updateAnimation(float adTime)
{
    mAnimationTimer += adTime;
    if (mAnimationLimit && mAnimationTimer > mAnimationLimit)
    {
        mAnimationTimer %= mAnimationLimit;
        mRect.top += mRectOffset.y;
        mRect.left += mRectOffset.x;
        if (mRect.top > mTextureSize.y) mRect.top = 0;
        if (mRect.left > mTextureSize.x) mRect.left = 0;
        mSprite.setTextureRect(mRect);

    }
}

void
gui::Drawable::setAnimationLimit(uint_16 aAnimationLimit)
{
    mAnimationLimit = aAnimationLimit;
}

dom::Pair<float>
gui::Drawable::getSpriteSize()
{
    sf::FloatRect bounds = mSprite.getGlobalBounds();
    return { bounds.width, bounds.height};
}

sf_2f_val
gui::Drawable::getSpritePosition()
{
    return  mSprite.getPosition();
}
