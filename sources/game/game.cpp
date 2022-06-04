#include "game/game.hpp"

#include "logic/buttons.hpp"

sr::Game::Game() :
	mPause(false),
	mNextState(ProgramStateName::Nun)
{
	Player* p = new Player();
	Background* b = new Background();
	Planet* pp = new Planet();
	Date* d = new Date();

	//lgc::Buttons* button = new lgc::Buttons(TEXTURES + "button.png", {"play", "exit"}, {100., 100.});

	// mObjectsDrawSide.insert(p);
	// mObjectsDrawSide.insert(b);
	// mObjectsDrawSide.insert(d);
	// mObjectsDrawSide.insert(pp);

	// mObjectsLogicSide.insert(p);
	// mObjectsLogicSide.insert(b);
	// mObjectsLogicSide.insert(d);
	// mObjectsLogicSide.insert(pp);
}

sr::Game::~Game()
{
	//for (auto i : mObjectsDrawSide) delete i;
}

// const SetDrawebleType*
// sr::Game::getPresentation() const
// {
// 	return &mObjectsDrawSide;
// }

void
sr::Game::processEvents(std::vector<gui::Event*> aEvents)
{
	for (gui::Event* i : aEvents)
	{
		switch (i->getEventType())
		{
		case gui::Event::EventType::MOUSE_RELEASED	:
			mouseEventsHandler(i);
			break;
		case gui::Event::EventType::KEY_RELEASED	:
			keyEventsHandler(i);
			break;
		case gui::Event::EventType::WINDOW_CLOSED	:
			close();
			break;
		}
	}
}

void
sr::Game::update()
{
	if (!mPause)
	{
		timeUpdate();
		// for (auto i : lgc::ObjectStorage::globalObjecStorage["logical"])
		// {
		// 	dynamic_cast<lgc::LogicObject*>(i)->update(0);
		// }
	}
}

std::optional<lgc::ProgramState::ProgramStateName>
sr::Game::getNextStateName()
{
	if (mNextState != ProgramStateName::Nun) return mNextState;
	return {};
}

void 
sr::Game::mouseEventsHandler(gui::Event* aEvent)
{
	gui::MouseEvent* moveEvent = static_cast <gui::MouseEvent*> (aEvent);
	std::cout << moveEvent->mCoord.x << " " << moveEvent->mCoord.y << "\n";

	// auto res = 
	// (dynamic_cast<lgc::LogicObject*>
	// 	(*lgc::ObjectStorage::globalObjecStorage["Button"].begin())
	// )->processEvent(aEvent);
	// if (res) std::cout << res.value() << '\n';
	// else  std::cout << "false" << '\n';

	for (auto i : lgc::ObjectStorage::globalObjecStorage["logical"])
	{
		// TODO: Brackets are somehow critical
		(dynamic_cast<lgc::LogicObject*>(i))->processEvent(aEvent);
	}
}

void 
sr::Game::keyEventsHandler(gui::Event* aEvent)
{
	gui::KeyEvent* moveEvent = static_cast <gui::KeyEvent*> (aEvent);

	switch (moveEvent->getKey())
	{
	case gui::KeyEvent::KeyType::Space :
		mPause = !mPause;
		break;
	case gui::KeyEvent::KeyType::Escape :
		mNextState = lgc::ProgramState::ProgramStateName::Menu;
		break;
	case gui::KeyEvent::KeyType::X :
		close();
		break;
	}
}