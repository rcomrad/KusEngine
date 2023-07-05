#include "scene.hpp"

#include "window.hpp"

gui::Scene::Scene() noexcept
{
    // mView.
}

void
gui::Scene::draw() noexcept
{
    auto& window = Window::getInstance();
    window.setView(mView);
}
