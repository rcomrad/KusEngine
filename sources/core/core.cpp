#include "core/core.hpp"

//--------------------------------------------------------------------------------

#define WORLD_SIZE_X	32
#define WORLD_SIZE_Y	20



#define PAUSE_DELTA		7

sr::Core::Core() :
	mCurrentState(nullptr)
{
	makeNextState(lgc::ProgramState::ProgramStateName::Menu);
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
		auto nextState = mCurrentState->getNextStateName();
		if (nextState) makeNextState(nextState.value());
		if (mCurrentState->isClosed()) break;
		mCurrentState->update();
	}

}

void
sr::Core::makeNextState(lgc::ProgramState::ProgramStateName aName)
{
	if (mCurrentState != nullptr) delete mCurrentState;
	switch (aName)
	{
	case lgc::ProgramState::ProgramStateName::Nun :
		break;
	case lgc::ProgramState::ProgramStateName::Game :
		mCurrentState = new Game();
		break;	
	case lgc::ProgramState::ProgramStateName::Menu :
		mCurrentState = new Menu();
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------------------------