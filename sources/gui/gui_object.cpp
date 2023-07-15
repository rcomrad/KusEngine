#include "gui_object.hpp"

gui::GUIObject::GUIObject(const std::string& aTextureName) noexcept
{
    mTexture.loadFromFile(aTextureName);
    mSprite.setTexture(mTexture);
}

void
gui::GUIObject::draw(gui::Window& aWindow) const noexcept
{
    aWindow.draw(mSprite);
}

void
gui::GUIObject::move(const dom::Pair<float>& aCoord) noexcept
{
    mSprite.move({aCoord.x, aCoord.y});
}

void
gui::GUIObject::setPosition(const dom::Pair<float>& aCoord) noexcept
{
    mSprite.setPosition(sf::Vector2f(aCoord.x, aCoord.y));
}

// void
// gui::GUIObject::resetPosition(dom::Pair<float> aCoord)
// {
//     mSprite.setPosition(
//         {(aCoord.x - mPositionOffset.x), (aCoord.y - mPositionOffset.y)});
// }

void
gui::GUIObject::setScale(const dom::Pair<float>& aCoord) noexcept
{
    mSprite.setScale({float(aCoord.x), float(aCoord.y)});

    // mPositionOffset.x = mSprite.getGlobalBounds().height / 2;
    // mPositionOffset.y = mSprite.getGlobalBounds().width / 2;
}

gui::GUIObject::PositionUnion
gui::GUIObject::getPosition() const noexcept
{
    return {mSprite.getPosition()};
}

bool
gui::GUIObject::contains(const dom::Pair<float>& aCoord) const noexcept
{
    return mSprite.getLocalBounds().contains({aCoord.x, aCoord.y});
}

gui::GUIObject::PositionUnion::operator sf::Vector2f() const noexcept
{
    return sfmlPos;
}

gui::GUIObject::PositionUnion::operator dom::Pair<float>() const noexcept
{
    return {sfmlPos.x, sfmlPos.y};
}
