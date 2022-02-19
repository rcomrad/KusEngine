#ifndef GAME_H
#define GAME_H

//--------------------------------------------------------------------------------

#include <iostream>

#include "core/program_state.hpp"
#include "space/player.hpp"
#include "gui/background.hpp"
#include "events//key_event.hpp"

#include "game/date.hpp"

namespace sr
{
	class Game : public ProgramState
	{
	public:
		Game();
		virtual ~Game();

		virtual bool run(std::vector<sr::Event*> aEvents);
		virtual
			const SET_DRAWEBLE_TYPE*
			getPresentation() const;
	private:
		bool mPause;
		SET_DRAWEBLE_TYPE mObjectsDrawSide;
		std::set<GameObject*> mObjectsLogicSide;;
		//std::vector<MyDrawable*> mObjectss;

		void mouseEventsHandler(Event* aEvent);
		void keyEventsHandler(Event* aEvent);

		//Date* d;
	};
}

//--------------------------------------------------------------------------------

#endif // !GAME_H