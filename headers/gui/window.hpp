#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

namespace sr
{
	class Window
	{
	public:
		Window();
		virtual ~Window();
		static sf::RenderWindow allWindow;
		//sf::RenderWindow mWindow;
	};
}

#endif // !WINDOW_H