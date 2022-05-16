#include "events/event.hpp"

evn::Event::Event(EventType aType)
{
	mType = aType;
}

evn::Event::~Event(){}

evn::Event::EventType
evn::Event::getEventType()
{
	return mType;
}