#include "scene.hpp"

#include <functional>

#include "file/common_data.hpp"
#include "file/parser.hpp"
#include "file/path.hpp"
#include "gui/window.hpp"

lgc::Scene::Scene(const std::string& aPath) noexcept
{
    // mObjects.emplace_back(
    //     file::Path::getInstance().getPath("textures").value() +
    //     "player.png");
    // mObjects.back().setPosition({100, 100});

    // if ()

    //     static std::unordered_map<std::string, int> levelValue = {
    //                 {"background", 0},
    //                 {"object", 0},
    //         {"menu_bar",            0},
    //         {"menu_bar_background", 1},

    //     };

    auto objects = file::Parser::getAllObjects(aPath);
    applySettings(objects);

    for (auto& object : objects)
    {
        auto level = getObjectLevel(object);
        auto& cur  = mObjects[level].emplace_back(object);
    }
}

void
lgc::Scene::draw() noexcept
{
    // objects[0]
    auto& window = gui::Window::getInstance();
    window.setView(mView);
    for (auto& level : mObjects)
    {
        for (auto& i : level.second) i.draw(window);
    }
}

bool
lgc::Scene::interact(event::MouseEvent aEvent) noexcept
{
    static auto& window = gui::Window::getInstance();
    window.convertCoordinates(aEvent.coord, mView);

    bool result = false;
    for (auto& level : mObjects)
    {
        for (auto& i : level.second)
        {
            result = i.interact(aEvent);
            if (result) break;
        }
    }
    return result;
}

void
lgc::Scene::applySettings(std::vector<file::VariableArray>& aVariables) noexcept
{
    static std::unordered_map<std::string, decltype(&lgc::Scene::loadLevels)>
        router = {
            {"level", &lgc::Scene::loadLevels}
    };

    int indx = 0;
    for (; indx < aVariables.size() && aVariables[indx].count("setting");
         ++indx)
    {
        auto& object = aVariables[indx];

        auto it = object.find("type");
        if (it == object.end()) continue;

        auto funcIt = router.find(std::string(it->second));
        if (funcIt == router.end()) continue;

        object.erase("type");
        object.erase("setting");

        (this->*funcIt->second)(object);
    }

    aVariables.erase(aVariables.begin(), aVariables.begin() + indx);
}

void
lgc::Scene::loadLevels(file::VariableArray& aVariables) noexcept
{
    auto it = aVariables.find("load");
    if (it != aVariables.end())
    {
        file::CommonData::getInstance().addData("level", it->second,
                                                aVariables);
    }
    aVariables.erase("load");

    for (auto& i : aVariables)
    {
        mLevelValue[i.first] = i.second;
    }
}

int
lgc::Scene::getObjectLevel(file::VariableArray& aVariables) const noexcept
{
    int result = 1e9;

    auto it = aVariables.find("level");
    if (it != aVariables.end())
    {
        auto it2 = mLevelValue.find(it->second);
        if (it2 != mLevelValue.end())
        {
            result = it2->second;
        }
    }

    return result;
}
