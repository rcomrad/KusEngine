#ifndef SCENE_HPP
#define SCENE_HPP

//--------------------------------------------------------------------------------

#include <SFML/Graphics/View.hpp>

#include <vector>

#include "basic_object.hpp"

namespace gui
{
class Scene
{
public:
    Scene(const std::string& aPath) noexcept;
    void draw() const noexcept;

private:
    sf::View mView;

    std::vector<BasicObject> mObjects;
};
} // namespace gui

//--------------------------------------------------------------------------------

#endif // !SCENE_HPP
