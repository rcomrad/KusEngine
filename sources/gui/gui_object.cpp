#include "gui_object.hpp"

#include "file/path.hpp"

gui::GUIObject::GUIObject(const std::string& aTextureName) noexcept
{
    mTexture.loadFromFile(aTextureName);
    mSprite.setTexture(mTexture);

    mFont.loadFromFile(file::Path::getInstance().getPath("font").value() +
                       "font.ttf");
    mText.setFont(mFont);
}

void
gui::GUIObject::draw(gui::Window& aWindow) noexcept
{
    if (mTexts.empty())
    {
        aWindow.draw(mSprite);
    }
    else
    {
        auto temp = getPosition();
        for (auto& i : mTexts)
        {
            aWindow.draw(mSprite);
            move(mOfset);
        }
        setPosition(temp);
    }
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

void
gui::GUIObject::setOfset(const dom::Pair<float>& aOfset) noexcept
{
    mOfset = aOfset;
}

void
gui::GUIObject::setTexts(const std::vector<std::string>& aTexts) noexcept
{
    mTexts = aTexts;
}

void
gui::GUIObject::emplaceBackText(const std::string& aText) noexcept
{
    mTexts.emplace_back(aText);
}

int
gui::GUIObject::contains(const dom::Pair<float>& aCoord) noexcept
{
    int result = -1;
    if (mTexts.empty())
    {
        result =
            mSprite.getGlobalBounds().contains({aCoord.x, aCoord.y}) ? 1 : -1;
    }
    else
    {
        auto temp = getPosition();
        for (int i = 0; i < mTexts.size(); ++i)
        {
            auto t1  = mSprite.getLocalBounds();
            auto t2  = mSprite.getGlobalBounds();
            auto t23 = mSprite.getTextureRect();

            if (mSprite.getGlobalBounds().contains({aCoord.x, aCoord.y}))
            {
                result = i;
                break;
            }
            move(mOfset);
        }
        setPosition(temp);
    }
    return result;
}

gui::GUIObject::PositionUnion::operator sf::Vector2f() const noexcept
{
    return sfmlPos;
}

gui::GUIObject::PositionUnion::operator dom::Pair<float>() const noexcept
{
    return {sfmlPos.x, sfmlPos.y};
}
