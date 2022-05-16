#ifndef EVN_MOUSE_EVENT_H
#define EVN_MOUSE_EVENT_H

//--------------------------------------------------------------------------------

#include "domain/dom_pair.hpp"

#include "event.hpp"

namespace evn
{
	class MoveEvent : public Event
	{
    public:
		MoveEvent(float aX, float aY);

    public:
		dom::Pair<float> mCoord;
	};
}

//--------------------------------------------------------------------------------

#endif // !EVN_MOUSE_EVENT_H