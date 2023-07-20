#ifndef GUI_OBJECT_HPP
#define GUI_OBJECT_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include <string>
#include <vector>

#include "domain/holy_trinity.hpp"
#include "domain/pair.hpp"

#include "window.hpp"

namespace gui
{
class GUIObject
{
    struct PositionUnion;

public:
    GUIObject(const std::string& aTextureName) noexcept;
    HOLY_TRINITY_MOST(GUIObject);

    void draw(Window& aWindow) noexcept;

    void move(const dom::Pair<float>& aCoord) noexcept;
    void setPosition(const dom::Pair<float>& aCoord) noexcept;
    // void resetPosition(dom::Pair<float> aCoord) noexcept;
    void setScale(const dom::Pair<float>& aCoord) noexcept;

    // bool hasIntersection() const noexcept;

    PositionUnion getPosition() const noexcept;

    void setOfset(const dom::Pair<float>& aOfset) noexcept;
    void setTexts(const std::vector<std::string>& aTexts) noexcept;
    void emplaceBackText(const std::string& aText) noexcept;

    int contains(const dom::Pair<float>& aCoord) noexcept;

private:
    sf::Texture mTexture;
    sf::Sprite mSprite;
    // static sf::Text mText;
    // static sf::Font mFont;
    sf::Text mText;
    sf::Font mFont;

    dom::Pair<float> mOfset;
    std::vector<std::string> mTexts;

    struct PositionUnion
    {
        sf::Vector2f sfmlPos;

        operator sf::Vector2f() const noexcept;
        operator dom::Pair<float>() const noexcept;
    };
};
} // namespace gui

#endif // !GUI_OBJECT_HPP
