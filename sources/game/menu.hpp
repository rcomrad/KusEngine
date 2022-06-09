#ifndef MENU_H
#define MENU_H

//--------------------------------------------------------------------------------

#include <iostream>

#include "gui/key_event.hpp"
#include "gui/close_event.hpp"
#include "gui/mouse_event.hpp"

#include "logic/program_state.hpp"
#include "logic/objects_storage.hpp"
#include "logic/buttons.hpp"
#include "logic/program_states_data.hpp"

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