#include "game/game.hpp"

#include "logic/buttons.hpp"

sr::Game::Game() :
	ProgramState	("game.info"),
	mPause(false),
	mNextState(ProgramStateName::Nun)
{
	//this->stateSetup(lgc::ProgramStatesData::globalProgramStatesData.getData("Game"));
	// boost::property_tree::ptree data;
	// boost::property_tree::info_parser::read_info(DATA "game.info", data);
	// this->stateSetup(data.find("StateSettings")->second);
	
	Player::create();
	Background::create();
	Planet::create();
	Date::create();

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

	auto logArray = lgc::ObjectStorage::globalObjecStorage["logical"];
	if (logArray)
	{
		for (auto& logObj : logArray.value())
		{
			// TODO: Brackets are somehow critical
			(dynamic_cast<lgc::LogicObject*>(logObj.get()))->processEvent(aEvent);
		}
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