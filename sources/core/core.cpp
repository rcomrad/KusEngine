#include "core/core.hpp"

//--------------------------------------------------------------------------------

#define WORLD_SIZE_X	32
#define WORLD_SIZE_Y	20



#define PAUSE_DELTA		7

sr::Core::Core()
{
	mCurrentState = new Game();
}

sr::Core::~Core(){}

void
sr::Core::run()
{
	while (true)
	{
		// while (lgc::Time::globalTime.getFPSDCount() == 0)
		// {
		//  	lgc::Time::globalTime.updateTimeAndFPS();
		// }
		// lgc::Time::globalTime.updateTimeAndFPS();
		// if (lgc::Time::globalTime.getFPSDCount())
		// {
		//  	mView.drawObjects();
		// }
		mView.drawObjects();
		mCurrentState->processEvents(mView.getEvents());
		if (mCurrentState->isClosed()) break;
		mCurrentState->update();
	}

}

//--------------------------------------------------------------------------------