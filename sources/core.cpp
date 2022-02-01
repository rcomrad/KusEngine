#include "core.hpp"

//--------------------------------------------------------------------------------

#define WORLD_SIZE_X	32
#define WORLD_SIZE_Y	20

#define WINDOW_SIZE_X	1775
#define WINDOW_SIZE_Y	940

#define PAUSE_DELTA		7

Core::Core() :
	mView	(WINDOW_SIZE_X, WINDOW_SIZE_Y)
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
	}

}

//--------------------------------------------------------------------------------