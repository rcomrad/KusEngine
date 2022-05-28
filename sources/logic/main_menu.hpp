#ifndef MAIN_MUNE_HPP
#define MAIN_MUNE_HPP

//--------------------------------------------------------------------------------

#include "gui/gui_key_event.hpp"
#include "gui/gui_close_event.hpp"
#include "gui/gui_mouse_event.hpp"

#include "program_state.hpp"
#include "objects_storage.hpp"

namespace lgc
{
	class MainMenu : public lgc::ProgramState
	{
	public:
		MainMenu() = default;
		virtual ~MainMenu() = default;

		virtual void processEvents(std::vector<gui::Event*> aEvents);
		virtual void update();

	private:
		void mouseEventsHandler(gui::Event* aEvent);
		void keyEventsHandler(gui::Event* aEvent);
	};
}

//--------------------------------------------------------------------------------

#endif // !MAIN_MUNE_HPP