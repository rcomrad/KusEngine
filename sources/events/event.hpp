#ifndef EVENT_H
#define EVENT_H

//--------------------------------------------------------------------------------

#include "domain/dom_pair.hpp"

namespace evn
{
	class Event
	{
	public:
		enum class EventType
		{
			NUN = 0,
			MOUSE_MOVE = 1,
			KEY_PRESSED = 2,
			CLOSE = 3
		};

		Event(EventType aType);
		virtual ~Event();

		EventType getEventType();

	private:
		EventType mType;
	};
}

//--------------------------------------------------------------------------------

#endif // !EVENT_H