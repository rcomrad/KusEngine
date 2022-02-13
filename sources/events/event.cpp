#include "events/event.hpp"

sr::Event::Event(EventType aType)
{
	mType = aType;
}

sr::Event::~Event(){}

sr::Event::EventType
sr::Event::getEventType()
{
	return mType;
}

sr::MoveEvent::MoveEvent(float aX, float aY) :
	Event		(EventType::MOVE),
	mCoord		(aX, aY)
{

}