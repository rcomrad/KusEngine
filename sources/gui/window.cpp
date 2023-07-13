#include "window.hpp"

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

// bool
// gui::Window::pollEvent(sf::Event& event) noexcept
// {
//     return mWindow.pollEvent(event);
// }
