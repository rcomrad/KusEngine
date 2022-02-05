#ifndef EVENT_H
#define EVENT_H

//--------------------------------------------------------------------------------

#include "domain.hpp"

class Event
{
public:
	enum EventType
	{
		NUN = 0,
		MOVE = 1
	};

	Event(EventType aType);
	virtual ~Event();

	EventType getEventType();

private:
	EventType mType;
};

struct MoveEvent : public Event
{
	MoveEvent(float aX, float aY);
	Pair<float> mCoord;
};

//--------------------------------------------------------------------------------

#endif // !EVENT_H