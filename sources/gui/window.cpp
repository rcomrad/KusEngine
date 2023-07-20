#include "window.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>

#include "core/variable_storage.hpp"

gui::Window&
gui::Window::getInstance() noexcept
{
    static Window instance;
    return instance;
}

gui::Window::Window() noexcept
{
    auto& var = core::VariableStorage::getInstance();

    int width        = var.getInt("window_height", 400);
    int height       = var.getInt("window_height", 300);
    std::string name = var.getWord("window_name", "window");

    mWindow.create(sf::VideoMode(width, height), name);

    int framerateLimit = var.getInt("framerate_limit", 60);
    mWindow.setFramerateLimit(framerateLimit);
}

void
gui::Window::draw(const sf::Text& aTarget) noexcept
{
    mWindow.draw(aTarget);
}

void
gui::Window::draw(const sf::Sprite& aTarget) noexcept
{
    mWindow.draw(aTarget);
}

void
gui::Window::clear() noexcept
{
    mWindow.clear(sf::Color::Black);
}

void
gui::Window::display() noexcept
{
    mWindow.display();
}

void
gui::Window::setView(const sf::View& aView) noexcept
{
    mWindow.setView(aView);
}

void
gui::Window::close() noexcept
{
    return mWindow.close();
}

void
gui::Window::convertCoordinates(dom::Pair<float>& aCord,
                                sf::View aVies) const noexcept
{
    auto temp = mWindow.mapPixelToCoords(sf::Vector2i(aCord.x, aCord.y), aVies);
    aCord.x   = temp.x;
    aCord.y   = temp.y;
}

std::vector<event::GUIEvent>
gui::Window::pollEvent() noexcept
{
    std::vector<event::GUIEvent> result;

    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        auto& temp = result.emplace_back();

        switch (event.type)
        {
            case sf::Event::Closed:
                temp.type = event::GUIEvent::Type::Close;
                break;

            case sf::Event::KeyPressed:
                temp.actionType = event::ActionType::Pressed;
            case sf::Event::KeyReleased:
                if (temp.type == event::GUIEvent::Type::Nun)
                    temp.actionType = event::ActionType::Relised;

                temp.type = event::GUIEvent::Type::KeyInput;

                temp.value = event.key.code;
                break;

            case sf::Event::MouseButtonPressed:
                temp.actionType = event::ActionType::Pressed;
            case sf::Event::MouseButtonReleased:
                if (temp.type == event::GUIEvent::Type::Nun)
                    temp.actionType = event::ActionType::Relised;

                temp.type = event::GUIEvent::Type::MouseInput;

                temp.value =
                    event.mouseButton.button == sf::Mouse::Left ? 1 : -1;
                setMousePosition(temp);
                break;
        }
    }

    if (result.empty())
    {
        auto& temp = result.emplace_back();
        temp.type  = event::GUIEvent::Type::MouseInput;
        setMousePosition(temp);
    }

    return result;
}

void
gui::Window::setMousePosition(event::GUIEvent& aEvent) const noexcept
{
    aEvent.x = sf::Mouse::getPosition(mWindow).x;
    aEvent.y = sf::Mouse::getPosition(mWindow).y;
}
