#ifndef CORE_H
#define CORE_H

//--------------------------------------------------------------------------------

#include <iostream>

#include "gui/gui.hpp"
#include "game/game.hpp"
#include "game/menu.hpp"

#include "logic/program_state.hpp"
#include "logic/lgc_time.hpp"

namespace sr
{
	class Core
	{
	public:
		Core();
		~Core();

		void run();
		void makeNextState(lgc::ProgramState::ProgramStateName aName);

	private:
		gui::GUI mView;

		lgc::ProgramState* mCurrentState;
	};
}

//--------------------------------------------------------------------------------

#endif // CORE_H