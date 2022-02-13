#ifndef CORE_H
#define CORE_H

//--------------------------------------------------------------------------------

#include <iostream>

#include "gui/gui.hpp"
#include "core/program_state.hpp"
#include "game/game.hpp"
#include "core/my_time.hpp"

namespace sr
{
	class Core
	{
	public:
		Core();
		~Core();

		void run();

	private:
		GUI mView;

		ProgramState* mCurrentState;
	};
}

//--------------------------------------------------------------------------------

#endif // CORE_H