#ifndef GUI_HPP
#define GUI_HPP

#include <vector>

#include "scene.hpp"

namespace gui
{
class GUI
{
public:
    GUI() noexcept = default;

    void draw(const std::vector<Scene>& aScenes) noexcept;
    // void update() noexcept;
};
} // namespace gui

#endif // !GUI_HPP
