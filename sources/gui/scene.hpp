#ifndef SCENE_HPP
#define SCENE_HPP

//--------------------------------------------------------------------------------

#include <SFML/Graphics/View.hpp>

namespace gui
{
class Scene
{
public:
    Scene() noexcept;
    void draw() noexcept;

private:
    sf::View mView;
    
};
} // namespace gui

//--------------------------------------------------------------------------------

#endif // !SCENE_HPP
