#include "window.hpp"

#define WINDOW_SIZE_X	1000
#define WINDOW_SIZE_Y	1000

MyWindow::MyWindow() {}

MyWindow::~MyWindow() {}

sf::RenderWindow MyWindow::mWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Evolution");
