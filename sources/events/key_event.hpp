#ifndef KEY_EVENT_HPP
#define KEY_EVENT_HPP

//--------------------------------------------------------------------------------

#include "core/domain.hpp"
#include "events/event.hpp"

namespace evn
{
	class KeyEvent : public Event
	{
		KeyEvent(KeyEventType aType);
		~KeyEvent();

		KeyEventType mType;
	};
}

//--------------------------------------------------------------------------------

#endif // !KEY_EVENT_HPP