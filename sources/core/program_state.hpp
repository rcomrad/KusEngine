#ifndef PROGRAM_STATE_H
#define PROGRAM_STATE_H

//--------------------------------------------------------------------------------

#include <set>

#include "core/domain.hpp"
#include "events/event.hpp"
#include "gui/drawable.hpp"

//#define SET_DRAWEBLE_TYPE std::set<sr::GuiOutputBase*, sr::GuiOutputBaseComparator>
typedef std::set<gui::GuiOutputBase*, gui::GuiOutputBaseComparator> SetDrawebleType;

namespace sr
{
	class ProgramState
	{
	public:
		ProgramState();
		virtual ~ProgramState();

		virtual bool run(std::vector<Event*> aEvents) = 0;
		virtual
			const SetDrawebleType*
			getPresentation() const = 0;
	};
}

//--------------------------------------------------------------------------------

#endif // !PROGRAM_STATE_H