#ifndef GUI_H
#define GUI_H

//--------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

#include <SFML/Graphics.hpp>

#include "space/player.hpp"
#include "background.hpp"

#include "gui_window.hpp"
#include "gui_drawable.hpp"
#include "gui_close_event.hpp"
#include "gui_event.hpp"
#include "gui_mouse_event.hpp"
#include "gui_close_event.hpp"
#include "gui_key_event.hpp"

#include "logic/program_state.hpp"

namespace sr
{
	class GUI
	{
	public:
		// enum class EventType
		// {
		// 	NUN = 0,
		// 	SWITCH_DRAW_MODE = 1,
		// 	SWITCH_PAUSE = 2,
		// 	INCREASE_SPEED = 3,
		// 	DECREASE_SPEED = 4,
		// 	STANDART_PAUSE = 5
		// };

		GUI();

		// bool isAppClosed() const;
		std::vector<gui::Event*> getEvents();

		void drawObjects
		(
			const SetDrawebleType* aDrawableObjects
		);

	private:
		gui::CloseEvent* makeCloseEvent(sf::Event* aEvent);
		gui::MouseEvent* makeMouseEvent(sf::Event* aEvent);
		gui::KeyEvent* makeKeyEvent(sf::Event* aEvent);

		//std::set<MyDrawable*> mDrawableObjects;
		//std::set<MyDrawable*> mDrawableObjects;
		//sf::RenderWindow mWindow;
		//auto ;
		//std::set<int, decltype(cmp)> s;
		//std::map< sf::Keyboard::Key, KeyEvent::KeyEventType> mHotkeys;
	};
}

//--------------------------------------------------------------------------------

#endif // GUI_H