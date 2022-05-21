#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <map>

#include <SFML/Graphics.hpp>

#include "domain/dom_string.hpp"
#include "domain/dom_type.hpp"
#include "domain/dom_error_message.hpp"

#include "gui_types.hpp"

namespace gui
{
	class Window
	{
	public:
		static Window globalWindow;

		Window();
		virtual ~Window();
		//static void draw(auto& aTarget);

		void draw(sf::Text& aTarget);
		void draw(sf::Sprite& aTarget);

		void clear	();
		void display();
		void close	();

		bool pollEvent(sf::Event& event);

		uint_8	getViewNumber	(str_const_ref aViewName);
		void	setView			(uint_8 aViewNumber);
		void	centrateView	(uint_8 aViewNumber, sf_2f_const_ref aCoord);
		//TODO:
		void	centrateView	(str_const_ref aViewName, sf_2f_const_ref aCoord);

	public:
		sf::RenderWindow mWindow;

		uint_8						mCurrentViewNumber;		
		std::vector<sf::View>		mViews;
		std::map<str_val, uint_8>	mViewNumbers;
		
		//sf::RenderWindow mWindow;
	};
}

#endif // !WINDOW_H