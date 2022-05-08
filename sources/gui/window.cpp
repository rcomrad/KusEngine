#include "gui/window.hpp"

#define WINDOW_SIZE_X	1000
#define WINDOW_SIZE_Y	1000

gui::Window::Window() {}

gui::Window::~Window() {}

sf::RenderWindow gui::Window::allWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Evolution");

// void 
// gui::Window::draw(auto& aTarget)
// {
//     allWindow.draw(aTarget);
// }

void 
gui::Window::draw(sf::Text&aTarget)
{
    allWindow.draw(aTarget);
}

void 
gui::Window::draw(sf::Sprite& aTarget)
{
    allWindow.draw(aTarget);
}

void 
gui::Window::clear()
{
    allWindow.clear(sf::Color::Black);
}

void 
gui::Window::display()
{
    allWindow.display();
}

bool 
gui::Window::isOpen()
{
    return allWindow.isOpen();
}

bool 
gui::Window::pollEvent(sf::Event& event)
{
    return allWindow.pollEvent(event);
}

void 
gui::Window::close()
{
    return allWindow.close();
}