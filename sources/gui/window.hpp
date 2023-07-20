#ifndef KUS_WINDOW_HPP
#define KUS_WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/View.hpp>

#include <map>
#include <vector>

#include "event/gui_event.hpp"

namespace gui
{
class Window
{
public:
    static Window& getInstance() noexcept;

    void draw(const sf::Text& aTarget) noexcept;
    void draw(const sf::Sprite& aTarget) noexcept;

    void clear() noexcept;
    void display() noexcept;
    void close() noexcept;

    void setView(const sf::View& aView) noexcept;

    void convertCoordinates(dom::Pair<float>& aCord,
                            sf::View aVies) const noexcept;

    std::vector<event::GUIEvent> pollEvent() noexcept;

private:
    Window() noexcept;

    sf::RenderWindow mWindow;

    void setMousePosition(event::GUIEvent& aEvent) const noexcept;
};
} // namespace gui

#endif // !KUS_WINDOW_HPP
