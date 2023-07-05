#include "gui.hpp"

#include "window.hpp"

// gui::GUI::GUI()noexcept
// {
// }

void
gui::GUI::draw() noexcept
{

    auto& window = Window::getInstance();

    window.clear();
    for (auto& i : mScenes) i.draw();
    window.display();
}

void
gui::GUI::update() noexcept
{
}
