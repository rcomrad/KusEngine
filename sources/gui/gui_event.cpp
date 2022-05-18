#include "gui_event.hpp"

gui::Event::Event(EventType aType)
{
	mType = aType;
}

gui::Event::~Event(){}

gui::Event::EventType
gui::Event::getEventType()
{
	return mType;
}