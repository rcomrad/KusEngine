#ifndef EVENT_H
#define EVENT_H

//--------------------------------------------------------------------------------

#include "core/domain.hpp"

namespace sr
{
	class Event
	{
	public:
		enum EventType
		{
			NUN = 0,
			MOVE = 1,
			KEY_PRESSED = 2,
			CLOSE = 3
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
}

//--------------------------------------------------------------------------------

#endif // !EVENT_H