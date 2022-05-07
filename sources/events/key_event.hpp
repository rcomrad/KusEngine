#ifndef KEY_EVENT_HPP
#define KEY_EVENT_HPP

//--------------------------------------------------------------------------------

#include "core/domain.hpp"
#include "events/event.hpp"

namespace sr
{
	struct KeyEvent : public sr::Event
	{
		enum KeyEventType
		{
			NUN = 0,
			SPACE_PAUSE = 1
		};

		KeyEvent(KeyEventType aType);
		~KeyEvent();

		KeyEventType mType;
	};
}

//--------------------------------------------------------------------------------

#endif // !KEY_EVENT_HPP