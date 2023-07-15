#ifndef SCENE_HPP
#define SCENE_HPP

//--------------------------------------------------------------------------------

#include <SFML/Graphics/View.hpp>

#include <string>
#include <vector>

#include "domain/holy_trinity.hpp"

#include "basic_object.hpp"

namespace lgc
{
class Scene
{
public:
    Scene(const std::string& aPath) noexcept;
    HOLY_TRINITY_MOST(Scene);

    void draw() const noexcept;
    bool interact(const event::MouseEvent& aEvent) noexcept;

private:
    sf::View mView;

    std::vector<Object> mObjects;
};
} // namespace lgc

//--------------------------------------------------------------------------------

#endif // !SCENE_HPP
