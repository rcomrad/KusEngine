#include "game/game.hpp"

sr::Game::Game() :
	mPause(false)
{
	Player* p = new Player();
	Background* b = new Background();
	Planet* pp = new Planet();
	Date* d = new Date();

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
		for (auto i : lgc::ObjectStorage::globalObjecStorage["logical"])
		{
			dynamic_cast<lgc::LogicObject*>(i)->update();
		}
	}
}

void 
sr::Game::mouseEventsHandler(gui::Event* aEvent)
{
	gui::MouseEvent* moveEvent = static_cast <gui::MouseEvent*> (aEvent);
	std::cout << moveEvent->mCoord.x << " " << moveEvent->mCoord.y << "\n";

	for (auto i : lgc::ObjectStorage::globalObjecStorage["logical"])
	{
		dynamic_cast<lgc::LogicObject*>(i)->processEvent(aEvent);
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
	}
}