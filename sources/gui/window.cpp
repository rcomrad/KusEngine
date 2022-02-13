#include "gui/window.hpp"

#define WINDOW_SIZE_X	1000
#define WINDOW_SIZE_Y	1000

sr::Window::Window() {}

sr::Window::~Window() {}

sf::RenderWindow sr::Window::allWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Evolution");
