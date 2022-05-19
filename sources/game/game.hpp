#ifndef GAME_H
#define GAME_H

//--------------------------------------------------------------------------------

#include <iostream>

#include "gui/gui_key_event.hpp"
#include "gui/gui_close_event.hpp"
#include "gui/gui_mouse_event.hpp"

#include "logic/program_state.hpp"
#include "logic/objects_storage.hpp"

#include "game/date.hpp"
#include "space/planet.hpp"
#include "space/player.hpp"
#include "gui/background.hpp"

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

	private:
		bool mPause;
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