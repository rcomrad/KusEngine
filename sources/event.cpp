#include "event.hpp"

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

MoveEvent::MoveEvent(float aX, float aY) :
	Event		(EventType::MOVE),
	mCoord		(aX, aY)
{

}