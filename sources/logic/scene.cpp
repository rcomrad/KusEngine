#include "scene.hpp"

#include "file/parser.hpp"
#include "file/path.hpp"
#include "gui/window.hpp"

lgc::Scene::Scene(const std::string& aPath) noexcept
{
    // mObjects.emplace_back(
    //     file::Path::getInstance().getPath("textures").value() +
    //     "player.png");
    // mObjects.back().setPosition({100, 100});
    auto objects = file::Parser::getAllObjects(aPath);
    for (auto& i : objects)
    {
        auto& cur = mObjects.emplace_back(i);
    }
}

void
lgc::Scene::draw() const noexcept
{
    // objects[0]
    auto& window = gui::Window::getInstance();
    window.setView(mView);
    for (const auto& i : mObjects) i.draw(window);
}

bool
lgc::Scene::interact(const event::MouseEvent& aEvent) noexcept
{
    bool result = false;
    for (auto& i : mObjects)
    {
        result = i.interact(aEvent);
        if (result) break;
    }
    return result;
}
