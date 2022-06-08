#ifndef MAIN_MUNE_HPP
#define MAIN_MUNE_HPP

//--------------------------------------------------------------------------------

#include "gui/key_event.hpp"
#include "gui/close_event.hpp"
#include "gui/mouse_event.hpp"

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