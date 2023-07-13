#include "scene.hpp"

#include "file/parser.hpp"
#include "file/path.hpp"

#include "window.hpp"

gui::Scene::Scene(const std::string& aPath) noexcept
{
    // mObjects.emplace_back(
    //     file::Path::getInstance().getPath("textures").value() +
    //     "player.png");
    // mObjects.back().setPosition({100, 100});
    auto objects = file::Parser::getAllObjects(aPath);
    for (auto& i : objects)
    {

        auto& cur = mObjects.emplace_back(
            file::Path::getInstance().getPath("textures").value() +
            std::string(i["texture"]));

        auto it = i.find("scale");
        if (it != i.end()) cur.setScale(it->second);

        it = i.find("position");
        if (it != i.end()) cur.setPosition(it->second);
        // cur.setPosition({100, 100});
    }
}

void
gui::Scene::draw() const noexcept
{
    auto& window = Window::getInstance();
    window.setView(mView);
    for (const auto& i : mObjects) i.draw(window);
}
