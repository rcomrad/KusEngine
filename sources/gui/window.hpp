#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

namespace gui
{
	class Window
	{
	public:
		Window();
		virtual ~Window();
		//static void draw(auto& aTarget);
		static void draw(sf::Text& aTarget);
		static void draw(sf::Sprite& aTarget);
		static void clear();
		static void display();
		static bool isOpen();
		static bool pollEvent(sf::Event& event);
		static void close();

	public:
		static sf::RenderWindow allWindow;
		//sf::RenderWindow mWindow;
	};
}

#endif // !WINDOW_H