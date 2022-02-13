#include "core/core.hpp"

//--------------------------------------------------------------------------------

#define WORLD_SIZE_X	32
#define WORLD_SIZE_Y	20



#define PAUSE_DELTA		7

sr::Core::Core() :
	mView	(0, 0)
{
	mCurrentState = new Game();
	Time::updateTime();
	//for (int i = 0; i < 1e6; ++i);
}

sr::Core::~Core(){}

void
sr::Core::run()
{
	while (true)
	{
		Time::updateTime();
		if (Time::getFPSDCount())
			mView.drawObjects(mCurrentState->getPresentation());
		if (mCurrentState->run(mView.getEvents())) break;
		//for (int i = 0; i < 1e7; ++i);
	}

}

//--------------------------------------------------------------------------------