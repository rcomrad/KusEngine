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

    void draw() noexcept;
    bool interact(event::MouseEvent aEvent) noexcept;

private:
    sf::View mView;

    std::unordered_map<std::string, int> mLevelValue;
    std::map<int, std::vector<Object>> mObjects;

    void applySettings(std::vector<file::VariableArray>& aVariables) noexcept;

    void loadLevels(file::VariableArray& aVariables) noexcept;

    int getObjectLevel(file::VariableArray& aVariables) const noexcept;

    static void loadObjectInfo(const std::string& aPath,
                     file::VariableArray& aVariables) noexcept;
};
} // namespace lgc

//--------------------------------------------------------------------------------

#endif // !SCENE_HPP
