#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

class MyWindow
{
public:
	MyWindow();
	virtual ~MyWindow();
protected:
	static sf::RenderWindow mWindow;
	//sf::RenderWindow mWindow;
};

#endif // !WINDOW_H