#ifndef GAME_H
#define GAME_H

//--------------------------------------------------------------------------------

#include <iostream>

#include "gui/key_event.hpp"
#include "gui/close_event.hpp"
#include "gui/mouse_event.hpp"

#include "logic/program_state.hpp"
#include "logic/objects_storage.hpp"
#include "logic/program_states_data.hpp"

#include "game/date.hpp"
#include "space/planet.hpp"
#include "space/player.hpp"
#include "game/background.hpp"

namespace sr
{
	class Game : public lgc::ProgramState
	{
	public:
		Game();
		virtual ~Game();

		// virtual bool run(std::vector<gui::Event*> aEvents);
		//virtual const SetDrawebleType* getPresentation() const;
		virtual void processEvents(std::vector<gui::Event*> aEvents);
		virtual void update();
		std::optional<lgc::ProgramState::ProgramStateName> getNextStateName() override;

	private:
		bool mPause;
		ProgramStateName mNextState;
		//SetDrawebleType mObjectsDrawSide;
		//std::set<GameObject*> mObjectsLogicSide;;
		//std::vector<MyDrawable*> mObjectss;

		void mouseEventsHandler(gui::Event* aEvent);
		void keyEventsHandler(gui::Event* aEvent);

		//Date* d;
	};
}

//--------------------------------------------------------------------------------

#endif // !GAME_H