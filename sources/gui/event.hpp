#ifndef EVENT_H
#define EVENT_H

//--------------------------------------------------------------------------------

#include "domain/pair.hpp"

namespace gui
{
	class Event
	{
	public:
		enum class EventType
		{
			NUN,
			MOUSE_PRESSED,
			MOUSE_RELEASED,
			KEY_PRESSED,
			KEY_RELEASED,
			WINDOW_CLOSED
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