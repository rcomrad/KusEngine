#include "core.hpp"

//--------------------------------------------------------------------------------

#define WORLD_SIZE_X	32
#define WORLD_SIZE_Y	20



#define PAUSE_DELTA		7

Core::Core() :
	mView	(0, 0)
{
	mCurrentState = new Game();
}

Core::~Core(){}

void
Core::run()
{
	while (true)
	{
		mView.drawObjects(mCurrentState->getPresentation());
		mCurrentState->run(mView.getEvents());
		for (int i = 0; i < 1e7; ++i);
	}

}

//--------------------------------------------------------------------------------