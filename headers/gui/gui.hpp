#ifndef GUI_H
#define GUI_H

//--------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

#include <SFML/Graphics.hpp>

#include "core/domain.hpp"
#include "gui/window.hpp"
#include "space/player.hpp"
#include "gui/background.hpp"
#include "gui/drawable.hpp"
#include "events/close_event.hpp"

#include "events/event.hpp"
#include "events/key_event.hpp"

namespace sr
{
	class GUI
		//class GUI
	{
	public:
		enum EventType
		{
			NUN = 0,
			SWITCH_DRAW_MODE = 1,
			SWITCH_PAUSE = 2,
			INCREASE_SPEED = 3,
			DECREASE_SPEED = 4,
			STANDART_PAUSE = 5
		};

		GUI(sint_16 aN, sint_16 aM);

		bool isAppClosed() const;
		std::vector<Event*> getEvents();

		void drawObjects
		(
			const
			std::set<Drawable*, DrawableComparator>*
			aDrawableObjects
		);

	private:
		//std::set<MyDrawable*> mDrawableObjects;
		//std::set<MyDrawable*> mDrawableObjects;
		//sf::RenderWindow mWindow;
		//auto ;
		//std::set<int, decltype(cmp)> s;
		std::map< sf::Keyboard::Key, KeyEvent::KeyEventType> mHotkeys;
	};
}

//--------------------------------------------------------------------------------

#endif // GUI_H