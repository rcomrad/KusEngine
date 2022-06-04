#include "menu.hpp"


sr::Menu::Menu() :
	mNextState(ProgramStateName::Nun)
{
	lgc::Buttons* button = new lgc::Buttons(TEXTURES + "button.png", {"play", "exit"}, {100., 100.});
}

sr::Menu::~Menu()
{
}

void
sr::Menu::processEvents(std::vector<gui::Event*> aEvents)
{
	for (gui::Event* i : aEvents)
	{
		switch (i->getEventType())
		{
		case gui::Event::EventType::MOUSE_RELEASED	:
			mouseEventsHandler(i);
			break;
		case gui::Event::EventType::KEY_RELEASED	:
			break;
		case gui::Event::EventType::WINDOW_CLOSED	:
			close();
			break;
		}
	}
}

void
sr::Menu::update()
{
}

std::optional<lgc::ProgramState::ProgramStateName>
sr::Menu::getNextStateName()
{
	if (mNextState != ProgramStateName::Nun) return mNextState;
	return {};
}

void 
sr::Menu::mouseEventsHandler(gui::Event* aEvent)
{
	gui::MouseEvent* moveEvent = static_cast <gui::MouseEvent*> (aEvent);
	std::cout << moveEvent->mCoord.x << " " << moveEvent->mCoord.y << "\n";

	auto res = 
	(dynamic_cast<lgc::LogicObject*>
		(*lgc::ObjectStorage::globalObjecStorage["Button"].begin())
	)->processEvent(aEvent);
	if (res) 
    {
        switch (res.value())
        {
        case 0 :
            mNextState = lgc::ProgramState::ProgramStateName::Game;
            break;
        }
    }
    
   
}
