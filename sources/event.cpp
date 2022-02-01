#include "event.h"

Event::Event(EventType aType)
{
	mType = aType;
}

Event::~Event(){}

Event::EventType
Event::getEventType()
{
	return mType;
}

MoveEvent::MoveEvent(int aX, int aY) :
	Event		(EventType::MOVE),
	mCoord		(aX, aY)
{

}