#ifndef GUI_HPP
#define GUI_HPP

#include <vector>

#include "logic/scene.hpp"

namespace gui
{
class GUI
{
public:
    GUI() noexcept = default;

    void draw(std::vector<lgc::Scene>& aScenes) noexcept;
    // void update() noexcept;
};
} // namespace gui

#endif // !GUI_HPP
