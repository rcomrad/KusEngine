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
#include "gui_types.hpp"

namespace gui
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

		void drawObjects();

		static void addDrawable(gui::GuiOutputBase* aDrawable);
		static void removeDrawable(gui::GuiOutputBase* aDrawable);

	private:
		gui::CloseEvent* makeCloseEvent(sf::Event* aEvent);
		gui::MouseEvent* makeMouseEvent(sf::Event* aEvent);
		gui::KeyEvent* makeKeyEvent(sf::Event* aEvent);

		static DraweblesSet mDrawebles;
	};
}

//--------------------------------------------------------------------------------

#endif // GUI_H