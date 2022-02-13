#ifndef GAME_H
#define GAME_H

//--------------------------------------------------------------------------------

#include <iostream>

#include "core/program_state.hpp"
#include "space/player.hpp"
#include "gui/background.hpp"
#include "events//key_event.hpp"

namespace sr
{
	class Game : public ProgramState
	{
	public:
		Game();
		virtual ~Game();

		virtual bool run(std::vector<sr::Event*> aEvents);
		virtual
			const std::set<Drawable*, DrawableComparator>*
			getPresentation() const;
	private:
		bool mPause;
		std::set<Drawable*, DrawableComparator> mObjects;
		//std::vector<MyDrawable*> mObjectss;

		void mouseEventsHandler(Event* aEvent);
		void keyEventsHandler(Event* aEvent);
	};
}

//--------------------------------------------------------------------------------

#endif // !GAME_H