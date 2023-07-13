#ifndef GUI_OUTPUT_BASE_H
#define GUI_OUTPUT_BASE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include <string>
#include <vector>

#include "domain/pair.hpp"

#include "window.hpp"

namespace gui
{
class BasicObject
{
    struct PositionUnion;

public:
    BasicObject(const std::string& aTextureName) noexcept;
    virtual ~BasicObject() = default;
    // void create();

    void draw(Window& aWindow) const noexcept;

    void move(const dom::Pair<float>& aCoord) noexcept;
    void setPosition(const dom::Pair<float>& aCoord) noexcept;
    // void resetPosition(dom::Pair<float> aCoord) noexcept;
    void setScale(const dom::Pair<float>& aCoord) noexcept;

    PositionUnion getPosition() const noexcept;

    // void centrateViewOnThis();

    // bool operator<(const GuiOutputBase& aOther) const;

    // static void addLayer(const dom::Pair<const char*, layer_type>& aLayer);
    // static void addLayer(
    // const std::vector<dom::Pair<const char*, layer_type>>& aLayerArray);

private:
    sf::Texture mTexture;
    sf::Sprite mSprite;

    struct PositionUnion
    {
        sf::Vector2f sfmlPos;

        operator sf::Vector2f() const noexcept;
        operator dom::Pair<float>() const noexcept;
    };

    // static void addComponentToDictionary(
    //     std::map<str_val, layer_type>& aDictionary,
    //     const std::vector<dom::Pair<const char*, layer_type>>&
    //     aComponentArray);

    // static layer_type getComponentNumber(
    //     const std::map<str_val, layer_type>& aDictionary,
    //     str_const_ref aComponentName);
};
} // namespace gui

// struct GuiOutputBaseComparator
// {
//     bool operator()(GuiOutputBase* a, GuiOutputBase* b) const;
// };

// typedef std::set<gui::GuiOutputBase*, gui::GuiOutputBaseComparator>
//     DraweblesSet;

#endif // !GUI_OUTPUT_BASE_H
