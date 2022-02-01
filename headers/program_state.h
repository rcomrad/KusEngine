#ifndef PROGRAM_STATE_H
#define PROGRAM_STATE_H

//--------------------------------------------------------------------------------

#include <set>

#include "domain.hpp"
#include "event.h"
#include "drawable.hpp"

class ProgramState
{
public:
	ProgramState();
	virtual ~ProgramState();

	virtual void run(std::vector<Event*> aEvents) = 0;
	virtual
		const std::set<MyDrawable*, DrawableComparator>*
		getPresentation() const = 0;
};

//--------------------------------------------------------------------------------

#endif // !PROGRAM_STATE_H