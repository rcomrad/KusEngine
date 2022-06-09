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
#include "game/background.hpp"

#include "window.hpp"
#include "drawable.hpp"
#include "close_event.hpp"
#include "event.hpp"
#include "mouse_event.hpp"
#include "close_event.hpp"
#include "key_event.hpp"
#include "type.hpp"

#include "logic/objects_storage.hpp"

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
		
		static void addLayer(str_const_ref aName, layer_type& aLayerNumber);
		static void centrate(str_const_ref aViewName, str_const_ref aObjectTag);

	private:
		gui::CloseEvent* makeCloseEvent(sf::Event* aEvent);
		gui::MouseEvent* makeMouseEvent(sf::Event* aEvent);
		gui::KeyEvent* makeKeyEvent(sf::Event* aEvent);
	};
}

//--------------------------------------------------------------------------------

#endif // GUI_H