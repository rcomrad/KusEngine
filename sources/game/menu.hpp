#ifndef MENU_H
#define MENU_H

//--------------------------------------------------------------------------------

#include <iostream>

#include "gui/gui_key_event.hpp"
#include "gui/gui_close_event.hpp"
#include "gui/gui_mouse_event.hpp"

#include "logic/program_state.hpp"
#include "logic/objects_storage.hpp"
#include "logic/buttons.hpp"

namespace sr
{
	class Menu : public lgc::ProgramState
	{
	public:
		Menu();
		virtual ~Menu();

		virtual void processEvents(std::vector<gui::Event*> aEvents);
		virtual void update();
		std::optional<lgc::ProgramState::ProgramStateName> getNextStateName() override;

	private:
		ProgramStateName mNextState;

		void mouseEventsHandler(gui::Event* aEvent);

		//Date* d;
	};
}

//--------------------------------------------------------------------------------

#endif // !MENU_H