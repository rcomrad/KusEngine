#ifndef GUI_HPP
#define GUI_HPP

#include <vector>

#include "scene.hpp"

namespace gui
{
class GUI
{
public:
    // GUI() noexcept;

    void draw() noexcept;
    void update() noexcept;

private:
    std::vector<Scene> mScenes;
};
} // namespace gui

#endif // !GUI_HPP
